#include "../hpp/Player.h"
#include <iostream>
#include <algorithm>

Player::Player(Color color)
{
    this->color = color;
}

std::string Player::nextMove()
{
    std::string input;
    std::string name = (this->color == Color::White) ? "White to move: " : "Black to move: ";
    std::cout << name;
    std::getline(std::cin, input);
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    const size_t length = 5; // i.e. "E2 E4"

    if (input.length() != length)
    {
        std::cout << "Input must be 5 characters long. Try again." << std::endl;
        input = this->nextMove();
    }

    int firstX = 0, firstY = 1;
    int whitespace = 2;
    int secondX = 3, secondY = 4;

    if (input[firstX] < 'A' || input[firstX] > 'H' ||
        input[firstY] < '1' || input[firstY] > '8' ||
        input[whitespace] != ' ' ||
        input[secondX] < 'A' || input[secondX] > 'H' ||
        input[secondY] < '1' || input[secondY] > '8')
    {
        std::cout << "The coordinates are out of bounds. Try again." << std::endl;
        input = this->nextMove();
    }

    return input;
}
