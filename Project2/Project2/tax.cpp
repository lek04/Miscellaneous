#include <iostream>
#include <string>
using namespace std;

int main()
{
	/* Intializing variables*/
	string name;
	double actincome;
	double taxincome = 0;
	string job;
	int kids;

	/* Information Gathering */
	cout << "Name: ";
	getline(cin, name);
	cout << "Taxable Income: ";
	cin >> actincome;
	cin.ignore(10000, '\n');
	cout << "Occupation: ";
	getline(cin, job);
	cout << "Number of children: ";
	cin >> kids; 
	cout << "---" << endl;

	/* Calculating Tax based on occupation, income, and kids */
	if (actincome > 0 && actincome <= 55000) { 	/* First Tax Bracket (First 55k) */
		taxincome = actincome * 0.04;
	}
	else if (actincome <= 125000 && actincome >55000) { /* Second Tax Bracket (Next 70k) */
		if (job == "nurse" || job == "teacher") {
			taxincome = ((actincome - 55000) * 0.05) + (55000 * 0.04); /* Second Tax Bracket capped at 5% for teachers and nurses + first 55k tax */
		}
		else {
			taxincome = ((actincome - 55000) * 0.07) + (55000 * 0.04); /* Second Tax bracket 0.07 for everyone else + first 55k tax*/
		}
	}
	else if (actincome > 125000) { /* Third tax brakcet (For income that exceeds 125k) */
			if (job == "nurse" || job == "teacher") {
				taxincome = (55000 * 0.04) + (70000 * 0.05) + ((actincome - 125000) * 0.093); /* First 55k tax + next 70k tax w/ 5% cap for teachers/nurses + tax for income over 125k */
			}
			else {
				taxincome = (55000 * 0.04) + (70000 * 0.07) + ((actincome - 125000) * 0.093); /* First 55k tax + next 70k tax + tax for income over 125k */
			}
		}	 
	if (actincome < 125000) { /* Kids tax reduction */
		taxincome = taxincome - (kids * 200);
		if (taxincome <= 0) { /* Ensures tax is never below 0 or negative */
			taxincome = 0; 
		}
	}

	/* If user inputs in something invalid*/
	if (name == "") {
		cout << "You must enter a name";
		exit(0); 
	}
	if (actincome < 0) {
		cout << "The taxable income must not be negative";
		exit(0);
	}
	if (job == "") {
		cout << "You must enter an occupation";
		exit(0);
	}
	if (kids < 0) {
		cout << "The number of children must not be negative";
		exit(0);
	}

	/* If inputs are valid*/
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << name << " would pay $" << taxincome;
}