#pragma once
#include "Player.hpp"

namespace pandemic{
    class OperationsExpert : public Player{
        public:
        string role();
        Player& build();
        OperationsExpert(const Board& board, const City& CityId);
    };
}