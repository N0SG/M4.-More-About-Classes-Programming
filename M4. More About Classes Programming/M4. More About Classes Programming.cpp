// M4. More About Classes Programming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

// Class for the parked car info, both private and public for general info.
class parkedcar {
private:
    string make;
    string model;
    string color;
    string license;
    int minsparked;

public:
    parkedcar(string mk, string mdl, string clr, string lic, int min)
        : make(mk), model(mdl), color(clr), license(lic), minsparked(min) {
    }

    string getmake() const { return make;}
    string getmodel() const { return model;}
    string getcolor() const { return color;}
    string getlicense() const { return license;}
    int getminsparked() const { return minsparked;}
};

// The parkingmeter class! Both private and public for the mins purchased for the meter.
class parkingmeter {
private:
    int minspurchased;

public:
    parkingmeter(int mins) : minspurchased(mins) {}

    int getminspurchased() const { return minspurchased; }
};

// The parking ticket class!
class parkingticket {
private:
    string carmake;
    string carmodel;
    string carcolor;
    string carlicense;
    int minutesover;
    double fine;
    string officername;
    string officerbadge;

public:
    parkingticket(const parkedcar& car, int minsover, string name, string badge) {
        carmake = car.getmake();
        carmodel = car.getmodel();
        carcolor = car.getcolor();
        carlicense = car.getlicense();
        minutesover = minsover;

        // This is to calculate the fine (first hour/min is set to 25 due to the min fine and it being increased)
        fine = 25.0;
        int timeover = (minutesover - 60 + 59) / 60;
        if (timeover > 0) {
            fine += timeover * 10;
        }

        officername = name;
        officerbadge = badge;
    }

	// Method to print the ticket info
    void printtix() const {
        cout << endl << "*** A Parking Ticket has been issued! ***" << endl;
        cout << "The Officer's name is" << officername
            << "Their Badge Number: " << officerbadge << endl;
        cout << "The Vehicle license plate number: " << carlicense << endl;
        cout << "The Make: " << carmake
            << "The Model: " << carmodel
            << "The Color: " << carcolor << endl;
        cout << "The Total Minutes over: " << minutesover << endl;
        cout << "Total Parking Fine is:" << fine << endl;
    }
};

// The popo (said like poe poe) class
class policeofficer {
private:
    string name;
    string badgenum;

public:
    policeofficer(string n, string b) : name(n), badgenum(b) {}

    parkingticket* inspect(const parkedcar& car, const parkingmeter& meter) {
        int parked = car.getminsparked();
        int purchased = meter.getminspurchased();

		// If the car is parked longer than purchased, issue a ticket :(
        if (parked > purchased) {
            int minsover = parked - purchased;
            return new parkingticket(car, minsover, name, badgenum);
        }
        return nullptr;
    }
};

// Finally the MAIN PROGRAM! (w/ TEST SCENARIOS as laid out on the sheet!!!)
int main() {

    cout << endl << "=============================== Scenario 1: Car Legally Parked ===============================" << endl;
    {
        parkedcar car("Toyota", "Camry", "Red", "XYZ123", 30);
        parkingmeter meter(40);
        policeofficer officer("John Doe", "5678");

        parkingticket* ticket = officer.inspect(car, meter);

        if (ticket == nullptr)
            cout << endl << "Luckily the car is legally parked. So no ticket was issued." << endl;
        else {
            ticket->printtix();
            delete ticket;
        }
    }

    cout << endl << "=============== Scenario 2: Car Illegally Parked (Less Than an Hour Over Time) ===============" << endl;
    {
        parkedcar car("Honda", "Accord", "Blue", "ABC987", 70);
        parkingmeter meter(60);
        policeofficer officer("Jane Smith", "1234");

        parkingticket* ticket = officer.inspect(car, meter);

        if (ticket)
            ticket->printtix();
        delete ticket;
    }

    cout << endl << "================= Scenario 3: Car Illegally Parked (Multiple Hours Over Time) =================" << endl;
    {
        parkedcar car("Ford", "Mustang", "Black", "LMN456", 190);
        parkingmeter meter(60);
        policeofficer officer("James Brown", "4321");

        parkingticket* ticket = officer.inspect(car, meter);

        if (ticket)
            ticket->printtix();
        delete ticket;
    }

    cout << endl << "============================== Scenario 4: Multiple Cars Inspected ============================" << endl;
    {
        policeofficer officer("Eric Shawn", "9999");

        parkedcar car1("Kia", "Soul", "Green", "KIASSUX", 55);
        parkingmeter m1(30);

        parkedcar car2("BMW", "X5", "White", "NOBLINKA", 120);
        parkingmeter m2(60);

        parkedcar car3("Tame", "Impala", "Gray", "GOODBAND", 10);
        parkingmeter m3(20);

        parkingticket* t1 = officer.inspect(car1, m1);
        parkingticket* t2 = officer.inspect(car2, m2);
        parkingticket* t3 = officer.inspect(car3, m3);

        if (t1) t1->printtix();
        if (t2) t2->printtix();
        if (t3) t3->printtix();

        delete t1;
        delete t2;
        delete t3;
    }

    cout << endl << "Parking sim is done" << endl;
    return 0;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
