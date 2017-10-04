/* 
Nathaniel Neubert, Caleb Pomar, Section 3, nathanielneubert@gmail.com, cpsharksfan@gmail.com
We used proper pair programming.
Description: This program simulates the running of a Plinko board. Users select one
of four options in order to determine if they want to drop a single chip (1), drop
multiple chips (2), show menu options (3), or quit (4). If the user selects to drop
a single chip he then chooses a slot and the program outputs both the path of the 
chip and the winnings for the chip. If the user selects to drop multiple chips then
he has the option to select how many chips he wishes to drop and into which slot he
wishes to drop them. The program then calculates the total winnings and the average
winnings. If the user selects to show menu options it will display the options. By
selecting quit the program will exit.

Test Case #1
Input: The following test case is a stream of inputs which tests the possible
erroneous input situations: -5, 6, 0, 5, -1, 1, 9, 2, -1, 3, 2, 3, 9, 4
Expected output: Each of the inputs is meant to end in a set error mesage 
which will set the loop to begin again asking for the user to choose a new
menu option.
Result: Passed

Test Case #2
Input: (using fixed seed of 42) 1, 5, 1, 0, 1, 8, 4
Expected output:
[5.0, 5.5, 5.0, 5.5, 5.0, 5.5, 6.0, 5.5, 5.0, 5.5, 6.0, 6.5, 6.0] Winnings $1000.00
[0.0, 0.5, 1.0, 1.5, 1.0, 1.5, 1.0, 0.5, 1.0, 0.5, 1.0, O.5, 0.0] Winnings $100.00
[8.0, 7.5, 8.0, 7.5, 7.0, 6.5, 6.0, 6.5, 7.0, 7.5, 7.0, 7.5, 7.0] Winnings $500.00
Result: Passed

Test Case #3
Input: (using a fixed seed of 42) 2, 7, 6
Expected output:
Total winnings on 7 chips: $ 4100.00
Average winnings per chip : $585.71
Result: Passed

*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {

	const int DROP_SINGLE = 1;
	const int DROP_MULTIPLE = 2;
	const int SHOW_OPTIONS = 3;
	const int QUIT = 4;

	int userInput = 0;
	int slotNumber = 0;
	int pathDirection = 0;
	int numChips = 0;

	double finalPosition = 0.0;
	double positionChip = 0.0;
	double singleWinnings = 0.0;
	double totalWinnings = 0.0;
	double averageWinnings = 0.0;

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
	const double FLOAT_EPSILON = 0.0001;
	const double WINNINGS_SMALL = 100;
	const double WINNINGS_MEDIUM = 500;
	const double WINNINGS_LARGE = 1000;
	const double WINNINGS_FAILURE = 0;
	const double WINNINGS_JACKPOT = 10000;
	const double TOTAL_WINNINGS_RESET = 0.0;

	srand(RAND_SEED);

	cout << "Welcome to the Plinko simulator!  Enter 3 to see options." <<endl << endl;
	cout << "Enter your selection now: ";
	cin >> userInput;
	cout << endl;

	while (userInput != QUIT) {

		if (userInput == DROP_SINGLE) {
			cout << "*** Drop a single chip ***" << endl << endl;
			cout << "Which slot do you want to drop the chip in (0-8)? ";
			cin >> slotNumber;
			if ((slotNumber >= MIN_SLOT) && (slotNumber <= MAX_SLOT)) {
				cout << endl << "*** Dropping chip into slot " << slotNumber << " ***" << endl;
				cout << "Path: [" << fixed << setprecision(PATH_DECIMAL_PLACES) << static_cast<double>(slotNumber);
				positionChip = static_cast<double>(slotNumber);
				for (int i = 1; i <= NUM_PEGS; ++i) {
					if ((fabs(positionChip - MIN_SLOT) <= FLOAT_EPSILON) ||
						(fabs(positionChip - MAX_SLOT) <= FLOAT_EPSILON)) {
						if (fabs(positionChip - MIN_SLOT) <= FLOAT_EPSILON) {
							positionChip = positionChip + MOVE_RIGHT;
						}
						else if (fabs(positionChip - MAX_SLOT) <= FLOAT_EPSILON) {
							positionChip = positionChip + MOVE_LEFT;
						}
					}
					else {
						pathDirection = rand() % RAND_RANGE;
						if (pathDirection == LEFT_OPTION) {
							positionChip = positionChip + MOVE_LEFT;
						}
						else if (pathDirection == RIGHT_OPTION) {
							positionChip = positionChip + MOVE_RIGHT;
						}
					}
					cout << ", " << positionChip;
				}
				finalPosition = positionChip;
				if ((static_cast<int>(finalPosition) == 0) ||
					(static_cast<int>(finalPosition) == 8)) {
					singleWinnings = WINNINGS_SMALL;
				}
				else if ((static_cast<int>(finalPosition) == 1) ||
					(static_cast<int>(finalPosition) == 7)) {
					singleWinnings = WINNINGS_MEDIUM;
				}
				else if ((static_cast<int>(finalPosition) == 2) ||
					(static_cast<int>(finalPosition) == 6)) {
					singleWinnings = WINNINGS_LARGE;
				}
				else if ((static_cast<int>(finalPosition) == 3) ||
					(static_cast<int>(finalPosition) == 5)) {
					singleWinnings = WINNINGS_FAILURE;
				}
				else if (static_cast<int>(finalPosition) == 4) {
					singleWinnings = WINNINGS_JACKPOT;
				}
				cout << "]" << endl;
				cout << "Winnings: $" << fixed << setprecision(WINNING_DECIMAL_PLACES)
					<< singleWinnings << endl << endl;
			}
			else {
				cout << "Invalid slot." << endl << endl;
			}
		}




		else if (userInput == DROP_MULTIPLE) {
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
						positionChip = static_cast<double>(slotNumber);
						for (int j = 1; j <= NUM_PEGS; ++j) {
							if ((fabs(positionChip - MIN_SLOT) <= FLOAT_EPSILON) ||
								(fabs(positionChip - MAX_SLOT) <= FLOAT_EPSILON)) {
								if (fabs(positionChip - MIN_SLOT) <= FLOAT_EPSILON) {
									positionChip = positionChip + MOVE_RIGHT;
								}
								else if (fabs(positionChip - MAX_SLOT) <= FLOAT_EPSILON) {
									positionChip = positionChip + MOVE_LEFT;
								}
							}
							else {
								pathDirection = rand() % RAND_RANGE;
								if (pathDirection == LEFT_OPTION) {
									positionChip = positionChip + MOVE_LEFT;
								}
								else if (pathDirection == RIGHT_OPTION) {
									positionChip = positionChip + MOVE_RIGHT;
								}
							}
							finalPosition = positionChip;

							if ((static_cast<int>(finalPosition) == 0) ||
								(static_cast<int>(finalPosition) == 8)) {
								singleWinnings = WINNINGS_SMALL;
							}
							else if ((static_cast<int>(finalPosition) == 1) ||
								(static_cast<int>(finalPosition) == 7)) {
								singleWinnings = WINNINGS_MEDIUM;
							}
							else if ((static_cast<int>(finalPosition) == 2) ||
								(static_cast<int>(finalPosition) == 6)) {
								singleWinnings = WINNINGS_LARGE;
							}
							else if ((static_cast<int>(finalPosition) == 3) ||
								(static_cast<int>(finalPosition) == 5)) {
								singleWinnings = WINNINGS_FAILURE;
							}
							else if (static_cast<int>(finalPosition) == 4) {
								singleWinnings = WINNINGS_JACKPOT;
							}
						}
						totalWinnings = totalWinnings + singleWinnings;
					}
					cout << fixed << setprecision(WINNING_DECIMAL_PLACES) << "Total winnings on "
						<< numChips << " chips: $ " << totalWinnings << endl;
					averageWinnings = totalWinnings / numChips;
					cout << fixed << setprecision(WINNING_DECIMAL_PLACES) << "Average winnings per chip : $"
						<< averageWinnings << endl << endl;
					totalWinnings = TOTAL_WINNINGS_RESET;
				}
				else {
					cout << "Invalid slot." << endl << endl;
				}
			}
		}

		else if (userInput == SHOW_OPTIONS) {
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
