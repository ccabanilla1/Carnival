#include "magicCarpet.h"
#include "patron.h"
#include "teacups.h"
#include "worldTour.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#define MAX_PEOPLE 100

void displayMenuOption();
int getMenuOption();
void addPatron(Patron[], Patron, int *);
int readExistingPatrons(Patron[], string);
void printFileNotFound();
void displayPatrons(Patron[], int);
int getPatronOption(Patron[], int);
void removePatron(Patron[], int *);
Patron createNewPatron();
void modifyPatron(Patron *);
void displayModOptions();
void displayRideMenu();
int getModOption();
void addTickets(Patron *);
void addRide(Patron *);
void editName(Patron *);
void overwriteFile(Patron[], string, int);

int main(int argc, char *argv[]) {
  if (argc == 2) {

    string fileName;
    fileName = argv[1];
    ifstream file(fileName);
    if (file.fail()) {
      printFileNotFound();
    }

    int userInput;
    Patron patronArray[MAX_PEOPLE];
    Patron newPatron;
    Patron *patron;

    int patronToRemove;
    int userChoice;
    int userPatron;

    int numPatron = readExistingPatrons(patronArray, fileName);

    while (true) {
      int *numPatrons = &numPatron;
      displayMenuOption();
      userInput = getMenuOption();
      switch (userInput) {
      case 1: // adding
        newPatron = createNewPatron();

        addPatron(patronArray, newPatron, numPatrons);

        overwriteFile(patronArray, fileName, numPatron);
        break;

      case 2: // removing

        cout << "Enter the number of the patron you'd like to remove" << endl;
        displayPatrons(patronArray, numPatron);

        removePatron(patronArray, numPatrons);

        overwriteFile(patronArray, fileName, numPatron);
        break;

      case 3: // modifying
        cout << "Enter the number of the patron you'd like to modify" << endl;
        userPatron = getPatronOption(patronArray, numPatron);
        if (userPatron > numPatron) {
          cout << "Invalid Input" << endl;
          break;
        }
        userPatron = userPatron - 1;
        patron = &patronArray[userPatron];
        modifyPatron(patron);
        overwriteFile(patronArray, fileName, numPatron);
        break;

      case 4: // viewing
        cout << "Enter the number of the patron you'd like to view" << endl;
        userChoice = getPatronOption(patronArray, numPatron);
        if (userChoice - 1 > numPatron) {
          cout << "Invalid Input" << endl;
        } else {
          userChoice--;
          patron = &patronArray[userChoice];
          patron->displayPatronData();
        }

        break;

      case 0:
        return 0;

      default:
        cout << "Invalid Input" << endl;
        break;
      }
    }
  
  } else {
    printFileNotFound();
  }

  return 0;
}

int getMenuOption() {
  int userInput;
  cin >> userInput;
  return userInput;
}

void displayMenuOption() {
  cout << "1. Add Patron" << endl;
  cout << "2. Remove Patron" << endl;
  cout << "3. Modify Patron" << endl;
  cout << "4. View Patron" << endl;
  cout << "0. Exit" << endl;
  return;
}

void printFileNotFound() {
  cout << "Patron File not found. Run the program again with the file name on the command line." << endl;
  cout << "1. Add Patron" << endl;
  cout << "2. Remove Patron" << endl;
  cout << "3. Modify Patron" << endl;
  cout << "4. View Patron" << endl;
  cout << "0. Exit" << endl;
  return;
}

void displayRideMenu() {
  cout << "Select the ride you'd like to add." << endl;
  cout << "Ride (TicketCost)" << endl;
  cout << "1. Teacups (3 tickets)" << endl;
  cout << "2. Magic Carpet (2 tickets)" << endl;
  cout << "3. World Tour (1 tickets)" << endl;
  return;
}

int getModOption() {
  int userOption;
  cin >> userOption;
  return userOption;
}

void displayModOptions() {
  cout << "1. Add tickets" << endl;
  cout << "2. Purchase admittance to ride" << endl;
  cout << "3. Edit Name" << endl;
  cout << "0. Exit to main menu" << endl;
  return;
}

void overwriteFile(Patron patronArray[], string fileName, int numPatron) {
  ofstream myfile;
  myfile.open(fileName);
  for (int i = 0; i < numPatron; i++) {
    myfile << patronArray[i].getFirstName() << " "
           << patronArray[i].getLastName() << " "
           << patronArray[i].getPatronNumber() << " "
           << patronArray[i].getNumTickets();
    if (i < numPatron - 1) {
      myfile << endl;
    }
  }
}

int readExistingPatrons(Patron patronArray[], string fileName) {
  ifstream fin;
  string first, last;
  int id, tickets, i = 0;

  fin.open(fileName);

  while (!fin.eof()) {
    fin >> first >> last >> id >> tickets;
    Patron temp;
    temp.setFirstName(first);
    temp.setLastName(last);
    temp.setPatronNumber(id);
    temp.setNumTickets(tickets);
    patronArray[i] = temp;
    i++;
  }
  fin.close();
  return i;
}

void addPatron(Patron patronArray[], Patron newPatron, int *numPatrons) {
  patronArray[*numPatrons] = newPatron;
  *numPatrons = *numPatrons + 1;
}

Patron createNewPatron() {
  string first, last;
  int id, tickets;
  char userInput;
  cout << "Let's add a patron to the system! " << endl;
  cout << "Patron first and last name (Sara Davis)" << endl;
  cin >> first >> last;
  Patron newPatron;
  newPatron.setFirstName(first);
  newPatron.setLastName(last);

  cout << "Patron idNumber (last 4 digits of phone number)" << endl;
  cin >> id;
  newPatron.setPatronNumber(id);
  cout << "How many tickets would they like to purchase?" << endl;
  cin >> tickets;
  newPatron.setNumTickets(tickets);

  while (true) {
    cout << "Would you like to purchase rides? (y/n)" << endl;
    cin >> userInput;

    if (userInput == 'n') {
      break;
    }
    addRide(&newPatron);
  }
  return newPatron;
}

void displayPatrons(Patron patronArray[], int numPatron) {
  for (int i = 0; i < numPatron; i++) {
    cout << i + 1 << ". ";
    patronArray[i].displayName();
  }
}
void removePatron(Patron patronArray[], int *numPatrons) {
  int patronToRemove;
  cin >> patronToRemove;
  if (patronToRemove != 0) {
    for (int i = patronToRemove - 1; i < *numPatrons; i++) {
      patronArray[i] = patronArray[i + 1];
    }
    *numPatrons = *numPatrons - 1;
  }
}

int getPatronOption(Patron patronArray[], int numPatron) {
  int userChoice;
  for (int i = 0; i < numPatron; i++) {
    cout << i + 1 << ". ";
    patronArray[i].displayName();
  }
  cin >> userChoice;
  return userChoice;
}

void editName(Patron *patron) {

  int userChoice;
  string newLast;
  string newFirst;

  cout << "Would you like to edit the:" << endl;
  cout << "1. first" << endl;
  cout << "2. last" << endl;
  cout << "3. whole name" << endl;

  cin >> userChoice;

  switch (userChoice) {
  case 1:
    cout << "Enter edited first name:" << endl;

    cin >> newFirst;
    (*patron).setFirstName(newFirst);

    break;

  case 2:
    cout << "Enter edited last name:" << endl;

    cin >> newLast;
    (*patron).setLastName(newLast);
    break;

  case 3:
    cout << "Enter first name:" << endl;
    cin >> newFirst;
    cout << "Enter last name:" << endl;
    cin >> newLast;

    (*patron).setFirstName(newFirst);
    (*patron).setLastName(newLast);
    break;

  case 0:
    break;

  default:
    cout << "Invalid Input" << endl;
    break;
  }
}

void addTickets(Patron *patron) {
  cout << "How many tickets would you like to add?" << endl;
  int addTickets;
  int totalTickets;
  cin >> addTickets;
  totalTickets = (*patron).getNumTickets();
  totalTickets = totalTickets + addTickets;
  (*patron).setNumTickets(totalTickets);
}

void addRide(Patron *patron) {
  int rideInput;
  Ride ride;
  int tInput;
  displayRideMenu();
  cin >> rideInput;

  switch (rideInput) {
  case 1: // teacups
    ride = Teacups();
    break;
  case 2: // magic carpet
    ride = MagicCarpet();
    break;
  case 3: // world tour
    ride = WorldTour();
    break;
  default:
    cout << "Invalid Input" << endl;
    return;
  }

  if (patron->getNumTickets() >= ride.getNumTicketsNecessary()) {
    patron->addPatronRide(ride);
  } else {
    cout << "Not enough tickets 💀." << endl;
    cout << "Would you like to purchase more tickets? (1-Yes, 2-No)" << endl;
    cin >> tInput;

    if (tInput == 1) {
      addTickets(patron);
    }
  }
}
void modifyPatron(Patron *patron) {
  int userChoice;

  displayModOptions();
  userChoice = getModOption();
  if (userChoice == 1) {
    addTickets(patron);
  } else if (userChoice == 2) {
    addRide(patron);
  } else if (userChoice == 3) {
    editName(patron);
  } else if (userChoice == 0) {

  } else {
    cout << "Invalid Input";
  }
}