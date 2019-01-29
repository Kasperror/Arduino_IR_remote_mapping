#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>

class file_management
{
    public:
        file_management(){};
        ~file_management(){};
        //reads data from codes.txt file and pushes it into vector
        std::vector<std::string> read_data();
        //adds buttons with their names and codes to remote_map.txt
        void connect_button_to_code( std::vector<std::string> button_names, std::vector<std::string> IR_codes );

    private:
        std::string comment_part1 = "/* Include this file and create constexpr Remote object before setup method\n";
        std::string comment_part2 = "(line to copy: constexpr Remote remote;) after that you can call your mapped buttons\n" ;
        std::string comment_part3 = "by \"remote.b_yourButtonName()\" this method returns a const unsigned long variable - button IR code\n";
        std::string comment_part4 = "so you can use it in switch statement for example: case b_power: .... case b_1: .... */ \n\n";

};




#endif // FILE_MANAGEMENT_H

