#include <iostream>
using namespace std;

const int SIZE = 10;

class ITEMS {
    int itemCode[SIZE];   // stores item code
    float itemPrice[SIZE]; // stores item price
    int count;             // controls count of items

public:
    void CNT(void) { count = 0; }      // initializes count of items
    void getitem(void);                // accepts item code and price
    void displaySum(void);             // displays total value of all items
    void remove(void);                 // deletes a specified item
    void displayItems(void);           // displays all items
};

void ITEMS :: getitem(void) { // stores code and price of items
    cout << "Enter item code: ";
    cin >> itemCode[count];
    cout << "Enter item price: ";
    cin >> itemPrice[count];
    count++;
}

void ITEMS :: displaySum(void) { // displays total value of all items
    float sum = 0;
    for (int i = 0; i < count; i++)
        sum = sum + itemPrice[i];
    cout << "\nTotal value: " << sum << "\n";
}

void ITEMS :: remove(void) { // deletes a specified item
    int a;
    cout << "Enter item code: ";
    cin >> a;
    for (int i = 0; i < count; i++) {
        if (itemCode[i] == a)
            itemPrice[i] = 0;
    }
}

void ITEMS :: displayItems(void) { // displays code and price of all items
    cout << "\nCode Price\n";
    for (int i = 0; i < count; i++) {
        cout << "\n" << itemCode[i];
        cout << " " << itemPrice[i];
    }
    cout << "\n";
}

int main() {
    ITEMS order;
    order.CNT();
    int x;

    do {
        cout << "\nYou can do the following:";
        cout << "\nEnter appropriate number: ";
        cout << "\n1: Add an item";
        cout << "\n2: Display total value";
        cout << "\n3: Delete an item";
        cout << "\n4: Display all items";
        cout << "\n5: Quit";
        cout << "\nWhat is your option?: ";
        cin >> x;

        switch (x) {
            case 1:
                order.getitem();
                break;
            case 2:
                order.displaySum();
                break;
            case 3:
                order.remove();
                break;
            case 4:
                order.displayItems();
                break;
            case 5:
                break;
            default:
                cout << "Error in input; try again.\n";
        }
    } while (x != 5);

    return 0;
}