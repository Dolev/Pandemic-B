
#pragma once
#include <string>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "vector"
#include <typeinfo>
#include <set>
#include <stdexcept>    
//const static int max = 48;
//const static int max_player=5;
using namespace std;

namespace pandemic{

    class Player{

        protected:
        //PLAYER BOARD
        Board MyBoard;
        set<int> Cards;
        City CurrCity;
        
    
        public:
        Player(const Board& board, const City& CityId);   
		virtual ~Player() {}
                            // set<City> cand_rive;
        bool is_can_drive(const City& city) const {                         //map<City, set<City>> City_Pass
             set<City> TEMP;
             TEMP=Cities_Map[CurrCity];
			 set<City>::iterator it = TEMP.begin();
			 while (it != TEMP.end()){
				 if (city == *it)
					 return true;
				 it++;
			 }
			 return false;
        }     

        bool is_station(const City& city) const {                            
            return Board::stations[city];
        }
        
        bool is_player_have_five_same(const Color &color) const{  
			return is_player_have_n_same(color, 5);
        }

		bool is_player_have_n_same(const Color &color, int n) const{
			set<int>::iterator it = Cards.begin();
			int counter = 0;
			while (it != Cards.end()){
				if (color == City_Colors[*it])
					counter++;
				it++;
			}
			return counter >= n;
		}

        bool is_In_Map() const {
             return Board::City_Cubes.find(CurrCity) != Board::City_Cubes.end() ;
        }

        City rand_City() const {
            City new_City = City(rand()%48);
            return new_City;
        }

        void decrease_city_cubes() {
            this->MyBoard.less_city_cubes(this->CurrCity);
        }

        void remove_all_city_cubes() {
                int number_of_city_cubes = this->MyBoard.get_City_Cubes(this->CurrCity);
                while(number_of_city_cubes > 0) {
                    decrease_city_cubes();
                    number_of_city_cubes--;
                }
            }
        // Getters && Setters
        City Get_Curr_City() const { return this->CurrCity; }
        void Set_Curr_City(const City city) { this->CurrCity = city; };

         // change board- true of if the given city has a research station
        bool has_research_station(const City city) { return is_station(city); }
        
        void set_research_station(const City city) { if(!is_station(city)){
             Board::stations.find(city)->second = true;}
            else{
             throw "This city already Station.";
            }
        }

        bool is_has_card(const City& city) {return Cards.find(city) != Cards.end();}
		void dropColoredCards(const Color &color, int n);

        virtual Player& drive(const City& CityId) ;
        virtual Player& fly_direct(const City& CityId) ;
        virtual Player& fly_charter(const City& CityId) ;
        virtual Player& fly_shuttle(const City& CityId) ;
        virtual Player& build(); 
		void dropCards(const Color &color, int n);
        virtual Player& discover_cure(const Color& color);// return exeption at perant
        virtual Player& treat(const City &city);
        
        Player& take_card (const City& CityId);
        Player& remove_card (const City& CityId);
        Player& remove_cards ();
        virtual std::string role () = 0;
    };
}