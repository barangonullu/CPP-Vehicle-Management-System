#include <iostream>
#include <string>
using namespace std;

bool digit(char c) {
    return c >= '0' && c <= '9';
}

bool alpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool validatePlate(const string& plate) {
    int len = plate.length();
    if (len != 7 && len != 8) return false;
    
    if (!digit(plate[0]) || !digit(plate[1])) return false;
    if (!alpha(plate[2])) return false;
    
    int digitStart = 3;
    if (alpha(plate[3])) {
        digitStart = 4;
        if (len == 8 && alpha(plate[4])) {
            digitStart = 5;
        }
    }
    
    for (int i = digitStart; i < len; ++i) {
        if (!digit(plate[i])) return false;
    }
    return true;
}

bool isColor(const string& color) {
    return color == "White" || color == "Red" || color == "Black" || color == "Blue";
}

bool isPurpose(const string& purpose) {
    return purpose == "Private" || purpose == "Commercial";
}

bool isYear(int year) {
    return year >= 1900 && year <= 2025;
}

bool isChassis(const string& ch) {
    return ch.length() == 17;
}

bool isEngine(const string& en) {
    return en.length() == 17;
}

class Car {
private:
    string make;
    string model;
    string licensePlate;
    string color;
    int year;
    string chassisNumber;
    string engineNumber;
    string purposeOfUse;
    double price;

public: 
    Car() {
        cout << "Enter Make: ";
        cin >> make;
        cout << "Enter Model: ";
        cin >> model;

        do {
            cout << "Enter License Plate: ";
            cin >> licensePlate;
        } while (!validatePlate(licensePlate));

        do {
            cout << "Enter Color (White, Red, Black, Blue): ";
            cin >> color;
        } while (!isColor(color));

        do {
            cout << "Enter Year (2000 - 2025): ";
            cin >> year;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                year = -1;
            }
        } while (!isYear(year));

        do {
            cout << "Enter Chassis Number (17 characters): ";
            cin >> chassisNumber;
        } while (!isChassis(chassisNumber));

        do {
            cout << "Enter Engine Number (17 characters): ";
            cin >> engineNumber;
        } while (!isEngine(engineNumber));

        do {
            cout << "Enter Purpose of Use: ";
            cin >> purposeOfUse;
        } while (!isPurpose(purposeOfUse));

        do {
            cout << "Enter Price: ";
            cin >> price;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                price = -1;
            }
        } while (price <= 0);
    }

    void information() const {
        cout << endl << "Car Information:" << endl;
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "License Plate: " << licensePlate << endl;
        cout << "Color: " << color << endl;
        cout << "Year: " << year << endl;
        cout << "Chassis Number: " << chassisNumber << endl;
        cout << "Engine Number: " << engineNumber << endl;
        cout << "Purpose of Use: " << purposeOfUse << endl;
        cout << "Price: " << price << endl;
    }

    bool operator==(const Car& other) const {
        return (chassisNumber == other.chassisNumber) && (engineNumber == other.engineNumber);
    }
};

int main() {
    Car cars[3];
    for (int i = 0; i < 3; i++) {
        cars[i].information();
    }

    int car1, car2;
    cout << "Enter the index of the first car to compare (0, 1, or 2): ";
    cin >> car1;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        car1 = -1;
    }
    
    cout << "Enter the index of the second car to compare (0, 1, or 2): ";
    cin >> car2;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        car2 = -1;
    }

    if (car1 < 0 || car1 > 2 || car2 < 0 || car2 > 2) {
        cout << "Invalid car index entered!" << endl;
        return 1;
    }

    if (car1 == car2) {
        cout << "These cars are the same car." << endl;
    } else {
        if (cars[car1] == cars[car2]) {
            cout << "These cars have the same chassis and engine numbers." << endl;
        } else {
            cout << "These cars are different." << endl;
        }
    }

    return 0;
}