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

    std::map<std::string, std::string> brands;
    std::vector<std::string> brand_names;
    brand_names.push_back("apple");
    brand_names.push_back("microsoft");

    for(std::string name : brand_names){
        brands[name] = name;
    }

    typedef std::map<std::string, std::string>::const_iterator Iter;
    for(Iter p = brands.begin(); p != brands.end(); ++p){
        std::cout<<p->first<<" : "<<p->second<<std::endl;
    }


    return s;
}

void Config::save(std::string path) {
    std::ofstream fh;
    fh.open(path, std::ofstream::out | std::ofstream::trunc);
    fh << "stuff" << std::endl;
    fh.flush();
    fh.close();
}
