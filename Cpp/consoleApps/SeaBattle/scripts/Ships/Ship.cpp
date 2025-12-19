#include <iostream>
#include <string>
using namespace std;

class Ship
{

    struct ShipSample
    {
        int health;
        int x;
        int y;

        bool isHit;
    };

    public:
        ShipSample shipS;

        void GetShipData(int h, int posX, int posY)
        {
            shipS.health = h;
            shipS.x = posX;
            shipS.y = posY;
            shipS.isHit = false;
        }

        void HitShip()
        {
            shipS.isHit = true;
            shipS.health -= 1;
        }

        bool IsSunk()
        {
            return shipS.health <= 0;
        }

        

};