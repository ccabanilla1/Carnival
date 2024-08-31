#include "teacups.h"


Teacups::Teacups(){
    name = "Teacups";
    numTicketsNecessary = 3;
    heightRestricted = false;

}

Teacups::Teacups(const Teacups& copy){
    name = copy.name;
    numTicketsNecessary = copy.numTicketsNecessary;
    heightRestricted = copy.heightRestricted;

}
Teacups::Teacups(int newNumTicketsNecessary,string newName ,bool newHeightRestricted){

    name = "Teacups";
    numTicketsNecessary = 3;
    heightRestricted = false;    

}
