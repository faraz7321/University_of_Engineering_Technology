#include<iostream>
#include<string>
using namespace std;
int main()


{
	//Lab manual 3. AQI
	string x;
	
	cout << "Enter location name: ";
	cin >> x;    
	
	//.GETLINE() AND CHAR X[] COULD BE USED WHEN ENETRING SPACE TERMINATES THE STRING LINE.//
	
	if(x=="UET"){
		cout << "AQI for UET is 144 UNHEALTHY";
	}
	else if(x=="GT Road"){
		cout << "AQI for GT Road is 142 UNHEALTHY";
	}
		else if(x=="Samanabad"){
		cout << "AQI for Samanabad is 135 UNHEALTHY";
	}
		else if(x=="Defence Phase I"){
		cout << "AQI for Defence Phase I is 104 UNHEALTHY FOR SENSITIVE GROUPS";
	}
		else if(x=="Askari X"){
		cout << "AQI for Askari X is 134 UNHEALTHY FOR SENSITIVE GROUPS ";
	}
		else if(x=="Bahria Town"){
		cout << "AQI for Bahria Town is 76 MODERATE ";
	}
		else if(x=="Shalamar"){
		cout << "AQI for Shalamar is 133 UNHEALTHY FOR SENSITIVE GROUPS ";
	}
return 0;
}
