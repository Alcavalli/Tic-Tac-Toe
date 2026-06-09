#include "Renderer.hpp"
#include <string>
#include <stdexcept>

Renderer::Renderer()
{

}

sf::Vector2f Renderer::toPixel(const sf::Vector2i& cell) const
{
    return sf::Vector2f(static_cast<float>(cell.x) * Constants::CELL_SIZE, static_cast<float>(cell.y) * Constants::CELL_SIZE);
}

void Renderer::render(sf::RenderWindow& window, const Grid& table, GameStatus stato_gioco, CellStatus turno_corrente)
{
    // 1. Pulire la finestra
    window.clear();

    // 2. Disegnare gli elementi


    // 3. Mostrare il frame
    window.display();
}