#include "Game.hpp"

int main()
{
    Game match(GameMode::PvE, Difficulty::Hard);
    match.run();
    return 0;
}