#pragma once

#include "Constants.hpp"
#include "Enums.hpp"
#include <SFML/Graphics.hpp>
#include "Grid.hpp"

class Renderer
{
private:
    sf::Font font;
    sf::Text game_over, turno, punteggio;
    sf::Clock lampeggio;
    bool visibile{};
    sf::Vector2f toPixel(const sf::Vector2i& cella) const;

public:
    Renderer();
    void render(sf::RenderWindow& window, const Grid& table);
};