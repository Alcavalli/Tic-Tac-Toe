#pragma once

#include "Grid.hpp"
#include <random>

class AI
{
private:
    Difficulty difficulty;
    std::mt19937 rng;               //* Generatore numero casuale
    int minimax(Grid table, bool is_maximizing, int depth = 0);        //* is_maximizing serve per capire se deve fare la mossa migliore l'utente o l'AI
    std::pair<int, int> randomMove(const Grid& table);
    std::pair<int, int> getBestMove(const Grid& table);

public:
    AI(Difficulty diff);
    std::pair<int, int> makeMove(const Grid& table);
};