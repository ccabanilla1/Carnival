#include "ride.h"

Ride::Ride(){
    numTicketsNecessary = 0;
    name = "None";
    heightRestricted = true;


}

Ride::Ride(int newNumRideTickets, string newName, bool newHeightRestricted){
    numTicketsNecessary = newNumRideTickets;
    name = newName;
    heightRestricted = newHeightRestricted;


}

Ride::Ride(const Ride& old){
    numTicketsNecessary = old.numTicketsNecessary;
    name = old.name;
    heightRestricted = old.heightRestricted ;
    

} 


int Ride::getNumTicketsNecessary(){
    return numTicketsNecessary;

}



void Ride::setNumTicketsNecessary(int newNumTicketsNecessary){
    numTicketsNecessary = newNumTicketsNecessary;

}


string Ride::getRideName(){
    return name;

}

void Ride::setRideName(string newName){
    name = newName;

}
bool Ride::getHeightRestricted(){
    return heightRestricted;

}
void Ride::setHeightRestricted(bool newHeightRestricted){
    heightRestricted = newHeightRestricted;

}

