#pragma once

#include <SFML/Graphics.hpp>
#include "Grid.hpp"             //! Constants e Enums sono già inclusi, sarebbero ridondanti

class Renderer
{
private:
    sf::Font font;
    sf::Text text_gameOver, text_turno, text_punteggio, text_restart;
    sf::Clock blink;
    bool textStatus{};
    sf::Vector2f toPixel(const sf::Vector2i& cell) const;

public:
    Renderer();
    void render(sf::RenderWindow& window, const Grid& table, GameStatus stato_gioco, CellStatus turno_corrente);
};