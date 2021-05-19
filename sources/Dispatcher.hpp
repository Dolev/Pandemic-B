#pragma once
#include "Player.hpp"

namespace pandemic{

    class Dispatcher: public Player{
        public:
        string role();
        Dispatcher(const Board& board, const City& CityId);
		Player& fly_direct(const City& CityId);
    };
}