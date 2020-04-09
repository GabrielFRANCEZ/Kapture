#ifndef SHOCK_H__
#define SHOCK_H__


#include <SFML/Graphics.hpp>
#include "Character.h"


namespace kpt {

    class ShockTroops : public Character
    {
    public:
        /*** Constructeur ***/
        ShockTroops(unsigned int col, unsigned int line, const TileMap & map);
        /*** Destructeur ***/
        virtual ~ShockTroops () = default;
        /*** Opérateurs ***/

        /*** Méthodes ***/

    };
}
#endif
