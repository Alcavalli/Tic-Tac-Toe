#include "Game.hpp"

Game::Game(GameMode mode, Difficulty diff) : mode(mode), difficulty(diff), window(sf::VideoMode({Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT}), "Tic-Tac-Toe") {}

void Game::run()
{
    while (window.isOpen())
    {
        // 1. Input + Update integrato
        processInput();

        // 2. Renderer
        render();
    }
}

void Game::processInput()
{
    while (const std::optional<sf::Event> event{window.pollEvent()})
    {
        if (event->is<sf::Event::Closed>())
            window.close();

        if (const auto *mouseClick{event->getIf<sf::Event::MouseButtonPressed>()})
            if (mouseClick->button == sf::Mouse::Button::Left)
                update(mouseClick->position.y / Constants::CELL_SIZE, mouseClick->position.x / Constants::CELL_SIZE);       //! Ricorda: riga e colonna, quindi y e x (non x e y)
    }
}

void Game::update(int row, int col)
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