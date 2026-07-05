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
protected:
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

    virtual ~Car() {}

    virtual double calculateInsurance() const {
        return 0; 
    }

    virtual void information() const {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "License Plate: " << licensePlate << endl;
        cout << "Color: " << color << endl;
        cout << "Year: " << year << endl;
        cout << "Chassis Number: " << chassisNumber << endl;
        cout << "Engine Number: " << engineNumber << endl;
        cout << "Purpose of Use: " << purposeOfUse << endl;
        cout << "Price: " << price << endl;
        cout << "Insurance: " << calculateInsurance() << endl;
    }

    bool operator==(const Car& other) const {
        return (chassisNumber == other.chassisNumber) && (engineNumber == other.engineNumber);
    }
};

class PersonalCar : public Car {
private:
    int mileageLim;

public:
    PersonalCar() : Car() {
        do {
            cout << "Enter Yearly Mileage Limit (minimum 10000): ";
            cin >> mileageLim;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                mileageLim = -1;
            }
        } while (mileageLim < 10000);
    }

    double calculateInsurance() const override {
        return (price * 0.01) + (1000 * (mileageLim / 10000.0));
    }

    void information() const override {
        Car::information();
        cout << "Yearly Mileage Limit: " << mileageLim << endl;
    }
};

class CompanyCar : public Car {
protected:
    int totalCars;

public:
    CompanyCar() : Car() {
        do {
            cout << "Enter Total Number of Cars the Company Owns: ";
            cin >> totalCars;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                totalCars = -1;
            }
        } while (totalCars < 0);
    }

    double calculateInsurance() const override {
        double rate = 0.02 - (0.001 * (totalCars / 10.0));
        if (rate < 0.012) {
            rate = 0.012;
        }
        return price * rate;
    }

    void information() const override {
        Car::information();
        cout << "Total Company Cars: " << totalCars << endl;
    }
};

class FleetCar : public CompanyCar {
private:
    int cities;

public:
    FleetCar() : CompanyCar() {
        do {
            cout << "Enter Number of cities the Company Operates In: ";
            cin >> cities;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cities = -1;
            }
        } while (cities < 0);
    }

    double calculateInsurance() const override {
        double baseInsurance = CompanyCar::calculateInsurance();
        return baseInsurance * (1 + (cities / 10.0));
    }

    void information() const override {
        CompanyCar::information();
        cout << "Number of Cities Operated: " << cities << endl;
    }
};

int main() {
    Car* cars[3];

    cout << "\n--- Creating Personal Car ---" << endl;
    cars[0] = new PersonalCar();

    cout << "\n--- Creating Company Car ---" << endl;
    cars[1] = new CompanyCar();

    cout << "\n--- Creating Fleet Car ---" << endl;
    cars[2] = new FleetCar();

    cout << "\n___ Displaying All Cars ___" << endl;
    for (int i = 0; i < 3; i++) {
        cars[i]->information();
        cout << "__________________________" << endl;
    }
    
    for (int i = 0; i < 3; i++) {
        delete cars[i]; 
    }
    
    return 0;
}