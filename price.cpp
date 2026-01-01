#include <iostream>
#include <unordered_map>
#include <vector>
#include <iomanip>

using namespace std;

//calculating fare 
double calculateFare(double distance, double time, double surge) {
    double baseFare = 50;
    double perKm = 10;
    double perMin = 2;

    double fare = baseFare + (distance * perKm) + (time * perMin);
    fare = fare * surge;

    return fare;
}

int main() {

    // some sample ride requests
    vector<string> locations;
    locations.push_back("Delhi");
    locations.push_back("Pilani");
    locations.push_back("Delhi");
    locations.push_back("Mumbai");
    locations.push_back("Delhi");
    locations.push_back("Pilani");
    locations.push_back("Delhi");

    // Counting demand for each location
    unordered_map<string, int> demandCount;

    for (int i = 0; i < locations.size(); i++) {
        demandCount[locations[i]]++;
    }

    // Taking user input
    string pickupLocation;
    double distance, time;

    cout << "Enter pickup location: ";
    cin >> pickupLocation;

    cout << "Enter distance travelled (in km): ";
    cin >> distance;

    cout << "Enter ride time (in minutes): ";
    cin >> time;

    //Deciding surge pricing
    double surgeMultiplier = 1.0;

    if (demandCount[pickupLocation] >= 3) {
        surgeMultiplier = 1.5;
        cout << "\nHigh demand area detected (HOTSPOT)\n";
    } else {
        cout << "\nNormal demand area\n";
    }

    // Calculating final fare
    double finalFare = calculateFare(distance, time, surgeMultiplier);

    
    cout << "\nRide Fare Summary \n";
    cout << "Location: " << pickupLocation << endl;
    cout << "Surge Multiplier: " << surgeMultiplier << endl;
    cout << "Final Fare: ₹" << fixed << setprecision(2) << finalFare << endl;

    return 0;
}
