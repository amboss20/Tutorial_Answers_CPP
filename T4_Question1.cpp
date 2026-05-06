#include <iostream>
#include <string>
using namespace std;

class Purchase {
    private: 
    string itemName;
    int qty;
    float price, total;
    static int totalItems;
    static float grandTotal;

    public:
    Purchase();
    Purchase(string name, int quantity, float p);
    void set_data(string name, int quantity, float p);
    void calculate();
    void print();
    void printtotal();
};

int Purchase::totalItems = 0;
float Purchase::grandTotal = 0.0;

Purchase::Purchase() {
    qty = 0;
    price = 0;
    itemName = "";
    total = 0;
}

Purchase::Purchase(string name, int quantity, float p) {
    itemName = name;
    qty = quantity;
    price = p;
    total = 0;
}

void Purchase::set_data(string name, int quantity, float p) {
    itemName = name;
    qty = quantity;
    price = p;
    calculate();
}

void Purchase::calculate() {
    total = qty * price;

    totalItems += qty;
    grandTotal += total;

}

void Purchase::print() {
    cout << "==========================" << endl;
    cout << "RECEIPT" << endl;
    cout << "==========================" << endl;
    cout << "Name     : " << itemName << endl;
    cout << "Quantity : " << qty << endl;
    cout << "Price    : RM " << price << endl;
    cout << "Total    : RM " << total << endl;
}

void Purchase::printtotal(){
    cout << "\n========= GRAND TOTAL =========" << endl;
    cout << "Total number of items : " << totalItems << endl;
    cout << "Total amount to be paid : RM " << grandTotal << endl;
}

int main() {
    Purchase p1;

    string name;
    int qty;
    float price;

        while (true) {
        cout << "\nEnter item ('Q' to quit): ";
        cin >> name;

        if (name == "Q" || name == "q") {
            break;
        }

        cout << "Enter quantity: ";
        cin >> qty;

        cout << "Enter price: RM ";
        cin >> price;

        p1.set_data(name, qty, price);
        p1.print();
    }

    p1.printtotal();

    return 0;
}