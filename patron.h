#ifndef PATRON_H
#define PATRON_H
#include <iostream>
#include <string>
#include "ride.h"
using namespace std;

class Patron {
    protected:
        string firstName;
        string lastName;
        int patronNumber;
        int numTickets;
        int numRides;
        Ride patronRides[100];


    public:
        Patron();
        Patron(string,string,int,int,int, Ride []);
        Patron(const Patron &);
        string getFirstName();
        void setFirstName(string firstName);
        string getLastName();
        void setLastName(string lastName);
        int getPatronNumber();
        void setPatronNumber(int patronNumber);
        Ride* getPatronRides();
        void addPatronRide(Ride);
        void displayName();
        int getNumTickets();
        void setNumTickets(int numTickets);
        void displayPatronData();

};

#endif