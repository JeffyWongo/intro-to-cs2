#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Room
{
    private:
        int _number;
        int _occupancy;
        int _capacity;
    public:
        Room(int number, int capacity);
        Room(int number, string roomtype);
        int getNumber() const;
        int getOccupancy() const;
        int getCapacity() const;
        void setOccupancy(int occupancy);
        friend ostream& operator<<(ostream& out, Room& room);
};
#endif
