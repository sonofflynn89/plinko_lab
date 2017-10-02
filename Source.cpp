#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <math.h>
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
	const int PATH_DECIMAL_PLACES = 1;
	const int WINNING_DECIMAL_PLACES = 2;
	const int RAND_SEED = 42;
	const int RAND_RANGE = 2;
	const int NUM_PEGS = 12;
	const int LEFT_OPTION = 0;
	const int RIGHT_OPTION = 1;
	const double MIN_SLOT = 0.0;
	const double MAX_SLOT = 8.0;
	const double MOVE_LEFT = -0.5;
	const double MOVE_RIGHT = 0.5;
	double positionChip = 0.0;
	double singleWinnings = 0.0;
	double totalWinnings = 0.0;
	const double TOTAL_WINNINGS_RESET = 0.0;
	double averageWinnings = 0.0;

	const double FLOAT_EPSILON = 0.0001;
	const double WINNINGS_POS_0 = 100;
	const double WINNINGS_POS_1 = 500;
	const double WINNINGS_POS_2 = 1000;
	const double WINNINGS_POS_3 = 0;
	const double WINNINGS_POS_4 = 10000;
	const double WINNINGS_POS_5 = 0;
	const double WINNINGS_POS_6 = 1000;
	const double WINNINGS_POS_7 = 500;
	const double WINNINGS_POS_8 = 100;
	double finalPosition = 0.0;


	cout << "Welcome to the Plinko simulator!  Enter 3 to see options." << endl << endl;
	cout << "Enter your selection now: ";
	cin >> userInput;
	cout << endl;

	while (userInput != quit) {

		srand(RAND_SEED);

		if (userInput == dropSingle) {
			cout << "*** Drop a single chip ***" << endl << endl;
			cout << "Which slot do you want to drop the chip in (0-8)? ";
			cin >> slotNumber;
			if ((slotNumber >= MIN_SLOT) && (slotNumber <= MAX_SLOT)) {
				cout << endl << "*** Dropping chip into slot " << slotNumber << " ***" << endl;
				cout << "Path: [" << fixed << setprecision(PATH_DECIMAL_PLACES) << static_cast<double>(slotNumber);
				positionChip = static_cast<double>(slotNumber);
				for (int i = 1; i <= NUM_PEGS; ++i) {
					pathDirection = rand() % RAND_RANGE;
					if (fabs(positionChip - MIN_SLOT) <= FLOAT_EPSILON) {
						positionChip = positionChip + MOVE_RIGHT;
					}
					else if (fabs(positionChip - MAX_SLOT) <= FLOAT_EPSILON) {
						positionChip = positionChip + MOVE_LEFT;
					}
					else if (pathDirection == LEFT_OPTION) {
						positionChip = positionChip + MOVE_LEFT;
					}
					else {
						positionChip = positionChip + MOVE_RIGHT;
					}
					cout << ", " << positionChip;
				}
				finalPosition = positionChip;
				if ((static_cast<int>(finalPosition) == 0) || (static_cast<int>(finalPosition) == 8)) {
					singleWinnings = WINNINGS_POS_0;
				}
				else if ((static_cast<int>(finalPosition) == 1) || (static_cast<int>(finalPosition) == 7)) {
					singleWinnings = WINNINGS_POS_1;
				}
				else if ((static_cast<int>(finalPosition) == 2) || (static_cast<int>(finalPosition) == 6)) {
					singleWinnings = WINNINGS_POS_2;
				}
				else if ((static_cast<int>(finalPosition) == 3) || (static_cast<int>(finalPosition) == 5)) {
					singleWinnings = WINNINGS_POS_3;
				}
				else if (static_cast<int>(finalPosition) == 4) {
					singleWinnings = WINNINGS_POS_4;
				}
				cout << "]" << endl;
				cout << "Winnings: $" << fixed << setprecision(WINNING_DECIMAL_PLACES) << singleWinnings << endl << endl;
			}
			else {
				cout << "Invalid slot." << endl << endl;
			}				
		}

			
		

	else if (userInput == dropMultiple) {
		cout << "*** Drop multiple chips ***" << endl << endl;
		cout << "How many chips do you want to drop (>0)? ";
		cin >> numChips;
		cout << endl;

		if (numChips <= 0) {
			cout << "Invalid number of chips." << endl << endl;
		}
		else {
			cout << "Which slot do you want to drop the chip in (0-8)? ";
			cin >> slotNumber;
			cout << endl;
			if ((slotNumber >= MIN_SLOT) && (slotNumber <= MAX_SLOT)) {
				for (int i = 1; i <= numChips; ++i) {
					for (int j = 1; j <= NUM_PEGS; ++j) {
						pathDirection = rand() % RAND_RANGE;
						if (fabs(positionChip - MIN_SLOT) <= FLOAT_EPSILON) {
							positionChip = positionChip + MOVE_RIGHT;
						}
						else if (fabs(positionChip - MAX_SLOT) <= FLOAT_EPSILON) {
							positionChip = positionChip + MOVE_LEFT;
						}
						else if (pathDirection == LEFT_OPTION) {
							positionChip = positionChip + MOVE_LEFT;
						}
						else {
							positionChip = positionChip + MOVE_RIGHT;
						}

						if ((static_cast<int>(finalPosition) == 0) || (static_cast<int>(finalPosition) == 8)) {
							singleWinnings = WINNINGS_POS_0;
						}
						else if ((static_cast<int>(finalPosition) == 1) || (static_cast<int>(finalPosition) == 7)) {
							singleWinnings = WINNINGS_POS_1;
						}
						else if ((static_cast<int>(finalPosition) == 2) || (static_cast<int>(finalPosition) == 6)) {
							singleWinnings = WINNINGS_POS_2;
						}
						else if ((static_cast<int>(finalPosition) == 3) || (static_cast<int>(finalPosition) == 5)) {
							singleWinnings = WINNINGS_POS_3;
						}
						else if (static_cast<int>(finalPosition) == 4) {
							singleWinnings = WINNINGS_POS_4;
						}
						totalWinnings = totalWinnings + singleWinnings;
					}
				}
				cout << fixed << setprecision(WINNING_DECIMAL_PLACES) << "Total winnings on " << numChips << " chips: $" << totalWinnings << endl;
				averageWinnings = totalWinnings / numChips;
				cout << fixed << setprecision(WINNING_DECIMAL_PLACES) << "Average winnings per chip: $" << averageWinnings << endl << endl;
				totalWinnings = TOTAL_WINNINGS_RESET;
			}
			else {
				cout << "Invalid slot." << endl << endl;
			}
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
			cout << "Invalid selection. Enter 3 to see options." << endl << endl;
		}
		cout << "Enter your selection now: ";
		cin >> userInput;
		cout << endl;
	}
	cout << "Goodbye!" << endl;

	system("pause");
	return 0;
}