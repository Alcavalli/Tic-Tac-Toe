#include "Game.hpp"

int main()
{
    Game match(GameMode::PvE, Difficulty::Medium);
    match.run();
    return 0;
}