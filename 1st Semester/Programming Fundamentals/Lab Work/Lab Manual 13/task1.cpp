#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <conio.h>
#define MAX_STUDENTS 50
#define MAX_TEACHERS 50
using namespace std;
struct Student
{
    string firstName; //for student first name
    string lastName;  //for student last name
    string registrationNumber;
    string degreeTitle;
};
struct Teacher
{
    string tfirstName; //for Teacher first name
    string tlastName;  //for Teacher last name
    string experience;
    string contactNumber;
    string qualfication;
    string Email;
};
void menu();
void stdMenu();
void header();
void tMenu();
bool saveTeacher();
int main()
{
    int i, len;
    char option1, option2, option3, select;
    Student student[MAX_STUDENTS];
    Teacher teacher[MAX_TEACHERS];
    string line;
    ofstream myfile;
    ifstream getTeacher("teacher.txt"), getstudent("student.txt");

    //INITIALIZATION.//
    for (int i = 0; i < 50; i++)
    {
        teacher[i].tfirstName == "";
        teacher[i].tlastName == "";
        teacher[i].qualfication == "";
        teacher[i].experience == "";
        teacher[i].contactNumber == "";
        teacher[i].Email == "";
        student[i].firstName == "";
        student[i].lastName == "";
        student[i].registrationNumber == "";
        student[i].degreeTitle == "";
    }
    do
    {
        system("cls");
    menu:
        system("cls");
        header();
        menu();
        cin >> option1;

        switch (option1)
        {
        //Student Information
        case '1':
        {
            do
            {
            student:
                system("cls");
                header();
                stdMenu();
                cin >> option2;
                switch (option2)
                {
                //Creat New Entry
                case '1':
                {
                repeat1:
                    system("cls");
                    header();
                    cout << "Welcome to Student Information Section\n\n";
                    for (int i = 0; i < MAX_STUDENTS; i++)
                    {
                        if (student[i].firstName == "")
                        {
                            cout << "Enter your First Name: ";
                            cin.ignore();
                            getline(cin, student[i].firstName);

                            cout << "Enter your Last Name: ";
                            cin.ignore();
                            getline(cin, student[i].lastName);

                            cout << "Enter Registration Number: ";
                            cin.ignore();
                            getline(cin, student[i].registrationNumber);

                            cout << "Enter Degree Title: ";
                            cin.ignore();
                            getline(cin, student[i].degreeTitle);

                            break;
                        }
                    }
                    myfile.open("student.txt");

                    if (myfile.is_open())
                    {
                        for (int i = 0; i < MAX_STUDENTS; i++)
                        {
                            if (student[i].firstName != "")
                            {
                                myfile << student[i].firstName << ";";
                                myfile << student[i].lastName << ",";
                                myfile << student[i].registrationNumber << ",";
                                myfile << student[i].degreeTitle << ",";
                            }
                        }
                        myfile.close();
                        cout << "Record Save Successfully!\n\n";
                    }
                    else
                    {
                        cout << "File not opened!";
                    }
                    cout << "Do you want to Add new record or not? (Enter Y for Yes and N for No)";
                    cin >> select;
                    if (select == 'Y' || select == 'y')
                    {
                        goto repeat1;
                    }
                    else if (select == 'N' || select == 'n')
                    {
                        goto menu;
                    }
                    else
                    {
                        cout << "Invalid Input!";
                    }
                    break;
                }
                //Display Previous Records
                case '2':
                {
                    system("cls");
                    cout << "Welcome to Student Information Section\n\n";
                    cout << left << setw(7) << "S.No."
                         << left << setw(30) << "Student Name"
                         << left << setw(35) << "Student Registration Number"
                         << left << setw(35) << "Degree Title"
                         << endl;

                    i = 0;

                    if (!getstudent.is_open())
                    {
                        cout << "Item file failed to open" << endl;
                    }
                    else
                    {
                        while (!getstudent.eof() && i < MAX_STUDENTS)
                        {
                            getline(getstudent, line);
                            if (line == "")
                            {
                                continue;
                            }

                            stringstream ss(line);
                            getline(ss, student[i].firstName, ';');
                            getline(ss, student[i].lastName, ',');
                            getline(ss, student[i].registrationNumber, ',');
                            getline(ss, student[i].degreeTitle, ',');
                            len = student[i].firstName.size();
                            cout << left << setw(7) << i + 1
                                 << left << student[i].firstName << " " << left << setw(30 - len) << student[i].lastName
                                 << left << setw(30) << student[i].registrationNumber
                                 << left << setw(30) << student[i].degreeTitle
                                 << endl;
                            i++;
                        }
                        getstudent.close();
                        getch();
                        goto student;
                        break;
                    }
                }
                //Go back to menu
                case '3':
                {
                    goto menu;
                    break;
                }
                //Exit Program
                case '0':
                {
                    cout << "Program closed";
                    return 0;
                    break;
                }
                default:
                {
                    cout << "Input is invalid";
                    break;
                }
                }                     //Switch2 ends here.//
            } while (option2 != '0'); //Do-While2 ends here.//

            break;
        }
        //Teacher Information
        case '2':
        {
            do
            {
                system("cls");
                header();
                tMenu();
                cin >> option3;
                switch (option3)
                {
                case '1':
                {
                    cout << "Welcome to Teacher Information Section\n";
                    for (int i = 0; i < MAX_TEACHERS; i++)
                    {
                        if (teacher[i].tfirstName == "")
                        {
                            cout << "Enter your First Name: ";
                            cin.ignore();
                            getline(cin, teacher[i].tfirstName);

                            cout << "Enter your Last Name: ";
                            cin.ignore();
                            getline(cin, teacher[i].tlastName);

                            cout << "Enter your Qualification: ";
                            cin.ignore();
                            getline(cin, teacher[i].qualfication);

                            cout << "Enter your Expreience (year): ";
                            cin.ignore();
                            getline(cin, teacher[i].experience);

                            cout << "Enter your Contact Nunber: ";
                            cin.ignore();
                            getline(cin, teacher[i].contactNumber);

                            cout << "Enter Email Address: ";
                            cin.ignore();
                            getline(cin, teacher[i].Email);
                            break;
                        }
                    }
                    myfile.open("teacher.txt");

                    if (myfile.is_open())
                    {
                        for (int i = 0; i < MAX_TEACHERS; i++)
                        {
                            if (teacher[i].tfirstName != "")
                            {
                                myfile << teacher[i].tfirstName << ",";
                                myfile << teacher[i].tlastName << ",";
                                myfile << teacher[i].qualfication << ",";
                                myfile << teacher[i].experience << ",";
                                myfile << teacher[i].contactNumber << ",";
                                myfile << teacher[i].Email << endl;
                            }
                        }
                        myfile.close();
                        cout << "Record Save Successfully!\n\n";
                        getch();
                    }
                    else
                    {
                        cout << "File not opened!";
                        getch();
                    }
                    cout << "Do you want to Add new record or not? (Enter Y for Yes and N for No)\n";
                    cin >> select;
                    if (select == 'Y' || select == 'y')
                    {
                        goto repeat1;
                    }
                    else if (select == 'N' || select == 'n')
                    {
                        goto menu;
                    }
                    else
                    {
                        cout << "Invalid Input!";
                        getch();
                    }
                    break;
                }
                //Display record.
                case '2':
                {
                    system("cls");
                    cout << "Welcome to Teacher Information Section\n"
                         << "______________________________________________________________\n";
                    i = 0;
                    if (!getTeacher.is_open())
                    {
                        cout << "Item file failed to open" << endl;
                        return false;
                    }
                    else
                    {
                        while (!getTeacher.eof() && i < MAX_TEACHERS)
                        {
                            getline(getTeacher, line);
                            if (line == "")
                            {
                                continue;
                            }
                            stringstream ss(line);
                            getline(ss, teacher[i].tfirstName, ';');
                            cout << teacher[i].tfirstName << " ";
                            getline(ss, teacher[i].tlastName, ',');
                            cout << teacher[i].tlastName << endl;

                            getline(ss, teacher[i].experience, ',');
                            cout << "Experience: " << teacher[i].experience << endl;

                            getline(ss, teacher[i].qualfication, ',');
                            cout << "Qualification: " << teacher[i].qualfication << endl;

                            getline(ss, teacher[i].contactNumber, ',');
                            cout << "Contact Number: " << teacher[i].contactNumber << endl;

                            getline(ss, teacher[i].Email, ',');
                            cout << "Email: " << teacher[i].Email << endl;
                            cout << endl;
                            i++;
                        }
                        getTeacher.close();
                        cout << "______________________________________________________________\n";
                        getch();

                        break;
                    }
                }
                //Go back to menu
                case '3':
                {
                    goto menu;
                    break;
                }
                //Exit Program
                case '0':
                {
                    cout << "Program closed";
                    getch();
                    return 0;
                    break;
                }
                default:
                {
                    cout << "Input is invalid";
                    getch();
                    break;
                }
                }
            } while (option3 != '0');

            break;
        }
        //Exit Program
        case '0':
        {
            cout << "Program closed\n";
            getch();
            return 0;
            break;
        }
        default:
        {
            cout << "Input is invalid\n";
            getch();
            break;
        }
        }                     //Switch1 ends here.//
    } while (option1 != '0'); //Do-While1 ends here.//

    return 0;
}
void header()
{
    cout << "**************************************************************\n"
            "                   School Management System\n"
            "**************************************************************\n";
}
void menu()
{
    cout << "Choose the option from the menu:\n"
            "Enter 1 for Student Information\n"
            "Enter 2 for Teacher Information\n"
            "Enter 0 to close program\n"
            "Enter Input: ";
}
void stdMenu()
{
    cout << "Welcome to Student Infromation Section\n"
            "Choose the option from the menu:\n"
            "Enter 1 create new entry\n"
            "Enter 2 display previous record\n"
            "Enter 3 go to back\n"
            "Enter 0 to close program\n"
            "Enter Input: \n";
}
void tMenu()
{
    cout << "Welcome to Teacher Information Section\n"
            "Choose the option from the menu:\n"
            "Enter 1 create new entry\n"
            "Enter 2 display previous record\n"
            "Enter 3 go to back\n"
            "Enter 0 to close program\n"
            "Enter Input:";
}