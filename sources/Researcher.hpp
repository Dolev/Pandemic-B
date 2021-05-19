#pragma once
#include "Player.hpp"

namespace pandemic{
    class Researcher : public Player{
        public:
        string role();
        Researcher(const Board& board, const City& CityId);
        Player& discover_cure(const Color& color);
    };
}