#pragma once
#include "Player.hpp"

namespace pandemic{
    class Medic : public Player{
        public:
        string role();
        Medic(const Board& board, const City& CityId);
        Medic& treat(const City& city);// decrease by one mum of cubes/ should return warnning when mum of cubes already 0
    };
}