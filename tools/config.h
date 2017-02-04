#ifndef CONFIG_H
#define CONFIG_H

#include <fstream>
#include <string>
#include <map>

class Config {
public:
    // Constructor
    Config();
    // Destructor
    ~Config();

    // Populate the map with test data
    void generateMap();

    //Print the current map
    void printState();

    /*
     * File System
     */

    // Save the current map to the file
    void saveState();
    // Load the current map from the file
    void reloadState();
    // Set the path (not including the filename)
    void setPath(std::string path);
    // Set the filename
    void setFileName(std::string file_name);

    /*
     * Manipulation
     */

    // Get a value (from a key)
    std::string getValue(std::string key);
    // Set a value (key, value)
    void setValue(std::string key, std::string value);
    // Clear the current map
    void clearState();

private:
    std::map<std::string, std::string> state;
    std::string path;
    std::string file_name;
};

#endif // CONFIG_H
