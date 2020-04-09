#include "Character.h"
#include "TileMap.h"
#include <cmath>


kpt::Character::Character(unsigned int col, unsigned int line, unsigned int maxMove, const TileMap & map, const std::string & textureFilename)
: sf::Sprite()
{
    _col = col;
    _line = line;
    _maxMove = maxMove;
    _remainingMove = maxMove;
    _map = &map;
    _tex.loadFromFile(textureFilename);
    setTexture(_tex);
    setPosition(col*32,line*32);

}

void kpt::Character::move (unsigned int col, unsigned int line)
{
    if (col >= _map->getNbCols() || line >= _map->getNbLines())
    {
        return;
    }

    unsigned int dl = std::abs(int (line - _line));
    unsigned int dc = std::abs(int(col - _col));
    if (dc > 1 || dl > 1 || (dl == 0 && dc == 0))
    {
        return;
    }
    switch ((*_map)(col,line)) {
        case TerrainNu:
            if ( _remainingMove < 1)
                return; // ne se déplace pas
            _remainingMove--;
            break;
        case Foret:
            if (_remainingMove < 2)
                return; // ne se déplace pas
            _remainingMove -= 2;
            break;
        case Riviere:
            if (_remainingMove < _maxMove)
                return; // ne se déplace pas
            _remainingMove -= _maxMove;
            break;
    }
    _col = col;
    _line = line;
    setPosition(_col*32,_line*32);
}
