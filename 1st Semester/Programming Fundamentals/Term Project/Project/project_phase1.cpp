//User Functions are incomplete at this moment.//
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#define MAX_ITEMS 1024
#define MAX_USERS 1024
#define BUFFER 1024
#define MAX_EMPLOYEE 3
using namespace std;

///////////////////////////////////////////////////////////      MENU FUNCTIONS.     ////////////////////////////////////////////////////////////////
void welcome();
void adminMenu();
void companyMenu();
void employeeMenu();
void userMenu();
void invalid();
void exit();
void hold();

///////////////////////////////////////////////////////////     LOGGING FUNCTIONS.     //////////////////////////////////////////////////////////////
void login(string& userName, string& password);
void logout();
void loginfail();
bool userExist(string user[], string pass[], string users, string passs, int size);
bool loadUser(string usersList[], string passwordList[], int size);

////////////////////////////////////////////////////////////     ADMIN FUNCTIONS.     ///////////////////////////////////////////////////////////////
bool addEmployee(string employeeCode[], string employeePass[], string empCode, string empPass);
bool updateEmployee(string employeeCode[], string employeePass[], string empCode, string empPass);
bool deleteEmp(string employeeCode[], string employeePass[], string empCode, string empPass);
void viewEmployee(string employeeCode[], string employeePass[]);

///////////////////////////////////////////////////////////     EMPLOYEE FUNCTIONS.     /////////////////////////////////////////////////////////////
bool addItem(string itemList[], int barcodeList[], int quantityList[], double priceList[], string itemName, int barcode, int quantity, double price);
bool updateItem(string itemList[], int barcodeList[], int quantityList[], double priceList[], string itemName, int barcode, int quantity, double price);
bool deleteItem(string itemList[], int barcodeList[], int quantityList[], double priceList[], string itemName, int barcode, int quantity, double price);
void viewItemsWithStock(string itemList[], int barcodeList[], int quantityList[], double priceList[]);
void viewItemsWithBarcode(string itemList[], int barcodeList[], int quantityList[], double priceList[]);
void searchItem(string itemList[], int barcodeList[], int quantityList[], string itemName);

//////////////////////////////////////////////////////////////     USER FUNCTIONS.     //////////////////////////////////////////////////////////////
void userSearchItem(string itemList[], int quantityList[], double priceList[], string itemName, double userTotal); //////////////////////////////////
void userItemList(string itemList[], int quantityList[], double priceList[], string itemName, double userTotal);   //////////////////////////////////
void viewAllItems(string itemList[], int quantityList[], double priceList[], string itemName, double userTotal);   //////////////////////////////////
void viewCart(double userTotal);
void checkout();

///////////////////////////////////////////////////////////////     VALIDATORS.     /////////////////////////////////////////////////////////////////
bool isValidEmpCode(string empCode);
bool isValidItemName(string itemName);
bool isValidBarcode(int barcode);
bool isValidQuantity(int quantity);
bool isValidPrice(double price);
int searchEmployeeCode(string employeeCode[], string empCode);
int searchItemName(string itemList[], string itemName);
int main()
{
	//Options For Switch Cases.//
	short int option1, option2, option3, option4, option5;

	//FOR LOGIN.//
	string username, password;
	string usersList[MAX_USERS], passwordList[MAX_USERS];

	//VARIABLES FOR ADMIN USE.//
	string employeeCode[MAX_EMPLOYEE], employeePass[MAX_EMPLOYEE];
	string empCode, empPass;
	int totalPurchases = 0, totalSales = 0;

	//VARIABLES FOR EMPLOYEE USE.//
	string itemList[MAX_ITEMS];
	string itemName;
	int barcodeList[MAX_ITEMS], quantityList[MAX_ITEMS];
	double priceList[MAX_ITEMS];
	int barcode, quantity;
	double price;

	//VARIABLES FOR USER.//
	int CURRENT_USER = 1;
	string userItemList[MAX_USERS][100]; ////////////////////////////////////////////////////////////////////////////////////////////////////////////
	double userTotal;

	//loadUser(usersList, passwordList, MAX_USERS);

	//INITIALIZATION.//
	for (int i = 0; i < MAX_EMPLOYEE; i++)
	{
		employeeCode[i] = " ";
		employeePass[i] = " ";
	}
	int i = 0;
	while (i < MAX_ITEMS)
	{
		itemList[i] = " ";
		barcodeList[i] = -1;
		quantityList[i] = -1;
		priceList[i] = -1;
		i++;
	}
	do
	{
	mainmenu:
		welcome();
		cin >> option1;
		switch (option1) //Switch 1 for Welcome Menu//
		{
		case 1:
		{
		companymenu:
			companyMenu();
			cin >> option2;
			switch (option2) //Switch 2 for Company Menu.//
			{
				//ADMIN ACCESS.//
			case 1:
			{
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
						case 1:
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
								if (addEmployee(employeeCode, employeePass, empCode, empPass) == true)
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
						case 2:
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
									if (isValidEmpCode(empCode) == false)
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
										if (updateEmployee(employeeCode, employeePass, empCode, empPass) == true)
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
						case 3:
						{
							cout << "Enter Employee Code To Delete\n";
							cin >> empCode;
							//Validate the Employee Code
							if (isValidEmpCode(empCode))
							{
								//call function to delete the Employee detail which has same Employee code as user enter
								if (deleteEmp(employeeCode, employeePass, empCode, empPass))
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
						case 4:
						{
							viewEmployee(employeeCode, employeePass);
							hold();
							break;
						}
						//Print balance sheet.//
						case 5:
						{ /* code */
							break;
						}
						//Logout of the System.//
						case 6:
						{
							logout();
							goto mainmenu;
							break;
						}
						//Exit program.//
						case 7:
						{
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
				}
				break;
			} //End Of Admin Access Case.//

			//EMPLOYEE ACCESS.//
			case 2:
			{
				login(username, password);
				if (username == "e" && password == "e")
				{
					do
					{
						employeeMenu();
						cin >> option4;
						cout << endl;
						switch (option4)
						{
							//Add Item.//
						case 1:
						{
							cout << "Enter Item Name: ";
							cin >> itemName;
							cout << "Enter Barcode, Quantity and Price of the Product: ";
							cin >> barcode;
							cin >> quantity;
							cin >> price;
							if (isValidItemName(itemName) == true && isValidQuantity(quantity) == true && isValidBarcode(barcode) == true && isValidPrice(price) == true)
							{
								addItem(itemList, barcodeList, quantityList, priceList, itemName, barcode, quantity, price);
								if (addItem(itemList, barcodeList, quantityList, priceList, itemName, barcode, quantity, price) == true)
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
						case 2:
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
									cin >> price;
									if (isValidItemName(itemName) == true && isValidQuantity(quantity) == true && isValidBarcode(barcode) == true && isValidPrice(price) == true)
									{
										addItem(itemList, barcodeList, quantityList, priceList, itemName, barcode, quantity, price);
										if (addItem(itemList, barcodeList, quantityList, priceList, itemName, barcode, quantity, price) == true)
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
						case 3:
						{
							cout << "Enter Item To Delete: ";
							cin >> itemName;
							//Validate the Employee Code
							if (isValidItemName(itemName))
							{
								if (deleteItem(itemList, barcodeList, quantityList, priceList, itemName, barcode, quantity, price))
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
						case 4:
						{
							viewItemsWithStock(itemList, barcodeList, quantityList, priceList);
							hold();
							break;
						}
						//View All Items with barcode.//
						case 5:
						{
							viewItemsWithBarcode(itemList, barcodeList, quantityList, priceList);
							hold();
							break;
						}
						//Search an Item according To name.//
						case 6:
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
						case 7:
						{ /* code */
							break;
						}
						//Logout.//
						case 8:
						{
							logout();
							goto mainmenu;
							break;
						}
						//Exit.//
						case 9:
						{
							exit();
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
				}
				break;
			} //End Of Employee Access Case.//
			case 3:
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
			//End Of Company Access Case.//
		}
		//USER ACCESS.//
		case 2:
		{
			login(username, password);
			if (password == password)
			{
				do
				{
					userMenu();
					cin >> option5;
					cout << endl;
					switch (option5)
					{
						//Search and buy a Product.//
					case 1:
					{
						cout << "Enter Product/Item Name to search";
						cin >> itemName;
						//userSearchItem(itemList, quantityList, priceList, itemName, userTotal);
						break;
					}
					//buy Product from the list.//
					case 2:
					{ /* code */
						break;
					}
					//View All Product with their price.//
					case 3:
					{ /* code */
						break;
					}
					//view cart and check out.//
					case 4:
					{ /* code */
						break;
					}
					//Logout of the System.//
					case 5:
					{
						logout();
						goto mainmenu;
						break;
					}
					//Exit program.//
					case 6:
					{
						exit();
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
				loginfail();
			}
			break;
		} //End Of User Access Case.//
		case 3:
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
}
//Validators.//
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
bool isValidPrice(double price)
{
	bool flag = false;
	if (price >= 0.0 && price <= 9999.0)
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
		"Press 3 to Exit Program\n"
		"Enter Option Number: ";
}
void companyMenu()
{
	system("cls");
	cout << "Press 1 For Admin Access\n"
		"Press 2 For Employee Access\n"
		"Press 3 To Go Back To Main Menu\n"
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
		"Press 7 To Exit Program\n"
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
		"Press 9 To Exit program\n"
		"Enter Option Number: ";
}
void userMenu()
{
	system("cls");
	cout << "Press 1 To search and buy a Product\n"
		"Press 2 To buy Product from the list\n"
		"Press 3 To View All Product with their price\n"
		"Press 4 To View Cart And Check Out\n"
		"Press 5 To Logout Of The System\n"
		"Press 6 To Exit Program\n"
		"Enter Option Number: ";
}
void login(string& userName, string& password)
{
	system("cls");
	cout << "Enter User name: ";
	cin >> userName;
	cout << "Enter Password: ";
	cin >> password;
	cout << endl;
}
bool userExist(string user[], string pass[], string users, string passs, int size)
{
	bool flag = false;
	int i;
	for (i = 0; i < size; i++)
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
	cout << "\n\n------------------Thank you!------------------\n";
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
		if (employeeCode[i] == " ")
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
		if (employeeCode[i] != " ")
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
		employeeCode[i] = " ";
		employeePass[i] = " ";
		flag = true;
	}
	return flag;
}

//Employee Functions.//
bool addItem(string itemList[], int barcodeList[], int quantityList[], double priceList[], string itemName, int barcode, int quantity, double price)
{
	bool flag = false;
	for (short int i = 0; i < MAX_ITEMS; i++)
	{
		if (itemList[i] == " ")
		{
			itemList[i] = itemName;
			barcodeList[i] = barcode;
			quantityList[i] = quantity;
			priceList[i] = price;
			flag = true;
			break;
		}
	}
	return flag;
}
bool updateItem(string itemList[], int barcodeList[], int quantityList[], double priceList[], string itemName, int barcode, int quantity, double price)
{
	bool flag = false;
	int updateIndex = searchItemName(itemList, itemName);
	if (updateIndex != -1)
	{
		itemList[updateIndex] = itemName;
		barcodeList[updateIndex] = barcode;
		quantityList[updateIndex] = quantity;
		priceList[updateIndex] = price;
		flag = true;
	}
	return flag;
}
bool deleteItem(string itemList[], int barcodeList[], int quantityList[], double priceList[], string itemName, int barcode, int quantity, double price)
{
	bool flag = false;
	int i = searchItemName(itemList, itemName);
	if (i != -1)
	{
		itemList[i] = " ";
		barcodeList[i] = -1;
		quantityList[i] = -1;
		priceList[i] = -1;
		flag = true;
	}
	return flag;
}
void viewItemsWithStock(string itemList[], int barcodeList[], int quantityList[], double priceList[])
{
	system("cls");
	cout << "********************************************************************\n";
	cout << left << setw(30) << "Item Name" << left << setw(30) << "Quantity";
	cout << endl;
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (itemList[i] != " ")
		{
			cout << left << setw(30) << itemList[i] << left << setw(30) << quantityList[i] << endl;
		}
	}
	cout << "\n******************************************************************\n";
}
void viewItemsWithBarcode(string itemList[], int barcodeList[], int quantityList[], double priceList[])
{
	system("cls");
	cout << "**************************************************************************************************************\n";
	cout << left << setw(30) << "Item Name" << left << setw(30) << "Barcode" << left << setw(30) << "Price";
	cout << endl;
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (itemList[i] != " ")
		{
			cout << left << setw(30) << itemList[i] << left << setw(30) << barcodeList[i] << left << setw(30) << priceList[i] << endl;
		}
	}
	cout << "\n************************************************************************************************************\n";
}
void searchItem(string itemList[], int barcodeList[], int quantityList[], string itemName)
{
}

//User Functions.//
void userSearchItem(string itemList[], int quantityList[], double priceList[], string itemName, double userTotal) ///////////////////////////////////
{
}
void userItemList(string itemList[], int quantityList[], double priceList[], string itemName, double userTotal) /////////////////////////////////////
{
}
void viewAllItems(string itemList[], int quantityList[], double priceList[], string itemName, double userTotal) /////////////////////////////////////
{
}
void viewCart(double userTotal)
{
}
void checkout()
{
}
