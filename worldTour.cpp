#include "worldTour.h"


WorldTour::WorldTour(){
    name = "World Tour";
    numTicketsNecessary = 1;
    heightRestricted = false;

}

WorldTour::WorldTour(const WorldTour& copy){
    name = copy.name;
    numTicketsNecessary = copy.numTicketsNecessary;
    heightRestricted = copy.heightRestricted;

}
WorldTour::WorldTour(int newNumTicketsNecessary,string newName ,bool newHeightRestricted){
    name = "World Tour";
    numTicketsNecessary = 1;
    heightRestricted = false;
}
