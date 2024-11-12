#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>


using namespace std;

#include "ATCSystem.h"
#include "Aircraft.h"

void startSystem(string inputOption){
	ifstream inputFile;
	string filePath;
	vector<Aircraft> aircraftList;

	filePath = "/data/home/qnxuser/Low.txt";
	inputFile.open(filePath);

	if (!inputFile) {
		cerr << "Error opening file: " << filePath << endl;
	} else {
		cout << "File " << filePath << " opened successfully." << endl;

		// Parse each line of the file
		string line;
		while (getline(inputFile, line)) {
			stringstream ss(line);
			int entryTime, id;
			float x, y, z, speedX, speedY, speedZ;
			char comma;

			// Read values from the line separated by commas
			if (ss >> entryTime >> comma >> id >> comma >> x >> comma >> y >> comma
				>> z >> comma >> speedX >> comma >> speedY >> comma >> speedZ) {

				// Construct an Aircraft object and add it to the vector
				Aircraft aircraft(entryTime, id, x, y, z, speedX, speedY, speedZ);
				aircraftList.push_back(aircraft);
			} else {
				cerr << "Error parsing line: " << line << endl;
			}
		}

		cout << "Parsed " << aircraftList.size() << " aircraft entries." << endl;
	}
	inputFile.close();
}

int main() {

	// Will have to parse the text file here and file in the the list of
	// aircrafts then construct the aircraft class with this list
	// use pThread library to manage priorities

	string inputOption;


	cout << "\tWelcome to our ATC System" << endl;
	cout << "Choose your flight density to simulate." << endl;
	cout << "(Low, Medium, High, Congested)" << endl;

	do{
		cout << "Enter here: ";
		cin >> inputOption;
	}while(inputOption != "Low" && inputOption != "Medium" && inputOption != "High" && inputOption != "Congested");

	startSystem(inputOption);

	return 0;
}



