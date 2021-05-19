#include <string>
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{
    Player::Player(const Board& board, const City& CityId) : MyBoard(board), CurrCity(CityId) {
            
    }

    Player& Player::drive(const City& CityId)
    {
        if(is_can_drive(CityId)){
            CurrCity=CityId;
            return *this;
        }
            throw "This City isn't in options. ";
    }

	Player& Player::fly_direct(const City& CityId){
		if(is_station(CurrCity)){
            Player::CurrCity=rand_City();   
        }
        if (CityId == CurrCity) {
            throw invalid_argument{"Already in this city."};
        }
        if (is_has_card(CityId)) {
            remove_card(CityId);
            CurrCity = CityId;
        } else {
            throw invalid_argument{"Can't fly into a city without City card."};
        }
        return *this;
	}


    Player& Player::fly_charter(const City &CityId)
    {// check with friend
		if (CityId == CurrCity) {
            throw invalid_argument{" You are already in this city."};
        }
        if (is_has_card(CurrCity)) {
            remove_card(CurrCity);
            CurrCity = CityId;
        } else {
            throw invalid_argument{"Can't fly charter, you need maching card."};
        }
        return *this;
    }

    Player& Player::fly_shuttle(const City& CityId)
    {   
		if (!is_station(CurrCity)) {
			throw invalid_argument{ "Error. can't fly shuttle from a city without study station." };
		}
		//if the destination city doesn't have study station 
		if (!is_station(CityId)) {
			throw invalid_argument{ "This City isnt in Research Station." };
		}
		// Check if the current city is already in station list
       if (CityId == CurrCity) {
            throw invalid_argument{"Error. can't fly to the same city."};
        }
        
        //both has study stations
        CurrCity = CityId;
        return *this;
    }
    
    Player& Player::build()
    {   // Check if the current city is already in station list
         if (is_station(CurrCity)) {
            if (is_has_card(CurrCity)) {
                remove_card(CurrCity);
                Board::stations.at(CurrCity) = true;
            } else {
                throw invalid_argument{"Error. can't build study station without matching card."};
            }
        }
        return *this;
    }

	void Player::dropColoredCards(const Color &color, int n){
		set<int>::iterator it = Cards.begin();
		while (it != Cards.end() && n > 0){
			if (color == City_Colors[*it]){
				it = Cards.erase(it);
				n--;
			}
			else
				it++;
		}
	}

	void Player::dropCards(const Color &color, int n){
		set<int>::iterator it = Cards.begin();
		while (it != Cards.end() && n > 0){
				it = Cards.erase(it);
		}
	}

    Player& Player::discover_cure(const Color &color)
    {
        if(is_station(CurrCity)){
            if(is_player_have_five_same(color)){
				dropColoredCards(color, 5);
				MyBoard.set_cure(color);
                return *this;
            }
            throw "You dont have 5 color cards. ";
        }
        throw " (discover_cure) This City isnt in Research Station. ";
    }

    Player& Player::treat(const City& city)
    {
        if (city != CurrCity) {
            throw invalid_argument{"can't treat a city without being in it."};
        }
        //if has sickness cubes
        if ( 0 < Board::City_Cubes[city] ) {
            Board::City_Cubes[city]--;
            Color temp=Blue;
            temp=City_Colors[city];
            if (MyBoard.is_has_cure(temp)) {
                Board::City_Cubes[city] = 0;                //if we discovered a cure
            }
        } else {
            throw invalid_argument{"Error. can't treat a healthy city."};
        }
        return *this;
    }

    Player& Player::take_card(const City& CityId) // Take City card (one per City)
    {
            Cards.insert(CityId);
            return *this; 
    }
    
    Player& Player::remove_card (const City& CityId){
        Cards.erase(CityId); 
        return *this;
    }

    Player& Player::remove_cards (){
        Cards.clear();
        return *this;
    }
}