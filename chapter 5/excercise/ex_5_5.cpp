/*5.5: Create two classes DM and DB which store the value of distances. DM stores
distances in meters and centimeters and DB in feet and inches. Write a program
that can read values for the class objects and add one object of DM with another
object of DB.
Use a friend function to carry out the addition operation. The object that stores the
results may be a DM object or DB object, depending on the units in which the
results are required.
The display should be in the format of feet and inches or meters and centimeters
depending on the object on display. */
#include <iostream>
#define factor 0.3048 // Conversion factor from feet to meters

using namespace std;

class DB; // Forward declaration of class DB

class DM
{
    float d; // Distance in meters

public:
    void store(float x) { d = x; } // Store distance in meters
    friend void sum(DM, DB);       // Friend function to perform addition
    void show();                   // Function to display the result in meters and centimeters
};

class DB
{
    float d1; // Distance in feet

public:
    void store(float y) { d1 = y; } // Store distance in feet
    friend void sum(DM, DB);        // Friend function to perform addition
    void show();                    // Function to display the result in feet and inches
};

// Function to display distance in meters and centimeters
void DM::show()
{
    cout << "\n Distance = " << d << " meters or " << d * 100 << " centimeters\n";
}

// Function to display distance in feet and inches
void DB::show()
{
    cout << "\n Distance = " << d1 << " feet or " << d1 * 12 << " inches \n";
}

// Friend function to add distances from DM (meters) and DB (feet)
void sum(DM m, DB b)
{
    float sumInMeters = m.d + b.d1 * factor; // Convert feet to meters and add
    float sumInFeet = sumInMeters / factor;  // Convert the sum back to feet

    DM mResult; // Create a DM object to store the result in meters
    DB bResult; // Create a DB object to store the result in feet
    mResult.store(sumInMeters);
    bResult.store(sumInFeet);

    cout << "Press 1 to display result in meters\n"
         << "Press 2 to display result in feet\n"
         << "What is your option?: ";
    int option;
    cin >> option;

    // Display the result based on user input
    if (option == 1)
        mResult.show();
    else if (option == 2)
        bResult.show();
    else
        cout << "Invalid option!" << endl;
}

int main()
{
    DM dm;
    DB db;

    // Store distances in meters and feet
    dm.store(10.5); // 10.5 meters
    db.store(12.3); // 12.3 feet

    // Perform the sum of distances
    sum(dm, db);

    return 0;
}
