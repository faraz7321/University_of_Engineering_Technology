#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main ()

{
	int input, i=0,a=0,b;
	string student[5]={"NV","NV","NV","NV","NV"};
	string studentname;
	string grade[5];
	int marks[5]={-1,-1,-1,-1,-1};
	string UserName, Password;
	bool flag=0;
	
	    cout << "*********************************************************************" <<endl
	         << "                      University Grading System                      " << endl
	         << "*********************************************************************" << endl
	         << "            Please Enter the Administration Credentials!             " << endl
			 << "*********************************************************************" << endl;
	
	/*cout << "Userame     : ";
	cin >> UserName;
	cout << "Password    : ";
	cin >> Password;
	cout << endl;
	if (UserName=="Administrators" || Password=="PF2020"){
	*/
		do {
		cout << "\n"
	         << "Choose the option from the menu:" << endl
	         << "Enter 1 to add a student" << endl
	         << "Enter 2 to search a student" << endl
	         << "Enter 3 to delete a student" << endl
	         << "Enter 4 to update the data of a student" << endl
	         << "Enter 5 to display number of students in the system" << endl
	         << "Enter 6 to display list of all student without grade" << endl
	         << "Enter 7 to display list of all students with grade" << endl
	         << "Enter 0 to close program" << endl
	         << "Enter input: ";
	    cin >> input;  
	    cout << "\n";
	switch(input){
	
	case 1:
	for(i=0; i<5; i++){
		if (student[i]=="NV" && marks[i]==-1){
			cout << "                          Add a Student" << endl;
			cout << "Enter Student Name   : ";
			cin >> student[i];
			//getline(cin,student[i]);
			cout << "Enter Student Marks  : ";
			cin >> marks[i];
			 
			if(marks[i]>=85){
				    grade[i]='A';
				}
			else if(marks[i]>=70){
					grade[i]='B';
				}
			else if(marks[i]>=55){
					grade[i]='C';
				}
			else if(marks[i]>=40){
					grade[i]='D';			
				}
				break;
			}	 
			}
	break;
	case 2:
		cout << "                          Search Student" << endl;
		cout << "Enter Student Name: ";
		cin >> studentname;	
		for(i=0; i<6; i++){
			if (studentname==student[i]){
				cout << "Student Name     : " << student[i] << endl
				     << "Marks            : " << marks[i] << endl
				     << "Grade            : " << grade[i] << endl;	
				break;
			}
		}
	cout << endl;		
	//End of case 2
	break;
	case 3:
		cout << "                          Delete Student Record" << endl;
		cout << "Enter student name    : ";
		cin >> studentname;
		for(i=0; i<5; i++){
			if (student[i]==studentname){
				student[i]="NV"; marks[i]=-1;
				break;
		}
		}
		for(i=0;i<5;i=i+1)
		{
			cout<<"student"<<i<<"="<<student[i]<<"            "<<"marks"<<i<<"="<<marks[i]<<endl;
		}
	cout << endl;
	//End of case 3
	break;
	case 4:
		cout << "                          Update Student Record" << endl;
		cout << "Enter Student Name: ";
		cin >> studentname;
		
		for(i=0; i<6; i++){
			if (studentname==student[i]){
				cout << endl;
				cout << "Student Name        : " << student[i] << endl
				     << "Student Marks       : " << marks[i] << endl
				     << "Enter Student Marks : ";
				     cin >> marks[i];
				     if(marks[i]>=85){
				     	grade[i]='A';
					 }
					 else if(marks[i]>=70){
					 	grade[i]='B';
					 }
					 else if(marks[i]>=55){
					 	grade[i]='C';
					 }
					 else if(marks[i]>=40){
					 	grade[i]='D';			
					 }
				     cout << "Student Record Updated SUCCESSFULLY!";
				     break;
			    }
			}
	cout << endl;		
	//End of case 4		
	break;		
	case 5:
		a=0;
		for(i=0; i<5; i++){
			if (student[i]!="NV"){
				a=a+1;
            }
            else{
            		break;
			}
		}
		cout << "Total Number of Students in System:      "<< a << endl;
	cout << endl;		
	//End of case 5	
	break;
	case 6:
		cout << "               Display Student Record Without Grades"                  << endl
		     << "*********************************************************************" <<endl
			 <<left<<setw(30)<<"Student Name" <<setw(15)<< "Marks" << endl
			 << "*********************************************************************" <<endl;   
		for(i=0; i<5; i++){
			if (student[i]!="NV"){
			    cout << left << setw(30) << student[i] << left <<setw(15)<< marks[i] << endl;
				 }	 
			}
		cout << "*********************************************************************";
	cout << endl;		
	//End of case 6
	break;	
	case 7:
		cout << "                      Student Records with Grades" << endl;
		cout << "*********************************************************************" <<endl
			 <<left<< setw(30) << "Student Name" <<left<<setw(15) << "Marks"<< left << setw(10) << "Grade" << endl
			 << "*********************************************************************" <<endl;
		for(i=0; i<5; i++){
			if (student[i]!="NV"){ 		
			     	cout << left << setw(30) << student[i] << left << setw(15) << marks[i] << left << setw(10) << grade[i] <<endl;
				 }
				 else{
				 	break;
				 }
				 }
		cout << "*********************************************************************";  
	cout << endl;	 
	//End of case 7
	break;
	case 0:
		cout << "                          Thank You!";
	}//Switch ends here.//
	}//do while.//
	while (input!=0);
}
