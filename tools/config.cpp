#include "config.h"

#include <string>
#include <iostream>
#include <map>
#include <vector>

// Constructor
Config::Config()
{
    std::cout << "Created new instance" << std::endl;
    setPath("./");
    setFileName("random.txt");
}

// Destructor
Config::~Config(){
    std::cout << "Activated destructor" << std::endl;
}

// Populate the map with test data
void Config::generateMap(){
    std::vector<std::string> brand_names;
    brand_names.push_back("apple");
    brand_names.push_back("microsoft");
    brand_names.push_back("sony");
    brand_names.push_back("google");

    for(std::string name : brand_names){
        state[name] = name + "value";
    }
}

//Print the current map
void Config::printState(){
    std::cout << "Current State:" << std::endl;
    typedef std::map<std::string, std::string>::const_iterator Iter;
    for(Iter i = state.begin(); i != state.end(); ++i){
        std::cout << i->first << " | " << i->second << std::endl;
    }
    std::cout << "End of state." << std::endl;
}

/*
 * File System
 */

// Save the current map to the file
void Config::saveState() {
    std::cout << "Saved to " << path << file_name << std::endl;
    std::ofstream fh;
    fh.open(path + file_name, std::ofstream::out | std::ofstream::trunc);

    typedef std::map<std::string, std::string>::const_iterator Iter;
    for(Iter i = state.begin(); i != state.end(); ++i){
        fh << i->first << " | " << i->second << std::endl;
    }

    fh.flush();
    fh.close();
}

// Load the current map from the file
void Config::reloadState(){
    std::cout << "Loaded from " << path << file_name << std::endl;
    std::ifstream fh;
    std::string line;
    fh.open(path + file_name, std::ifstream::in);

    std::string delimiter = " | ";
    while(std::getline (fh, line)){
        int splitPosition = line.find(delimiter);
        std::string key = line.substr(0, splitPosition);
        std::string value = line.substr(splitPosition + delimiter.length());
        state[key] = value;
    }

    fh.close();
}

// Set the path (not including the filename)
void Config::setPath(std::string path){
    this -> path = path;
}

// Set the filename
void Config::setFileName(std::string file_name){
    this -> file_name = file_name;
}

/*
 * Manipulation
 */

// Get a value (from a key)
std::string Config::getValue(std::string key){
    return state[key];
}

// Set a value (key, value)
void Config::setValue(std::string key, std::string value){
    state[key] = value;
}

// Clear the current map
void Config::clearState(){
    state.clear();
    std::cout << " Cleared " << std::endl;
    printState();
}
