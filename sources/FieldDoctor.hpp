#pragma once
#include "Player.hpp"
namespace pandemic{
    class FieldDoctor : public Player{
    public:
        string role();
        FieldDoctor(const Board& board, const City& CityId);
		Player& treat(const City &city);
    };
}