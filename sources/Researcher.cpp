#include "Researcher.hpp"


namespace pandemic{
    /*void ()
    */
    Researcher:: Researcher(const Board& board, const City& CityId):Player(board, CityId){}

    string Researcher::role(){
        string name = "Researcher";
        return name;
    }

    Player& Researcher::discover_cure(const Color& color){
		
			if (is_player_have_five_same(color)){
				dropColoredCards(color, 5);
				MyBoard.set_cure(color);
				return *this;
			}
			else{
				throw "You dont have 5 color cards. ";
			}
		
    }
}