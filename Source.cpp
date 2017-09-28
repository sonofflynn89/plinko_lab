#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main() {
	int dropSingle = 1;
	int dropMultiple = 2;
	int showOptions = 3;
	int quit = 4;
	int userInput = 0;
	int slotNumber = 0;
	int pathDirection = 0;
	int numChips = 0;
	const int pathDecimalPlaces = 1;
	const int MIN_SLOT = 0;
	const int MAX_SLOT = 8;
	const int RAND_SEED = 42;
	const int RAND_RANGE = 2;
	const int NUM_PEGS = 12;
	const int LEFT_OPTION = 0;
	const int RIGHT_OPTION = 1;
	const double MOVE_LEFT = -0.5;
	const double MOVE_RIGHT = 0.5;
	double positionChip = 0.0;
	double totalWinning = 0.0;
	double averageWinnings = 0.0;

	const double WINNINGS_POS_0 = 100;
	const double WINNINGS_POS_1 = 500;
	const double WINNINGS_POS_2 = 1000;
	const double WINNINGS_POS_3 = 0;
	const double WINNINGS_POS_4 = 10000;
	const double WINNINGS_POS_5 = 0;
	const double WINNINGS_POS_6 = 1000;
	const double WINNINGS_POS_7 = 500;
	const double WINNINGS_POS_8 = 100;
	

	srand(RAND_SEED);

	cout << "Welcome to the Plinko simulator!  Enter 3 to see options." << endl << endl;
	cout << "Enter your selection now:" << endl;
	cin >> userInput;




	while (userInput != quit) {
		
		if (userInput == dropSingle) {
			cout << "*** Drop a single chip ***" << endl << endl;
			cout << "Which slot do you want to drop the chip in (0-8)? ";
			cin >> slotNumber;
			if ((slotNumber >= MIN_SLOT) && (slotNumber <= MAX_SLOT)) {
				cout << endl << endl << "*** Dropping chip into slot " << slotNumber << " ***" << endl;
				cout << "Path: [" << fixed << setprecision(pathDecimalPlaces) << static_cast<double>(slotNumber);
				positionChip = static_cast<double>(slotNumber);
				for (int i = 1; i <= NUM_PEGS; ++i) {
					pathDirection = rand() % RAND_RANGE;
					if (pathDirection == LEFT_OPTION) {
						positionChip = positionChip + MOVE_LEFT;
					}
					else {
						positionChip = positionChip + MOVE_RIGHT;
					}
					cout << ", " << positionChip;
				}
				cout << "]" << endl;
				cout << "Winnings: $" << winnings <<endl;

			}
			else {
				cout << "Invalid slot." << endl << endl;
			}

		}
		else if (userInput == showOptions) {
			cout << "Menu: Please select one of the following options:" << endl << endl;
			cout << "1 - Drop a single chip into one slot" << endl;
			cout << "2 - Drop multiple chips into one slot" << endl;
			cout << "3 - Show the options menu" << endl;
			cout << "4 - Quit the program" << endl << endl;			
		}
		else {
			cout << "Invalid selection. Enter 3 to see options." << endl;
		}
		cout << "Enter your selection now:" << endl;
		cin >> userInput;
	}


	system("pause");
	return 0;
}