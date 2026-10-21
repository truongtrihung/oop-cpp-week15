#include <iostream>
#include <string>
using namespace std;

class Room {
protected:
    string id;
    int adults;
    int children;

public:
    Room() {
        id = "";
        adults = 2;
        children = 1;
    }

    Room(string i, int a, int c) {
        id = i;
        adults = a;
        children = c;
    }

    // Ham ao thuan tuy
    virtual void displayInfo() = 0;

    // Getter
    string getId() const {return id;}
    int getAdults() const {return adults;}
    int getChildren() const {return children;}

    // Setter
    void setId(string i) {id = i;}
    void setAdults(int a) {adults = a;}
    void setChildren(int c) {children = c;}

    virtual ~Room() = default;
};

// ==================== STANDARD ROOM ====================
class StandardRoom : public Room {
public:
    StandardRoom() : Room() {}

    StandardRoom(string i) : Room(i, 2, 1) {}

    void displayInfo() override {
        cout << "Standard Room"
             << " | ID: " << id
             << " | Adults: " << adults
             << " | Children: " << children
             << endl;
    }
};

// ==================== DELUXE ROOM ====================
class DeluxeRoom : public Room {
private:
    int bedOption;

public:
    DeluxeRoom() : Room() {bedOption = 1;}

    DeluxeRoom(string i, int option) : Room(i, 2, 1) {bedOption = option;}

    // Getter
    int getBedOption() const {return bedOption;}

    // Setter
    void setBedOption(int option) {bedOption = option;}

    void displayInfo() override {
        cout << "Deluxe Room"
             << " | ID: " << id
             << " | Adults: " << adults
             << " | Children: " << children;

        if (bedOption == 1)
            cout << " | Bed: 1 Large Double Bed";
        else
            cout << " | Bed: 2 Double Beds";

        cout << endl;
    }
};

// ==================== LUXURY ROOM ====================
class LuxuryRoom : public Room {
private:
    int bedOption;
    bool privateBathroom;

public:
    LuxuryRoom() : Room() {
        bedOption = 1;
        privateBathroom = true;
    }

    LuxuryRoom(string i, int option) : Room(i, 2, 1) {
        bedOption = option;
        privateBathroom = true;
    }

    // Getter
    int getBedOption() const {return bedOption;}

    bool hasPrivateBathroom() const {return privateBathroom;}

    // Setter
    void setBedOption(int option) {bedOption = option;}

    void setPrivateBathroom(bool bathroom) {privateBathroom = bathroom;}

    void displayInfo() override {
        cout << "Luxury Room"
             << " | ID: " << id
             << " | Adults: " << adults
             << " | Children: " << children;

        if (bedOption == 1)
            cout << " | Bed: 1 Large Double Bed";
        else
            cout << " | Bed: 2 Double Beds";

        cout << " | Private Bathroom: "
             << (privateBathroom ? "Yes" : "No")
             << endl;
    }
};

// ==================== MAIN ====================
int main() {
    // 10 Standard Rooms
    StandardRoom standard[10] = {
        StandardRoom("S01"),
        StandardRoom("S02"),
        StandardRoom("S03"),
        StandardRoom("S04"),
        StandardRoom("S05"),
        StandardRoom("S06"),
        StandardRoom("S07"),
        StandardRoom("S08"),
        StandardRoom("S09"),
        StandardRoom("S10")
    };

    // 10 Deluxe Rooms
    DeluxeRoom deluxe[10] = {
        DeluxeRoom("D01", 1),
        DeluxeRoom("D02", 2),
        DeluxeRoom("D03", 1),
        DeluxeRoom("D04", 2),
        DeluxeRoom("D05", 1),
        DeluxeRoom("D06", 2),
        DeluxeRoom("D07", 1),
        DeluxeRoom("D08", 2),
        DeluxeRoom("D09", 1),
        DeluxeRoom("D10", 2)
    };

    // 10 Luxury Rooms
    LuxuryRoom luxury[10] = {
        LuxuryRoom("L01", 1),
        LuxuryRoom("L02", 2),
        LuxuryRoom("L03", 1),
        LuxuryRoom("L04", 2),
        LuxuryRoom("L05", 1),
        LuxuryRoom("L06", 2),
        LuxuryRoom("L07", 1),
        LuxuryRoom("L08", 2),
        LuxuryRoom("L09", 1),
        LuxuryRoom("L10", 2)
    };

    // Mang con tro lop cha: quan ly 30 phong
    Room* rooms[30];

    for (int i = 0; i < 10; i++) {
        rooms[i] = &standard[i];
        rooms[i + 10] = &deluxe[i];
        rooms[i + 20] = &luxury[i];
    }

    // Hien thi thong tin 30 phong
    for (int i = 0; i < 30; i++) {
        rooms[i]->displayInfo();
    }

    return 0;
}
