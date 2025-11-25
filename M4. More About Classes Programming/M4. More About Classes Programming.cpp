// M4. More About Classes Programming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

//Hello this is my date class project with operator overloads and such!
class date {
private:
    int month, day, year;

	// Sets the maximum days in a month (probably seems familiar)
    int maxdays(int m, int y) const {
        if (m == 2) {

			// Da leap year check (Still find it really cool how this works)
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
                return 29;
            return 28;
        }
        if (m == 4 || m == 6 || m == 9 || m == 11)
            return 30;
        return 31;
    }

	// I was going to make it valid but isgood sounds funny to me
    bool isgood(int m, int d, int y) const {
        if (m < 1 || m > 12) return false;
        if (d < 1 || d > maxdays(m, y)) return false;
        if (y < 1) return false;
        return true;
    }

	// Public members to set defaults and overload operators
public:

    // Fun fact its the first year in our current calendar system!!! (did you know that?) (4713 BC) (Julian calendar)(YEAH)
    date() : month(1), day(1), year(4713) {}

    // Constructor with parameters
    date(int m, int d, int y) {
        if (isgood(m, d, y)) {
            month = m;
            day = d;
            year = y;
        }
        else {

			// Everytime i see Invalid date given! I think of kaiba's defeat meme
            cout << "Invalid date given! Setting to 1/1/4713." << endl;
            month = 1;
            day = 1;
            year = 4713;
        }
    }

	// setdate() method to set the date after object creation (with the is good to check)
    bool setdate(int m, int d, int y) {
        if (!isgood(m, d, y))
            return false;
        month = m;
        day = d;
        year = y;
        return true;
    }

	// Prefix ++ to increment the date by one day
    date& operator++() {
        day++;
        if (day > maxdays(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return *this;
    }

	// Postfix ++ to increment the date by one day once again
    date operator++(int) {
        date temp = *this;
        ++(*this);
        return temp;
    }

	// Prefix -- to decrement the date by one day
    date& operator--() {
        day--;
        if (day < 1) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            day = maxdays(month, year);
        }
        return *this;
    }

	// Postfix -- to decrement the date by one day once again 
    date operator--(int) {
        date temp = *this;
        --(*this);
        return temp;
    }

	// Subtracting the days between two dates
    int operator-(const date& other) const {

		// First we have to convert both dates to numbers
        return countdays() - other.countdays();
    }

    long countdays() const {
        long days = 0;

        // Next sdd all the days from previous years
        for (int y = 1; y < year; y++) {
            days += 365;
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
                days++;
        }

        // Next pt2 add days for previous months in current year
        for (int m = 1; m < month; m++) {
            days += maxdays(m, year);
        }

		// Finally add days in current month!
        days += day;

        return days;
    }

	// Output operator << to display the date read from the keyboard
    friend ostream& operator<<(ostream& out, const date& d) {
        static string monthnames[12] =
        { "January","February","March","April","May","June",
         "July","August","September","October","November","December" };
        out << monthnames[d.month - 1] << " " << d.day << ", " << d.year;
        return out;
    }

    // Input operator >> to see the date typed on the keyboard
    friend istream& operator>>(istream& in, date& d) {
        int m, da, y;
        cout << "Enter the month, day, year! (Please): ";
        in >> m >> da >> y;

        if (!d.setdate(m, da, y)) {
            cout << "Invalid date! Keeping previous value.\n";
        }
        return in;
    }
};
// The test plan as laid out in the project sheet!
int main() {

    cout << "\n==== DA TEST PLAN START ====\n\n";

    // 1. Default constructor
    date d1;
    cout << "Default constructor: " << d1 << endl;

    // 2. Constructor with parameters
    date d2(4, 18, 2018);
    cout << "Parameterized constructor: " << d2 << endl;

    // 3. Test setdate()
    d1.setdate(3, 15, 2020);
    cout << "After setdate(): " << d1 << endl;

    // 4-6 invalid dates
    cout << "Set to 13/45/2018: " << (d1.setdate(13, 45, 2018) ? "ACCEPTED" : "REJECTED") << endl;
    cout << "Set to 4/31/2000: " << (d1.setdate(4, 31, 2000) ? "ACCEPTED" : "REJECTED") << endl;
    cout << "Set to 2/29/2009: " << (d1.setdate(2, 29, 2009) ? "ACCEPTED" : "REJECTED") << endl;

    // 7 subtraction example #1
    date a(4, 10, 2014);
    date b(4, 18, 2014);
    cout << endl << "4/18/2014 - 4/10/2014 = " << (b - a) << " days" << endl;

    // 8 subtraction example #2
    date c1(2, 2, 2006);
    date c2(11, 10, 2003);
    cout << "2/2/2006 - 11/10/2003 = " << (c1 - c2) << " days" <<endl;

    // 9 Pre-increment/decrement
    date d3(2, 29, 2008);
    cout << "Starting date: " << d3 << endl;
    ++d3;
    cout << "After ++d3: " << d3 << endl;
    --d3;
    cout << "After --d3: " << d3 << endl;

    // 10 Post-increment/decrement
    d3++;
    cout << "After d3++: " << d3 << endl;
    d3--;
    cout << "After d3--: " << d3 << endl;

    // 11 Year rollover test
    date d4(12, 31, 2024);
    cout << endl << "Start: " << d4 << endl;
    d4++;
    cout << "After d4++: " << d4 << endl;
    d4--;
    cout << "After d4--: " << d4 << endl;

    // 12 cin >> and cout <<
    date userdate;
    cin >> userdate;
    cout << "You entered: " << userdate << endl;

    cout << endl << "==== TEST PLAN END ====" << endl;
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
