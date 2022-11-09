#include"util.h"


//there is no element of user input - it's just an AI finding the ships(1s) that were randomly placed at the start

int main()
{
    Clear();
    PlaceShips();
    Build();
    Scan();
    return(0);
}