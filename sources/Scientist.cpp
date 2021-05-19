#include "Scientist.hpp"

#include "string"

using namespace std;

namespace pandemic
{
    Scientist::Scientist(const Board& board, const City& CityId, const int Num): Player(board, CityId){
        this->Num_of_cards= Num;
    }

    string Scientist::role() {
        string name = "Scientist";
        return name;
    }

    Scientist& Scientist::discover_cure(const Color& color) {
		if (is_station(CurrCity)){
			if (is_player_have_n_same(color, Num_of_cards)){
				dropColoredCards(color, Num_of_cards);
				MyBoard.set_cure(color);
				return *this;
			}
			else{
				throw "You dont have enough color cards. ";
			}
		}
		throw " (discover_cure) This City isnt in Research Station. ";
    }
}

 