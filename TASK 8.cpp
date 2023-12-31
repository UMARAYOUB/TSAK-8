#include <iostream>
#include <vector>

using namespace std;

// Structure to hold boat information
struct Boat {
    int boatNumber;
    bool isAvailable;
    int totalHours;
    float moneyTaken;
    string returnTime;
};

// Function to calculate money taken for one boat
void calculateDailyProfitForOneBoat(Boat &boat) {
    float costPerHour = 20.0;
    float costPerHalfHour = 12.0;

    int hours;
    cout << "Enter the number of hours the boat " << boat.boatNumber << " was hired: ";
    cin >> hours;

    if (hours > 10 && hours <= 17) {  // Assuming maximum hire duration is 7 hours (between 10:00 and 17:00)
        boat.totalHours += hours;

        float amount;
        if (hours >= 1) {
            amount = hours * costPerHour;
        } else {
            amount = 0.5 * costPerHour;
        }

        boat.moneyTaken += amount;

        // Calculate return time
        // ... Code to calculate return time based on current time and hired hours

        cout << "Money taken for boat " << boat.boatNumber << " today: $" << amount << endl;
    } else {
        cout << "Invalid input for hours. Must be between 0.5 and 7." << endl;
    }
}


void findNextAvailableBoat(const vector<Boat> &boats) {
    int earliestAvailableIndex = -1;
    string currentTime = ""; // Assuming this holds the current time

    for (size_t i = 0; i < boats.size(); ++i) {
        if (boats[i].isAvailable) {
            if (boats[i].returnTime.empty()) {
                earliestAvailableIndex = i;
                break;
            } else if (boats[i].returnTime < currentTime) {
                earliestAvailableIndex = i;
                currentTime = boats[i].returnTime;
            }
        }
    }

    if (earliestAvailableIndex != -1) {
        cout << "Next available boat: Boat " << boats[earliestAvailableIndex].boatNumber << endl;
    } else {
        cout << "No boats are currently available." << endl;
    }
}


// Function to calculate money taken for all boats at the end of the day
void calculateTotalMoneyTaken(const vector<Boat> &boats) {
    float totalMoney = 0.0;
    int totalHours = 0;
    int unusedBoats = 0;
    int maxUsedBoatNumber = -1;
    int maxUsedHours = 0;

    for (size_t i = 0; i < boats.size(); ++i) {
        totalMoney += boats[i].moneyTaken;
        totalHours += boats[i].totalHours;

        if (boats[i].totalHours == 0) {
            unusedBoats++;
        }

        if (boats[i].totalHours > maxUsedHours) {
            maxUsedHours = boats[i].totalHours;
            maxUsedBoatNumber = boats[i].boatNumber;
        }
    }

    cout << "Total money taken for all boats today: $" << totalMoney << endl;
    cout << "Total hours boats were hired today: " << totalHours << " hours" << endl;
    cout << "Number of boats not used today: " << unusedBoats << endl;
    cout << "Boat used the most: Boat " << maxUsedBoatNumber << " with " << maxUsedHours << " hours" << endl;
}

int main() {
    vector<Boat> boats;

    // Initialize boat information
    for (int i = 1; i <= 10; ++i) {
        Boat boat;
        boat.boatNumber = i;
        boat.isAvailable = true;
        boat.totalHours = 0;
        boat.moneyTaken = 0.0;
        boat.returnTime = "";

        boats.push_back(boat);
    }

    // Perform tasks
    // Task 1 - Calculate the money taken for one boat
    int boatNumber;
    cout << "Enter boat number to calculate daily profit: ";
    cin >> boatNumber;

    calculateDailyProfitForOneBoat(boats[boatNumber - 1]);

    // Task 2 - Find the next boat available
    findNextAvailableBoat(boats);

    // Task 3 - Calculate the money taken for all the boats at the end of the day
    calculateTotalMoneyTaken(boats);

    return 0;
}

