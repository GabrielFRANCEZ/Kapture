#ifndef CANNONCHAIRS_H__
#define CANNONCHAIRS_H__


#include <SFML/Graphics.hpp>
#include "Character.h"


namespace kpt {

    class CannonChairs : public Character
    {
    public:
        /*** Constructeur ***/
        CannonChairs(unsigned int col, unsigned int line, const TileMap & map);
        /*** Destructeur ***/
        virtual ~CannonChairs () = default;
        /*** Opérateurs ***/

        /*** Méthodes ***/

    };
}
#endif
