#include <SFML/Graphics.hpp>
#include <optional>
#include <string>

struct Button
{
    sf::RectangleShape shape;
    std::optional<sf::Text> button_text;
    Button(sf::Vector2f dim, sf::Vector2f pos, const std::string& label, const sf::Font& font);
    bool isClicked(sf::Vector2i pos);
    void draw(sf::RenderWindow& window);
};