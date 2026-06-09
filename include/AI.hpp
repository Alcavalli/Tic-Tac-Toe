#pragma once

#include "Grid.hpp"

class AI
{
private:
    Difficulty difficulty;
    int minimax(Grid table, bool is_maximizing);        //* is_maximizing serve per capire se deve fare la mossa migliore l'utente o l'AI
    std::pair<int, int> randomMove(const Grid& table);

public:
    AI(Difficulty diff);
    std::pair<int, int> makeMove(const Grid& table);
};