using System;
using System.Text.RegularExpressions;

namespace Lab10

{
    class Student
    {
        private String studentName;
        private String registrationNumber;
        private DateTime dateOfBirth;
        private double cgpa;
        private String cnic;
        public static int numberOfInstances;

        public Student()
        {
            numberOfInstances = numberOfInstances + 1;
        }

        public string StudentName { get => studentName; set => studentName = value; }
        public string RegistrationNumber { get => registrationNumber; set => registrationNumber = value; }
        public DateTime DateOfBirth { get => dateOfBirth; set => dateOfBirth = value; }
        public double Cgpa { get => cgpa; set => cgpa = value; }
        public string Cnic { get => cnic; set => cnic = value; }

        public String getStatus(double cgpa)
        {
            String status = "";
            if (cgpa < 2.0)
            {
                status = "Suspended";

            }
            else if (cgpa < 2.5 && cgpa >= 2.0)
            {
                status = "Below Average";
            }
            else if (cgpa < 3.3 && cgpa >= 2.5)
            {
                status = "Average";
            }
            else if (cgpa < 3.5 && cgpa >= 3.3)
            {
                status = "Good";
            }
            else if (cgpa >= 3.5)
            {
                status = "Excellent";
            }
            return status;
        }

        public String getAge(String dobb)
        {
            DateTime dob = Convert.ToDateTime(dobb);
            // string text = "CalculateYourAge(dob)";

            DateTime Now = DateTime.Now;
            int Years = new DateTime(DateTime.Now.Subtract(dob).Ticks).Year - 1;
            DateTime PastYearDate = dob.AddYears(Years);
            int Months = 0;
            for (int i = 1; i <= 12; i++)
            {
                if (PastYearDate.AddMonths(i) == Now)
                {
                    Months = i;
                    break;
                }
                else if (PastYearDate.AddMonths(i) >= Now)
                {
                    Months = i - 1;
                    break;
                }
            }
            int Days = Now.Subtract(PastYearDate.AddMonths(Months)).Days;
            return String.Format("(Age is {0} years {1} months {2} days)", Years, Months, Days);

        }

        public bool isNameValid(String name)
        {
            bool flag = false;
            if(name.Contains(" ")||Regex.IsMatch(name, @"^[a-zA-Z]+$"))
            {
                flag = true;
            }
            return flag;

        }
        public bool isValidRegNo(String regno)
        {
            char[] arr = regno.ToCharArray();
            bool flag = false;

            if (arr.Length == 11)
            {
                if ((arr[0] == '2' && arr[1] == '0') && (arr[2] == '1' || arr[2] == '2') && (arr[3] >= '0' && arr[3] <= '9')
                        && arr[4] == '-' && arr[7] == '-')
                {
                    if ((arr[5] >= 'A' && arr[5] <= 'Z') && (arr[6] >= 'A' && arr[6] <= 'Z'))
                    {
                        for (int i = 8; i < 11; i++)
                        {
                            if ((arr[i] >= '0' && arr[i] <= '9'))
                            {
                                flag = true;
                            }
                            else
                            {
                                flag = false;
                            }
                        }
                    }
                }
                else
                {
                    flag = false;
                }
            }
            return flag;

        }

        public bool isValidCnic(String cnic)
        {
            bool flag = false;

            if (cnic.Length == 13 && Regex.IsMatch(cnic, "[0-9]"))
            {
                flag = true;
            }
            return flag;
        }

        public String getGender(String cnic)
        {
            String gender;
            if (cnic[12] % 2 != 0)
            {
                gender = "Male";
            }
            else
            {
                gender = "Female";
            }
            return gender;
        }

        public int numberOfWordsInName(String name)
        {
            int wrd = 1, l = 0;

            while (l <= name.Length - 1)
            {
                if (name[l] == ' ' || name[l] == '\n' || name[l] == '\t')
                {
                    wrd++;
                }

                l++;
            }

            return wrd;
        }

        public void input()
        {
            Console.ReadLine();
        }
        public static String getNumOfInstances()
        {
            return String.Format("Student class has the {0} objects", numberOfInstances.ToString());
        }
    }
}
