#include <iostream>
#include <map>
#include <string>

using namespace std;

class Hotel {
private:
    struct Room {
        bool isOccupied = false;
        string guestName;
    };
    map<int, Room> rooms;

public:
    void addRoom(int roomNumber) {
        rooms[roomNumber] = {};
        cout << "Room " << roomNumber << " added." << endl;
    }

    void bookRoom(int roomNumber, string guestName) {
        if (!rooms[roomNumber].isOccupied) {
            rooms[roomNumber] = {true, guestName};
            cout << "Room " << roomNumber << " booked for " << guestName << endl;
        } else {
            cout << "Room " << roomNumber << " is already occupied!" << endl;
        }
    }

    void checkoutRoom(int roomNumber) {
        if (rooms[roomNumber].isOccupied) {
            cout << rooms[roomNumber].guestName << " checked out from Room " << roomNumber << endl;
            rooms[roomNumber] = {false, ""};
        } else {
            cout << "Room " << roomNumber << " is not occupied!" << endl;
        }
    }

    void showAvailableRooms() {
        cout << "Available rooms:\n";
        for (auto &entry : rooms) {
            if (!entry.second.isOccupied) {
                cout << "Room " << entry.first << endl;
            }
        }
    }
};

int main() {
    Hotel hotel;
    hotel.addRoom(101); hotel.addRoom(102); hotel.addRoom(103);
    hotel.bookRoom(101, "Alice"); hotel.bookRoom(102, "Bob");
    hotel.showAvailableRooms();
    hotel.checkoutRoom(101);
    hotel.showAvailableRooms();
    return 0;
}
