#include "../hpp/Player.h"
#include "../hpp/Piece.h"
#include "../hpp/Board.h"
#include <iostream>
#include <algorithm>

#define ASCII_LETTER_TO_INT(LETTER) (LETTER - 0x40)
#define ASCII_NUMBER_TO_INT(NUMBER) (NUMBER - 0x30)
#define INT_TO_ASCII_LETTER(INT)    (INT + 0x40)
#define INT_TO_ASCII_NUMBER(INT)    (INT + 0x30)
#define ASCII_CHAR_WHITESPACE 0x20

Player::Player(Color color)
{
    this->color = color;
}

Color Player::getColor() const
{
    return this->color;
}

void Player::nextMove(const VectorPiece& pieces, const PtrBoard& board)
{
    std::string input;
    
    do
    {
        std::string name = (this->color == Color::White) ? "White to move: " : "Black to move: ";
        std::cout << name;
        std::getline(std::cin, input);
        std::transform(input.begin(), input.end(), input.begin(), ::toupper);

    } while (!isInputValid(input, pieces, board));
}

Position Player::getMostRecentMove() const
{
    return this->move;
}

bool Player::isInputValid(const std::string& input, const VectorPiece& pieces, const PtrBoard& board)
{
    const size_t length = 5; // i.e. "E2 E4"

    if (input.length() != length)
    {
        std::cout << "Input must be 5 characters long. Try again." << std::endl;
        //input = this->nextMove(pieces, board);
        return false;
    }

    const int col_1 = ASCII_LETTER_TO_INT(input[0]);
    const int row_1 = ASCII_NUMBER_TO_INT(input[1]);
    const int space = input[2];
    const int col_2 = ASCII_LETTER_TO_INT(input[3]);
    const int row_2 = ASCII_NUMBER_TO_INT(input[4]);

    Position source(col_1, row_1);
    Position destination(col_2, row_2);

    if (!source.isWithinBounds())
    {
        std::cout << "The piece coordinates [" << input[0] << input[1] << "] are out of bounds. Try again." << std::endl;
        return false;
    }
    else if (space != ASCII_CHAR_WHITESPACE)
    {
        std::cout << "The coordinates [" << input << "] is missing a space in the middle. Try again." << std::endl;
        return false;
    }
    else if (!destination.isWithinBounds())
    {
        std::cout << "The destination coordinates [" << input[3] << input[4] << "] are out of bounds. Try again." << std::endl;
        return false;
    }

    if (!this->findPiece(pieces, source))
    {
        // Piece not found
        std::cout << "The coordinates [" << input[0] << input[1] << "] don't match any piece. Try again." << std::endl;
        return false;
    }
    else
    {
        // Piece found
        PtrPiece ally = board->getPiece(source);
        if (this->color != ally->getColor())
        {
            std::cout << "The piece selected [" << input[0] << input[1] << "] is an enemy piece. Try again." << std::endl;
            return false;
        }
        else
        {
            //Ensure that the piece can move to destination
            if (ally->isValidMove(destination))
            {
                this->move = destination;
            }
            else
            {
                std::cout << "The destination [" << input[3] << input[4] << "] is invalid. Try again." << std::endl;
                return false;
            }
        }
    }

    this->source = source;
    this->destination = destination;

    return true;
}

Position Player::getSource() const
{
    return this->source;
}

Position Player::getDestination() const
{
    return this->destination;
}

bool Player::findPiece(const VectorPiece& pieces, const Position& position)
{
    bool found = false;

    for (const auto& piece : pieces)
    {
        if (piece->getPosition() == position)
        {
            found = true;
            break;
        }
    }

    return found;
}
