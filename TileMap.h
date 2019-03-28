#ifndef TILEMAP_H__
#define TILEMAP_H__

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "TypeField.h"

namespace kpt {
    class TileMap : public sf::Drawable, public sf::Transformable
    {
    private:
        unsigned int _nbCols;
        unsigned int _nbLines;
        std::vector<TypeField> _cases;
        sf::VertexArray m_vertices;
        sf::Texture m_tileset;

    public:
        /*** Constructeur ***/
        TileMap(unsigned int nbCols, unsigned int nbLines);

        unsigned int getNbCols() const;
        unsigned int getNbLines() const;

        /*** Opérateurs ***/
        kpt::TypeField & operator () (unsigned int column, unsigned int line);
        const kpt::TypeField & operator () (unsigned int column, unsigned int line) const;
        /*** Méthodes ***/
        bool loadMap(const std::string & filename);
        bool loadTexture (const std::string& tileset, sf::Vector2u tileSize);
        bool load (const std::string & filename,const std::string& tileset, sf::Vector2u tileSize);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}
#endif
