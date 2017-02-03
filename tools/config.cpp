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

std::string Config::generateMap(){
    std::string s{"Here we go"};

    std::map<std::string, std::string> state;
    std::vector<std::string> brand_names;
    brand_names.push_back("apple");
    brand_names.push_back("microsoft");

    for(std::string name : brand_names){
        state[name] = name;
    }

    typedef std::map<std::string, std::string>::const_iterator Iter;
    for(Iter p = state.begin(); p != state.end(); ++p){
        std::cout<<p->first<<" : "<<p->second<<std::endl;
    }


    return s;
}

void Config::save(std::string path) {
    std::cout << "foo";
    std::ofstream fh;
    fh.open(path, std::ofstream::out | std::ofstream::trunc);
    typedef std::map<std::string, std::string>::const_iterator Iter;
    for(Iter i = state.begin(); i != state.end(); ++i){
        fh << i->first << " " << i->second << std::endl;
    }
    fh.flush();
    fh.close();
}
