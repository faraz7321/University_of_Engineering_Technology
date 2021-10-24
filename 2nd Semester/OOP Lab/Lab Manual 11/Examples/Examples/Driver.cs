using System;
using System.Text.RegularExpressions;
namespace Lab10

{
    class Driver
    {
        static void Main(string[] args)
        {
            Student student1 = new Student();
            Student student2 = new Student();

        //STUDENT 1.//
        namee:
            Console.WriteLine("Enter Name: ");
            String name = Console.ReadLine();
            if (student1.isNameValid(name))
            {
                student1.StudentName = name;
            }
            else
            {
                System.Console.WriteLine("INVALID NAME!");
                goto namee;
            }
        reg:
            Console.WriteLine("Enter Registeration No: ");
            String regno = Console.ReadLine();
            if (student1.isValidRegNo(regno))
            {

                student1.RegistrationNumber = regno;
            }
            else
            {
                System.Console.WriteLine("INVALID REGISTERATION NUMBER!");
                goto reg;
            }

            Console.WriteLine("Enter CGPA: ");
            student1.Cgpa = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine("Enter Date of Birth (yyyy/mm/dd) : ");
            String dob = Console.ReadLine();
            DateTime DOB = DateTime.Parse(dob);
            student1.DateOfBirth = DOB;
        cnicc:
            Console.WriteLine("Enter CNIC: ");
            String cnic = Console.ReadLine();
            if (cnic.Length != 13 || Regex.IsMatch(cnic, "[0-9]"))
            {
                student1.Cnic = cnic;
            }
            else
            {
                System.Console.WriteLine("INVALID CNIC!");
                goto cnicc;
            }

        //STUDENT 2.//
        namee1:
            Console.WriteLine("\n\nEnter Name: ");
            name = Console.ReadLine();
            if (student2.isNameValid(name))
            {
                student2.StudentName = name;
            }
            else
            {
                System.Console.WriteLine("INVALID NAME!");
                goto namee1;
            }
        reg1:
            Console.WriteLine("Enter Registeration No: ");
            regno = Console.ReadLine();
            if (student2.isValidRegNo(regno))
            {
                student2.RegistrationNumber = regno;
            }
            else
            {
                System.Console.WriteLine("INVALID REGISTERATION NUMBER!");
                goto reg1;
            }

            Console.WriteLine("Enter CGPA: ");
            student2.Cgpa = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine("Enter Date of Birth (yyyy/mm/dd) : ");
            dob = Console.ReadLine();
            DOB = DateTime.Parse(dob);
            student2.DateOfBirth = DOB;

            Console.WriteLine("Enter CNIC: ");
            cnic = Console.ReadLine();
            if (cnic.Length != 13 || Regex.IsMatch(cnic, "[0-9]"))
            {
                student2.Cnic = cnic;
            }

            //Output.//
            Console.WriteLine("\n\nName: " + student1.StudentName + "(Contain {0} word(s))", student1.numberOfWordsInName(student1.StudentName));
            Console.WriteLine("Registration Number: " + student1.RegistrationNumber);
            Console.WriteLine("CGPA: " + student1.Cgpa + " " + student1.getStatus(student1.Cgpa));
            Console.WriteLine("Date of Birth: " + student1.DateOfBirth.ToLongDateString() + " " + student1.getAge(dob));
            Console.WriteLine("CNIC: " + student1.Cnic);
            Console.WriteLine("Gender: " + student1.getGender(student1.Cnic));

            Console.WriteLine("\n\nName: " + student2.StudentName + "(Contain {0} word(s))", student2.numberOfWordsInName(student2.StudentName));
            Console.WriteLine("Registration Number: " + student2.RegistrationNumber);
            Console.WriteLine("CGPA: " + student2.Cgpa + " " + student2.getStatus(student2.Cgpa));
            Console.WriteLine("Date of Birth: " + student2.DateOfBirth.ToLongDateString() + " " + student2.getAge(dob));
            Console.WriteLine("CNIC: " + student2.Cnic);
            Console.WriteLine("Gender: " + student2.getGender(student2.Cnic));
            Console.WriteLine(Student.getNumOfInstances());
        }
    }
}
