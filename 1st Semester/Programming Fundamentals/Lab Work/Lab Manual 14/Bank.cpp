#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#define MAX_USERS 50
#define MAX_LOAN 50
#define MAX_TRANSACTIONS 50
#define _CRT_NONSTDC_NO_WARNINGS
using namespace std;
struct Bank_Statement
{
    string Transaction_Type;
    string date;
    string time;
    string amount;
};
struct Loan
{
    string Loan_Date;
    string Loan_ID;
    int Loan_Amount;
    int Installment_Period;
    int Loan_Monthly_Inst;
};
struct Account
{
    string firstName;
    string lastName;
    string dateOfBirth;
    string contact;
    string cnic;
    string address;
    string email;
    string password;
    Bank_Statement transaction[MAX_TRANSACTIONS];
    Loan loanID;
    int amount = 0;
};

//MENU.//
void menu();
void header();
void userMenu();
void hold();
void invalid();

//BANK MANAGEMENT.//
bool createAccount(Account createAccounts, Account users[]);
bool cashDeposit(Account createAccounts, Account users[]);
bool cashWithdraw(Account createAccounts, Account users[]);
bool login(string email, string password, Account users[]);
bool saveTransaction(Account users[]);
bool loadTransaction(Account users[]);
string Date_Time();

//LOAN.//
void loanMenu();
bool loanRequest(Account createAccounts, Account users[]);
void loanProfile(Account createAccounts, Account users[]);
bool saveLoan(Account users[]);
bool loadLoan(Account users[]);
bool loanLogin(Account createAccounts, Account users[]);
string loanID();
bool loanIDValid(Account createAccounts, Account users[]);

//VALIDATORS.//
bool isValidcnic(string cnic);
bool isValidContact(string contact);
bool isValidName(string name);
bool isValidBirth(string dateOfBirth);
bool isValidAddress(string address);
bool isValidEmail(string email);
bool loadUser(Account users[]);
bool saveTransaction(Account users[]);
int index(Account createAccounts, Account users[]);

//INITIALIZATION AND SAVE DATA.//
void initializeUsers(Account users[]);
bool saveUsers(Account users[]);

int main()
{
    char option1, option2, select;
    Account users[MAX_USERS];
    Account createAccounts;
    int ind = 0;

    initializeUsers(users);
    loadUser(users);
    loadLoan(users);
    do
    {
    menu:
        header();
        menu();
        cin >> option1;
        switch (option1)
        {
            //Create new account
        case '1':
        {
            header();
        name:
            cout << "Enter First Name: ";
            cin.ignore();
            getline(cin, createAccounts.firstName);
            if (!isValidName(createAccounts.firstName))
            {
                cout << "Invalid Name!\n";
                hold();
                goto name;
            }
        name1:
            cout << "Enter Last Name: ";
            getline(cin, createAccounts.lastName);
            if (!isValidName(createAccounts.lastName))
            {
                cout << "Invalid Name!\n";
                hold();
                goto name1;
            }
        dob:
            cout << "Enter Date-of-birth: ";
            getline(cin, createAccounts.dateOfBirth);
            if (!isValidBirth(createAccounts.dateOfBirth))
            {
                cout << "Invalid date of birth!\n";
                hold();
                goto dob;
            }
        contact:
            cout << "Enter Contact Number: ";
            getline(cin, createAccounts.contact);
            if (!isValidContact(createAccounts.contact))
            {
                cout << "Invalid Contact Number!\n";
                hold();
                goto contact;
            }
        cnic:
            cout << "Enter Valid CNIC: ";
            getline(cin, createAccounts.cnic);
            if (!isValidcnic(createAccounts.cnic))
            {
                cout << "Invalid CNIC!\n";
                hold();
                goto cnic;
            }
        add:
            cout << "Enter Address: ";
            getline(cin, createAccounts.address);
            if (!isValidAddress(createAccounts.address))
            {
                cout << "Invalid Address!\n";
                hold();
                goto add;
            }
        email:
            cout << "Enter Email Address: ";
            getline(cin, createAccounts.email);
            if (!isValidEmail(createAccounts.email))
            {
                cout << "Invalid Email Address!\n";
                hold();
                goto email;
            }
            cout << "Enter Password: ";
            getline(cin, createAccounts.password);
            if (createAccount(createAccounts, users))
            {
                cout << "Account created successfully!\n";
                saveUsers(users);
                loadUser(users);
                hold();
            }
            else
            {
                cout << "invalid Data!\n";
                getch();
            }
            break;
        }
        //login account
        case '2':
        {

        login:
            header();
            cout << "Enter valid credential for login\n";
            cout << "Enter Email Address: ";
            cin >> createAccounts.email;
            cout << "Enter Password:";
            cin >> createAccounts.password;
            for (int i = 0; i < MAX_USERS; i++)
            {
                if (createAccounts.password == users[i].password && createAccounts.email == users[i].email)
                {
                    ind = i;
                umenu:
                    header();
                    userMenu();
                    cin >> option2;

                    switch (option2)
                    {
                    case '1':
                    {
                        cout << "Enter the required information to deposit amount:\n";
                        cout << "Enter CNIC: \n";
                        cin.ignore();
                        getline(cin, createAccounts.cnic);

                        cout << "Enter Contact Number: \n";
                        getline(cin, createAccounts.contact);

                        cout << "Enter your Password: \n";
                        getline(cin, createAccounts.password);

                        cout << "Enter the amount to deposit (in digits): \n";
                        cin >> createAccounts.amount;
                        if (cashDeposit(createAccounts, users))
                        {
                            cout << "Amount has been added to your account\n";
                            hold();
                        }
                        else
                        {
                            cout << "Operation Unsuccessfull!\n";
                            hold();
                        }
                        break;
                    }
                    case '2':
                    {
                        cout << "Enter the required information to withdraw amount:\n";
                        cout << "Enter CNIC: \n";
                        cin.ignore();
                        getline(cin, createAccounts.cnic);

                        cout << "Enter Contact Number: \n";
                        getline(cin, createAccounts.contact);

                        cout << "Enter your Password: \n";
                        getline(cin, createAccounts.password);

                        cout << "Enter the amount to deposit (in digits): \n";
                        cin >> createAccounts.amount;
                        if (cashWithdraw(createAccounts, users))
                        {
                            cout << "Collect your money!\n";
                            hold();
                            goto umenu;
                        }
                        else
                        {
                            cout << "Operation Unsuccessfull!\n";
                            hold();
                            goto umenu;
                        }
                        hold();
                        break;
                    }
                    case '3':
                    {
                        header();
                        cout << left << setw(10) << "S.No."
                             << setw(30) << "Email"
                             << setw(30) << "CNIC"
                             << setw(30) << "Transaction-Type(W/D)"
                             << setw(30) << "Data and Time" << endl;
                        for (int i = 0; i < MAX_USERS; i++)
                        {
                            if (users[i].transaction[i].Transaction_Type != "")
                            {
                                cout << left << setw(10) << i + 1 << setw(30) << users[i].email << setw(30) << users[i].cnic
                                     << setw(30) << users[i].transaction[i].Transaction_Type << setw(30) << users[i].transaction[i].date
                                     << endl;
                                hold();
                            }
                        }
                        break;
                    }
                    case '4':
                    {
                        header();
                        cout << "Account profile is\t\t\t\t"
                             << "Current Amount: " << users[i].amount << endl;
                        cout << "Full Name: " << users[i].firstName << " " << users[i].lastName << endl
                             << "CNIC: " << users[i].cnic << endl
                             << "Email-Address: " << users[i].email << endl
                             << "Contact-Number: " << users[i].contact << endl
                             << "Password: " << users[i].password << endl
                             << "Date-of-Birth:" << users[i].dateOfBirth << endl;
                        hold();
                        goto umenu;
                        break;
                    }
                    case '5':
                    {
                        saveTransaction(users);
                        goto login;
                        break;
                    }
                    default:
                    {
                        invalid();
                    }
                    break;
                    }
                }
            }
            break;
        }
        //loan management
        case '3':
        {
            header();
            cout << "Welcome to load Management\n"
                 << "Enter the required information\n"
                 << "Enter your Email Address: ";
            cin.ignore();
            getline(cin, createAccounts.email);
            cout << "Enter Valid CNIC: ";
            getline(cin, createAccounts.cnic);
            cout << "Enter Password: ";
            getline(cin, createAccounts.password);
            ind = index(createAccounts, users);
            if (loanLogin(createAccounts, users))
            {
                cout << "Your Loan id is: " << loanID() << endl;
                users[ind].loanID.Loan_ID = loanID();
                cout << "Press any key to proceed\n";
                getch();
                do
                {
                    cout << "\n\n1-Loan Request\n"
                         << "2-Loan Profile\n"
                         << "Press 0 to go back\n";
                    cin >> option1;
                    header();
                    switch (option1)
                    {
                    case '1':
                    {
                        cout << "Enter the required information for loan request\n";
                        cout << "Enter CNIC:";
                        cin.ignore();
                        getline(cin, createAccounts.cnic);
                        cout << "Enter Password:";
                        getline(cin, createAccounts.password);
                        cout << "Enter Loan ID:";
                        getline(cin, createAccounts.loanID.Loan_ID);
                        cout << "Enter requested amount:";
                        cin >> createAccounts.loanID.Loan_Amount;
                        cout << "Enter installment period (in month):";
                        cin >> createAccounts.loanID.Installment_Period;
                        cout << "Your Monthly will be:";
                        cin >> createAccounts.loanID.Loan_Monthly_Inst;
                        cout << "Did you want to proceed (Y/N)?";
                        cin >> select;

                        if ((select == 'Y' || select == 'y'))
                        {
                            if (loanIDValid(createAccounts, users))
                            {
                                cout << "Your request will be verified soon. Check loan profile\n";
                                saveLoan(users);
                                hold();
                            }
                            else
                            {
                                cout << "Incorrect Credentials\n";
                                hold();
                            }
                        }
                        else if (select == 'N' || select == 'n')
                        {
                            cout << "okay!";
                            getch();
                        }
                        else
                        {
                            invalid();
                        }

                        break;
                    }
                    case '2':
                    {
                        loadLoan(users);
                        cout << "User Loan Profile\n";
                        cout << "Enter CNIC:";
                        cin.ignore();
                        getline(cin, createAccounts.cnic);
                        cout << "Enter Loan ID:";
                        getline(cin, createAccounts.loanID.Loan_ID);
                        cout << "Enter Password:";
                        getline(cin, createAccounts.password);
                        if (loanIDValid(createAccounts, users))
                        {
                            loanProfile(createAccounts, users);
                        }
                        else
                        {
                            cout << "Invalid Data!\n";
                            getch();
                        }
                        break;
                    }
                    case '0':
                    {
                        goto menu;
                        break;
                    }
                    default:
                    {
                        invalid();
                        break;
                    }
                    }
                } while (option1 != '0');
            }
            else
            {
                cout << "Invalid credentials!\n";
                getch();
            }

            break;
        }
        //close program
        case '0':
        {
            saveUsers(users);
            cout << "Program CLosed!\n\n";
            return 0;
            break;
        }
        default:
        {
            invalid();
            break;
        }
        }

    } while (option1 != '0');
    return 0;
}
//MENU FUNCTIONS.//
void header()
{
    system("cls");
    cout << "**************************************************************\n"
            "                   Bank Management System\n"
            "**************************************************************\n";
}
void menu()
{
    cout << "Welcome to Bank\n"
            "1. Create a new account\n"
            "2. Login Account\n"
            "3. Loan Management\n"
            "0. Close the program\n"
            "Enter User Input: ";
}
void userMenu()
{
    cout << " 1- Deposit Money\n"
            " 2- Withdraw Money\n"
            " 3- View all transaction\n"
            " 4- View account details\n"
            " 5- Logout the current user\n";
}
void hold()
{
    cout << "Press any key to continue...\n";
    getch();
}
void invalid()
{
    cout << "\nInvalid Input!\n";
    getch();
}

//BANK MANAEGEMENT.//
bool createAccount(Account createAccounts, Account users[])
{
    bool flag = false;
    for (int i = 0; i < MAX_USERS; i++)
    {
        if (users[i].firstName == "" && users[i].address == "")
        {
            users[i].firstName = createAccounts.firstName;
            users[i].lastName = createAccounts.lastName;
            users[i].dateOfBirth = createAccounts.dateOfBirth;
            users[i].contact = createAccounts.contact;
            users[i].cnic = createAccounts.cnic;
            users[i].address = createAccounts.address;
            users[i].email = createAccounts.email;
            users[i].password = createAccounts.password;
            flag = true;
            break;
        }
    }
    return flag;
}
bool cashDeposit(Account createAccounts, Account users[])
{
    bool flag = false;
    int index;
    for (int i = 0; i < MAX_USERS; i++)
    {
        if (createAccounts.cnic == users[i].cnic && createAccounts.contact == users[i].contact && createAccounts.password == users[i].password)
        {
            index = i;
            users[i].amount = users[i].amount + createAccounts.amount;
            flag = true;
            break;
        }
    }
    for (int i = 0; i < MAX_TRANSACTIONS; i++)
    {
        if (users[index].transaction[i].Transaction_Type == "")
        {
            users[index].transaction[i].Transaction_Type = "D";
            users[index].transaction[i].date = Date_Time();
            break;
        }
    }
    return flag;
}
bool cashWithdraw(Account createAccounts, Account users[])
{
    bool flag = false;
    int index;
    for (int i = 0; i < MAX_USERS; i++)
    {
        if (createAccounts.cnic == users[i].cnic && createAccounts.contact == users[i].contact && createAccounts.password == users[i].password)
        {
            if (createAccounts.amount <= users[i].amount)
            {
                index = i;
                users[i].amount = users[i].amount - createAccounts.amount;
                flag = true;
                break;
            }
        }
    }
    for (int i = 0; i < MAX_TRANSACTIONS; i++)
    {
        if (users[index].transaction[i].Transaction_Type == "")
        {
            users[index].transaction[i].Transaction_Type = "W";
            users[index].transaction[i].date = Date_Time();
            break;
        }
    }
    return flag;
}
void initializeUsers(Account users[])
{
    for (int i = 0; i < MAX_USERS; i++)
    {
        users[i].firstName = "";
        users[i].lastName = "";
        users[i].contact = "";
        users[i].dateOfBirth = "";
        users[i].address = "";
        users[i].cnic = "";
        users[i].email = "";
        users[i].password = "";
        users[i].amount = 0;
        users[i].loanID.Loan_ID = "";
        users[i].transaction[i].Transaction_Type == "";
    }
}
bool loadUser(Account users[])
{
    int i = 0;
    ifstream getUsers("account.txt");
    if (!getUsers.is_open())
    {
        cout << "Users file failed to open" << endl;
        return false;
    }
    else
    {
        string name, name1, add, id, cont, dob, emaiL, pass;
        string line;
        while (!getUsers.eof() && i < MAX_USERS)
        {
            getline(getUsers, line);
            stringstream ss(line);

            getline(ss, name, ';');
            users[i].firstName = name;

            getline(ss, name1, ',');
            users[i].lastName = name1;

            getline(ss, id, ',');
            users[i].cnic = id;

            getline(ss, emaiL, ',');
            users[i].email = emaiL;

            getline(ss, cont, ',');
            users[i].contact = cont;

            getline(ss, pass, ',');
            users[i].password = pass;

            getline(ss, add, ',');
            users[i].address = add;

            getline(ss, dob, ',');
            users[i].dateOfBirth = dob;
            i++;
        }
        getUsers.close();
        return true;
    }
}
bool saveUsers(Account users[])
{
    ofstream myfile;

    myfile.open("account.txt");
    if (myfile.is_open())
    {
        for (int i = 0; i < MAX_USERS; i++)
        {
            if (users[i].firstName != "")
            {
                myfile << users[i].firstName << ";";
                myfile << users[i].lastName << ",";
                myfile << users[i].cnic << ",";
                myfile << users[i].email << ",";
                myfile << users[i].contact << ",";
                myfile << users[i].password << ",";
                myfile << users[i].address << ",";
                myfile << users[i].dateOfBirth << "," << endl;
            }
        }
        myfile.close();
        return true;
    }
    else
    {
        return false;
    }
}
bool saveTransaction(Account users[])
{
    ofstream myfile;

    myfile.open("transaction.txt");
    if (myfile.is_open())
    {
        for (int i = 0; i < MAX_USERS; i++)
        {
            if (users[i].firstName != "")
            {
                for (int j = 0; j < MAX_TRANSACTIONS; j++)
                {
                    myfile << users[i].cnic << ";";
                    myfile << users[i].transaction[j].Transaction_Type << ",";
                    myfile << users[i].transaction[j].amount << ",";
                    myfile << users[i].transaction[j].date << "," << endl;
                }
            }
        }
        myfile.close();
        return true;
    }
    else
    {
        return false;
    }
}
bool loadTransaction(Account users[])
{
    int i = 0;
    ifstream getUsers("account.txt");
    if (!getUsers.is_open())
    {
        cout << "Users file failed to open" << endl;
        return false;
    }
    else
    {
        string name, name1, add, id, gg;
        string line;
        while (!getUsers.eof() && i < MAX_USERS)
        {
            getline(getUsers, line);
            stringstream ss(line);

            getline(ss, name, ';');
            users[i].cnic = name;

            getline(ss, name1, ',');
            users[i].transaction[i].Transaction_Type = name1;

            getline(ss, gg, ',');
            users[i].transaction[i].amount = gg;
            
            getline(ss, id, ',');
            users[i].transaction[i].date = id;
            i++;
        }
        getUsers.close();
        return true;
    }
}
bool login(string email, string password, Account users[])
{
    bool flag = false;
    for (int i = 0; i < MAX_USERS; i++)
    {
        if (email == users[i].email && password == users[i].password)
        {
            flag = true;
        }
    }
    return flag;
}
string Date_Time()
{
    time_t tt;
    struct tm *ti;
    time(&tt);
    ti = localtime(&tt);
    cout << "Current Day, Date and Time is = " << asctime(ti);
    string time_Date = asctime(ti);
    return time_Date;
}

//VALIDATORS.//
bool isValidName(string name)
{
    bool flag = false;
    int len = name.size();
    for (int i = 1; i < len; i++)
    {
        if (name[0] >= 'A' && name[0] <= 'Z')
        {
            flag = true;
        }
        if (name[i] >= 'a' && name[i] <= 'z')
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
bool isValidBirth(string dob)
{
    bool flag = true;
    return flag;
}
bool isValidContact(string contact)
{
    bool check = false;
    bool flag = false;
    if (contact.length() == 11)
    {
        check = true;
    }
    if (check == true)
    {
        for (int i = 0; i < 11; i++)
        {
            if (contact[i] >= '0' && contact[i] <= '9')
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
    return flag;
}
bool isValidcnic(string cnic)
{
    bool flag = false;
    bool check = false;
    if (cnic.length() == 13)
    {
        check = true;
    }
    if (check == true)
    {
        for (int i = 0; i < 13; i++)
        {
            if (cnic[i] >= '0' && cnic[i] <= '9')
            {
                flag = true;
            }
        }
    }
    return flag;
}
bool isValidAddress(string address)
{
    bool flag = false;
    int len = address.size();
    for (int i = 0; i < len; i++)
    {
        if ((address[i] >= 'A' && address[i] <= 'Z') || (address[i] >= 'a' && address[i] <= 'a') || (address[i] >= '0' && address[i] <= '9') || (address[i] == '-'))
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
bool isValidEmail(string email)
{
    bool flag1 = false, flag2 = false, flag3 = false;
    int len = email.size();
    for (int i = 0; i < len; i++)
    {
        if (email[i] == '@')
        {
            flag1 = true;
        }
        if (email[i] == '.')
        {
            flag2 = true;
        }
    }
    if (flag1 == true && flag2 == true)
    {
        flag3 = true;
    }
    return flag3;
}

//LOAN MANAGEMENT.//
void loanProfile(Account createAccounts, Account users[])
{
    loadLoan(users);
    header();
    for (int i = 0; i < MAX_USERS; i++)
    {
        if (createAccounts.cnic == users[i].cnic)
        {
            cout << "Full Name: " << users[i].firstName << " " << users[i].lastName << endl
                 << "CNIC: " << users[i].cnic << endl
                 << "Loan ID : " << users[i].loanID.Loan_ID << endl
                 << endl
                 << left << "Requested Amount: " << users[i].loanID.Loan_Amount
                 << setw(50) << "Monthly Installment " << users[i].loanID.Loan_Monthly_Inst << endl
                 << left << "Total Time Period (in Month)" << users[i].loanID.Installment_Period
                 << setw(50) << "Request Date-Time" << users[i].loanID.Loan_Date << endl;
        }
    }
    hold();
}
bool loanLogin(Account createAccounts, Account users[])
{
    bool flag = false;
    for (int i = 0; i < MAX_USERS; i++)
    {
        if (createAccounts.email == users[i].email && createAccounts.password == users[i].password && createAccounts.cnic == users[i].cnic)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
int index(Account createAccounts, Account users[])
{
    for (int i = 0; i < MAX_USERS; i++)
    {
        if (createAccounts.email == users[i].email && createAccounts.password == users[i].password && createAccounts.cnic == users[i].cnic)
        {
            return i;
            break;
        }
    }
}
string loanID()
{
    srand(time(0));
    int j = rand() % 9;
    int i = rand() % 9;
    int k = rand() % 9;
    int l = rand() % 9;
    string a, b, c, d;
    a = to_string(j);
    b = to_string(i);
    c = to_string(k);
    d = to_string(l);
    string LoanID;
    LoanID = a + b + c + "000" + d + "0";
    return LoanID;
}
bool loanIDValid(Account createAccounts, Account users[])
{
    bool flag = false;
    for (int i = 0; i < MAX_USERS; i++)
    {
        if (createAccounts.loanID.Loan_ID == users[i].loanID.Loan_ID && createAccounts.password == users[i].password && createAccounts.cnic == users[i].cnic)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
bool saveLoan(Account users[])
{
    ofstream myfile;

    myfile.open("loan.txt");
    if (myfile.is_open())
    {
        for (int i = 0; i < MAX_USERS; i++)
        {
            if (users[i].loanID.Loan_ID != "")
            {
                myfile << users[i].cnic << ",";
                myfile << users[i].loanID.Loan_ID << ",";
                myfile << users[i].loanID.Loan_Amount << ",";
                myfile << users[i].loanID.Loan_Monthly_Inst << ",";
                myfile << users[i].loanID.Loan_Date << ",";
                myfile << users[i].loanID.Installment_Period << "," << endl;
            }
        }
        myfile.close();
        return true;
    }
    else
    {
        return false;
    }
}
bool loadLoan(Account users[])
{
    int i = 0;
    ifstream getUsers("loan.txt");
    if (!getUsers.is_open())
    {
        cout << "Users file failed to open" << endl;
        return false;
    }
    else
    {
        string loanidd, id, dat, dob, emaiL, req1, inst1, pass1;
        string line;

        int req, inst, pass;
        while (!getUsers.eof() && i < MAX_USERS)
        {
            getline(getUsers, line);
            stringstream ss(line);

            getline(ss, id, ';');
            users[i].cnic = id;

            getline(ss, loanidd, ',');
            users[i].loanID.Loan_ID = loanidd;

            getline(ss, req1, ',');
            stringstream req2(req1);
            req2 >> req;
            users[i].loanID.Loan_Amount = req;

            getline(ss, inst1, ',');
            stringstream inst2(inst1);
            inst2 >> inst;
            users[i].loanID.Loan_Monthly_Inst = inst;

            getline(ss, dat, ',');
            users[i].loanID.Loan_Date = dat;

            getline(ss, pass1, ',');
            stringstream pass2(inst1);
            pass2 >> pass;
            users[i].loanID.Installment_Period = pass;
            i++;
        }
        getUsers.close();
        return true;
    }
}