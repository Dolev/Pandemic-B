//auther Dolev Hindy

#include "OperationsExpert.hpp"
#include <typeinfo>
#include <typeindex>
using namespace std;

namespace pandemic{
    /*void ()
    */
    OperationsExpert:: OperationsExpert(const Board& board, const City& CityId):Player(board, CityId){}

    string OperationsExpert::role(){
        string name = "OperationsExpert";
        return name;
    }
    
    Player& OperationsExpert::build(){// Can do it allways
        Board::stations.find(CurrCity)->second = true;
        return *this;
    }
}