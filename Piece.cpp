#include "Piece.h"
Piece::Piece(): x_postion {0}, y_postion {0}, m_name {"pawn"}, m_color {"white"}, m_images_path {"images"} {}


Piece::Piece(
    int x = 0, 
    int y = 0, 
    std::string name = "pawn", 
    std::string color = "white",
    std::string images_path = "images"
    ):  x_postion {x}, y_postion {y}, 
        m_name {name}, m_color {color},
        m_images_path {images_path}
{

}

void Piece::draw_piece(sf::RenderWindow& window)
{
    sf::Texture pieceTexture;
    if (!pieceTexture.loadFromFile(map_name()))
    {
        //add error handling
    }
    sf::Sprite pieceSprite(pieceTexture);
    pieceSprite.setPosition(sf::Vector2f(x_postion, y_postion));
    window.draw(pieceSprite);
}

std::string Piece::map_name()
{
    if (m_color == "white") {
        return m_images_path + "/w_" + m_name + ".png";
    } else {
        return m_images_path + "/b_" + m_name + ".png";
    }
    return "";
}

void Piece::follow_mouse(sf::RenderWindow& window)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        x_postion = mousePos.x;
        y_postion = mousePos.y;
    }
}

void Piece::set_position(int x, int y)
{
    x_postion = x;
    y_postion = y;
}

int Piece::get_x_position() const
{
    return x_postion;
}

int Piece::get_y_position() const
{
    return y_postion;
}