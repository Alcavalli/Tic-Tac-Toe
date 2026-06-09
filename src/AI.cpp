#include "AI.hpp"
#include <vector>
#include <random>

AI::AI(Difficulty diff) : difficulty(diff) {}

int AI::minimax(Grid table, bool is_maximizing)
{
    if (table.checkWinner() == CellStatus::Player1)
        return 10;
    if (table.checkWinner() == CellStatus::Player2)
        return -10;
    if (table.isFull())
        return 0;

    if (is_maximizing)          //* Tocca all'AI
    {
        int best{-10};      //* Risultato nel caso peggiore
        for (int i{}; i < Constants::ROWS; ++i)
            for (int j{}; j < Constants::COLS; ++j)
                if (table.getCell(i, j) == CellStatus::Empty)
                {
                    table.setCell(i, j, CellStatus::Player2);   //* Definiamo l'AI come player 2
                    int score{minimax(table, false)};
                    table.clearCell(i, j);          //! Serve ad annullare l'ultima mossa
                    best = std::max(best, score);
                }
        return best;
    }
    else                //* Tocca al giocatore
    {
        int best{10};
        for (int i{}; i < Constants::ROWS; ++i)
            for (int j{}; j < Constants::COLS; ++j)
                if (table.getCell(i, j) == CellStatus::Empty)
                {
                    table.setCell(i, j, CellStatus::Player1);   //* Definiamo l'utente come player 1
                    int score{minimax(table, true)};
                    table.clearCell(i, j);          //! Serve ad annullare l'ultima mossa
                    best = std::min(best, score);
                }
        return best;
    }
}

std::pair<int, int> AI::randomMove(const Grid &table)
{
}

std::pair<int, int> AI::makeMove(const Grid &table)
{
    int best{-11};          //* Peggio del risultato peggiore possibile
    std::pair<int, int> best_move{-1, -1};

    for (int i{}; i < Constants::ROWS; ++i)
        for (int j{}; j < Constants::COLS; ++j)
            if (table.getCell(i, j) == CellStatus::Empty)
            {
                Grid table_copy{table};
                table_copy.setCell(i, j, CellStatus::Player2);      //! Serve una copia della griglia per poter inserire il segno
                int score{minimax(table_copy, false)};
                if (score > best)
                {
                    best = score;
                    best_move = {i ,j};
                }
            }
    return best_move;
}