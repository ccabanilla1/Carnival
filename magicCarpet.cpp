#include "magicCarpet.h"


MagicCarpet::MagicCarpet(){
    name = "Magic Carpet";
    numTicketsNecessary = 2;
    heightRestricted = true;

}

MagicCarpet::MagicCarpet(const MagicCarpet& copy){
    name = copy.name;
    numTicketsNecessary = copy.numTicketsNecessary;
    heightRestricted = copy.heightRestricted;

}
MagicCarpet::MagicCarpet(int newNumTicketsNecessary,string newName ,bool newHeightRestricted){

    name = "Magic Carpet";
    numTicketsNecessary = 2;
    heightRestricted = true;  

}