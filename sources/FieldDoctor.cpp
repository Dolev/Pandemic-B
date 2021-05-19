#include "FieldDoctor.hpp"
#include "Player.hpp"
#include "string"
#include <typeinfo>
using namespace std;
using namespace pandemic;

namespace pandemic{

    FieldDoctor::FieldDoctor(const Board& board, const City& CityId):Player(board, CityId){}

    string FieldDoctor::role(){
       string name = "FieldDoctor";
       return name;
    }
   
	Player& FieldDoctor::treat(const City &city){
        if(is_can_drive(CurrCity)){
            int min_1=Board::City_Cubes[CurrCity];
        --min_1;
        Board::City_Cubes[CurrCity]=min_1;
        if(min_1<0){// if number of Cure is negative
            throw "This City has negative number of Cure Cubes. ";
        }
            return *this;
        }
            throw "This City isn't neighbor City. ";
    }

}  