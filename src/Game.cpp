#include "Game.hpp"

Game::Game(GameMode mode, Difficulty diff, sf::RenderWindow& window) : mode(mode), difficulty(diff), window(sf::VideoMode({Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT}), "Tic-Tac-Toe") {}

void Game::run()
{
    while (window.isOpen())
    {
        // 1. Input
        processInput();

        // 2. Update
        update();

        // 3. Renderer
        render();
    }
}

void Game::processInput()
{

}

void Game::update()
{

}

void Game::render()
{

}

void Game::reset()
{
    stato_gioco = GameStatus::InProgress;
    turno_corrente = CellStatus::Player1;
    table = Grid();
}