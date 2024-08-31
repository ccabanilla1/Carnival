carnival: driver.o patron.o ride.o worldTour.o teacups.o magicCarpet.o
	g++ -o carnival driver.o patron.o ride.o worldTour.o teacups.o magicCarpet.o
driver.o: driver.cpp patron.h ride.h worldTour.h teacups.h magicCarpet.h
	g++ -c driver.cpp
patron.o: patron.cpp patron.h ride.h
	g++ -c patron.cpp
ride.o: ride.cpp ride.h
	g++ -c ride.cpp
teacups.o: ride.h teacups.cpp
	g++ -c teacups.cpp
worldTour.o: ride.h worldTour.cpp
	g++ -c worldTour.cpp
magicCarpet.o: ride.h magicCarpet.cpp
	g++ -c magicCarpet.cpp
clean:
	rm *.o carnival