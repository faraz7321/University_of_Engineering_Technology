#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

void addData(char &ticketType, int &row, char &column); //To add Data from User.//
void asterisk(char map[][6]);							// This Function Prints Asterisks in map(below function).//
void Map(char map[][6], int row, char column);			//Final output in a form of map of airplane.//
int main()
{
	char ch, ticketType, column;
	int row;
	string terminate; //Terminator for loop.//
	char map[13][6];
	asterisk(map);
	do
	{
		addData(ticketType, row, column);
		Map(map, row, column);
		cout << "Enter any key to continue or enter '-1' to terminate.\n";
		cin >> terminate;
	} while (terminate != "-1");

	return 0;
}
void addData(char &ticketType, int &row, char &column)
{
	char columnIn;
	int rowIn;
	cout << "The airplane has 13 rows, with  six seats in each row. \n"
		 << "Enter Ticket Type:\n"
		 << "> F for First Class\n"
		 << "> B for Business Class\n"
		 << "> E for Economy Class\n";
	cin >> ticketType;
	while (ticketType != 'F' && ticketType != 'B' && ticketType && ticketType != 'E' && ticketType != 'f' && ticketType != 'b' && ticketType && ticketType != 'e')
	{
		cout << "INVALID TICKET TYPE! Please Try again.\n\n";
		cout << "Enter Ticket Type:\n"
			 << "F for First class\n"
			 << "B for Business class\n"
			 << "E for Economy class\n";
		cin >> ticketType;
	}
	switch (ticketType)
	{
		{
		case 'F':
		case 'f':
			do
			{
				cout << "Row '1' and '2' are First Class,\n";
				cout << "Enter row number: ";
				cin >> rowIn;
				if (rowIn >= 1 && rowIn <= 2)
				{
					row = rowIn;
					cout << "Enter desired seat location from 'A' to 'F'. \n";
					cin >> columnIn;
					if ((columnIn >= 'A' && columnIn <= 'F') || (columnIn >= 'a' && columnIn <= 'f'))
					{
						column = columnIn;
						column = static_cast<char>(toupper(column));
						break;
					}
					else
					{
						cout << "INVALID COLUMN SELECTED! Please try again.\n\n";
					}
				}
				else
				{
					cout << "INVALID ROW SELECTION! Please try agian.\n\n";
				}
			} while (column);
			break;
		}

		{
		case 'B':
		case 'b':
			do
			{
				cout << "Row '3' to '7' are Business Class,\n";
				cout << "Enter row number: ";
				cin >> rowIn;
				if (rowIn >= 3 && rowIn <= 7)
				{
					row = rowIn;
					cout << "Enter desired seat location from 'A' to 'F'. \n";
					cin >> columnIn;
					if ((columnIn >= 'A' && columnIn <= 'F') || (columnIn >= 'a' && columnIn <= 'f'))
					{
						column = columnIn;
						column = static_cast<char>(toupper(column));
						break;
					}
					else
					{
						cout << "INVALID COLUMN SELECTED! Please try again.\n\n";
					}
					
				}
				else
				{
					cout << "INVALID ROW SELECTION! Please try agian.\n\n";
				}
			} while (column);
			break;
		}

		{
		case 'E':
		case 'e':
			do
			{
				cout << "Row '8' to '13' are Economy Class.\n";
				cout << "Enter row number: ";
				cin >> rowIn;
				if (rowIn >= 8 && rowIn <= 13)
				{
					row = rowIn;
					cout << "Enter desired seat location from 'A' to 'F'. \n";
					cin >> columnIn;
					if ((columnIn >= 'A' && columnIn <= 'F') || (columnIn >= 'a' && columnIn <= 'f'))
					{
						column = columnIn;
						column = static_cast<char>(toupper(column));
						break;
					}
					else
					{
						cout << "INVALID COLUMN SELECTED! Please try again.\n\n";
					}
				}
				else
				{
					cout << "INVALID ROW SELECTION! Please try agian.\n\n";
				}
			} while (column);
			break;
		}

	} //Switch case ends here.//
}
void Map(char map[][6], int row, char column)
{
	if (map[row - 1][static_cast<int>(column - 65)] == 'X')
	{
		cout << "This seat already occupied. Please choose another seat: \n";
		cin >> column;
		column = static_cast<char>(toupper(column)); // Lowercase letter to uppercase letter function. <cctype>.//
	}
	map[row - 1][static_cast<int>(column) - 65] = 'X'; //Replacing '*' with 'X'.//

	cout << "* Indicates that the seat is available; \n"
		 << "X Indicates that the seat is occupied. \n"
		 << setw(12) << "A" << setw(6) << "B" << setw(6) << "C" << setw(6) << "D" << setw(6) << "E" << setw(8) << "F\n\n";

	for (int i = 0; i < 13; i++)
	{
		cout << left << setw(3) << "Row " << setw(2) << i + 1;
		for (int j = 0; j < 6; j++)
		{
			cout << right << setw(6) << map[i][j];
		}
		cout << endl;
	}
}
void asterisk(char map[][6])
{
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			map[i][j] = '*';
		}
	}
}