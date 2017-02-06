#ifndef CONFIG_H
#define CONFIG_H

#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <vector>

#include "macro.h"
#include "baseclass.h"

class Config : public BaseClass{
public:
    Config();
    Config(std::string pathToFile);
    ~Config();

    /*!
     * \brief Populate the current map with test data
     */
    void generateMap();

    /*!
     * \brief Print the current map
     */
    void printState();

    /***************
     * File System *
     ***************/

    /*!
     * \brief Save the current state to file
     */
    void saveState();

    /*!
     * \brief Load the current map from the file
     */
    void reloadState();

    /*!
     * \brief Set the path (not including the filename)
     */
    void setPath(std::string path);

    /*!
     * \brief Set the filename
     */
    void setFileName(std::string file_name);

    /*!
     * \brief Set the complete path
     *
     * Seperated by last occurence of /
     */
    void setCompletePath(std::string complete_path);

    /****************
     * Manipulation *
     ****************/

    /*!
     * \brief Get a value (from a key)
     */
    std::string getValue(std::string key);

    /*!
     * \brief Set a value (key, value)
     */
    void setValue(std::string key, std::string value);

    /*!
     * \brief Clear the current map
     */
    void clearState();

private:
    std::map<std::string, std::string> state;
    std::string path;
    std::string file_name;
};

#endif // CONFIG_H
