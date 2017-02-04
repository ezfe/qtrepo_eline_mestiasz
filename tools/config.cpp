#include "config.h"

#include <string>
#include <iostream>
#include <map>
#include <vector>

Config::Config()
{
    std::cout << "Created new instance" << std::endl;
    setPath("./");
    setFileName("random.txt");
}

Config::~Config(){
    std::cout << "Activated destructor" << std::endl;
}

std::string Config::getValue(std::string key){
    return state[key];
}

void Config::setValue(std::string key, std::string value){
    state[key] = value;
}

void Config::generateMap(){

    std::vector<std::string> brand_names;
    brand_names.push_back("apple");
    brand_names.push_back("microsoft");

    for(std::string name : brand_names){
        state[name] = name;
    }

}

void Config::saveState() {
    std::ofstream fh;
    fh.open(path + file_name, std::ofstream::out | std::ofstream::trunc);

    typedef std::map<std::string, std::string>::const_iterator Iter;
    for(Iter i = state.begin(); i != state.end(); ++i){
        fh << i->first << " | " << i->second << std::endl;
    }

    fh.flush();
    fh.close();
}

void Config::reloadState(){
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

void Config::printState(){
    typedef std::map<std::string, std::string>::const_iterator Iter;
    for(Iter i = state.begin(); i != state.end(); ++i){
        std::cout << i->first << " | " << i->second << std::endl;
    }
}

void Config::setPath(std::string path){
    this -> path = path;
}

void Config::setFileName(std::string file_name){
    this -> file_name = file_name;
}
