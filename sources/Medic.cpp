#include "Medic.hpp"
#include "string"
#include <typeinfo>

using namespace std;


namespace pandemic
{
    Medic::Medic(const Board &board, const City& CityId): Player(board, CityId){

        
    }

    string Medic::role() {
        string name = typeid(Medic).name();
        return name;
    }

    Medic& Medic::treat(const City& city) {
		if (city != CurrCity) {
			throw invalid_argument{ "can't treat a city without being in it." };
		}
		
		//if has sickness cubes
		if (0 < Board::City_Cubes[city]) {
			Board::City_Cubes[city] = 0;
		}
		else {
			throw invalid_argument{ "Error. can't treat a healthy city." };
		}
		return *this;
    }
}