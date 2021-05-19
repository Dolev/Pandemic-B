#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

#include <iostream>
#include <fstream>
#include <algorithm>    // std::none_of
using namespace std;
using namespace pandemic;

const static int MAX = 48;

namespace pandemic{
	map<int, int> Board::City_Cubes;
	map<Color, bool> Board::cures;
	map<City, bool> Board::stations;
	map<int, string> Board::City_names;
	map<int, string> Board::City_colors;

    Board::Board(){
        for(int i = 0; i < MAX; i++) {// 48 cities
            string name_city = City_Names[i];
            Board::City_Cubes[i] = 0;
            Board::City_names[i] = name_city;
            City city = index_for_city(i);
            Board::stations.insert({city, false});
        }
        for(int i = 0; i < 4; i++) {// 4 players
            //Color color = color_by_index(i);
			Color color = static_cast<Color>(i);
            Board::cures.insert({color, false});
        }
    }

    int& Board::operator[](const City& CityId){
        if(City_Cubes.find(CityId)==City_Cubes.end()){
            throw "This City isnt in options";
        }
        return City_Cubes.at(CityId);
    } 

    ostream& operator<<(ostream& Output, const Board& board){
        return Output;
    }

	bool comp(const pair<int, int>& p){
		return p.second != 0;
	}

    bool Board::is_clean() {
		return none_of(City_Cubes.begin(), City_Cubes.end(), comp);
    }

    void Board::remove_cures(){               //Done
        std::map<int, int>::iterator itr;
        for(itr = City_Cubes.begin(); itr != City_Cubes.end(); ++itr){
        itr->second=0;
        }
    }
  
    void Board::remove_stations(){          //Looks Done
          stations.clear(); 
    }
}  