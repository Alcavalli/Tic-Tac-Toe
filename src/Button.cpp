#include "Button.hpp"
#include <stdexcept>

Button::Button(sf::Vector2f dim, sf::Vector2f pos, const std::string& label, const sf::Font& font)
{
    shape.setSize(dim);
    sf::Rect shape_bounds{shape.getLocalBounds()};
    shape.setOrigin({shape_bounds.position.x + shape_bounds.size.x / 2.f, shape_bounds.position.y + shape_bounds.size.y / 2.f});
    shape.setPosition(pos);
    shape.setFillColor(sf::Color::Yellow);

    button_text.emplace(font);
    button_text->setString(label);
    button_text->setCharacterSize(50);
    button_text->setFillColor(sf::Color::Black);
    sf::Rect button_bounds{button_text->getLocalBounds()};
    button_text->setOrigin({button_bounds.position.x + button_bounds.size.x / 2.f, button_bounds.position.y + button_bounds.size.y / 2.f});
    button_text->setPosition({shape.getPosition().x, shape.getPosition().y});
}

bool Button::isClicked(sf::Vector2i pos)
{
    return shape.getGlobalBounds().contains(sf::Vector2f(pos));
}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(shape);
    window.draw(*button_text);
}