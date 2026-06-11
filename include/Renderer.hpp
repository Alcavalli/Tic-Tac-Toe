#pragma once

#include <SFML/Graphics.hpp>
#include "Grid.hpp"
#include <optional>         //? Per i testi per SFML 3
#include "Button.hpp"

class Renderer
{
private:
    sf::Font font;
    std::optional<sf::Text> text_gameOver, text_restart, symbol_X, symbol_O;
    sf::RectangleShape background, v_line1, v_line2, h_line1, h_line2;
    std::optional<Button> btn_pvp, btn_easy, btn_mid, btn_hard, btn_first, btn_second, btn_back;
    sf::Clock blink;
    bool text_status{};
    sf::Vector2f toPixel(const sf::Vector2i& cell) const;

public:
    Renderer();
    void render(sf::RenderWindow& window, const Grid& table, GameStatus stato_gioco, CellStatus turno_corrente);
    const Button* getButton(ButtonTypes btn) const;
};