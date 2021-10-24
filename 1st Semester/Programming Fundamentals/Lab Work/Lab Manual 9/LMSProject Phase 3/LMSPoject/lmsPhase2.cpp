#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;
bool isValidCourseCode(char courseCode[]);
bool isValidCourseName(char courseName[]);
bool isValidCreditHours(int crdHrs);
bool isValidSemester(int semester);
bool saveCourses(string codeList[], string nameList[], int crdHrsList[], int semList[], int semester);
bool loadCourses(string codeList[], string nameList[], int crdHrsList[], int semList[]);
bool check_courseCode(string codeList[], string EditCourseCode);
void AddCourse(string codeList[], string nameList[], int crdHrsList[], int semList[], char courseCode[], char courseName[], int crdHrs, int semester);
void EditCourse(string codeList[], string nameList[], int crdHrsList[], int semList[], char courseCode[], char courseName[], int crdHrs, int semester, string EditCourseCode);
void DeleteCourse(string codeList[], string nameList[], int crdHrsList[], int semList[], string del);
void ViewCourses(string codeList[], string nameList[], int crdHrsList[], int semList[]);
void ViewSemesterCourses(string codeList[], string nameList[], int crdHrsList[], int semList[], int semester);
int index_courseCode(string codeList[], string EditCourseCode);
int max_index(int semList[]);
int main()
{
    //Variables.//
    int option, crdHrs, semester;
    char courseCode[5], courseName[50];
    string del, codeList[5] = {"NV", "NV", "NV", "NV", "NV"}, nameList[5] = {"NV", "NV", "NV", "NV", "NV"}, course_code, EditCourseCode;
    int a = 1, crdHrsList[5] = {-1, -1, -1, -1, -1}, semList[5] = {-1, -1, -1, -1, -1};
    bool check;
    string username;
    string password;
    ifstream Users_file;
    Users_file.open("Users.txt");
    string passcheck, usercheck;
    system("CLS");

    //Main code.//

    cout << "** Welcome to University Learning Management System ** \n"
         << "Dear User, current software is intended for authorized users only.\n"
         << "Login to the system to get access.\n";

    do
    {

        cout << "Username: ";
        cin >> usercheck;
        cout << "Password: ";
        cin >> passcheck;
        Users_file >> username;
        Users_file >> password;

        if (username == usercheck && password == passcheck)
        {
            do
            {
                cout << "Choose the following option: \n"
                     << "1      Add Course\n"
                     << "2      Update Course\n"
                     << "3      Delete Course\n"
                     << "4      View All Courses\n"
                     << "5      View Courses of a Semester\n"
                     << "0      Exit Program\n\n"
                     << "Choose the option: ";
                cin >> option;
                cout << endl;
                switch (option)
                {
                //Add courses
                case 1:
                {
                    cout << "Enter the details of the course: ";
                    cin >> courseCode >> crdHrs >> semester;
                    //cin.ignore(25, '\n');
                    cin.get(courseName, 25);
                    AddCourse(codeList, nameList, crdHrsList, semList, courseCode, courseName, crdHrs, semester);
                    break;
                }
                //Update Course
                case 2:
                {
                    cout << "Enter the course code to Update: ";
                    cin >> EditCourseCode;
                    cout << endl;
                    if (check_courseCode(codeList, EditCourseCode) == true)
                    {
                        EditCourse(codeList, nameList, crdHrsList, semList, courseCode, courseName, crdHrs, semester, EditCourseCode);
                    }
                    else
                    {
                        cout << "\nCourse not found!\n";
                    }
                    break;
                }
                //Delete Course
                case 3:
                {
                    cout << "Enter course code to delete: ";
                    cin >> del;
                    if (check_courseCode(codeList, del) == true)
                    {
                        DeleteCourse(codeList, nameList, crdHrsList, semList, del);
                    }
                    else
                    {
                        cout << "\nThis is no course by this course code\n";
                    }
                    break;
                }
                //View all courses
                case 4:
                {
                    ViewCourses(codeList, nameList, crdHrsList, semList);
                    break;
                }
                //View courses by semester
                case 5:
                {
                    ViewSemesterCourses(codeList, nameList, crdHrsList, semList, semester);
                    break;
                }
                //Exit the program
                case 0:
                {
                    cout << "Thank You!\n";
                    option = 0;
                    break;
                }
                default:
                {
                    cout << "Invalid option selected!\n";
                }
                }
            } while (option != 0);
        }
        else{
            cout << "Dear User, Username/password is incorrect\n. Enter the username/password again to get access to the system";
        }
    } while (!Users_file.eof());
}
//To check validity of courseCode.//
bool isValidCourseCode(char courseCode[])
{
    bool flag1 = false, flag2 = false, flag3 = false;
    for (int i = 0; i < 2; i++)
    {
        if ((courseCode[i] >= 'A' && courseCode[i] <= 'Z') || (courseCode[i] >= 'a' && courseCode[i] <= 'z'))
        {
            flag1 = true;
        }
        else
        {
            flag1 = false;
        }
    }
    for (int i = 2; i < 5; i++)
    {
        if ((courseCode[i] >= 48 && courseCode[i] <= 57))
        {
            flag2 = true;
        }
        else
        {
            flag2 = false;
        }
    }
    if (flag1 == true && flag2 == true)
    {
        flag3 = true;
    }
    return flag3;
}
//To check validity of courseName.//
bool isValidCourseName(char courseName[])
{
    bool flag = false;
    for (int i = 0; i < 50; i++)
    {
        if ((courseName[i] >= 65 && courseName[i] <= 90) || (courseName[i] >= 97 && courseName[i] <= 122) || (courseName[i] == 32))
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
    }
    return flag;
}
//To check validity of crdHrs.//
bool isValidCreditHours(int crdHrs)
{
    bool flag = false;
    if (crdHrs >= 1 && crdHrs <= 3)
    {
        flag = true;
    }
    return flag;
}
//To check validity of semester.//
bool isValidSemester(int semester)
{
    bool flag = false;
    if (semester >= 1 && semester <= 8)
    {
        flag = true;
    }
    return flag;
}
//To check availabity of courseCode.//
bool check_courseCode(string codeList[], string EditCourseCode)
{
    bool flag = false;
    for (int i = 0; i < 5; i++)
    {
        if (codeList[i] == EditCourseCode)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
//To check index of selected code when deleting or updating.//
int index_courseCode(string codeList[], string EditCourseCode)
{
    int i = -1;
    for (int j = 0; j < 5; j++)
    {
        if (codeList[j] == EditCourseCode)
        {
            i = j;
            break;
        }
    }
    return i;
}
int max_index(int semList[])
{
    int a = 0, counter = 0;
    while (semList[a] != 0)
    {
        counter++;
        a++;
    }
    return --counter;
}

//Function to add course.//
void AddCourse(string codeList[], string nameList[], int crdHrsList[], int semList[], char courseCode[], char courseName[], int crdHrs, int semester)
{
    //if (isValidSemester(semester) == true && isValidCourseCode(courseCode) == true && isValidCreditHours(crdHrs) == true && isValidCourseName(courseName) == true)
    //{
    for (int i = 0; i < 5; i++)
    {
        if (semList[i] == -1 && codeList[i] == "NV" && nameList[i] == "NV" && crdHrsList[i] == -1 && semList[i] == -1)
        {
            codeList[i] = courseCode;
            crdHrsList[i] = crdHrs;
            semList[i] = semester;
            nameList[i] = courseName;
            cout << "\nCourse has been added successfully!\n";
            break;
        }
    }
    //}
}
//Function to update course.//
void EditCourse(string codeList[], string nameList[], int crdHrsList[], int semList[], char courseCode[], char courseName[], int crdHrs, int semester, string EditCourseCode)
{
    cout << "Enter the new details of the course: ";
    cin >> courseCode >> crdHrs >> semester;
    //cin.ignore(25, '\n');
    cin.get(courseName, 50);

    if (isValidSemester(semester) == true && isValidCourseCode(courseCode) == true && isValidCreditHours(crdHrs) == true && isValidCourseName(courseName) == true)
    {
        int i = index_courseCode(codeList, EditCourseCode);
        codeList[i] = courseCode;
        crdHrsList[i] = crdHrs;
        semList[i] = semester;
        nameList[i] = courseName;
        cout << "\nCourse has been edited successfully.\n";
    }
}
//Function to delete course.//
void DeleteCourse(string codeList[], string nameList[], int crdHrsList[], int semList[], string del)
{
    int i = index_courseCode(codeList, del);
    codeList[i] = "NV";
    nameList[i] = "NV";
    crdHrsList[i] = -1;
    semList[i] = -1;
    cout << "\nCourse has been deleted successfully\n";
}
//Function to all view courses.//
void ViewCourses(string codeList[], string nameList[], int crdHrsList[], int semList[])
{
    cout << "\t" << left << setw(15) << "Course Code" << left << setw(30) << "Name" << left << setw(20) << "Credit Hours" << left << setw(20) << "Semester" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (semList[i] != -1 && codeList[i] != "NV" && nameList[i] != "NV" && crdHrsList[i] != -1 && semList[i] != -1)
        {
            cout << "\t" << left << setw(15) << codeList[i] << left << setw(30) << nameList[i] << left << setw(20) << crdHrsList[i] << left << setw(20) << semList[i] << endl;
        }
    }
    cout << "_______________________________________________________________________________________\n";
}
//Function to view courses by semester.//
void ViewSemesterCourses(string codeList[], string nameList[], int crdHrsList[], int semList[], int semester)
{
    int size = max_index(semList);
    cout << "Enter the semester: ";
    cin >> semester;
    cout << endl;
    cout << left << setw(15) << "Course Code" << left << setw(30) << "Name" << left << setw(20) << "Credit Hours" << endl;
    int index, i = 0;

    for (semList[i] != 0; i < 5; i++)
    {
        if (semList[i] == semester)
        {
            cout << left << setw(15) << codeList[i] << left << setw(30) << nameList[i] << left << setw(20) << crdHrsList[i] << endl;
        }
    }
    cout << "_______________________________________________________________________________________\n";
}
bool saveCourses(string codeList[], string nameList[], int crdHrsList[], int semList[], int semester)
{
    bool flag = false;
    ofstream outData;
    outData.open("Courses.txt");
    int size = max_index(semList);

    for (int i = 0; i <= size; i++)
    {
        outData << codeList[i] << "," << nameList[i] << "," << crdHrsList[i] << "," << semList[i] << endl;
        flag = true;
    }
    outData.close();
    return flag;
}
bool loadCourses(string codeList[], string nameList[], int crdHrsList[], int semList[])
{
}