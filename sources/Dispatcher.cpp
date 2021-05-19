#include "Dispatcher.hpp"
#include <typeinfo>
#include <stdexcept>      
namespace pandemic{
    //Dispatcher constuctor 
    Dispatcher::Dispatcher(const Board& board, const City& CityId):Player(board, CityId){

    }
    
    string Dispatcher::role(){
        string name = "Dispatcher";
        return name;
    }

	Player& Dispatcher::fly_direct(const City& CityId){// done :
         if (CityId == CurrCity) {
            throw invalid_argument{"Error. can't fly to the same city."};
        }
        if (is_station(CurrCity)) {
            CurrCity = CityId;
        } else {
            Player::fly_direct(CityId);
        }
        return *this;
    }
}   