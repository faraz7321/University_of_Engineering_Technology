#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#define BUFFER 10
using namespace std;

void initializeCourses(string codeList[], string nameList[], int crtHrsList[], int semList[], int size);
void initializeUsers(string usernames[], string passwords[], int size);

//function for data persistent
bool saveCourse(string codeList[], string nameList[], int crtHrsList[], int semList[], int size);
bool loadCourses(string codeList[], string nameList[], int crtHrsList[], int semList[], int size);
bool loadUser(string usersList[], string passwordList[], int size);

//COURSE MANAGEMENT
int searchCourseCode(string codeList[], int size, string courseCode);
bool addCourses(string codeList[], string nameList[], int creditHours[], int semList[], int size, string courseCode, string courseName, int credit, int semester);
void viewCourses(string codeList[], string nameList[], int creditHours[], int semList[], int size);
void viewSemesterCourse(string codeList[], string nameList[], int creditHours[], int semList[], int size, int semester);
bool updateCourse(string codeList[], string nameList[], int creditHours[], int semList[], int size, string courseCode, string courseName, int credit, int semester);
bool deleteCourse(string codeList[], string nameList[], int creditHours[], int semList[], int size, string courseCode);

//VALIDATION FUNCTIONS
bool isValidCourseCode(string code);
bool isValidCreditHours(int creditHours);
bool isValidSemester(int semester);
bool isValidCourseName(string name);
bool validateAllData(string courseCode, string courseName, int credit, int semester);
bool isValidRegistrationNumber(char regNo[]); //– Acceptable Format 20XX-CY-001
bool isValidStudentName(char studentName[]);  //– Use same rules as per course name.

//USER MANAGEMENT
bool userExist(string user[], string pass[], string users, string passs, int size);
void login(string &userName, string &password);

//STUDENT MANAGEMENT
bool addStudent(string stdNamesList[], string stdRegNoList[], int stdArraySize, string studentName, string regNo);
bool updateStudent(string stdNamesList[], string stdRegNoList[], int stdArraySize, string stdRegNoToUpdate, string studentName, string regNo);
bool deleteStudent(string stdNamesList[], string stdRegNoList[], string stdCourseList[], int stdArraySize, string regNo);
bool registerCourse(string stdRegNoList[], string stdCourseList[], string courseCodeList, int stdArraySize, string regNo, string courseCode);
//This function checks if given courseCode is in courseCodeList or not. If yes, then adds it in stdCourseList[] against student’s index.
bool unRegisterCourse(string stdRegNoList[], string courseList[], int stdArraySize, string regNo, string courseCode);
bool loadStudents();
bool saveStudents();
void viewstudents(string stdRegNoList[], string stdNameList[]);

int main()
{
    //Maximum Size of All arrays
    int MAX_COURSES = 10;
    int MAX_USERS = 10;
    int MAX_STUDENTS[BUFFER];
    bool flag = false;
    string userName;
    string password;
    string courseCode;
    string courseName;
    int credit;
    int semester;
    int input;
    //Declare All Arrays
    string usersList[MAX_USERS], passwordList[MAX_USERS];
    string codeList[MAX_COURSES], nameList[MAX_COURSES];
    int creditHours[MAX_COURSES], semList[MAX_COURSES];
    string stdNamesList[BUFFER], stdRegNoList[BUFFER], stdCourseList[BUFFER];

    //Initialize all arrays
    initializeCourses(codeList, nameList, creditHours, semList, MAX_COURSES);
    initializeUsers(usersList, passwordList, MAX_USERS);

    //This function will load the courses in arrays
    loadCourses(codeList, nameList, creditHours, semList, MAX_COURSES);

    //This function will load the users in array
    loadUser(usersList, passwordList, MAX_USERS);

    //Variables
    char regNo[10], studentName[100];
    //string stdNameList, stdRegNoList;
    int stdArraySize = 100;

    //For starting code
    login(userName, password);

    for (int i = 0; i < BUFFER; i++)
    {
        stdNamesList[i] = "NV";
        stdRegNoList[i] = "NV";
        stdCourseList[i] = "NV";
    }
    do
    {
        while (userExist(usersList, passwordList, userName, password, MAX_USERS) != true || (userName == "" && password == ""))
        {
            cout << "Incorrect info! Please reenter username and password\n";
            cout << "Enter User name: ";
            cin >> userName;
            cout << "Enter Password: ";
            cin >> password;
            cout << endl;
        }
        if (userExist(usersList, passwordList, userName, password, MAX_USERS))
        {
            cout << "Choose the following option\n"
                 << "1    Add Courses\n"
                 << "2    Update Courses\n"
                 << "3    Delete Courses\n"
                 << "4    View All Courses\n"
                 << "5    View Courses of a Semester\n"
                 << "6    Add new student\n"
                 << "7    Update Student\n"
                 << "8    Delete Student\n"
                 << "9    View All Students\n"
                 << "10   Register the course for student\n"
                 << "11   Unregister the course for student\n"
                 << "12   Logout of the system\n"
                 << "13   Exit Program\n"
                 << "Enter the option: ";
            cin >> input;
            switch (input)
            {
            // This case for adding the course details
            case 1:
            {
                cout << "Enter the details of the course: ";
                cin >> courseCode;
                cin >> credit;
                cin >> semester;
                cin.ignore();
                getline(cin, courseName);
                //Check validity of all inputs
                if (validateAllData(courseCode, courseName, credit, semester))
                {
                    //Call addCourse function
                    if (addCourses(codeList, nameList, creditHours, semList, MAX_COURSES, courseCode, courseName, credit, semester))
                    {
                        cout << "Course added SUCCESSFULY!\n";
                    }
                    else
                    {
                        cout << "Sorry! No space to add new course\n";
                    }
                }
                else
                {
                    //If any validity is false it will not add the course
                    cout << "Invalid details\n";
                }
                break;
            }
            // This case for Updating the course details
            case 2:
            {
                cout << "Enter the course code\n";
                cin >> courseCode;

                //check validity of courseCode
                if (!isValidCourseCode(courseCode))
                {
                    //Find the index of courseCode which user entered to update the course details
                    cout << "Enter the details of the course: ";
                    cin >> courseCode;
                    cin >> credit;
                    cin >> semester;
                    cin.ignore();
                    getline(cin, courseName);
                    //Check validity of all details entered by user
                    if (validateAllData(courseCode, courseName, credit, semester))
                    {
                        if (updateCourse(codeList, nameList, creditHours, semList, MAX_COURSES, courseCode, courseName, credit, semester))
                        {
                            cout << "Course successfully updated\n";
                        }
                        else
                        {
                            cout << "No course found\n";
                        }
                    }
                    else
                    {
                        cout << "Invalid data\n";
                    }
                }
                else
                {
                    //here we will show message of not valid data
                    cout << "Invalid Data\n";
                }
                break;
            }
            //This case for deleting the course details
            case 3:
            {
                cout << "Enter Course code\n";
                cin >> courseCode;
                //Validate the course Code
                if (!isValidCourseCode(courseCode))
                {
                    //call function to delete the course detail which has same course code as user enter
                    if (deleteCourse(codeList, nameList, creditHours, semList, MAX_COURSES, courseCode))
                    {
                        cout << "Course Successfully deleted\n";
                    }
                    else
                    {
                        cout << "Sorry No Course found \n";
                    }
                }
                else
                {
                    //if course code is invalid then this message will show
                    cout << "Invalid Course code\n";
                }
                break;
            }
            //This case for displaying all details of all courses
            case 4:
            {
                //View all courses
                viewCourses(codeList, nameList, creditHours, semList, MAX_COURSES);
                break;
            }
            //This case for displaying course details of specific semester
            case 5:
            {
                cout << "Enter the semester:";
                cin >> semester;
                //Check valildidty of semester entered by user
                if (isValidSemester(semester))
                {
                    //Show All details of course of the semester entered by user
                    viewSemesterCourse(codeList, nameList, creditHours, semList, MAX_COURSES, semester);
                }
                else
                {
                    //If our semester is invalid
                    cout << "Invalid data\n";
                }
                break;
            }
            // Add New Student
            case 6:
            {
                cout << "Enter details of the Student: ";
                cin >> regNo;
                cin.get(studentName, 100);
                if (isValidRegistrationNumber(regNo) == false && isValidStudentName(studentName) == false)
                {
                    cout << "\nError! Invalid Registration number or Student Name.\n";
                }
                else
                {
                    addStudent(stdNamesList, stdRegNoList, stdArraySize, studentName, regNo);
                    if (addStudent(stdNamesList, stdRegNoList, stdArraySize, studentName, regNo) == true)
                    {
                        cout << "Student has been added successfully\n";
                    }
                    else
                    {
                        cout << "Error adding Student\n";
                    }
                }
                break;
            }
            // Update Student
            case 7:
            {
                cout << "Enter registration Number of the student to edit: ";
                cin >> regNo;
                cout << "Enter details of the student : ";
                cin >> studentName;
                cin.ignore();
                cin.get(studentName, 100);

                if (isValidStudentName(studentName) && isValidRegistrationNumber(stdReg))
                {

                    if (updateStudent(stdNameList, stdRegNoList, MAX_STUDENTS, regToUpdate, stdName, stdReg))
                    {
                        cout << "Student has been Updated Successfully...!" << endl
                             << "Press any key to continue" << endl;

                        getch();
                    }
                }
                else
                {
                    cout << "You have entered invalid data....! " << endl;
                }
                break;
            }
            // Delete Student
            case 8:
            {
                cout << "Enter registration Number of the student to delete: ";
                //cin >> ;
                /*  if(deleteStudent()==true)
                {
                    cout << "Student has been deleted successfully";
                }
                else
                {
                    cout << "Error";
                }
            */
                break;
            }
            // View All Students
            case 9:
            {
                //viewstudents(stdRegNoList[], stdNameList[]);

                break;
            }
            // Register the Course For Student
            case 10:
            {
                //registerCourse();

                break;
            }
            // Unregister the Course For Student
            case 11:
            {
                cout << "Enter registration Number of the student: ";
                //cin >> ;
                cout << "Enter Course Code to unregister: ";
                /*if (unRegisterCourse(stdRegNoList[], courseList[], stdArraySize, regNo, courseCode) == true)
                {
                    cout << "Course has been unregistered";
                }
                else
                {
                    cout << "Error!";
                }*/
                break;
            }
            // For Closing the Program
            case 12:
            {
                if (saveCourse(codeList, nameList, creditHours, semList, MAX_COURSES))
                {
                    cout << "All courses Data Saved successfully\n";
                }
                else
                {
                    cout << "All data you entered is lost due to some error\n";
                }
                userName = "";
                password = "";
                login(userName, password);
                break;
            }
            // Logout
            case 13:
            {
                if (saveCourse(codeList, nameList, creditHours, semList, MAX_COURSES))
                {
                    cout << "All courses Data Saved successfully\n";
                }
                else
                {
                    cout << "All data you entered is lost due to some error\n";
                }
                cout << "Program closed ";
                break;
            }
            default:
                cout << "Invalid choice";
            }
        }
    } while (input != 13);

    return 0;
}
void initializeCourses(string codeList[], string nameList[], int crtHrsList[], int semList[], int size)
{
    for (int s = 0; s < size; s++)
    {
        codeList[s] = " ";
        nameList[s] = " ";
        crtHrsList[s] = 0;
        semList[s] = 0;
    }
}
void initializeUsers(string usernames[], string passwords[], int size)
{
    for (int s = 0; s < size; s++)
    {
        usernames[s] = " ";
        passwords[s] = " ";
    }
}
bool saveCourse(string codeList[], string nameList[], int crtHrsList[], int semList[], int size)
{
    // This variable for read data from file
    ofstream myfile;
    /*Open the file if exist if not exist then make new file of this name ios::app maens that the new data will append in file and 
	not remove previous content of file */
    myfile.open("Courses.txt");
    //This function will check if the file open then write data from file
    if (myfile.is_open())
    {
        for (int i = 0; i < size; i++)
        {
            if (codeList[i] != "" && nameList[i] != "" && crtHrsList[i] != 0 && semList[i] != 0)
            {
                //These lines will write all array data to the file and make a comma separated file
                myfile << codeList[i] << ",";
                myfile << nameList[i] << ",";
                myfile << crtHrsList[i] << ",";
                myfile << semList[i] << endl;
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
//Function to load course in arrays
bool loadCourses(string codeList[], string nameList[], int crtHrsList[], int semList[], int size)
{
    int i = 0;
    ifstream getCourse("Courses.txt");
    if (!getCourse.is_open())
    {
        cout << "File failed to open\n";
        return false;
    }
    else
    {
        string courseCode, courseName;
        string creditHours, semester;
        int credit, sem;
        string line;
        while (!getCourse.eof() && i < size)
        {
            getline(getCourse, line);
            if (line == "")
                continue;
            stringstream ss(line);
            getline(ss, courseCode, ',');
            codeList[i] = courseCode;
            getline(ss, courseName, ',');
            nameList[i] = courseName;
            getline(ss, creditHours, ',');
            credit = stoi(creditHours);
            crtHrsList[i] = credit;
            getline(ss, semester, ',');
            sem = stoi(semester);
            semList[i] = sem;
            i++;
        }
        getCourse.close();
        return true;
    }
}
//Fuunction to read users from file and load then onto the arrays
bool loadUser(string usersList[], string passwordList[], int size)
{
    int i = 0;
    ifstream getUsers("Users.txt");
    if (!getUsers.is_open())
    {
        cout << "File failed to open\n";
        return false;
    }
    else
    {
        string username, password;
        string line;
        while (!getUsers.eof() && i < size)
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
int searchCourseCode(string codeList[], int size, string courseCode)
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (codeList[i] == courseCode)
        {
            index = i;
            break;
        }
    }
    return index;
}
//This Function Will add the function
bool addCourses(string codeList[], string nameList[], int creditHours[], int semList[], int size, string courseCode, string courseName, int credit, int semester)
{
    bool flag = false;
    int i = searchCourseCode(codeList, size, " ");
    if (i != -1)
    {
        codeList[i] = courseCode;
        nameList[i] = courseName;
        creditHours[i] = credit;
        semList[i] = semester;
        flag = true;
    }
    return flag;
}
// This Function will display all course details
void viewCourses(string codeList[], string nameList[], int creditHours[], int semList[], int size)
{
    for (int u = 0; u < 80; u++)
        cout << "-";
    cout << endl;
    cout << left;
    cout << setw(10) << "Course"
         << setw(50) << "Course"
         << setw(10) << "Credit"
         << setw(10) << "Semester\n";
    cout << setw(10) << "Code"
         << setw(50) << "Name"
         << setw(10) << "Hours"
         << setw(10) << "\n";
    for (int u = 0; u < 80; u++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        if (codeList[i] != " ")
        {
            cout << setw(10) << codeList[i]
                 << setw(50) << nameList[i]
                 << setw(10) << creditHours[i]
                 << setw(10) << semList[i] << endl;
        }
    }
    cout << endl;
    for (int u = 0; u < 80; u++)
        cout << "-";
    cout << endl;
}
//This function will display the course details of the specific semester
void viewSemesterCourse(string codeList[], string nameList[], int creditHours[], int semList[], int size, int semester)
{
    for (int u = 0; u < 80; u++)
        cout << "-";
    cout << endl;
    cout << left;
    cout << setw(10) << "Course"
         << setw(50) << "Course"
         << setw(10) << "Credit"
         << setw(10) << "Semester\n";
    cout << setw(10) << "Code"
         << setw(50) << "Name"
         << setw(10) << "Hours"
         << setw(10) << "\n";
    for (int u = 0; u < 80; u++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        if (semList[i] == semester && codeList[i] != "")
        {
            cout << setw(10) << codeList[i]
                 << setw(50) << nameList[i]
                 << setw(10) << creditHours[i]
                 << setw(10) << semList[i] << endl;
        }
    }
    cout << endl;
    for (int u = 0; u < 80; u++)
        cout << "-";
    cout << endl;
}
// This function will update the course by using courseCode index which we define as globel varaible
bool updateCourse(string codeList[], string nameList[], int creditHours[], int semList[], int size, string courseCode, string courseName, int credit, int semester)
{
    bool flag = false;
    int updateIndex = searchCourseCode(codeList, size, courseCode);
    if (updateIndex != -1)
    {
        codeList[updateIndex] = courseCode;
        nameList[updateIndex] = courseName;
        creditHours[updateIndex] = credit;
        semList[updateIndex] = semester;
        flag = true;
    }
    return flag;
}
// This function will delete the course by using courseCode
bool deleteCourse(string codeList[], string nameList[], int creditHours[], int semList[], int size, string courseCode)
{
    bool flag = false;
    int i = searchCourseCode(codeList, size, courseCode);
    if (i != -1)
    {
        codeList[i] = " ";
        nameList[i] = " ";
        creditHours[i] = 0;
        semList[i] = 0;
        flag = true;
    }
    return flag;
}
//checking validity of coursecode
bool isValidCourseCode(string code)
{
    int x = code.length();
    bool flag = true;
    if (x == 5)
    {
        for (int i = 0; i < 2; i++)
        {
            if (!((code[i] >= 'a' && code[i] <= 'z') || (code[i] >= 'A' && code[i] <= 'Z')))
            {
                flag = false;
                break;
            }
        }
        for (int i = 2; i < 5 && flag; i++)
        {
            if (!(code[i] >= '0' && code[i] <= '9'))
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}
// checking the credit hours
bool isValidCreditHours(int creditHours)
{
    bool flag = true;
    if (!(creditHours >= 1 && creditHours <= 3))
    {
        flag = false;
    }
    return flag;
}
//checking semester
bool isValidSemester(int semester)
{
    bool flag = true;
    if (!(semester >= 1 && semester <= 9))
    {
        flag = false;
    }
    return flag;
}
//checking coursename
bool isValidCourseName(string name)
{
    bool flag = true;
    if (name.length() <= 50)
    {
        for (int i = 0; i < name.length(); i++)
        {
            if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] == ' ')))
                flag = false;
        }
    }
    else
    {
        flag = false;
    }
    return flag;
}
bool validateAllData(string courseCode, string courseName, int credit, int semester)
{
    cout << isValidCourseCode(courseCode) << endl;
    cout << isValidCourseName(courseName) << endl;
    cout << isValidCreditHours(credit) << endl;
    cout << isValidSemester(semester) << endl;
    if (!(isValidCourseCode(courseCode) && isValidCreditHours(credit) && isValidSemester(semester) && isValidCourseName(courseName)))
    {
        return false;
    }
    return true;
}
bool isValidRegistrationNumber(char regNo[])
{
    bool flag = true, flag2 = false, flag3 = false, flag4 = false, flag5 = false, flag6 = false;

    if (regNo[0] == '2' && regNo[1] == '0' && (regNo[2] == '1' || regNo[2] == '2') && regNo[4] == '-' && regNo[7] == '-')
    {
        //2020-CS-144
        //012345678910
        if (regNo[3] >= '0' && regNo[3] <= '9')
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
        if (regNo[5] >= 'A' && regNo[5] <= 'Z')
        {
            flag2 = true;
        }
        if (regNo[6] >= 'A' && regNo[6] <= 'Z')
        {
            flag3 = true;
        }
        if (regNo[8] >= '0' && regNo[8] <= '9')
        {
            flag4 = true;
        }
        if (regNo[9] >= '0' && regNo[9] <= '9')
        {
            flag5 = true;
        }
        if (regNo[10] >= '0' && regNo[10] <= '9')
        {
            flag6 = true;
        }
    }
    else
    {
        flag = false;
    }

    if (flag == true && flag2 == true && flag3 == true && flag4 == true && flag5 == true && flag6 == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isValidStudentName(char studentName[])
{
    bool flag = false;
    for (int i = 0; studentName[i] != '\0'; i++)
    {
        for (char a = '0'; a <= '9'; a++)
        {
            if (studentName[i] == a)
            {
                flag = true;
            }
        }
    }
    return flag;
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
void login(string &userName, string &password)
{
    system("cls");
    cout << endl;
    cout << "** Welcome To University Learning Management System ** \n";
    cout << "Dear users current software is intended for authorized users only.\n";
    cout << "Login to the system to get access\n";
    cout << "Enter User name: ";
    cin >> userName;
    cout << "Enter Password: ";
    cin >> password;
    cout << endl;
}

bool addStudent(string stdNamesList[], string stdRegNoList[], int stdArraySize, string studentName, string regNo)
{
    bool flag = false;
    for (int i = 0; i < 10; i++)
    {
        if (stdNamesList[i] != "NV")
        {
            stdNamesList[i] = studentName;
            stdRegNoList[i] = regNo;
            flag = true;
        }
    }

    return flag;
}
bool updateStudent(string stdNamesList[], string stdRegNoList[], int stdArraySize, string stdRegNoToUpdate, string studentName, string regNo)
{
    bool flag;

    return flag;
}
bool deleteStudent(string stdNamesList[], string stdRegNoList[], string stdCourseList[], int stdArraySize, string regNo)
{
    bool flag;

    return flag;
}
bool registerCourse(string stdRegNoList[], string stdCourseList[], string courseCodeList, int stdArraySize, string regNo, string courseCode)
{
    bool flag;

    return flag;
}
/*bool unRegisterCourse(string stdRegNoList[], string stdCourseList[][100], string reg_no, string courseCode)
{
	//int variable = index_reg_code(stdRegNoList, reg_no);
	bool flag = true;

	for (int i = 0; stdCourseList[variable][i] != "\0"; i++)
	{
		if (stdCourseList[variable][i] == courseCode)
		{
			stdCourseList[variable][i] = "\0";
			flag = true;
			break;
		}
		else
		{
			flag = false;
		}
	}
	if (flag == false)
	{
		cout << endl
			 << "There is no course registered for the student by this course code.\n";
	}
	else
	{
		cout << endl
			 << "Course has been unregistered successfully.\n";
	}
}*/

bool loadStudents()
{
    /*int i = 0;
    ifstream getCourse("Courses.txt");
    if (!getCourse.is_open())
    {
        cout << "File failed to open\n";
        return false;
    }
    else
    {
        string courseCode, courseName;
        string creditHours, semester;
        int credit, sem;
        string line;
        while (!getCourse.eof() && i < size)
        {
            getline(getCourse, line);
            if (line == "")
                continue;
            stringstream ss(line);
            getline(ss, courseCode, ',');
            codeList[i] = courseCode;
            getline(ss, courseName, ',');
            nameList[i] = courseName;
            getline(ss, creditHours, ',');
            credit = stoi(creditHours);
            crtHrsList[i] = credit;
            getline(ss, semester, ',');
            sem = stoi(semester);
            semList[i] = sem;
            i++;
        }
        getCourse.close();
        return true;*/
}
bool saveStudents()
{
}
void viewstudents(string stdRegNoList[], string stdNameList[])
{
    cout << left;
    cout << setw(30) << "\t Student Name"
         << "Registration Number" << endl;
    for (int i = 0; stdRegNoList[i] != "NV"; i++)
    {
        cout << left;
        cout << "\t" << setw(30) << stdNameList[i] << stdRegNoList[i] << endl;
    }
}