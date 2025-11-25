// M4. More About Classes Programming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
 cout << "Hello Welcome to my M4! I have each branch set the projects name!" << endl;
 int pdjtnum;
 cout << endl << "With 2 being Parked Car Simulation and 1 being The Date Class Project with Operator Overloading" << endl << "Please enter a number between 1 and 2 to see a the name of the project branch: " << endl;

 if (cin >> pdjtnum) 
     switch (pdjtnum) {
     case 1:
         cout << "The name of the branch is The Date Class Project with Operator Overloading!" << endl;
         break;
     case 2:
         cout << "The name of the branch is Parked Car Simulation!" << endl;
         break;
     default:
         cout << "You did not enter a valid number between 1 and 2!" << endl;
         break;
	 }
 
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
