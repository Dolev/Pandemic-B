#pragma once
#include "Player.hpp"

namespace pandemic{
    class GeneSplicer: public Player{
        public:
        string role();
        GeneSplicer(const Board& board, const City& CityId);
        Player& discover_cure(const Color& color);
    };
}