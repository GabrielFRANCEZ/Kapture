#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "Scout.h"
#include <iostream>

int main()
{
     sf::RenderWindow window(sf::VideoMode(25*32,8*32), "Kapture!", sf::Style::Close);

    kpt::TileMap map (25,8);
    kpt::Scout scou (0,0, map);
    sf::RectangleShape pointerShadow(sf::Vector2f(32,32));
    pointerShadow.setFillColor(sf::Color(255, 255, 255, 50));

    map.load("mapTest.txt", "./sprites/Field-Spritesheet.png", sf::Vector2u(32, 32));

    // on fait tourner la boucle principale
    while (window.isOpen())
    {
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            int line = 0;
            int col = 0;
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseMoved:
                    line = event.mouseMove.y / 32;
                    col = event.mouseMove.x / 32;
                    pointerShadow.setPosition(col*32, line*32);
                    break;
                case sf::Event::MouseButtonPressed:
                    // mouvement de personnage
                    line = event.mouseButton.y / 32;
                    col = event.mouseButton.x / 32;
                    scou.move(col, line);
                    break;
                default:
                    break;
            }


        }

        // on dessine le niveau
        window.clear();
        window.draw(map);
        window.draw(pointerShadow);
        window.draw(scou);
        window.display();
    }
    // for (unsigned int ligne = 0; ligne < map.getNbLines(); ligne++)
    // {
    //     for (unsigned int colonne = 0; colonne < map.getNbCols(); colonne++)
    //     {
    //         std::cout << map(colonne, ligne);
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}
