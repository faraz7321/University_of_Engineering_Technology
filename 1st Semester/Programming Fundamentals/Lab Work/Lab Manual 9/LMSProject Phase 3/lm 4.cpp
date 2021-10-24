#include<iostream>
#include<string>
using namespace std;
int main ()

{
	int input, i, marks1=-1, marks2=-1, marks3=-1, marks4=-1, marks5=-1; 
	string student1= "NV", student2= "NV", student3= "NV", student4= "NV", student5= "NV", studentname, studentname2, studentname3, studentname4;
	char g1, g2, g3, g4, g5;
	string UserName, Password;
	
	    cout << "**************************************************************" <<endl
	         << "                  University Grading System                   " << endl
	         << "**************************************************************" << endl
	         << "          Please Enter Administration Credentials!" << endl
			 << "**************************************************************" << endl;
	
	cout << "Userame     : ";
	cin >> UserName;
	cout << "Password    : ";
	cin >> Password;
	cout << endl;
	if (UserName=="Administrators" || Password=="PF2020"){
	
		
		do {
	    cout << "Choose the option from the menu:" << endl
	         << "Enter 1 to add a student" << endl
	         << "Enter 2 to search a student" << endl
	         << "Enter 3 to delete a student" << endl
	         << "Enter 4 to update the data of a student" << endl
	         << "Enter 5 to display number of students in the system" << endl
	         << "Enter 6 to display list of all student without grades" << endl
	         << "Enter 7 to display list of all students with grades" << endl
	         << "Enter 0 to close the program" << endl
	         << "Enter input: "; 
	    cin >> input;  
	
	/*
	if(input==1){
		cout << "Enter 1 to add a student" << endl;
	}
	else if(input==2){
		cout << "Enter 2 to search a student" << endl;
	}
	else if(input==3){
		cout << "Enter 3 to delete a student" << end;
	}
	else if(input==4){
		cout << "Enter 4 to update the data of a student" << endl;
	}
	else if(input==5){
		cout << "Enter 5 to display number of students in the system" << endl;
	}
	else if(input==6){
		cout << "Enter 6 to display list of all student without grades" << endl;
	}
		if(input==7){
		cout << "Enter 7 to display list of all students with grades" << endl;
	} 
	else
		cout << "Program closed";
	*/
	
	switch (input){
		case 1:
			cout << "                 Add a Student" << endl;
			if (student1=="NV" && marks1==-1){
				cout << "Enter name of the student: ";
			cin >> student1;
			cout << "Enter marks: ";
			cin >> marks1;
			 if(marks1>=85){
				     	g1='A';
					 }
					 else if(marks1>=70){
					 	g1='B';
					 }
					 else if(marks1>=55){
					 	g1='C';
					 }
					 else if(marks1>=40){
					 	g1='D';			
					 }
			}
			else if (student2=="NV" && marks2==-1){
				cout << "Enter name of the student: ";
			cin >> student2;
			cout << "Enter marks: ";
			cin >> marks2;
			if(marks2>=85){
				     	g2='A';
					 }
					 else if(marks2>=70){
					 	g2='B';
					 }
					 else if(marks2>=55){
					 	g2='C';
					 }
					 else if(marks2>=40){
					 	g2='D';
					 }
			}
			else if (student3=="NV" && marks3==-1){
				cout << "Enter name of the student: ";
			cin >> student3;
			cout << "Enter marks: ";
			cin >> marks3;
			if(marks3>=85){
				     	g3='A';
					 }
					 else if(marks3>=70){
					 	g3='B';
					 }
					 else if(marks3>=55){
					 	g3='C';
					 }
					 else if(marks4>=40){
					 	g3='D';
					 }
			}
			else if (student4=="NV" && marks4==-1){
				cout << "Enter name of the student: ";
			cin >> student4;
			cout << "Enter marks: ";
			cin >> marks4;
			 if(marks4>=85){
				     	g4='A';
					 }
					 else if(marks4>=70){
					 	g4='B';
					 }
					 else if(marks4>=55){
					 	g4='C';
					 }
					 else if(marks4>=40){
					 	g4='D';
					 }
			}
			else if (student5=="NV" && marks5==-1){
				cout << "Enter name of the student: ";
			cin >> student5;
			cout << "Enter marks: ";
			cin >> marks5;
			if(marks5>=85){
				     	g5='A';
					 }
					 else if(marks5>=70){
					 	g5='B';
					 }
					 else if(marks5>=55){
					 	g5='C';
					 }
					 else if(marks5>=40){
					 	g5='D';
					 }
			}
			else{
				cout << "Memory full!";
			}
			cout << endl;
			break;
			//End of case 1
			
		case 2:
			cout << "             Search Student" << endl;
			cout << "Enter student name: ";
			cin >> studentname2;
			if (studentname2==student1){
				cout << "Student name: " <<student1 << endl
				     << "Marks       : " << marks1 << endl;

				cout << "Grade       : " << g1 << endl;
				 
			}
			else if (studentname2==student2){
				cout << "Student name: " <<student2 << endl
				     << "Marks       : " << marks2 << endl;
				     
				      
				cout << "Grade       : " << g2 << endl;
				 
			}
			else if (studentname2==student3){
				cout << "Student name: " <<student3 << endl
				     << "Marks       : " << marks3 << endl;
				     
				     
				cout << "Grade       : " << g3 << endl;
				 
			}
			else if (studentname2==student4){
				cout << "Student name: " <<student4 << endl
				     << "Marks       : " << marks4 << endl;
				     
				    
				cout << "Grade       : " << g4 << endl;
				 
			}
			else if (studentname2==student5){
				cout << "Student name: " <<student5 << endl
				     << "Marks       : " << marks5 << endl;
				     
				cout << "Grade       : " << g5 << endl;
				 
			}
			else {
				cout << "Record Not Found!";
			}
			cout << endl;
			break;
			//End of case 2
			
		case 3:
			cout << "             Delete Student Record" << endl;
			cout << "Enter student name: ";
			cin >> studentname3;
			if (studentname3==student1){
				student1="NV"; marks1=-1;
			}
			else if (studentname3==student2){
				student2="NV"; marks2=-1;
			}
			else if (studentname3==student3){
				student3="NV"; marks3=-1;
			}
			else if (studentname3==student4){
				student4="NV"; marks4=-1;
			}
			else if (studentname3==student5){
				student5="NV"; marks5=-1;
			}
			else{
				cout << "Student Record Not Found!" << endl;
			}
			cout << endl;
			break;
			//End of case 3
			
		case 4:
			cout << "            Update Student Record" << endl;
			cout << "Enter student Name: ";
			cin >> studentname4;
			if (studentname4==student1){
				cout << "Student Name        : " << student1 << endl
				     << "Student Marks       : " << marks1 << endl
				     << "Enter Student Marks : ";
				     cin >> marks1;
				     if(marks1>=85){
				     	g1='A';
					 }
					 else if(marks1>=70){
					 	g1='B';
					 }
					 else if(marks1>=55){
					 	g1='C';
					 }
					 else if(marks1>=40){
					 	g1='D';			
					 }
				     cout << "Student Record Updated SUCCESSFULLY!";
			}
			else if (studentname4==student2){
				cout << "Student Name        : " << student2 << endl
				     << "Student Marks       : " << marks2 << endl
				     << "Enter Student Marks : ";
				     cin >> marks2;
				     if(marks2>=85){
				     	g2='A';
					 }
					 else if(marks2>=70){
					 	g2='B';
					 }
					 else if(marks2>=55){
					 	g2='C';
					 }
					 else if(marks2>=40){
					 	g2='D';
					 }
				     cout << "Student Record Updated SUCCESSFULLY!";
			}
			else if (studentname4==student3){
				cout << "Student Name        : " << student3 << endl
				     << "Student Marks       : " << marks3 << endl
				     << "Enter Student Marks : ";
				     cin >> marks3;
				     if(marks3>=85){
				     	g3='A';
					 }
					 else if(marks3>=70){
					 	g3='B';
					 }
					 else if(marks3>=55){
					 	g3='C';
					 }
					 else if(marks4>=40){
					 	g3='D';
					 }
				     cout << "Student Record Updated SUCCESSFULLY!";
			}
			else if (studentname4==student4){
				cout << "Student Name        : " << student4 << endl
				     << "Student Marks       : " << marks4 << endl
				     << "Enter Student Marks : ";
				     cin >> marks4;
				     if(marks4>=85){
				     	g4='A';
					 }
					 else if(marks4>=70){
					 	g4='B';
					 }
					 else if(marks4>=55){
					 	g4='C';
					 }
					 else if(marks4>=40){
					 	g4='D';
					 }
				     cout << "Student Record Updated SUCCESSFULLY!";
			}
			else if (studentname4==student5){
				cout << "Student Name        : " << student5 << endl
				     << "Student Marks       : " << marks5 << endl
				     << "Enter Student Marks : ";
				     cin >> marks5;
				     if(marks5>=85){
				     	g5='A';
					 }
					 else if(marks5>=70){
					 	g5='B';
					 }
					 else if(marks5>=55){
					 	g5='C';
					 }
					 else if(marks5>=40){
					 	g5='D';
					 }
				     cout << "Student Record Updated SUCCESSFULLY!";
			}
			cout << endl;
			break;
			//End of case 4
			
		case 5:
			i=0;
			if (student1!="NV"){
				i=i+1;
			}
			if (student2!="NV"){
				i=i+1;
			}
			if (student3!="NV"){
				i=i+1;
			}
			if (student4!="NV"){
				i=i+1;
			}
			if (student5!="NV"){
				i=i+1;
			}
			cout << "Total number of students in the system: "<< i << endl;
			cout << endl;
			break;
			//End of case 5
			
		case 6:
			cout << "            Display Student Record Without Grades" << endl;
			cout << "**************************************************************" <<endl
			     << "Student Name               Marks"                               << endl
			     << "**************************************************************" <<endl;
			     if (student1!="NV"){
			     	cout << student1 << "                          "<< marks1 << endl;
				 }
				  if (student2!="NV"){
			     	cout << student2 << "                          " << marks2 << endl;
				 }
				  if (student3!="NV"){
			     	cout << student3 << "                          " << marks3 << endl;
				 }
				  if (student4!="NV"){
			     	cout << student4 << "                          " << marks4 << endl;
				 }
				  if (student5!="NV"){
			     	cout << student5 << "                          " << marks5 << endl;
				 }
				 cout << endl;
			break;
			//End of case 6
			
		case 7:
			   cout << "         Display Student Record Without Grades" << endl;
			cout << "**************************************************************" <<endl
			     << "Student Name               Marks             Grades"            << endl
			     << "**************************************************************" <<endl;
			     if (student1!="NV"){
			     	cout << student1 << "                          " << marks1 << "                    " << g1 << endl;
				 }
				  if (student2!="NV"){
			     	cout << student2 << "                          " << marks2 << "                    " << g2 << endl;
				 }
				  if (student3!="NV"){
			     	cout << student3 << "                          " << marks3 << "                    " << g3 << endl;
				 }
				  if (student4!="NV"){
			     	cout << student4 << "                          " << marks4 << "                    " << g4 << endl;
				 }
				  if (student5!="NV"){
			     	cout << student5 << "                          " << marks5 << "                    " << g5 << endl;
				 }
				 cout << endl;
		    break;
			//End of case 7
		
		case 0:
			cout << "                     Thank You!";
				
	}//Switch ends here.//
	  
	}//do while.//
	while (input!=0);
	

	}
}
	
	
