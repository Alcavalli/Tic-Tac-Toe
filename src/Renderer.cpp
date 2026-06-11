#include "Renderer.hpp"
#include <string>
#include <stdexcept>

Renderer::Renderer()
{
    //* Caricamento del font
    if (!font.openFromFile("assets/font.ttf"))
        throw std::runtime_error("ERROR: font not found in assets/font.ttf");

    //* Creazione dello sfondo
    background.setSize({static_cast<float>(Constants::WINDOW_WIDTH), static_cast<float>(Constants::WINDOW_HEIGHT)});
    background.setFillColor(sf::Color(206, 206, 126));
    background.setPosition({0.f, 0.f});

    //* Creazione dei bottoni
    btn_pvp.emplace(sf::Vector2f{Constants::BUTTON_WIDTH, Constants::BUTTONS_HEIGHT}, sf::Vector2f{static_cast<float>(Constants::WINDOW_WIDTH) / 2.f, Constants::SEMI_DIS_BUTTONS * 2.f + Constants::BUTTONS_HEIGHT / 2.f}, "PvP", font);
    btn_easy.emplace(sf::Vector2f{Constants::BUTTON_WIDTH, Constants::BUTTONS_HEIGHT}, sf::Vector2f{static_cast<float>(Constants::WINDOW_WIDTH) / 2.f, static_cast<float>(Constants::WINDOW_HEIGHT) / 2.f - Constants::SEMI_DIS_BUTTONS - Constants::BUTTONS_HEIGHT / 2.f}, "AI Easy", font);
    btn_mid.emplace(sf::Vector2f{Constants::BUTTON_WIDTH, Constants::BUTTONS_HEIGHT}, sf::Vector2f{static_cast<float>(Constants::WINDOW_WIDTH) / 2.f, static_cast<float>(Constants::WINDOW_HEIGHT) / 2.f + Constants::SEMI_DIS_BUTTONS + Constants::BUTTONS_HEIGHT / 2.f}, "AI Medium", font);
    btn_hard.emplace(sf::Vector2f{Constants::BUTTON_WIDTH, Constants::BUTTONS_HEIGHT}, sf::Vector2f{static_cast<float>(Constants::WINDOW_WIDTH) / 2.f, static_cast<float>(Constants::WINDOW_HEIGHT) - Constants::SEMI_DIS_BUTTONS * 2.f - Constants::BUTTONS_HEIGHT / 2.f}, "AI Hard", font);
    btn_first.emplace(sf::Vector2f{Constants::BUTTON_WIDTH, Constants::BUTTONS_HEIGHT}, sf::Vector2f{static_cast<float>(Constants::WINDOW_WIDTH) / 2.f, static_cast<float>(Constants::WINDOW_HEIGHT) / 2.f - Constants::SEMI_DIS_BUTTONS - Constants::BUTTONS_HEIGHT / 2.f}, "You start", font);
    btn_second.emplace(sf::Vector2f{Constants::BUTTON_WIDTH, Constants::BUTTONS_HEIGHT}, sf::Vector2f{static_cast<float>(Constants::WINDOW_WIDTH) / 2.f, static_cast<float>(Constants::WINDOW_HEIGHT) / 2.f + Constants::SEMI_DIS_BUTTONS + Constants::BUTTONS_HEIGHT / 2.f}, "AI starts", font);
    btn_back.emplace(sf::Vector2f{100.f, 60.f}, sf::Vector2f{static_cast<float>(Constants::GRID_OFFSET_X) / 2.f, static_cast<float>(Constants::GRID_OFFSET_Y) / 2.f}, "BACK", font);

    //* Creazione delle linee della griglia
    v_line1.setSize({static_cast<float>(Constants::LINES_WIDTH), static_cast<float>(Constants::LINES_LENGTH)});
    v_line2.setSize({static_cast<float>(Constants::LINES_WIDTH), static_cast<float>(Constants::LINES_LENGTH)});
    h_line1.setSize({static_cast<float>(Constants::LINES_LENGTH), static_cast<float>(Constants::LINES_WIDTH)});
    h_line2.setSize({static_cast<float>(Constants::LINES_LENGTH), static_cast<float>(Constants::LINES_WIDTH)});
    v_line1.setFillColor(sf::Color(3, 3, 48));
    v_line2.setFillColor(sf::Color(3, 3, 48));
    h_line1.setFillColor(sf::Color(3, 3, 48));
    h_line2.setFillColor(sf::Color(3, 3, 48));
    v_line1.setPosition({static_cast<float>(Constants::CELL_SIZE) + Constants::GRID_OFFSET_X, Constants::GRID_OFFSET_Y});
    v_line2.setPosition({static_cast<float>(Constants::CELL_SIZE) * 2.f + Constants::LINES_WIDTH + Constants::GRID_OFFSET_X, Constants::GRID_OFFSET_Y});
    h_line1.setPosition({Constants::GRID_OFFSET_X, static_cast<float>(Constants::CELL_SIZE) + Constants::GRID_OFFSET_Y});
    h_line2.setPosition({Constants::GRID_OFFSET_X, static_cast<float>(Constants::CELL_SIZE) * 2.f + Constants::LINES_WIDTH + Constants::GRID_OFFSET_Y});

    //* Creazione dei testi (invarianti)
    text_gameOver.emplace(font);           //* Si usa .emplace
    text_gameOver->setString("Game Over"); //! Occhio alle frecce e non punti
    text_gameOver->setCharacterSize(80);
    text_gameOver->setFillColor(sf::Color(153, 0, 0));
    sf::FloatRect bounds_gameOver{text_gameOver->getLocalBounds()};
    text_gameOver->setOrigin({bounds_gameOver.position.x + bounds_gameOver.size.x / 2.f, bounds_gameOver.position.y + bounds_gameOver.size.y / 2.f}); //! I bounds hanno ora come metodi .position.x/y e .size.x/y, e setOrigin accetta un sf::Vector2f
    text_gameOver->setPosition({Constants::WINDOW_WIDTH / 2.f, Constants::WINDOW_HEIGHT / 2.f});
    //! Occhio alle graffe, in SFML 3 accetta un sf::Vector2f, non 2 float (come per setOrigin)

    text_restart.emplace(font);
    text_restart->setString("Press any key to restart...");
    text_restart->setCharacterSize(40);
    text_restart->setFillColor(sf::Color(230, 255, 255));
    sf::FloatRect bounds_restart{text_restart->getLocalBounds()};
    text_restart->setOrigin({bounds_restart.position.x + bounds_restart.size.x / 2.f, bounds_restart.position.y + bounds_restart.size.y / 2.f});
    text_restart->setPosition({Constants::WINDOW_WIDTH / 2.f, Constants::WINDOW_HEIGHT / 2.f + 80.f});

    symbol_X.emplace(font);
    symbol_O.emplace(font);
    symbol_X->setString("X");
    symbol_O->setString("O");
    symbol_X->setCharacterSize(Constants::CELL_SIZE - 40);
    symbol_O->setCharacterSize(Constants::CELL_SIZE - 40);
    symbol_X->setFillColor(sf::Color::Red);
    symbol_O->setFillColor(sf::Color::Cyan);
    sf::FloatRect bounds_symbol_X{symbol_X->getLocalBounds()};
    symbol_X->setOrigin({bounds_symbol_X.position.x + bounds_symbol_X.size.x / 2.f, bounds_symbol_X.position.y + bounds_symbol_X.size.y / 2.f});
    sf::FloatRect bounds_symbol_O{symbol_O->getLocalBounds()};
    symbol_O->setOrigin({bounds_symbol_O.position.x + bounds_symbol_O.size.x / 2.f, bounds_symbol_O.position.y + bounds_symbol_O.size.y / 2.f});
}

sf::Vector2f Renderer::toPixel(const sf::Vector2i &cell) const
{
    return sf::Vector2f(static_cast<float>(cell.x) * Constants::CELL_SIZE + Constants::GRID_OFFSET_X, static_cast<float>(cell.y) * Constants::CELL_SIZE + Constants::GRID_OFFSET_Y);
}

void Renderer::render(sf::RenderWindow &window, const Grid &table, GameStatus stato_gioco, CellStatus turno_corrente)
{
    // 1. Pulire la finestra
    window.clear();

    // 2. Disegnare gli elementi
    window.draw(background);

    switch (stato_gioco)
    {
    case GameStatus::Menu:
        btn_pvp->draw(window);
        btn_easy->draw(window);
        btn_mid->draw(window);
        btn_hard->draw(window);
        break;
    case GameStatus::OrderSelection:
        btn_first->draw(window);
        btn_second->draw(window);
        btn_back->draw(window);
        break;
    case GameStatus::InProgress:
        window.draw(v_line1);
        window.draw(v_line2);
        window.draw(h_line1);
        window.draw(h_line2);
        btn_back->draw(window);

        for (int i{}; i < Constants::ROWS; ++i)
            for (int j{}; j < Constants::COLS; ++j)
            {
                if (table.getCell(i, j) == CellStatus::Empty)
                    continue;

                sf::Text *symbol = (table.getCell(i, j) == CellStatus::Player1) ? &(*symbol_X) : &(*symbol_O);
                symbol->setPosition({static_cast<float>(Constants::CELL_SIZE) * j + static_cast<float>(Constants::CELL_SIZE) / 2 + Constants::GRID_OFFSET_X, static_cast<float>(Constants::CELL_SIZE) * i + static_cast<float>(Constants::CELL_SIZE) / 2 + Constants::GRID_OFFSET_Y});
                window.draw(*symbol);
            }
            break;
    case GameStatus::Player1Win:
    case GameStatus::Player2Win:
    case GameStatus::Draw:
        window.draw(*text_gameOver); //! Siccome sono stati fatti con optional serve dereferenziare
        if (blink.getElapsedTime().asMilliseconds() >= 500)
        {
            text_status = !text_status;
            blink.restart();
        }
        if (text_status)
            window.draw(*text_restart);
        break;
    }

    // 3. Mostrare il frame
    window.display();
}

const Button* Renderer::getButton(ButtonTypes btn) const
{
    switch (btn)
    {
    case ButtonTypes::PvP:
        return &(*btn_pvp);
        break;
    case ButtonTypes::Easy:
        return &(*btn_easy);
        break;
    case ButtonTypes::Mid:
        return &(*btn_mid);
        break;
    case ButtonTypes::Hard:
        return &(*btn_hard);
        break;
    case ButtonTypes::First:
        return &(*btn_first);
        break;
    case ButtonTypes::Second:
        return &(*btn_second);
        break;
    case ButtonTypes::Back:
        return &(*btn_back);
        break;
    }
    return nullptr;
}