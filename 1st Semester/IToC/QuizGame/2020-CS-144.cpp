#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
using namespace std;

// Global Variables
const int total_questions = 20;
int question_counter = 0;
string questions[total_questions]; //from index 0 to 4 in questions array (questions related to Category 1)
                                   //from index 4 to 9 in questions array (questions related to Category 2)
                                   //from index 10 to 14 in questions array (questions related to Category 3)
                                   //from index 14 to 19 in questions array (questions related to Category 4)
string option1[total_questions];
string option2[total_questions];
string option3[total_questions];
string option4[total_questions];
int correct_option[total_questions];

int count = -1;
string player[5] = {"NV", "NV", "NV", "NV", "NV"};
int score[5] = {0, 0, 0, 0, 0};

// Functions Declaration
void quiz_heading();    //This function will show the main heading of welcome to the quiz game and then ask the player name and the store the name in player array.//
char menu_option();     //Menu will be displayed.//
int highest_score();    //This function will search the whole array of scores and return the index on which the highest score is present.//
int lowest_score();     //This function will search the whole array of scores and return the index on which the lowest score is present.//
int select_category();  //This function will show the user about the available categories of your Quiz game and then ask the user to select 1 category and then return that category to main fuction.//
void view_players();    //This function will show all the available players and their scores.//
void reset_score();     //This function will reset the score of the current player.//
void help();            //Shows Help menu.//
void add_data();        //This function will call the add_question("Question", "Option 1", "Option 2", "Option 3", "Option 4", correct option number) 20 times
                        //and add all the questions related to your categories.*/
void ask_question(int); //This function will receive the index of the question that you want to ask the user and then show the question and its available
                        //options. then ask the user about the correct option and then check whether the user entered the correct option or not. then it will
                        //calculate the marks for the current logged in user.//
void add_question(
    string, string, string, string, string, int); //This function will store the questions in your related global parallel arrays defined at the begining of the code.//
void halt();
//Main function
int main()
{
    system("CLS");
    char option = 'a';
    int number;
    char changeUser;
    string name;
    int highestindex;
    int lowestindex;
    add_data();

start:
    quiz_heading();
    halt();
    do
    {
        option = menu_option();
        system("CLS");
        if (option == 'T' || option == 't')
        {
            highestindex = highest_score();
            cout << "The highest score is " << score[highestindex] << ", of player "
                 << "'" << player[highestindex] << "'\n";
        }
        if (option == 'L' || option == 'l')
        {
            lowestindex = lowest_score();
            cout << "The lowest score is " << score[lowestindex] << ", of player "
                 << "'" << player[lowestindex] << "'\n";
        }
        if (option == 'S' || option == 's')
        {
            number = select_category();
            halt();
            ask_question(number);
        repeat:
            cout << "\n"
                 << "Your Quiz finished. If you want to Continue as " << player[count] << "\n"
                 << "Press Y otherwise Press N\n";
            cin >> changeUser;
            if (changeUser == 'N' || changeUser == 'n')
            {
                goto start;
                system("CLS");
            }
            else if (changeUser == 'Y' || changeUser == 'y')
            {
                system("CLS");
            }
            else
            {
                cout << "You entered invalid option\n";
                goto repeat;
                system("CLS");
            }
        }
        if (option == 'v' || option == 'V')
        {
            view_players();
        }
        if (option == 'R' || option == 'r')
        {
            reset_score();
        }
        if (option == 'H' || option == 'h')
        {
            help();
        }
    } while ((option != 'q') && (option != 'Q'));
    return 0;
}

// Functions Definition

void quiz_heading()
{
    count++;
    cout << "-------------------------------------------------------------------------------------------------\n";
    cout << "                                   Welcome to Quiz Game\n";
    cout << "-------------------------------------------------------------------------------------------------\n";
    cout << "Enter your Name: ";
    cin >> player[count];
}
char menu_option()
{
    char op;
    cout << "**********************************************************\n"
         << "                 MENU OF THE GAME                         \n"
         << "**********************************************************\n"
         << "> Press S to Start the Game.\n"
         << "> Press V to View the Score of all Players.\n"
         << "> Press T to View the Highest Score of the Player.\n"
         << "> Press L to View the Lowest Score of the Player.\n"
         << "> Press R to Reset the Score of current Player.\n"
         << "> Press H for Help.\n"
         << "> Press Q to Quit the Game.\n";
    cin >> op;
    return op;
}
int highest_score()
{
    int high = -1, x;
    for (int i = 0; i < 5; i++)
    {
        if (score[i] > high)
        {
            high = score[i];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (score[i] == high)
        {
            x = i;
            break;
        }
    }
    return x;
}
int lowest_score()
{
    int low = 99999999, x;
    for (int i = 0; i < 5; i++)
    {
        if (score[i] < low)
        {
            low = score[i];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (score[i] == low)
        {
            x = i;
            break;
        }
    }
    return x;
}
int select_category()
{
    int category;
    cout << player[count] << ", Select an option from the folowing Categories:\n";
    cout << "\n";
    cout << "1. Games            2. Programming\n";
    cout << "3. Movies           4. Music\n";
    cout << "Enter your option: ";
    cin >> category;
    return category;
}
void add_data()
{
    ifstream q, ca;
    int times;
    string ques;
    string o1, o2, o3, o4;
    int option;
    q.open("data.text");
    ca.open("CA");
    q >> times;
    for (int i = 0; i < 20; i++)
    {
        getline(q, ques);
        getline(q, o1);
        getline(q, o2);
        getline(q, o3);
        getline(q, o4);
        ca >> option;
        add_question(ques, o1, o2, o3, o4, option);

    } //how to close
    
   // q.close("data.text");
  //  ca.close("CA.txt");

    // nooooooo lol
    //blkay nai sahi hi ha
}
void add_question(string q, string o1, string o2, string o3, string o4, int ans)
{
    questions[question_counter] = q;
    option1[question_counter] = o1;
    option2[question_counter] = o2;
    option3[question_counter] = o3;
    option4[question_counter] = o4;
    correct_option[question_counter] = ans;
    question_counter++;
}
void ask_question(int index)
{
    int option;
    switch (index)
    {
    case 1:
        for (int i = 0; i < 5; i++)
        {
            cout << questions[i] << "\n";
            cout << option1[i] << setw(30) << option2[i] << "\n";
            cout << option3[i] << setw(30) << option4[i] << "\n";
            cout << "Enter Option Number: ";
            cin >> option;
            if (option == correct_option[i])
            {
                cout << "Hurray !!! Your Answer is Correct!!!\n";
                score[count] = score[count] + 100;
            }
            else
            {
                cout << "Sorry, Your Answer  is Wrong\n";
                cout << "Correct Answer is " << correct_option[i] << "\n";
                score[count] = score[count] - 50;
            }
            halt();
        }
        break;
    case 2:
        for (int i = 5; i < 10; i++)
        {
            cout << questions[i] << "\n";
            cout << option1[i] << setw(30) << option2[i] << "\n";
            cout << option3[i] << setw(30) << option4[i] << "\n";
            cout << "Enter Option Number: ";
            cin >> option;
            if (option == correct_option[i])
            {
                cout << "Hurray !!! Your Answer is Correct!!!\n";
                score[count] = score[count] + 100;
            }
            else
            {
                cout << "Sorry, Your Answer  is Wrong\n";
                cout << "Correct Answer is " << correct_option[i] << "\n";
                score[count] = score[count] - 50;
            }
            halt();
        }
        break;
    case 3:
        for (int i = 10; i < 15; i++)
        {
            cout << questions[i] << "\n";
            cout << option1[i] << setw(30) << option2[i] << "\n";
            cout << option3[i] << setw(30) << option4[i] << "\n";
            cout << "Enter Option Number: ";
            cin >> option;
            if (option == correct_option[i])
            {
                cout << "Hurray !!! Your Answer is Correct!!!\n";
                score[count] = score[count] + 100;
            }
            else
            {
                cout << "Sorry, Your Answer  is Wrong\n";
                cout << "Correct Answer is " << correct_option[i] << "\n";
                score[count] = score[count] - 50;
            }
            halt();
        }
        break;
    case 4:
        for (int i = 15; i < 20; i++)
        {
            cout << questions[i] << "\n";
            cout << option1[i] << setw(30) << option2[i] << "\n";
            cout << option3[i] << setw(30) << option4[i] << "\n";
            cout << "Enter Option Number: ";
            cin >> option;
            if (option == correct_option[i])
            {
                cout << "Hurray !!! Your Answer is Correct!!!\n";
                score[count] = score[count] + 100;
            }
            else
            {
                cout << "Sorry, Your Answer  is Wrong\n";
                cout << "Correct Answer is " << correct_option[i] << "\n";
                score[count] = score[count] - 50;
            }
            halt();
        }
        break;
    default:
        cout << "Invalid Category";
        halt();
        break;
    }
}
void view_players()
{
    cout << "_______________________________________________________\n";
    cout << left << setw(30) << "Username" << setw(30) << "Points" << endl;
    cout << "_______________________________________________________\n";
    for (int i = 0; i < 5; i++)
    {
        if (player[i] != "NV")
        {
            cout << left << setw(30) << player[i] << setw(30) << score[i] << "\n";
        }
        else
        {
            break;
        }
    }
    halt();
}
void reset_score()
{
    score[count] = 0;
    cout << "The score has been reset.\n";
    halt();
}
void help()
{
    cout << "Here are some of the Rules and Regulations of the Game.\n"
         << "Firstly, there will be no hooting and shouting while playing the game.\n"
         << "There are 4 categories in the Game.\n"
         << "You can choose any one of them.\n"
         << "Each category consists of 5 Questions.\n"
         << "Each Question carries 100 Marks.\n"
         << "Correct answer will give you +100 marks whereas Wrong answer will give you -50 marks\n";
    halt();
}
void halt()
{
    cout << "Press any key to continue...\n";
    getch();
    system("CLS");
}