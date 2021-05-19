#pragma once

#include <set>
#include <map>
#include "City.hpp"
#include <string>

#include <stdio.h>
using namespace std;

namespace pandemic{
    class Board{
        //cahnge string to set of cities
        public:
            static map<int, int> City_Cubes;
            static map<Color,bool> cures;
            static map<City,bool> stations;
            static map<int, string> City_names;
            static map<int, string> City_colors;
            
            //const
            Board();
            int& operator[](const City& city);
            friend ostream& operator<<(ostream& Output, const Board& board);
            static bool is_clean() ;
        


            //add and less cubes
            void add_city_cubes(const City city) { this->City_Cubes.at(city)++; }
            void less_city_cubes(const City city) { this->City_Cubes.at(city)--; }

            bool is_has_cure(const Color color) { return this->cures.find(color)->second; }
            void set_cure(const Color color) { this->cures.find(color)->second = true; }
            void del_cure(const Color color) { this->cures.find(color)->second = false; }
            
            static void remove_cures();
            static void remove_stations();

            string get_city_name(const City city) const { return this->City_names.at(city); }
            string get_city_color(const Color color) const { return this->City_colors.at(color); }
            //return city_cubes in city
            int get_City_Cubes(const City city) const { return this->City_Cubes.at(city); }
    };
}    

