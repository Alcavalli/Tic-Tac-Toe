#pragma once

#include "Grid.hpp"             //* Constants.hpp e Enums.hpp già inclusi con Grid.hpp
#include "Renderer.hpp"

class Game
{
private:
    GameStatus stato_gioco{GameStatus::InProgress};
    CellStatus turno_corrente{CellStatus::Player1};
    GameMode mode{GameMode::PvP};           //! default in caso di fallback, va nel constructor
    sf::RenderWindow window;
    Renderer renderer;
    // TODO: aggiungere un oggetto AI per la modalità di gioco
    Difficulty difficulty{Difficulty::Easy};        //! default in caso di fallback, va nel constructor
    Grid table;
    unsigned int punteggio_1{}, punteggio_2{};

public:
    Game(GameMode mode, Difficulty diff);
    void run();
    void processInput();
    void update(int row, int col);
    void render();
    void reset();
};