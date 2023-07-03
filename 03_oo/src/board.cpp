#include "board.hpp"
#include "player.hpp"

GameStatus asGameStatus(Color color) {
    switch (color) {
    case Color::CROSS:
        return GameStatus::CROSS;
    default:
        return GameStatus::CIRCLE;
    }
}

GameStatus asGameStatus(Field field) {
    switch (field) {
    case Field::CROSS:
        return GameStatus::CROSS;
    case Field::CIRCLE:
        return GameStatus::CIRCLE;
    default:
        std::abort();
    }
}

Field asField(Color color) {
    switch (color) {
    case Color::CROSS:
        return Field::CROSS;
    default:
        return Field::CIRCLE;
    }
}

Color enemyOf(Color color) {
    switch (color) {
    case Color::CROSS:
        return Color::CIRCLE;
    default:
        return Color::CROSS;
    }
}

Board::Board() : fields(std::vector<std::vector<Field>>(3, std::vector<Field>(3, Field::EMPTY))) {}

std::optional<GameStatus> Board::whoWon() const {
     // Prüfen auf horizontalen Gewinner
    for (const auto& row : fields) {
        if (row[0] != Field::EMPTY && row[0] == row[1] && row[0] == row[2]) {
            return asGameStatus(row[0]);
        }
    }

    // Prüfen auf vertikalen Gewinner
    for (size_t col = 0; col < 3; ++col) {
        if (fields[0][col] != Field::EMPTY && fields[0][col] == fields[1][col] && fields[0][col] == fields[2][col]) {
            return asGameStatus(fields[0][col]);
        }
    }

    // Prüfen auf diagonalen Gewinner (links oben nach rechts unten)
    if (fields[0][0] != Field::EMPTY && fields[0][0] == fields[1][1] && fields[0][0] == fields[2][2]) {
        return asGameStatus(fields[0][0]);
    }

    // Prüfen auf diagonalen Gewinner (rechts oben nach links unten)
    if (fields[0][2] != Field::EMPTY && fields[0][2] == fields[1][1] && fields[0][2] == fields[2][0]) {
        return asGameStatus(fields[0][2]);
    }

    // Prüfen auf Unentschieden
    bool isFull = true;
    for (const auto& row : fields) {
        for (const auto& field : row) {
            if (field == Field::EMPTY) {
                isFull = false;
                break;
            }
        }
    }

    if (isFull) {
        return GameStatus::TIE;
    }

    // Das Spiel ist noch im Gange
    return std::nullopt;
}

std::ostream& operator<<(std::ostream& os, const Board& board) {
    for (const auto& row : board) {
        os << "| ";
        for (const auto& field : row) {
            switch (field) {
            case Field::CROSS:
                os << "X";
                break;
            case Field::CIRCLE:
                os << "O";
                break;
            case Field::EMPTY:
                os << " ";
                break;
            }
            os << " | ";
        }
        os << std::endl;
    }
    return os;
}
