#pragma once
#include "Player.hpp"
namespace pandemic{
    class Virologist : public Player{
    public:
        string role();
        Virologist(const Board& board, const City& CityId);
        Virologist& treat(const City CityId) ;
    };
}