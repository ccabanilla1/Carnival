#include "patron.h"

Patron::Patron(){
    firstName = "Wrong";
    lastName = "Incorrect";
    patronNumber = -1111;
    numTickets = -1;
    numRides = 0;
}

Patron::Patron(string newFirstName,string newLastName,int newPatronNumber,int newNumTickets,int newNumRides,Ride newPatronRides[]){
    firstName = newFirstName;
    lastName = newLastName;
    patronNumber = newPatronNumber;
    numTickets = newNumTickets;
    numRides = newNumRides;
    for(int i = 0; i < numRides; i++){
        patronRides[i] = newPatronRides[i];

    }
}

Patron::Patron(const Patron & old){

    firstName = old.firstName;
    lastName = old.lastName;
    patronNumber = old.patronNumber;
    numTickets = old.numTickets;
    numRides = old.numRides;
    for(int i = 0; i < old.numRides; i++){
        patronRides[i] = old.patronRides[i];

    }
    

}


string Patron::getFirstName(){
    return firstName;
}

void Patron::setFirstName(string newFirstName) {
    firstName = newFirstName;
}

string Patron::getLastName(){
    return lastName;
}
void Patron::setLastName(string newLastName) {
    lastName = newLastName;

}

int Patron::getPatronNumber(){
    return patronNumber;
}

void Patron::setPatronNumber(int newPatronNumber){
    patronNumber = newPatronNumber;

}

int Patron::getNumTickets(){
    return numTickets;
}

void Patron::setNumTickets(int newNumTickets){
    numTickets = newNumTickets;

}

void Patron::displayName(){
    cout<< firstName << " " << lastName << endl;
}

void Patron::displayPatronData(){
    cout << "\n" << "First Name: " << getFirstName() << "\n" << "Last Name: " << getLastName() << "\n" << "Patron Number: " << getPatronNumber() << "\n" << "Number of Rides: " << numRides << "\n" << "Number of Tickets: " << numTickets << "\n" << endl;

    cout << "Rides: " << endl;
    for(int i = 0; i < numRides; i++){
        cout << patronRides[i].getRideName() << endl;
    } 
    cout << endl;
}

Ride* Patron::getPatronRides(){
    return patronRides;

}

void Patron::addPatronRide(Ride newRide){
	
    patronRides[numRides] = newRide;
    numRides++;

  numTickets -= newRide.getNumTicketsNecessary();
}





