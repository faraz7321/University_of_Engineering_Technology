#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
//#include <boost\lexical.hpp>
#define _CRT_NONSTDC_NO_WARNINGS
#define MAX_ITEMS 1024
#define MAX_USERS 1024
#define MAX_EMPLOYEE 3
using namespace std;

///////////////////////////////////////////////////////////      MENU FUNCTIONS.     ///////////////////////////////////////////////////////////////////////////////////////////////////

void welcome();
void adminMenu();
void companyMenu();
void employeeMenu();
void userMenu();
void invalid();
void exit();
void hold();

///////////////////////////////////////////////////////////      LOGIN FUNCTIONS.      /////////////////////////////////////////////////////////////////////////////////////////////////

void login(string &username, string &password);
void logout();
void loginfail();
bool userExist(string user[], string pass[], string users, string passs);
bool E_userExist(string user[], string pass[], string users, string passs);
bool loadUser(string usersList[], string passwordList[]);
bool loadEmployeeUser(string employeeCode[], string employeePass[]);
bool saveEmployeeUser(string employeeCode[], string employeePass[]);
bool userSaveShopping(string userItemsList[], int userQuantityList[], double userPriceList[], double userTotal, string phone, string address);

////////////////////////////////////////////////////////////     ADMIN FUNCTIONS.     //////////////////////////////////////////////////////////////////////////////////////////////////

bool addEmployee(string employeeCode[], string employeePass[], string empCode, string empPass);
bool updateEmployee(string employeeCode[], string employeePass[], string empCode, string empPass);
bool deleteEmp(string employeeCode[], string employeePass[], string empCode, string empPass);
void viewEmployee(string employeeCode[], string employeePass[]);
void print(double sale, double purchase);

///////////////////////////////////////////////////////////     EMPLOYEE FUNCTIONS.     ////////////////////////////////////////////////////////////////////////////////////////////////

bool addItem(string itemList[], int barcodeList[], int quantityList[], double costList[], double priceList[], string itemName, int barcode, int quantity, double cost, double price);
bool updateItem(string itemList[], int barcodeList[], int quantityList[], double costList[], double priceList[], string itemName, int barcode, int quantity, double cost, double price);
bool deleteItem(string itemList[], int barcodeList[], int quantityList[], double costList[], double priceList[], string itemName, int barcode, int quantity, double cost, double price);
void viewItemsWithStock(string itemList[], int barcodeList[], int quantityList[], double costList[], double priceList[]);
void viewItemsWithBarcode(string itemList[], int barcodeList[], int quantityList[], double costList[], double priceList[]);
void searchItem(string itemList[], int barcodeList[], int quantityList[], string itemName);
void initializeItems(string itemList[], int barcodeList[], int quantityList[], double costList[], double priceList[]);
bool saveItems(string itemList[], int barcodeList[], int quantityList[], double costList[], double priceList[]);
bool loadItems(string itemList[], int barcodeList[], int quantityList[], double costList[], double priceList[]);
void initializeUserItems(string userItemsList[], int userQuantityList[], double userPriceList[], double userTotal);

//////////////////////////////////////////////////////////////     USER FUNCTIONS.     /////////////////////////////////////////////////////////////////////////////////////////////////

bool registerUser(char phone[], char address[]);
void userSearchItem(string itemList[], int quantityList[], double costList[], double priceList[], string itemName); ////////////////////////////////////////////////////
void userItemList(string itemList[], int barcodeList[], int quantityList[], double costList[], double priceList[], string itemName, double userTotal, string userItemsList[], int userQuantityList[], double userPriceList[]);
void viewAllItems(string itemList[], int quantityList[], double costList[], double priceList[], string itemName, double userTotal); ////////////////////////////////////////////////////
void viewCart(string userItemsList[], int userQuantityList[], double userPriceList[], double userTotal);

///////////////////////////////////////////////////////////////     VALIDATORS.     ////////////////////////////////////////////////////////////////////////////////////////////////////

bool isValidPhoneNumber(char phone[]);
bool isValidEmpCode(string empCode);
bool isValidItemName(string itemName);
bool isValidBarcode(int barcode);
bool isValidQuantity(int quantity);
bool isValidPrice(double cost, double price);
int searchEmployeeCode(string employeeCode[], string empCode);
int searchItemName(string itemList[], string itemName);

int main()
{
	//Options For Switch Cases'.'//
	char option1, option2, option3, option4, option5, input;

	//FOR LOGIN.//
	string username, password;
	string usersList[MAX_USERS], passwordList[MAX_USERS];
	string employeeCode[MAX_EMPLOYEE], employeePass[MAX_EMPLOYEE];

	//VARIABLES FOR ADMIN USE.//
	string empCode, empPass;
	double totalPurchases = 0, totalSales = 0;

	//VARIABLES FOR EMPLOYEE USE.//
	string itemList[MAX_ITEMS];
	string itemName;
	double costList[MAX_ITEMS], priceList[MAX_ITEMS];
	double cost, price;
	int barcodeList[MAX_ITEMS], quantityList[MAX_ITEMS];
	int barcode, quantity;

	//VARIABLES FOR USER.//
	int CURRENT_USER = 1, i;
	string userItemsList[MAX_ITEMS];
	double userTotal = 0.0;
	int userQuantityList[MAX_ITEMS];
	double userPriceList[MAX_ITEMS];
	char phone[11], address[100];

	//INITIALIZATION.//
	loadUser(usersList, passwordList);
	loadEmployeeUser(employeeCode, employeePass);
	initializeItems(itemList, barcodeList, quantityList, costList, priceList);
	initializeUserItems(userItemsList, userQuantityList, userPriceList, userTotal);
	loadItems(itemList, barcodeList, quantityList, costList, priceList);

	do
	{
	mainmenu:
		welcome();
		cin >> option1;
		switch (option1) //Switch 1 for Welcome Menu//
		{
		case '1':
		{
			companyMenu();
			cin >> option2;
			switch (option2) //Switch 2 for Company Menu.//
			{
				//ADMIN ACCESS.//
			case '1':
			{
			adminlogin:
				login(username, password);
				if (username == "a" && password == "a")
				{
					do
					{
					adminmenu:
						adminMenu();
						cin >> option3;
						cout << endl;
						switch (option3) //Switch 3 for Admin Menu.//
						{
							//Add Employee detail.//
						case '1':
						{
							cout << "Enter Employee Code: ";
							cin >> empCode;
							cout << "Enter Employee Pass: ";
							cin >> empPass;
							if (isValidEmpCode(empCode) == false)
							{
								cout << "\nError! Invalid Employee Code\n";
								hold();
							}
							else
							{
								addEmployee(employeeCode, employeePass, empCode, empPass);
								if (true)
								{
									cout << "Employee Has Been Added Successfully!\n";
									hold();
								}
								else
								{
									cout << "Error Adding Employee!\n";
									hold();
								}
							}
							break;
						}
						//Update employee details.//
						case '2':
						{
							cout << "Enter Employee Code To Update: ";
							cin >> empCode;
							//Validate the Employee Code
							if (isValidEmpCode(empCode))
							{
								//call function to delete the Employee detail which has same Employee code as user enter
								if (searchEmployeeCode(employeeCode, empCode) != -1)
								{
								add:
									cout << "Enter New Employee Code: ";
									cin >> empCode;
									if (false)
									{
										cout << "Invalid Employee Code!\n";
										hold();
										goto add;
									}
									else
									{
										cout << "Enter New Employee Password: ";
										cin >> empPass;
										updateEmployee(employeeCode, employeePass, empCode, empPass);
										if (true)
										{
											cout << "Employee Updated Successfully!\n";
											hold();
										}
										else
										{
											cout << "Error Adding Employee\n";
											hold();
										}
									}
								}
								else
								{
									cout << "Sorry No Employee found!\n";
									hold();
								}
							}
							else
							{
								//if Employee code is invalid then this message will show
								cout << "Invalid Employee Code!\n";
								hold();
							}
							break;
						}
						//Delete employee details.//
						case '3':
						{
							cout << "Enter Employee Code To Delete\n";
							cin >> empCode;
							//Validate the Employee Code
							if (isValidEmpCode(empCode))
							{
								//call function to delete the Employee detail which has same Employee code as user enter
								if (true)
								{
									cout << "Employee Deleted Successfully!\n";
									hold();
								}
								else
								{
									cout << "Sorry No Employee found!\n";
									hold();
								}
							}
							else
							{
								//if Employee code is invalid then this message will show
								cout << "Invalid Employee Code!\n";
								hold();
							}
							break;
						}
						//View Employee Details.//
						case '4':
						{
							viewEmployee(employeeCode, employeePass);
							hold();
							break;
						}
						//Print balance sheet.//
						case '5':
						{
							i = 0;
							while (i != MAX_ITEMS)
							{
								if (userPriceList[i] != -1)
								{
									totalPurchases = totalPurchases + (costList[i] * userQuantityList[i]);
								}
								i++;
							}

							i = 0;
							while (i != MAX_ITEMS)
							{
								if (userPriceList[i] != -1)
								{
									totalSales = totalSales + (userPriceList[i] * userQuantityList[i]);
								}
								i++;
							}
							print(totalSales, totalPurchases);
							cout << "Sheet Printed Successfully!";
							hold();
							break;
						}
						//Logout of the System.//
						case '6':
						{
							if (saveEmployeeUser(employeeCode, employeePass))
							{
								cout << "Data saved successfully!";
								logout();
							}
							else
							{
								cout << "All data you entered is lost due to some error" << endl;
								hold();
							}
							username = "";
							password = "";
							goto mainmenu;
							break;
						}
						//Exit program.//
						case '7':
						{
							if (saveEmployeeUser(employeeCode, employeePass))
							{
								cout << "Data saved successfully!";
							}
							else
							{
								cout << "All data you entered is lost due to some error" << endl;
								hold();
							}
							exit();
							return 0;
							break;
						}
						default:
						{
							invalid();
							goto adminmenu;
							break;
						}
						} //End OF Switch 3.//
					} while (option2 != 7);
				}
				else
				{
					loginfail();
				repeat1:
					cout << "Try again? (Y/N): ";
					cin >> input;
					if (input == 'n' || input == 'N')
					{
						goto mainmenu;
					}
					else if (input == 'y' || input == 'Y')
					{
						goto adminlogin;
					}
					else
					{
						cout << "Invalid choice!";
						getch();
						goto repeat1;
					}
					loginfail();
				}
				break;
			} //End Of Admin Access Case.'/'/

			//EMPLOYEE ACCESS.//
			case '2':
			{
			employeelogin:
				login(username, password);
				if (E_userExist(employeeCode, employeePass, username, password))
				{
					do
					{
						employeeMenu();
						cin >> option4;
						cout << endl;
						switch (option4)
						{
							//Add Item.//
						case '1':
						{
							cout << "Enter Item Name: ";
							cin >> itemName;
							cout << "Enter Barcode, Quantity, Cost and Price of the Product: ";
							cin >> barcode;
							cin >> quantity;
							cin >> cost;
							cin >> price;
							if (true)
							{
								addItem(itemList, barcodeList, quantityList, costList, priceList, itemName, barcode, quantity, cost, price);
								if (addItem(itemList, barcodeList, quantityList, costList, priceList, itemName, barcode, quantity, cost, price) == true)
								{
									cout << "Item Added Successfully!\n";
									hold();
								}
								else
								{
									cout << "Error Adding Item Data!\n";
									hold();
								}
							}
							else
							{
								cout << "Error Adding Item Data!\n";
								hold();
							}
							break;
						}
						//Update Item.//
						case '2':
						{
							cout << "Enter Item Name to Update: ";
							cin >> itemName;
							if (isValidItemName(itemName) == true)
							{
								if (searchItemName(itemList, itemName) != -1)
								{
									cout << "Item Found!\n";
									cout << "Enter Item Name: ";
									cin >> itemName;
									cout << "Enter Barcode, Quantity and Price of the Product: ";
									cin >> barcode;
									cin >> quantity;
									cin >> cost;
									cin >> price;
									if (isValidItemName(itemName) == true && isValidQuantity(quantity) == true && isValidBarcode(barcode) == true && isValidPrice(cost, price) == true)
									{
										addItem(itemList, barcodeList, quantityList, costList, priceList, itemName, barcode, quantity, cost, price);
										if (addItem(itemList, barcodeList, quantityList, costList, priceList, itemName, barcode, quantity, cost, price) == true)
										{
											cout << "Item Updated Successfully!\n";
											hold();
										}
										else
										{
											cout << "Error Updating Item Data!\n";
											hold();
										}
									}
									else
									{
										cout << "Invalid Data!";
										hold();
									}
								}
								else
								{
									cout << "No Item Found With This Name!\n";
									hold();
								}
							}
							else
							{
								cout << "Error! Invalid Item Name.\n";
								hold();
							}
							break;
						}
						//delete Item.//
						case '3':
						{
							cout << "Enter Item To Delete: ";
							cin >> itemName;
							//Validate the Employee Code
							if (isValidItemName(itemName))
							{
								if (deleteItem(itemList, barcodeList, quantityList, costList, priceList, itemName, barcode, quantity, cost, price))
								{
									cout << "Item Deleted Successfully!\n";
									hold();
								}
								else
								{
									cout << "Sorry No Item found!\n";
									hold();
								}
							}
							else
							{
								cout << "Invalid Item Name!\n";
								hold();
							}
							break;
						}
						//View All Items with stock availability.//
						case '4':
						{
							viewItemsWithStock(itemList, barcodeList, quantityList, costList, priceList);
							hold();
							break;
						}
						//View All Items with barcode.//
						case '5':
						{
							viewItemsWithBarcode(itemList, barcodeList, quantityList, costList, priceList);
							hold();
							break;
						}
						//Search an Item according To name.//
						case '6':
						{
							cout << "Enter Item Name: ";
							cin >> itemName;
							if (searchItemName(itemList, itemName) != -1)
							{
								searchItem(itemList, barcodeList, quantityList, itemName);
							}
							break;
						}
						//Search an Item according To barcode.//
						case '7':
						{ /* code */
							break;
						}
						//Logout.//
						case '8':
						{
							if (saveItems(itemList, barcodeList, quantityList, costList, priceList))
							{
								cout << "Data saved successfully!";
								logout();
							}
							else
							{
								cout << "All data you entered is lost due to some error" << endl;
								hold();
							}
							username = "";
							password = "";
							goto mainmenu;
							break;
						}
						//Exit.//
						case '9':
						{
							if (saveItems(itemList, barcodeList, quantityList, costList, priceList))
							{
								exit();
							}
							else
							{
								cout << "All data you entered is lost due to some error" << endl;
								hold();
							}

							return 0;
							break;
						}
						default:
						{
							invalid();
							break;
						}
						}
					} while (option4 != 9);
				}
				else
				{
					loginfail();
				repeat:
					cout << "Try again? (Y/N): ";
					cin >> input;
					if (input == 'n' || input == 'N')
					{
						goto mainmenu;
					}
					else if (input == 'y' || input == 'Y')
					{
						goto employeelogin;
					}
					else
					{
						cout << "Invalid choice!";
						getch();
						goto repeat;
					}
				}
				break;
			} //End Of Employee Access Case.'/'/
			case '3':
			{
				goto mainmenu;
				break;
			}
			default:
			{
				invalid();
				break;
			}
			} //End OF Switch 2.//
			break;
			//End Of Company Access Case.'/'/
		}
		//USER ACCESS.//
		case '2':
		{
		userlogin:
			login(username, password);
			if (userExist(usersList, passwordList, username, password))
			{
				do
				{
					userMenu();
					cin >> option5;
					cout << endl;
					switch (option5)
					{
						//Search and buy a Product.//
					case '1':
					{
						cout << "Enter Product/Item Name to search: ";
						cin.ignore();
						std::getline(cin, itemName);
						userSearchItem(itemList, quantityList, costList, priceList, itemName);
						hold();
						break;
					}
					//buy Product from the list.//
					case '2':
					{

						userItemList(itemList, barcodeList, quantityList, costList, priceList, itemName, userTotal, userItemsList, userQuantityList, userPriceList);

						break;
					}
					//View All Product with their price.//
					case '3':
					{
						viewAllItems(itemList, quantityList, costList, priceList, itemName, userTotal);
						break;
					}
					//view cart and check out.//
					case '4':
					{
						viewCart(userItemsList, userQuantityList, userPriceList, userTotal);
						break;
					}
					//Logout of the System.//
					case '5':
					{
						if (saveItems(itemList, barcodeList, quantityList, costList, priceList))
						{
							logout();
							goto mainmenu;
						}
						else
						{
							cout << "All data you entered is lost due to some error" << endl;
						}

						break;
					}
					//Exit program.//
					case '6':
					{
						if (saveItems(itemList, barcodeList, quantityList, costList, priceList))
						{
							exit();
						}
						else
						{
							cout << "All data you entered is lost due to some error" << endl;
						}
						return 0;
						break;
					}
					default:
					{
						invalid();
						break;
					}
					}
				} while (option5 != 6);
			}
			else
			{
				cout << "No user found with this credentials!\n"
					 << "Do you want to register as new user? (Y/N)";
				cin >> option1;
				if (option1 == 'y' || option1 == 'N')
				{
					goto registeruser;
				}
				else if (option1 == 'N' || option1 == 'n')
				{
					goto userlogin;
				}
				else
				{
					cout << "Invalid Input!";
					hold();
				}
			}
			break;
		} //End Of User Access Case.//
		//Register User.//
		case '3':
		{
		registeruser:
			if (registerUser(phone, address))
			{
				cout << "User registered successfully!";
			}
			else
			{
				cout << "Error while registering new user!";
			}

			break;
		}
		case '4':
		{
			exit();
			return 0;
		}
		default:
		{
			cout << "Invalid Option! Please Try Again\n"
					"Press Any Key To Continue...\n";
			getch();
			break;
		}
		} //End of Switch 1.//
	} while (option1 != 3);

	return 0;
} //End of Main Function.//

///////////////////////////////////////////////////////////      FUNCTIONS     ///////////////////////////////////////////////////////////////////////////

//Initializations.//
void initializeUserItems(string userItemsList[], int userQuantityList[], double userPriceList[], double userTotal)
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		userItemsList[i] = "yo";
		userPriceList[i] = -1;
		userQuantityList[i] = -1;
	}
}
void initializeEmployee(string employeeCode[], string employeePass[])
{
	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		employeeCode[i] = "";
		employeePass[i] = "";
	}
	int i = 0;
}
void initializeItems(string itemList[], int barcodeList[], int quantityList[], double costList[], double priceList[])
{
	int i = 0;
	while (i < MAX_ITEMS)
	{
		itemList[i] = "";
		barcodeList[i] = -1;
		quantityList[i] = -1;
		costList[i] = -1;
		priceList[i] = -1;
		i++;
	}
}
bool saveItems(string itemList[], int barcodeList[], int quantityList[], double costList[], double priceList[])
{
	// This variable for read data from file
	ofstream myfile;
	/*Open the file if exist if not exist then make new file of this name ios::app maens that the new data will append in file and 
	not remove previous content of file */
	myfile.open("itemList.txt");
	//This function will check if the file open then write data from file
	if (myfile.is_open())
	{
		for (int i = 0; i < MAX_ITEMS; i++)
		{
			if (itemList[i] != "" && barcodeList[i] != -1 && quantityList[i] != -1 && priceList[i] != -1)
			{
				//These lines will write all array data to the file and make a comma separated file
				myfile << itemList[i] << ",";
				myfile << barcodeList[i] << ",";
				myfile << quantityList[i] << ",";
				myfile << costList[i] << ",";
				myfile << priceList[i] << endl;
			}
		}
		myfile.close();
		return true;
	}
	else
	{
		//If there is error while opening file this function will return false
		return false;
	}
}
bool loadItems(string itemList[], int barcodeList[], int quantityList[], double costList[], double priceList[])
{
	int i = 0;
	ifstream getItems("itemList.txt");
	if (!getItems.is_open())
	{
		cout << "Item file failed to open" << endl;
		return false;
	}
	else
	{
		string barcode, itemName;
		string quantity, price, cost;
		int bar, quan, pri, cos;
		string line;
		while (!getItems.eof() && i < MAX_ITEMS)
		{
			std::getline(getItems, line);
			if (line == "")
			{
				continue;
			}
			stringstream ss(line);
			std::getline(ss, itemName, ',');
			itemList[i] = itemName;

			std::getline(ss, barcode, ',');
			bar = stoi(barcode);
			barcodeList[i] = bar;

			std::getline(ss, quantity, ',');
			quan = stoi(quantity);
			quantityList[i] = quan;

			std::getline(ss, cost, ',');
			cos = stoi(cost);
			costList[i] = cos;

			std::getline(ss, price, ',');
			pri = stoi(price);
			priceList[i] = pri;
			i++;
		}
		getItems.close();
		return true;
	}
}
bool loadUser(string usersList[], string passwordList[])
{
	int i = 0;
	ifstream getUsers("Users.txt");
	if (!getUsers.is_open())
	{
		cout << "Users file failed to open" << endl;
		return false;
	}
	else
	{
		string username, password;
		string line;
		while (!getUsers.eof() && i < MAX_USERS)
		{
			getline(getUsers, line);
			stringstream ss(line);
			getline(ss, username, ',');
			usersList[i] = username;
			getline(ss, password, ',');
			passwordList[i] = password;
			i++;
		}

		getUsers.close();
		return true;
	}
}
bool saveEmployeeUser(string employeeCode[], string employeePass[])
{
	// This variable for read data from file
	ofstream myfile;
	/*Open the file if exist if not exist then make new file of this name ios::app maens that the new data will append in file and 
	not remove previous content of file */
	myfile.open("Employee.txt");
	//This function will check if the file open then write data from file
	if (myfile.is_open())
	{
		for (int i = 0; i < MAX_EMPLOYEE; i++)
		{
			if (employeePass[i] != "" && employeePass[i] != "")
			{
				//These lines will write all array data to the file and make a comma separated file
				myfile << employeeCode[i] << ",";
				myfile << employeePass[i] << ",";
			}
		}
		myfile.close();
		return true;
	}
	else
	{
		//If there is error while opening file this function will return false
		return false;
	}
}
bool loadEmployeeUser(string employeeCode[], string employeePass[])
{
	int i = 0;
	ifstream getUsers("Employee.txt");
	if (!getUsers.is_open())
	{
		cout << "Employee file failed to open" << endl;
		return false;
	}
	else
	{
		string username, password;
		string line;
		while (!getUsers.eof() && i < MAX_EMPLOYEE)
		{
			getline(getUsers, line);
			stringstream ss(line);
			getline(ss, username, ',');
			employeeCode[i] = username;
			getline(ss, password, ',');
			employeePass[i] = password;
			i++;
		}
		getUsers.close();
		return true;
	}
}

//Validators.//
bool isValidPhoneNumber(char phone[])
{
	bool flag = false;
	for (int i = 0; i < 11; i++)
	{
		if (phone[i] >= '0' && phone[i] <= '9')
		{
			flag = true;
		}
		else
		{
			flag = false;
			break;
		}
	}
	return flag;
}
bool isValidEmpCode(string empCode)
{
	bool flag = false;
	int length = empCode.size();
	if (length == 5)
	{
		for (int i = 0; i < 2; i++)
		{
			if (empCode[0] >= 'A' && empCode[0] <= 'Z' && empCode[1] >= 'A' && empCode[1] <= 'Z')
			{
				flag = true;
			}
			else
			{
				flag = false;
				break;
			}
		}
		for (int i = 2; i < length; i++)
		{
			if (empCode[i] >= '0' && empCode[i] <= '9')
			{
				flag = true;
			}
			else
			{
				flag = false;
				break;
			}
		}
	}
	else
	{
		flag = false;
	}
	return flag;
}
int searchEmployeeCode(string employeeCode[], string empCode)
{
	int index = -1;
	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		if (employeeCode[i] == empCode)
		{
			index = i;
			break;
		}
	}
	return index;
}
int searchItemName(string itemList[], string itemName)
{
	int index = -1;
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (itemList[i] == itemName)
		{
			index = i;
			break;
		}
	}
	return index;
}
bool isValidItemName(string itemName)
{
	bool flag = false;
	return true;
}
bool isValidBarcode(int barcode)
{
	bool flag = false;
	if (barcode >= 1000 && barcode <= 9999)
	{
		flag = true;
	}
	return flag;
}
bool isValidQuantity(int quantity)
{
	bool flag = false;
	if (quantity >= 1 && quantity <= 1000)
	{
		flag = true;
	}
	return flag;
}
bool isValidPrice(double cost, double price)
{
	bool flag = false;
	if (price >= 0.0 && price <= 9999.0 && cost >= 0.0 && cost <= 9999.0)
	{
		flag = true;
	}
	return flag;
}

//Menu Functions.//
void welcome()
{
	system("cls");
	cout << "---------W E L C O M E---------\n\n"
			"Press 1 For Company Access\n"
			"Press 2 For User Access\n"
			"Press 3 to Register New User\n"
			"Press 4 to Exit Program\n\n"
			"Enter Option Number: ";
}
void companyMenu()
{
	system("cls");
	cout << "Press 1 For Admin Access\n"
			"Press 2 For Employee Access\n"
			"Press 3 To Go Back To Main Menu\n\n"
			"Enter Option Number: ";
}
void adminMenu()
{
	system("cls");
	cout << "Press 1 To Add Employee Details\n"
			"Press 2 To Update Employee Details\n"
			"Press 3 To Delete Employee Details\n"
			"Press 4 To View Employee Details\n"
			"Press 5 To Print Balance Sheet\n"
			"Press 6 To Logout Of The System\n"
			"Press 7 To Exit Program\n\n"
			"Enter Option Number: ";
}
void employeeMenu()
{
	system("cls");
	cout << "Press 1 To Add Item\n"
			"Press 2 To Update Item\n"
			"Press 3 To Delete Item\n"
			"Press 4 To View All Items With Stock Availability\n"
			"Press 5 To View All Items With Barcode\n"
			"Press 6 To Search An Item According To Name\n"
			"Press 7 To Search An Item according To Barcode\n"
			"Press 8 To Logout Of The System\n"
			"Press 9 To Exit program\n\n"
			"Enter Option Number: ";
}
void userMenu()
{
	system("cls");
	cout << "Press 1 To Search and Buy a Product\n"
			"Press 2 To Buy Product from the list\n"
			"Press 3 To View All Product with their price\n"
			"Press 4 To View Cart And Check Out\n"
			"Press 5 To Logout Of The System\n"
			"Press 6 To Exit Program\n\n"
			"Enter Option Number: ";
}

//Login Functions.//
void login(string &username, string &password)
{
	system("cls");
	cout << "Enter User name: ";
	cin >> username;
	cout << "Enter Password: ";
	cin >> password;
	cout << endl;
}
bool userExist(string user[], string pass[], string users, string passs)
{
	bool flag = false;
	int i;
	for (i = 0; i < MAX_USERS; i++)
	{
		if (user[i] == users && pass[i] == passs)
		{
			flag = true;
			break;
		}
	}
	return flag;
}
bool E_userExist(string user[], string pass[], string users, string passs)
{
	bool flag = false;
	int i;
	for (i = 0; i < MAX_EMPLOYEE; i++)
	{
		if (user[i] == users && pass[i] == passs)
		{
			flag = true;
			break;
		}
	}
	return flag;
}
void logout()
{
	cout << "Logged Out Successfully!\n"
			"Press Any Key To Continue...\n";
	getch();
}
void loginfail()
{
	cout << "Invalid Username or Password!\n"
			"Press Any Key To Continue...\n";
	getch();
}
void exit()
{
	cout << "\n\n--------------------Thank you!--------------------\n";
	cout << "\n\n------------------BY FARAZ AHMAD------------------\n";
	getch();
}
void invalid()
{
	cout << "Invalid Option! Please Try Again\n"
			"Press Any Key To Continue...\n";
	getch();
}
void hold()
{
	cout << "Press Any Key To Continue...\n";
	getch();
}

//Admin Functions.//
bool addEmployee(string employeeCode[], string employeePass[], string empCode, string empPass)
{
	bool flag = false;
	for (short int i = 0; i < MAX_EMPLOYEE; i++)
	{
		if (employeeCode[i] == "")
		{
			employeeCode[i] = empCode;
			employeePass[i] = empPass;
			flag = true;
			break;
		}
	}
	return flag;
}
bool updateEmployee(string employeeCode[], string employeePass[], string empCode, string empPass)
{
	bool flag = false;
	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		if (employeeCode[i] == empCode)
		{
			employeeCode[i] = empCode;
			employeePass[i] = empPass;
			flag = true;
			break;
		}
	}
	return flag;
}
void viewEmployee(string employeeCode[], string employeePass[])
{
	system("cls");
	cout << "***********************************************************************************************\n";
	cout << left << setw(30) << "Employee Code" << left << setw(30) << "Passwords";
	cout << endl;
	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		if (employeeCode[i] != "")
		{
			cout << left << setw(30) << employeeCode[i] << left << setw(30) << employeePass[i] << endl;
		}
	}
	cout << "\n***********************************************************************************************\n";
}
bool deleteEmp(string employeeCode[], string employeePass[], string empCode, string empPass)
{
	bool flag = false;
	int i = searchEmployeeCode(employeeCode, empCode);
	if (i != -1)
	{
		employeeCode[i] = "";
		employeePass[i] = "";
		flag = true;
	}
	return flag;
}
void print(double sale, double purchase)
{
	// This variable for read data from file
	ofstream myfile;
	/*Open the file if exist if not exist then make new file of this name ios::app maens that the new data will append in file and 
	not remove previous content of file */
	myfile.open("profit.txt");
	//This function will check if the file open then write data from file
	if (myfile.is_open())
	{

		//These lines will write all array data to the file and make a comma separated file
		myfile << "Total Purachases: " << sale<< endl;
		myfile << "Total Sales: " <<  purchase << endl;
		myfile << "Profit: " << purchase - sale << endl;
		myfile.close();
	}
	else
	{
		cout << "If there is error while opening file";
	}
}

//Employee Functions.//
bool addItem(string itemList[], int barcodeList[], int quantityList[], double costList[], double priceList[], string itemName, int barcode, int quantity, double cost, double price)
{
	bool flag = false;
	for (short int i = 0; i < MAX_ITEMS; i++)
	{
		if (itemList[i] == "")
		{
			itemList[i] = itemName;
			barcodeList[i] = barcode;
			quantityList[i] = quantity;
			costList[i] = cost;
			priceList[i] = price;
			flag = true;
			break;
		}
	}
	return flag;
}
bool updateItem(string itemList[], int barcodeList[], int quantityList[], double costList[], double priceList[], string itemName, int barcode, int quantity, double cost, double price)
{
	bool flag = false;
	int updateIndex = searchItemName(itemList, itemName);
	if (updateIndex != -1)
	{
		itemList[updateIndex] = itemName;
		barcodeList[updateIndex] = barcode;
		quantityList[updateIndex] = quantity;
		costList[updateIndex] = cost;
		priceList[updateIndex] = price;
		flag = true;
	}
	return flag;
}
bool deleteItem(string itemList[], int barcodeList[], int quantityList[], double costList[], double priceList[], string itemName, int barcode, int quantity, double cost, double price)
{
	bool flag = false;
	int i = searchItemName(itemList, itemName);
	if (i != -1)
	{
		itemList[i] = "";
		barcodeList[i] = -1;
		quantityList[i] = -1;
		costList[i] = -1;
		priceList[i] = -1;
		flag = true;
	}
	return flag;
}
void viewItemsWithStock(string itemList[], int barcodeList[], int quantityList[], double costList[], double priceList[])
{
	system("cls");
	cout << "**************************************************************************************************************\n";
	cout << left << setw(25) << "Item Name" << left << setw(25) << "Cost" << left << setw(25) << "Price" << left << setw(25) << "Quantity";
	cout << endl<<endl;
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (itemList[i] != "")
		{
			cout << left << setw(25) << itemList[i] << left << setw(25) << costList[i] << left << setw(25) << priceList[i] << left << setw(25) << quantityList[i] << endl;
		}
	}
	cout << "\n************************************************************************************************************\n";
	//getch();
}
void viewItemsWithBarcode(string itemList[], int barcodeList[], int quantityList[], double costList[], double priceList[])
{
	system("cls");
	cout << "**************************************************************************************************************\n";
	cout << left << setw(30) << "Item Name" << left << setw(30) << "Barcode" << left << setw(30) << "Price";
	cout << endl;
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (itemList[i] != "")
		{
			cout << left << setw(30) << itemList[i] << left << setw(30) << barcodeList[i] << left << setw(30) << priceList[i] << endl;
		}
	}
	cout << "\n************************************************************************************************************\n";
}
void searchItem(string itemList[], int barcodeList[], int quantityList[], string itemName)
{
	int i = 0;
	short int count = 0;
	while (i != MAX_ITEMS)
	{
		if (itemName == itemList[i])
		{
			cout << left << setw(30) << "Item Name" << left << setw(30) << "Barcode" << left << setw(30) << "Stock";
			cout << endl;
			cout << left << setw(30) << itemList[i] << left << setw(30) << barcodeList[i] << left << setw(30) << quantityList[i] << endl;
			count++;
			hold();
		}
		i++;
	}
	if (count == 0)
	{
		cout << "Item Not Found";
	}
}

//User Functions.//
bool registerUser(char phone[], char address[])
{
	string ad=address;
repeat:
	cout << "Enter Phone Number: ";
	cin >> phone;
	if (!isValidPhoneNumber(phone))
	{
		cout << "Invalid Phone Number!";
		hold();
		goto repeat;
	}
	else
	{
		cout << "Enter Address: ";
		cin.ignore();
		getline(cin, ad);
	}
	char file[20];
	strcpy(file, phone);
	strcat(file, ".txt");
	ofstream f(file);
	f << "Phone Number: " << phone << "\nAddress: " << ad;
	f.close();
	return true;
}
void userSearchItem(string itemList[], int quantityList[], double costList[], double priceList[], string itemName) ///////////////////////////////////
{
	int i = 0;
	short int count = 0;
	while (i != MAX_ITEMS)
	{
		if (itemName == itemList[i])
		{
			cout << left << setw(30) << "Item Name" << left << setw(30) << "Price" << left << setw(30) << "Stock";
			cout << endl;
			cout << left << setw(30) << itemList[i] << left << setw(30) << priceList[i] << left << setw(30) << quantityList[i] << endl;
			count++;
		}
		i++;
	}
	if (count == 0)
	{
		cout << "Item Not Found";
	}
}
void userItemList(string itemList[], int barcodeList[], int quantityList[], double costList[], double priceList[], string itemName, double userTotal, string userItemsList[], int userQuantityList[], double userPriceList[]) /////////////////////////////////////
{
	system("cls");
	loadItems(itemList, barcodeList, quantityList, costList, priceList);
	int i = 0, quan;
	cout << "**************************************************************************************************************\n";
	cout << left << setw(30) << "Item Name" << left << setw(30) << "Price" << left << setw(30) << "Stock";
	cout << endl<<endl;
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (itemList[i] != "")
		{
			cout << left << setw(30) << itemList[i] << left << setw(30) << priceList[i] << left << setw(30) << quantityList[i] << endl;
		}
	}
	cout << "\n************************************************************************************************************\n";
	cout << "Enter product's name to buy: ";
	cin.ignore();
	getline(cin, itemName);
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (itemName == itemList[i])
		{
			cout << "Enter Quantity: ";
			cin >> quan;
			if (quan <= quantityList[i])
			{
				for (int j = 0; j < MAX_ITEMS; j++)
				{
					if (userItemsList[j] == "yo")
					{
						userItemsList[j] = itemName;
						userQuantityList[j] = quan;
						userPriceList[j] = priceList[i];
						cout << "Item added to cart!\n";
						quantityList[i] = quantityList[i] - quan;
						saveItems(itemList, barcodeList, quantityList, costList, priceList);
						hold();
						break;
					}
				}
			}
			else
			{
				cout << "Error!\n";
				hold();
			}
		}
	}
}
void viewAllItems(string itemList[], int quantityList[], double costList[], double priceList[], string itemName, double userTotal) /////////////////////////////////////
{
	system("cls");
	cout << "**************************************************************************************************************\n";
	cout << left << setw(25) << "Item Name" << left << setw(25) << "Price" << left << setw(25) << "Stock";
	cout << endl;
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (itemList[i] != "")
		{
			cout << left << setw(25) << itemList[i] << left << setw(25) << priceList[i] << left << setw(25) << quantityList[i] << endl;
		}
	}
	cout << "\n************************************************************************************************************\n";
	hold();
}
void viewCart(string userItemsList[], int userQuantityList[], double userPriceList[], double userTotal)
{
	double total = 0;
	userTotal = 0;
	char phone[11], address[100];
	cout << "**************************************************************************************************************\n";
	cout << left << setw(25) << "Item Name" << left << setw(25) << "Quantity" << left << setw(25) << "Price" << left << setw(25) << "Total Price";
	cout << endl;
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (userItemsList[i] != "yo")
		{
			total = userQuantityList[i] * userPriceList[i];
			cout << left << setw(25) << userItemsList[i] << left << setw(25) << userQuantityList[i] << left << setw(25) << userPriceList[i] << left << setw(25) << total << endl;
			userTotal = userTotal + total;
		}
	}
	cout << "\nTotal Bill= " << userTotal;
	cout << endl;
	cout << "\n************************************************************************************************************\n";
	if (registerUser(phone, address))
	{
		if (userSaveShopping(userItemsList, userQuantityList, userPriceList, userTotal, phone, address))
		{
			cout << "Bill generated successfully!\n";
			hold();
		}
		else
		{
			cout << "No user found with this phone number\nPlease register first.\n";
			hold();
		}
	}
	else
	{
		cout << "Error!\n";
		hold();
	}
}
bool userSaveShopping(string userItemsList[], int userQuantityList[], double userPriceList[], double userTotal, string phone, string address)
{
	// This variable for read data from file
	ofstream myfile;
	/*Open the file if exist if not exist then make new file of this name ios::app maens that the new data will append in file and 
	not remove previous content of file */
	myfile.open(phone);
	//This function will check if the file open then write data from file
	if (myfile.is_open())
	{
		myfile << "Phone Number: " << phone << endl;
		myfile << "Address: " << address << endl;
		for (int i = 0; i < MAX_ITEMS; i++)
		{
			if (userItemsList[i] != "yo" && userQuantityList[i] != -1 && userPriceList[i] != -1)
			{
				//These lines will write all array data to the file and make a comma separated file

				myfile << "Item Name: " << userItemsList[i] << endl;
				myfile << "Item Price: " << userPriceList[i] << endl;
				myfile << "Total Quantity: " << userQuantityList[i] << endl
					   << endl;
			}
		}
		myfile << "Total Bill: " << userTotal << endl;
		myfile.close();
		return true;
	}
	else
	{
		//If there is error while opening file this function will return false
		return false;
	}
}