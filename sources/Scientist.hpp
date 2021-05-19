#pragma once
#include "Player.hpp"

namespace pandemic{

class Scientist: public Player{
    private:
        int Num_of_cards;
    public:
        Scientist(const Board& board, const City& CityId, const int Num);
        string role();
        Scientist& discover_cure(const Color &color);
    };
} 