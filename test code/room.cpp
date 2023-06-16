#include "Room.h"
using namespace std;
Room::Room(int number, int capacity)
{
    _number = number;
    _capacity = capacity;
    _occupancy = 0;
}

Room::Room(int number, string roomtype)
{
    _number = number;
    if(roomtype == "single")
    {
        _capacity = 1;
    }
    else if(roomtype == "double")
    {
        _capacity = 2;
    }
    else if(roomtype == "triple")
    {
        _capacity = 3;
    }
    else if(roomtype == "quadruple")
    {
        _capacity = 4;
    }
    _occupancy = 0;
}

int Room::getNumber() const
{
    return _number;
}

int Room::getOccupancy() const
{
    return _occupancy;
}

int Room::getCapacity() const
{
    return _capacity;
}

void Room::setOccupancy(int occupancy)
{
    if (occupancy > _capacity)
    {
        cout << "error";
        exit(1);
    }
    else {
        _occupancy = occupancy;
    }
}

ostream& operator<<(ostream& out, Room& room)
{
    out << room._number << ": " << room._occupancy << "/" << room._capacity;
    return out;
}