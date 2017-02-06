#include "config.h"

Config::Config(){
    SHOW_WHERE;
    setCompletePath("./random.txt");
    reloadState();
}

Config::Config(std::string pathToFile){
    SHOW_WHERE;
    setCompletePath(pathToFile);
    reloadState();
}

Config::Config(Config &obj) {
    SHOW_WHERE;
    file_name = obj.file_name;
    path = obj.path;
    state = obj.state;
}

void Config::operator =(Config &obj) {
    file_name = obj.file_name;
    path = obj.path;
    state = obj.state;
}

Config::~Config(){
    SHOW_WHERE;
    saveState();
}

/*!
 * \brief Populate the current map with test data
 */
void Config::generateMap(){
    SHOW_WHERE;
    std::vector<std::string> brand_names;
    brand_names.push_back("apple");
    brand_names.push_back("microsoft");
    brand_names.push_back("sony");
    brand_names.push_back("google");

    for(std::string name : brand_names){
        state[name] = name + "value";
    }
}

/*!
 * \brief Print the current map
 */
void Config::printState(){
    SHOW_WHERE;
    typedef std::map<std::string, std::string>::const_iterator Iter;
    for(Iter i = state.begin(); i != state.end(); ++i){
        std::cout << i->first << " | " << i->second << std::endl;
    }
    std::cout << "------" << std::endl;
}

/***************
 * File System *
 ***************/

/*!
 * \brief Save the current state to file
 */
void Config::saveState() {
    SHOW_WHERE;
    std::cout << "Path: " << path << file_name << std::endl;
    std::ofstream fh;
    try{
        fh.open(path + file_name, std::ofstream::out | std::ofstream::trunc);
    } catch (std::exception &e) {
        std::cout << "An error occurred flushing the file" << std::endl;
    }

    typedef std::map<std::string, std::string>::const_iterator Iter;
    for(Iter i = state.begin(); i != state.end(); ++i){
        fh << i->first << " | " << i->second << std::endl;
    }

    fh.flush();
    fh.close();
}

/*!
 * \brief Load the current map from the file
 */
void Config::reloadState(){
    SHOW_WHERE;
    clearState();
    std::cout << "Path: " << path << file_name << std::endl;
    std::ifstream fh;
    std::string line;

    try{
        fh.open(path + file_name, std::ifstream::in);
    } catch (std::exception &e) {
        std::cout << "An error occurred flushing the file" << std::endl;
    }

    std::string delimiter = " | ";
    while(std::getline (fh, line)){
        int splitPosition = line.find(delimiter);
        std::string key = line.substr(0, splitPosition);
        std::string value = line.substr(splitPosition + delimiter.length());
        state[key] = value;
    }

    try{
        fh.close();
    } catch (std::exception &e){
        std::cout << "An error occurred flushing the file" << std::endl;
    }
}

/*!
 * \brief Set the path (not including the filename)
 */
void Config::setPath(std::string path){
    this -> path = path;
}

/*!
 * \brief Set the filename
 */
void Config::setFileName(std::string file_name){
    this -> file_name = file_name;
}

/*!
 * \brief Set the complete path
 *
 * Seperated by last occurence of /
 */
void Config::setCompletePath(std::string complete_path) {
    int splitPosition = complete_path.find_last_of("/");
    setPath(complete_path.substr(0, splitPosition + 1));
    setFileName(complete_path.substr(splitPosition + 1));
}

/****************
 * Manipulation *
 ****************/

/*!
 * \brief Get a value (from a key)
 */
std::string Config::getValue(std::string key){
    return state[key];
}

/*!
 * \brief Set a value (key, value)
 */
void Config::setValue(std::string key, std::string value){
    state[key] = value;
}

/*!
 * \brief Clear the current map
 */
void Config::clearState(){
    SHOW_WHERE;
    state.clear();
    std::cout << " Cleared " << std::endl;
    printState();
}
