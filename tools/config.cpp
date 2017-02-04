#include "config.h"

#include <string>
#include <iostream>
#include <map>
#include <vector>

Config::Config()
{
    std::cout << "Created new instance" << std::endl;
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

void Config::saveState(std::string path) {
    std::ofstream fh;
    fh.open(path, std::ofstream::out | std::ofstream::trunc);

    typedef std::map<std::string, std::string>::const_iterator Iter;
    for(Iter i = state.begin(); i != state.end(); ++i){
        fh << i->first << " | " << i->second << std::endl;
    }

    fh.flush();
    fh.close();
}

void Config::reloadState(std::string path){
    std::ifstream fh;
    std::string line;
    fh.open(path, std::ifstream::in);

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
