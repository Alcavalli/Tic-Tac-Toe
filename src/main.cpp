#include "Game.hpp"

int main()
{
    Game match(GameMode::PvE, Difficulty::Easy);
    match.run();
    return 0;
}