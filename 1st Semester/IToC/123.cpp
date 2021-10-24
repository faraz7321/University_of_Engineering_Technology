#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
int main()
{
    system("CLS");
    string name;
    int option = 0, correct = 0, score = 0;
    char check, in;
    char input = 'i';

    cout << "***************************************************************\n";
    cout << "                     WELCOME TO THE GAME                       \n";
    cout << "***************************************************************\n";
    cout << "Enter Your Name: ";
    getline(cin, name);
    cout << endl;
    system("CLS");
        cout << endl;
        cout << "PRESS 'S' TO START THE GAME\n"  //1
             << "PRESS 'V' TO VIEW THE SCORE\n"  //2
             << "PRESS 'R' TO RESET THE SCORE\n" //3
             << "PRESS 'H' FOR HELP\n"           //4
             << "PRESS 'Q' TO QUIT THE GAME\n"   //5
             << "Choose an option: ";
        cin >> input;
        in = input;
    do
    {
        
        switch (in)
        {
        case 115:
        case 83:

            system("CLS");
            cout << name << ", PLEASE SELECT ONE OF THE FOLLOWING CATEGORIES TO BEGIN\n\n"
                 << "1. Games          2. Movies\n"
                 << "3. Programming    4. Science\n"
                 << "0. Go back in MENU\n"
                 << "Choose and option: ";
            cin >> option;
            switch (option)
            {
            case 1:
                //GAMES.//
                system("cls");
                cout << "Q1. The original designer behind the game Tetris is from which nation?\n";
                cout << "1. France\t\t\t2. USA\n"
                     << "3. Russia\t\t\t4. China\n"
                     << "Enter Your Option: ";

                cin >> correct;
                if (correct == 3)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is Russia.\n";
                    score = score - 50;
                }
                cout << "Press any key to continue...";
                getch();
                system("cls");
                cout << "Q2. When was Grand Theft Auto released?\n"
                     << "1. 1992\t\t\t2. 1997\n"
                     << "3. 2000\t\t\t4. 1950\n"
                     << "Enter Your Option: ";
                cin >> correct;
                if (correct == 2)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is 1997\n";
                    score = score - 50;
                }
                cout << "Press any key to continue...";
                getch();
                system("cls");
                cout << "Q3. Which one of these characters in GTA V is not playable with?\n"
                     << "1. Trevor \t\t\t2. Micheal\n"
                     << "3. Franklin\t\t\t" << right << "4. CJ\n"
                     << "Enter Your Option: ";
                cin >> correct;
                if (correct == 4)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is CJ\n";
                    score = score - 50;
                }
                cout << "Press any key to continue...";
                getch();
                system("cls");
                cout << "Q4. What does Mario jump on when he completes a level?\n";

                cout << "1. A Pipe\t\t\t2. A brick\n"
                     << "3. A flag pole\t\t\t" << right << "4. None of these\n"
                     << "Enter Your Option: ";
                cin >> correct;
                if (correct == 3)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is A flag pole\n";
                    score = score - 50;
                }
                cout << "Press any key to continue...";
                getch();
                system("cls");
                cout << "Q5. Which of the following is the game of the year of 2019?\n"
                     << "1. Sekiro: Shadows Die Twice     2. Call of Duty: Modern Warfare\n"
                     << "3. Apex Legends                  4. Mortal Combat 11\n"
                     << "Enter Your Option: ";
                cin >> correct;
                if (correct == 1)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is Sekiro: Shadows Die Twice\n";
                    score = score - 50;
                }
                cout << "Press any key to continue...";
                getch();
                system("cls");
                break;
            case 2:
                //MOVIES.//
                system("cls");
                cout << "Q1. Who directed Titanic, Avatar and The Terminator?\n"
                     << "1. quentin Tarantino       2. Martin Scorses\n"
                     << "3. James Cameron           4. David Lynch\n"
                     << "Enter Your Option: ";
                cin >> correct;
                if (correct == 3)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is James Cameron\n";
                    score = score - 50;
                }
                cout << "Press any key to continue...";
                getch();
                system("cls");
                cout << "Q2. What is the name of the lead female character in Dilwale Dulhania Le Jayenge?\n"
                     << "1. Senorita          2. Simrun\n"
                     << "3. Sunita            4. Pooja\n"
                     << "Enter Your Option: ";
                cin >> correct;
                if (correct == 2)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is Simrun\n";
                    score = score - 50;
                }
                cout << "Press any key to continue...";
                getch();
                system("cls");
                cout << "Q3. In Jab We Met, what is the name of Geet's first love?\n"

                     << "1. Aayushman      2. Anshuman\n"
                     << "3. Aakash         4. Armaan \n"
                     << "Enter Your Option: ";
                cin >> correct;
                if (correct == 1)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is Anshuman\n";
                    score = score - 50;
                }
                cout << "Press any key to continue...";
                getch();
                system("cls");
                cout << "Q4. Which one these movies was not directed by Christopher Nolan?\n"
                     << "1. Interstellar       2. Godfather\n"
                     << "3. The Dark Knight    4. Inception\n"
                     << "Enter Your Option: ";
                cin >> correct;
                if (correct == 4)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is Godfather\n";
                    score = score - 50;
                }
                cout << "Press any key to continue...";
                getch();
                system("cls");
                cout << "In which one of these movies Shahrukh Khan said\n"
                     << "'Bade bade shehron mein aisi chhoti chhoti baatein hoti rehti hain, Senorita.'?"
                     << "1. Kal Ho Naa Ho                    2. Kabhi Khushi Kabhi Gham\n"
                     << "3. Dilwalay Dhulania Le Jainge      4. Breaking Bad\n"
                     << "Enter Your Option: ";
                cin >> correct;
                if (correct == 3)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is Dilwalay Dhulania Le Jainge\n";
                    score = score - 50;
                }
                cout << "Press any key to continue...";
                getch();
                system("cls");
                break;
            case 3:
                //PROGRAMMING.//
                system("cls");
                cout << "Q1. Which programming language is called the mother of programming languages?\n"
                     << "1. Java             2. C\n"
                     << "3. A Python         4. FORTRAN\n"
                     << "Enter Your Option: ";
                cin >> correct;
                if (correct == 2)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is C\n";
                    score = score - 50;
                }
                cout << "Press any key to continue...";
                getch();
                system("cls");
                cout << "Q2. What is the other name of loop?\n"

                     << "1. Selection          2. Unconditional Transfer of Control\n"
                     << "3. Iteration          4. Sequence\n"
                     << "Enter Your Option: ";
                cin >> correct;
                if (correct == 3)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is Iteration\n";

                    score = score - 50;
                }
                cout << "Press any key to continue...";
                getch();
                system("cls");
                cout << "Q3. If we want to find the greater of two numbers, We'll use?\n"
                     << "1. if-else           2. For loop\n"
                     << "3. while loop        4. switch statement\n"
                     << "Enter Your Option: ";
                cin >> correct;
                if (correct == 1)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is if-else\n";
                    score = score - 50;
                }
                cout << "Press any key to continue...";
                getch();
                system("cls");
                cout << "Q4. What is a variable?\n"
                     << "1. Address of the memory location       2. address of register\n"
                     << "3. Name of the memory location          4. Memory itself\n"
                     << "Enter Your Option: ";
                cin >> correct;
                if (correct == 3)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is Name of the memory location\n";

                    score = score - 50;
                }
                cout << "Press any key to continue...";
                getch();
                system("cls");
                cout << "Q5. How many arguments \"for\" loop contains?\n"
                     << "1. 1          2. 2\n"
                     << "3. 3          4. 4\n"
                     << "Enter Your Option: ";
                cin >> correct;
                if (correct == 3)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is 3";
                    score = score - 50;
                }
                cout << "Press any key to continue...";
                getch();
                system("cls");
                break;
            case 4:
                //SCIENCE.//
                system("cls");
                cout << "Q1. How any object can travel from one galaxy to other in minimum amount of time?\n"
                     << "1. Through Blackhole         2. Through Wormhole\n"
                     << "3. Through Time Travel       4. Using Space Rockets\n"
                     << "Enter Your Option: ";
                cin >> correct;
                if (correct == 2)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is Through Wormhole\n";
                    score = score - 50;
                }
                cout << "Press any key to continue...";
                getch();
                system("cls");
                cout << "Q2. According to time dilation, which of the following is true?\n"
                     << "1. Time is slow where gravity is high       2. Time is fast where gravity is high\n"
                     << "3. Time doesn't depend on gravity           4. Time is constant for both massive and lighter bodies\n"
                     << "Enter Your Option: ";
                cin >> correct;
                if (correct == 1)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is Time is slow where gravity is high\n";
                    score = score - 50;
                }
                cout << "Press any key to continue...";
                getch();
                system("cls");
                cout << "Q3. Event Horizon Telescope was used to discover a blackhole recently, what is Even Horizon Telescope actually?\n"
                     << "1. Name of Telescope            2. Global Network of Telescope\n"
                     << "3. Type of radio telescope      4. None of them\n"
                     << "Enter Your Option: ";
                cin >> correct;
                if (correct == 2)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is Global Network of Telescope\n";
                    score = score - 50;
                }
                cout << "Press any key to continue...";
                getch();
                system("cls");
                cout << "Q4. What is the name of the 1st clonned Sheep?\n"
                     << "1. Dolly       2. Molly\n"
                     << "3. Minnie      4. Dixie\n"
                     << "Enter Your Option: ";
                cin >> correct;
                if (correct == 1)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is Dolly\n";
                    score = score - 50;
                }
                cout << "Press any key to continue...";
                getch();
                system("cls");
                cout << "Q5. Ripples in space-time are produced by black hole are called?\n"
                     << "1. Black Waves               2. space-time Waves\n"
                     << "3. Gravitational Waves       4. Cosmos Waves\n"
                     << "Enter Your Option: ";
                cin >> correct;
                if (correct == 3)
                {
                    cout << "HURRAY!!!  Your Answer is Correct!!!\n";
                    score = score + 100;
                }
                else
                {
                    cout << "Sorry,Your Answer is Wrong\n"
                         << "Correct Answer is Gravitational Waves\n";
                    score = score - 50;
                }
                in = 81;
                break;
            } //switch of case 1 closes here.
        case 104:
        case 72:
            system("CLS");
            cout << "1) There are 4 categories in the game, you can chose any of them.\n"
                 << "2) Each category consist of 5 questions.\n"
                 << "3) Each Question carries 100 marks.\n"
                 << "4) 100 marks will be awarded upon choosing correct option.\n"
                 << "   There will be negative marking of 50 upon choosing wrong answer.\n\n"
                 << "Press any key to continue...\n";
            getch();
            break;
        case 118:
        case 86:

            system("CLS");
            cout << name << " has scored " << score << " marks.\n"
                 << "Press any key to continue...\n";
            getch();
            break;

        case 82:
        case 114:

            system("cls");
            score = 0;
            cout << "SCORE HAD BEEN RESET\n"
                 << "Press any key to continue...\n";
            getch();
            break;

        case 81:
        case 113:
            system("CLS");
            cout << "Shutting Down...";
            break;
        }
    } while (in != 81 || in != 113);

    cout << "Thank you!";
}