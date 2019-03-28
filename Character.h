#ifndef CHARACTER_H__
#define CHARACTER_H__


#include <SFML/Graphics.hpp>


namespace kpt {
    class TileMap;

    class Character : public sf::Sprite
    {
    private:
        unsigned int _col;
        unsigned int _line;
        unsigned int _maxMove;
        unsigned int _remainingMove;
        const TileMap * _map;
        sf::Texture _tex;

    public:
        /*** Constructeur ***/
        Character(unsigned int col, unsigned int line, unsigned int maxMove, const TileMap & map, const std::string & textureFilename);
        /*** Destructeur ***/
        virtual ~Character () = default;
        /*** Opérateurs ***/

        /*** Méthodes ***/
        void move (unsigned int col, unsigned int line);

    };
}
#endif
