#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

//functions outside the main  are global variable
// we will discuss global variables later

void loadData(); //Don't bother about this code, you will learn it later.

const int qsize = 20; //Maximum number of questions
const int usize = 5;  //Maximum number of users
//variable area
bool qflag[qsize] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}; //use this array to check whether an element exist on an index or not.
string question[qsize];
string option1[qsize];
string option2[qsize];
string option3[qsize];
string option4[qsize];
string correctOption[qsize];

bool uflag[usize] = {false, false, false, false, false}; //use this array to check whether an element exist on an index or not.
string username[usize];
string passwords[usize];
int scores[usize]; //array will be used to save the score attempted.
int main()
{

    string user;
    string pwd;
    bool userSearchFlag = false;

    int input;

    int loggedInUserType = -10; //1 for administrator, 2 for user

    //TODO-- Initializtion of all arrays
    //assign an intial values to all arrays here.

    int j = 1, i, u;
    string username1, ans[i];
    int totalm[5] = {0, 0, 0, 0, 0};
    bool p = 1;

    loadData(); //Don't bother about this code, you will learn it later.

    //program header
    cout << "***************************************************************\n";
    cout << "                     Quiz System                               \n";
    cout << "***************************************************************\n";

    do
    {
        cout << endl;
        cout << "Choose the desired option\n";
        cout << left << setw(10) << "\t"
             << setw(25) << "1. Administrator Login"
             << setw(25) << "2. User Login"
             << setw(25) << "0. Exit";
        cout << endl;

        cout.unsetf(ios::left);
        cout.unsetf(ios::right);

        cout << "\tChoose an option: ";
        cin >> input;
        cout << endl;

        switch (input)
        {

        case 1:
            cout << "Enter the username: ";
            cin >> user;

            cout << "Enter Password: ";
            cin >> pwd;

            if (user == "Administrator" && pwd == "PF2020")
                loggedInUserType = 1;
            else
                loggedInUserType = -1;
            break;
        case 2:
            cout << "Enter the username: ";
            cin >> user;

            cout << "Enter Password: ";
            cin >> pwd;
            //write code to search user from user list
            for (i = 0; i < usize; i++)
            {
                if (user == username[i] && pwd == passwords[i])
                {
                    userSearchFlag = true;
                    u = i;
                    break;
                }
            }

            if (userSearchFlag == true)
            {
                loggedInUserType = 2;
            }
            else
            {
                loggedInUserType = -1;
            }
            break;
        case 0:
            loggedInUserType = -10;
            cout << "Thank you for using system" << endl;
            break;

        default:
            cout << "Invalid choice!!!";
            break;
        }

        if (loggedInUserType == 1) //administrator
        {
            do
            {
                cout << endl;
                cout << "Choose the desired option\n";
                cout << left << setw(20) << "\tQuestions"
                     << setw(15) << "1. Add"
                     << setw(15) << "2. Delete"
                     << setw(15) << "3. Update"
                     << setw(15) << "4. List";
                cout << endl;

                cout << setw(20) << "\tUsers"
                     << setw(15) << "5. Register"
                     << setw(15) << "6. Edit"
                     << setw(15) << "7. Delete"
                     << setw(15) << "8. List"
                     << endl;

                cout << left << setw(20) << "\t"
                     << setw(15) << "9. View Scores"
                     << setw(15) << " "
                     << setw(15) << "0. Logout";
                cout << endl;

                cout.unsetf(ios::left);
                cout.unsetf(ios::right);

                cout << "\tChoose an option: ";
                cin >> input;

                switch (input)
                {
                case 1:
                    for (i = 0; i < qsize; i++)
                    {
                        if (qflag[i] == false)
                        {
                            cout << "Enter the Question: ";
                            cin.ignore(25, '\n');
                            getline(cin, question[i]);
                            cout << endl;
                            cout << "Enter Options: ";
                            cin >> option1[i] >> option2[i] >> option3[i] >> option4[i];
                            cout << "Enter the correct option: ";
                            cin >> correctOption[i];
                            qflag[i] = true;
                            break;
                        }
                    }
                    cout << endl;
                    break;

                //End of case 1.//
                case 2:
                    cout << left << setw(5) << "Q.I" << left << setw(40) << "Question"
                         << left << setw(20) << "option 1" << left << setw(20) << "option 2"
                         << left << setw(20) << "option 3" << left << setw(20) << "option 4"
                         << left << setw(20) << "correct answer" << endl;
                    cout << "*************************************************************************"
                         << "*************************************************************************" << endl;
                    j = 1;
                    for (i = 0; i < qsize; i++)
                    {
                        if (qflag[i] == true)
                        {
                            cout << left << setw(5) << j << left << setw(40) << question[i]
                                 << left << setw(20) << option1[i] << left << setw(20) << option2[i]
                                 << left << setw(20) << option3[i] << left << setw(20) << option4[i]
                                 << left << setw(20) << correctOption[i] << endl;
                            j++;
                        }
                    }
                    cout << endl;
                    cout << "Select Question ID (Q.I) to delete a question: ";
                    cin >> j;
                    if (qflag[j - 1] == true)
                    {
                        qflag[j - 1] = false;
                        cout << endl;
                        cout << "Question Deleted Successfully!";
                    }
                    else
                    {
                        cout << endl;
                        cout << "Invalid Option!";
                    }

                    cout << endl;
                    break;

                //End of case 2.//
                case 3:
                    j = 1;
                    cout << left << setw(5) << "Q.I" << left << setw(40) << "Question"
                         << left << setw(20) << "option 1" << left << setw(20) << "option 2"
                         << left << setw(20) << "option 3" << left << setw(20) << "option 4"
                         << left << setw(20) << "correct answer" << endl;
                    cout << "*************************************************************************"
                         << "*************************************************************************" << endl;
                    for (i = 0; i < qsize; i++)
                    {
                        if (qflag[i] == true)
                        {
                            cout << left << setw(5) << j << left << setw(40) << question[i]
                                 << left << setw(20) << option1[i] << left << setw(20) << option2[i]
                                 << left << setw(20) << option3[i] << left << setw(20) << option4[i]
                                 << left << setw(20) << correctOption[i] << endl;
                            j++;
                        }
                    }
                    cout << endl;
                    cout << "Select Question ID (Q.I) to update a question: ";
                    cin >> j;
                    if (qflag[j - 1] == true)
                    {
                        cout << "Enter the updated question: ";
                        cin.ignore(25, '\n');
                        getline(cin, question[j - 1]);
                        cout << endl;
                        cout << "Enter Options: ";
                        cin >> option1[j - 1] >> option2[j - 1] >> option3[j - 1] >> option4[j - 1];
                        cout << "Enter the correct option: ";
                        cin >> correctOption[j - 1];
                        qflag[j - 1] = true;
                        break;
                        cout << endl;
                        cout << "Question Updated Successfully!";
                    }
                    else
                    {
                        cout << endl;
                        cout << "Invalid Option!";
                    }

                    cout << endl;

                    break;

                //End of case 3.//
                case 4:
                    j = 0;
                    cout << left << setw(5) << "Q.I" << left << setw(40) << "Question"
                         << left << setw(20) << "option 1" << left << setw(20) << "option 2"
                         << left << setw(20) << "option 3" << left << setw(20) << "option 4"
                         << left << setw(20) << "correct answer" << endl;
                    cout << "*************************************************************************"
                         << "*************************************************************************" << endl;
                    for (i = 0; i < qsize; i++)
                    {
                        if (qflag[i] == true)
                        {
                            cout << left << setw(5) << j << left << setw(40) << question[i]
                                 << left << setw(20) << option1[i] << left << setw(20) << option2[i]
                                 << left << setw(20) << option3[i] << left << setw(20) << option4[i]
                                 << left << setw(20) << correctOption[i] << endl;
                            j++;
                        }
                    }
                    cout << endl;
                    break;
                //End of case 4.//
                case 5:
                    for (i = 0; i < 5; i++)
                    {
                        if (uflag[i] == false)
                        {
                            cout << "Enter username: ";
                            cin >> username[i];
                            cout << "Enter Password: ";
                            cin >> passwords[i];
                            uflag[i] = true;
                            cout << "User Register Successfully!";
                            break;
                        }
                    }
                    cout << endl;
                    break;
                //End of case 5.//
                case 6:
                    cout << "Enter Username to edit/update: ";
                    cin >> username1;
                    for (i = 0; i < 5; i++)
                    {
                        if (username1 == username[i] && uflag[i] == true)
                        {
                            cout << "Enter updated username: ";
                            cin >> username[i];
                            cout << "Enter updated password: ";
                            cin >> passwords[i];
                            cout << "User Updated Successfully!";
                            break;
                        }
                    }
                    cout << endl;
                    break;
                //End of case 6.//
                case 7:
                    cout << "Enter username to delete: ";
                    cin >> username1;
                    for (i = 0; i < 5; i++)
                    {
                        if (username1 == username[i])
                        {
                            uflag[i] = false;
                            cout << "User Deleted Successfully!";
                            break;
                        }
                    }
                    break;
                case 8:
                    j = 1;
                    cout << left << setw(5) << "U.I" << left << setw(20) << "Username"
                         << left << setw(20) << "Password" << endl;
                    cout << "*************************************************************************" << endl;
                    for (i = 0; i < qsize; i++)
                    {
                        if (uflag[i] == true)
                        {
                            cout << left << setw(5) << j << left << setw(20) << username[i]
                                 << left << setw(20) << passwords[i] << endl;
                            j++;
                        }
                    }
                    break;
                case 9:
                    cout << left << setw(20) << "Username" << left << setw(30) << "Attained Marks"
                         << left << setw(30) << "Total Marks" << endl;
                    cout << "*************************************************************************" << endl;
                    for (i = 0; i < qsize; i++)
                    {
                        if (uflag[i] == true)
                        {
                            cout << left << setw(30) << username[i] << left << setw(20) << scores[i]
                                 << left << setw(20) << totalm[i];
                            j++;
                        }
                    }
                    break;
                case 0:
                    cout << "Thank you for using the system!" << endl;
                    cout << "***************************************************************" << endl
                         << "                          Quiz System" << endl
                         << "***************************************************************" << endl;
                    break;

                default:
                    cout << "Invalid choice!!!";
                    break;
                }
            } while (input != 0);
            input = -1; //this statment is to make sure that do not exit from outer loop
        }
        else if (loggedInUserType == 2) //user
        {
            cout << endl;
            cout << "Choose the desired option\n";
            cout << left << setw(10) << "\t"
                 << setw(25) << "1. Attempt Quiz"
                 << setw(25) << "2. View Score"
                 << setw(25) << "0. Logout";
            cout << endl;

            cout.unsetf(ios::left);
            cout.unsetf(ios::right);

            cout << "\tChoose an option: ";
            cin >> input;

            do
            {
                switch (input)
                {

                case 1:
                    j = 1;
                    for (i = 0; i < qsize; i++)
                    {
                        if (qflag[i] == true)
                        {
                        	totalm[u]=totalm[u]+1;
                            cout << "Q." << left << setw(5) << j << question[i] << endl
                                 << "A. " << left << setw(10) << option1[i] << "B. " << left << setw(10) << option2[i]
                                 << "C. " << left << setw(10) << option3[i] << "D. " << left << setw(10) << option4[i] << endl
                                 << "Enter your answer: ";
                            cin.ignore(25, '\n');
                            getline(cin, ans[i]);
                            if (ans[i] == correctOption[i])
                            {
                                scores[u] = scores[u] + 1;
                            }
                            cout << "Do you want to proceed or submit quiz? (1/0): ";
                            cin >> input;
                            j++;
                            if (input == 0)
                            {
                                break;
                            }
                        }
                    }
                    input = 0;
                    break;
                case 2:
                	cout << "*************************************************************************" << endl;
                    cout << left << setw(20) << "Username" << left << setw(30) << "Attained Marks"
                         << left << setw(30) << "Total Marks" << endl;
                    cout << "*************************************************************************" << endl;
                    //for (int i = 0; i < qsize; i++)
                   // {
                        if (uflag[u] == true)
                        {
                            cout << left << setw(30) << username[u] << left << setw(20) << scores[u]
                                 << left << setw(20) << totalm[u] << endl;
                            //j++;
                        }
                   // }
                    input=0;
                    break;

                case 0:
                    cout << "You are logged out" << endl;
                    break;

                default:
                    cout << "Invalid choice!!!";
                    break;
                }
            } while (input != 0);
            input = -1; //this statment is to make sure that do not exit from outer loop
        }
        else if (loggedInUserType == -1)
        {
            cout << "You have entered invalid Credentials!!!" << endl;
        }
    } while (input != 0);

    return 0;
}

void loadData()
{
    ifstream inf1("UserList.csv");
    string line1, field1;
    vector<vector<string> > array1;
    vector<string> v1;
    string usr = "user";
    while (getline(inf1, line1))
    {
        v1.clear();
        stringstream ss(line1);
        while (getline(ss, field1, ','))
        {
            v1.push_back(field1);
        }
        array1.push_back(v1);
    }
    for (size_t i = 1; i < array1.size(); ++i)
    {
        uflag[i] = true;
        username[i] = array1[i][0];
        passwords[i] = array1[i][1];
    }
    inf1.close();

    ifstream in("QuesionsList.csv");
    string line, field;
    vector<vector<string> > array;
    vector<string> v;

    while (getline(in, line))
    {
        v.clear();
        stringstream ss(line);
        while (getline(ss, field, ','))
        {
            v.push_back(field);
        }
        array.push_back(v);
    }
    for (size_t i = 1; i < array.size(); ++i)
    {
        qflag[i] = true;
        question[i] = array[i][0];
        option1[i] = array[i][1];
        option2[i] = array[i][2];
        option3[i] = array[i][3];
        option4[i] = array[i][4];
        correctOption[i] = array[i][5];
    }
    in.close();
}
