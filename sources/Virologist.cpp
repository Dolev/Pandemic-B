#include "Virologist.hpp"
#include <sstream>


namespace pandemic{
    Virologist::Virologist(const Board &board, const City& CityId): Player(board, CityId){
    }

    string Virologist::role() {
        string name = "Virologist";
        return name;
    }

    Virologist& Virologist::treat(const City CityId) {
        if(Board::City_Cubes[CityId]<=0){
        stringstream myCity;
        myCity<< "Can't treat the disease in: "<< CityId;
        throw invalid_argument(myCity.str());
        }
    if(CityId!=static_cast<City>(this->CurrCity)){
        this->remove_card(CityId);
        Color temp=Blue;
        temp=City_Colors[CityId];     // Cast City to Color
        if(MyBoard.is_has_cure(temp)) {
            Board::City_Cubes[CityId] = 0;
        }else {
            Board::City_Cubes[CityId] = Board::City_Cubes[CityId] - 1;
        }
    }else{
        Color temp=Blue;
        temp=City_Colors[CityId];
        if(MyBoard.is_has_cure(temp)) {
            Board::City_Cubes[CityId] = 0;
        }else {
            Board::City_Cubes[CityId] = Board::City_Cubes[CityId] - 1;
        }
    }
    return *this;
    }
    
}