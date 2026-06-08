#pragma once

#include "Constants.hpp"
#include "Enums.hpp"
#include <array>

class Grid
{
private:
    std::array<std::array<CellStatus, Constants::ROWS>, Constants::COLS> griglia{};

public:
    Grid();
    const CellStatus& const getCell() const;
    void setCell(const CellStatus& nuovo_stato);
};