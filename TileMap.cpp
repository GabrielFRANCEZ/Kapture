#include "TileMap.h"
#include <iostream>
#include <string>
#include <fstream>


kpt::TileMap::TileMap(unsigned int nbCols, unsigned int nbLines)
{
    _nbCols = nbCols;
    _nbLines = nbLines;
    for (unsigned int i = 0; i < nbCols * nbLines; i++)
    {
        _cases.push_back(TerrainNu);
    }

}

unsigned int kpt::TileMap::getNbCols() const
{
    return _nbCols;
}
unsigned int kpt::TileMap::getNbLines() const
{
    return _nbLines;
}


kpt::TypeField & kpt::TileMap::operator()(unsigned int column, unsigned int line)
{
    return _cases[line * _nbCols + column];
}

const kpt::TypeField & kpt::TileMap::operator()(unsigned int column, unsigned int line) const
{
    return _cases[line * _nbCols + column];
}    sf::VertexArray m_vertices;
    sf::Texture m_tileset;


bool kpt::TileMap::loadMap(const std::string & filename)
{
    std::ifstream file( filename, std::ios::in);

    if(file)
    {
        for (unsigned int index = 0; index < _cases.size(); index ++)
        {
            unsigned int field;
            file >> field;
            _cases[index] = static_cast<TypeField> (field);
        }
        file.close();
    }
    else
    {
        std::cerr << "Impossible to open the file !" << std::endl;
        return false;
    }
    return true;
}

bool kpt::TileMap::loadTexture (const std::string& tileset, sf::Vector2u tileSize)
   {
       unsigned int width = _nbCols;
       unsigned int height = _nbLines;
       // on charge la texture du tileset
       if (!m_tileset.loadFromFile(tileset))
           return false;

       // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
       m_vertices.setPrimitiveType(sf::Quads);
       m_vertices.resize(width * height * 4);

       // on remplit le tableau de vertex, avec un quad par tuile
       for (unsigned int i = 0; i < width; ++i)
           for (unsigned int j = 0; j < height; ++j)
           {
               // on récupère le numéro de tuile courant
               int tileNumber = _cases[i + j * width];

               // on en déduit sa position dans la texture du tileset
               int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
               int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

               // on récupère un pointeur vers le quad à définir dans le tableau de vertex
               sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

               // on définit ses quatre coins
               quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
               quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
               quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
               quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

               // on définit ses quatre coordonnées de texture
               quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
               quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
               quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
               quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
           }

       return true;
   }

void kpt::TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
    // on applique la transformation
    states.transform *= getTransform();

    // on applique la texture du tileset
    states.texture = &m_tileset;

    // et on dessine enfin le tableau de vertex
    target.draw(m_vertices, states);
    }

bool kpt::TileMap::load (const std::string & filename,const std::string& tileset, sf::Vector2u tileSize)
{
    loadMap(filename);
    if (!loadTexture(tileset,tileSize))
        return false;
    return true;
}
