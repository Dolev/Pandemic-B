#include "GeneSplicer.hpp"
#include "string"
#include <typeinfo>
using namespace std;

namespace pandemic{
    /*void ()
    */
    GeneSplicer:: GeneSplicer(const Board& board, const City& CityId):Player(board, CityId){}

    string GeneSplicer::role(){
        string name = "GeneSplicer";
       return name;
    }
    Player& GeneSplicer::discover_cure(const Color& color){
		if (is_station(CurrCity)){
			if (Cards.size() >= 5){
				dropCards(color, 5);
				MyBoard.set_cure(color);
				return *this;
			}
			throw "You dont have 5 color cards. ";
		}
		throw " (discover_cure) This City isnt in Research Station. ";
    }
}