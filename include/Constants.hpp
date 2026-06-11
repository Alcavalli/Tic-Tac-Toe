namespace Constants
{
    //* Griglia
    constexpr int ROWS = 3, COLS = 3;
    constexpr int CELL_SIZE = 150;
    constexpr int LINES_WIDTH = 20;
    constexpr int LINES_LENGTH = CELL_SIZE * ROWS + LINES_WIDTH * (ROWS - 1);

    //* Window
    constexpr int WINDOW_HEIGHT = CELL_SIZE * 5;
    constexpr int WINDOW_WIDTH = CELL_SIZE * 5;
    constexpr int GRID_OFFSET_X = (WINDOW_WIDTH - CELL_SIZE * COLS - LINES_WIDTH * (COLS - 1)) / 2;
    constexpr int GRID_OFFSET_Y = (WINDOW_HEIGHT - CELL_SIZE * ROWS - LINES_WIDTH * (ROWS - 1)) / 2;
    constexpr float BUTTONS_HEIGHT = 80.f;
    constexpr float BUTTON_WIDTH = 250.f;
    constexpr float SEMI_DIS_BUTTONS = (static_cast<float>(WINDOW_HEIGHT) - 4.f * BUTTONS_HEIGHT) / 10.f;
}