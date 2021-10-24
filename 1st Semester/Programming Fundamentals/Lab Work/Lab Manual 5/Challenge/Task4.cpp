#include <iostream>
using namespace std;
int main()
{
	int i;
	char input[11];
	bool flag = false;

	cout << "Enter Registration Number: ";
	cin >> input;

	if (input[0] == '2' && input[1] == '0' && input[4] == '-' && input[5] == 'C' && input[6] == 'S' && input[7] == '-'){
		if (input[2] == '1' || input[2] == '2'){
			if (input[3] >= 54 && input[3] <= 57 || input[3] == '0'){
				for (i = 8; i < 11; i++){
					if (input[i] >= 48 && input[i] <= 57){
						flag = true;
					}
				}
			}
		}
	}
	if (flag == true)
		cout << "Valid Registration Number";
	else
		cout << "Invalid Registration Number";

	return 0;
}