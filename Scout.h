#ifndef SCOUT_H__
#define SCOUT_H__


#include <SFML/Graphics.hpp>
#include "Character.h"


namespace kpt {

    class Scout : public Character
    {
    public:
        /*** Constructeur ***/
        Scout(unsigned int col, unsigned int line, const TileMap & map);
        /*** Destructeur ***/
        virtual ~Scout () = default;
        /*** Opérateurs ***/

        /*** Méthodes ***/

    };
}
#endif
