import java.io.File; // Import the File class
import java.io.IOException; // Import the IOException class to handle errors
import java.io.FileNotFoundException;// Import this class to handle errors
import java.util.Scanner; // Import the Scanner class to read text files
import javax.swing.*;
import java.util.*;

class CourseResult {

    public String CourseId;
    public String CourseTitle;
    public int CreditHours;
    public int marks;
    public int semester;
}

class Student {

    public String StudentName;
    public String RegisterationNumber;
    public String Degree;
    public List<CourseResult> list;
}

public class UetGradeBook {
    public static boolean validateStudentName(String name) {
        boolean flag = false;
        char[] arr = name.toCharArray();
        for (int i = 0; i < arr.length; i++) {
            if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z') || arr[i] == ' ') {
                flag = true;
            } else {
                flag = false;
            }
        }
        return flag;
    }

    public static boolean validateRegistrationNumber(String regNo) {
        boolean flag = false;
        char[] arr = regNo.toCharArray();

        if (arr.length == 11) {
            if ((arr[0] == '2' && arr[1] == '0') && (arr[2] == '1' || arr[2] == '2') && (arr[3] >= '0' && arr[3] <= '9')
                    && arr[4] == '-' && arr[7] == '-') {
                if ((arr[5] >= 'A' && arr[5] <= 'Z') && (arr[6] >= 'A' && arr[6] <= 'Z')) {
                    for (int i = 8; i < 11; i++) {
                        if ((arr[i] >= '0' && arr[i] <= '9')) {
                            flag = true;
                        } else {
                            flag = false;
                        }
                    }
                }
            } else {
                flag = false;
            }
        }
        return flag;
    }

    public static boolean validateDegree(String degree) {
        boolean flag = false;
        if (degree == "BS" || degree == "MS" || degree == "BE") {
            flag = true;

        } else {
            flag = false;
        }

        return flag;
    }

    public static boolean validateCourseId(String courseId) {
        boolean flag = false;
        char[] arr = courseId.toCharArray();

        if (arr.length >= 2 && arr.length <= 8) {

            if ((arr[0] >= 'A' && arr[0] <= 'Z') && (arr[1] >= 'A' && arr[1] <= 'Z')) {

                flag = true;
            } else {
                flag = false;
            }

        } else {
            flag = false;
        }

        return flag;
    }

    public static boolean validateCourseTitle(String courseTitle) {
        boolean flag = false;
        char[] arr = courseTitle.toCharArray();

        for (int i = 0; i < arr.length; i++) {
            if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z')) {
                flag = true;
            } else {
                flag = false;
            }
        }
        return flag;
    }

    public static boolean validateCreditHours(int creditHours) {
        boolean flag = false;
        if (creditHours >= 1 && creditHours <= 3) {
            flag = true;
        }
        return flag;
    }

    public static boolean validateMarks(int marks) {
        boolean flag = false;
        if (marks >= 0 && marks <= 100) {
            flag = true;
        }
        return flag;
    }

    public static boolean validateSemester(int semester) {
        boolean flag = false;
        if (semester >= 1 && semester <= 8) {
            flag = true;
        }
        return flag;
    }

    public static boolean validateCourse(CourseResult course) {
        boolean flag = false;
        if (validateCourseId(course.CourseId) == true && validateSemester(course.semester) == true
                && validateMarks(course.marks) == true && validateCourseTitle(course.CourseTitle) == true
                && validateCreditHours(course.CreditHours) == true) {
            flag = true;

        }
        return flag;
    }

    public static String getGrade(int marks) {
        String grade = "";

        if (marks >= 80) {
            grade = "A";

        } else if (marks <= 80 && marks > 70) {
            grade = "A-";
        } else if (marks <= 70 && marks > 65) {
            grade = "B+";
        } else if (marks <= 65 && marks > 60) {
            grade = "B-";
        } else if (marks <= 60 && marks > 55) {
            grade = "C+";
        } else if (marks <= 55 && marks > 50) {
            grade = "C";
        } else if (marks <= 40 && marks > 50) {
            grade = "D";
        } else if (marks < 40) {
            grade = "F";
        }
        return grade;

    }

    public static double getGradePoints(String grade) {
        double gradePoint = 0;
        if (grade == "A") {
            gradePoint = 4.0;
        } else if (grade == "A-") {
            gradePoint = 3.7;
        } else if (grade == "B+") {
            gradePoint = 3.3;
        } else if (grade == "B-") {
            gradePoint = 3.0;
        } else if (grade == "C+") {
            gradePoint = 2.7;
        } else if (grade == "C") {
            gradePoint = 3.2;
        } else if (grade == "D") {
            gradePoint = 1.0;
        } else if (grade == "F") {
            gradePoint = 0.0;

        }
        return gradePoint;
    }

    // public static int getSemesters(List<CourseResult> list) {

    // }

    // public static int getTotalCreditHours(List<CourseResult> list) {

    // }

    // public static int getSemesterCreditHours(int semester, List<CourseResult>
    // list) {

    // }

    // public static double getSemesterGPA(int semester, List<CourseResult> list) {

    // }

    // public static double getCGPA(int semester, List<CourseReuslt> list) {

    // }

    // public static String getSession(String regNo) {

    // }

    // public static String getDiscipline(String regNo) {

    // }

    // public static bool saveData(Student s1) {

    // }

    // public static Student readData() {

    // }

    // public static boolean saveDMC(Student s1) {

    // }

    public static void main(String[] args) {
        Student s1;
        int input;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Choose the following option:\n" + "Choose 1 to set basic information of student\n"
                + "Choose 2 to add new course in Grade Book\n" + "Choose 3 to edit a course\n"
                + "Choose 4 to delete a course\n" + "Choose 5 to view all courses\n" + "Choose 6 to view CGPA\n"
                + "Choose 7 to view detailed marks certificate\n" + "Choose 8 to save data\n" + "Choose 0 to exit\n");

        do {
            input = scanner.nextInt();
            switch (input) {
                // Basic Information of Student.//
                case 1: {
                    System.out.println("Please enter the basic information in the following format\n"
                            + "Name, Registeration Number, Degree");

                    break;
                }
                // Add new Course in Grade Book.//
                case 2: {
                    System.out.println("Please enter the basic information in the following format\n"
                            + "Course ID, Course Title, Credit Hours, Semester, Marks");

                    break;
                }
                // Edit a Course.//
                case 3: {
                    System.out.println("Enter course ID to update course");
                    System.out.println("Please enter the basic information in the following format\n"
                            + "Course ID, Course Title, Credit Hours, Semester, Marks");

                    break;
                }
                // Delete a Course.//
                case 4: {
                    System.out.println("Please enter the course ID you want to delete");
                    break;
                }
                // View All Courses.//
                case 5: {
                    break;
                }
                // View GPA.//
                case 6: {
                    break;
                }
                // View DMC.//
                case 7: {
                    break;
                }
                // Save Data.//
                case 8: {
                    break;
                }
                // Exit Program.//
                case 0: {
                    break;
                }

                default: {
                    System.out.println("Invalid Option!");
                    break;
                }
            }
        } while (input != 0);
        scanner.close();
    }

}