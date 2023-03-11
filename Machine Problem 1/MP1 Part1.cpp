//Justin Ritchey 9/11/2020. This is for Machine Problem 1 part 1. This cpp has 3 purposes, 1. to make an exponant calculator, 2. make a convert to seconds calculator and 3. create a function that only swaps numbers.

#include <cmath>
#include <iostream>
#include <iomanip>


using namespace std;


//Functions
double power(double, int);                     //Function to raise a number to a power, if no power is given default is 2
long int hms_to_secs(int, int, int);           //Function to take hours minutes and seconds and convert to total seconds
void swap(int&, int&);                         //Function to swap one int to the next


double number = 0.0;                           //NUmber entered by user for use in power function
int p = 2;                                     //int for power fucntion, defaults to power 2
string choice = "";                            //holds the choice of which function the user wants
int h, m, s = 0;                               //int's for hours minutes and seconds
int pass1, pass2 = 0;                          //int's meant to be interchanged
double powersolution = 0.0;                    //Solution for power function
long int ctsSolution = 0;                      //Solution for CTS fucntion
char c1, c2;                                   //Semi-colon space holder for hms_to_secs funciton



void main()
{

	cout << "What would you like to use? powers, convert to seconds(cts), or swap? ";           //asking user what they would like to do
	cin >> choice;
	cout << setprecision(1) << fixed;                                                           //setting decimal place for printing out doubles

	if (choice == "powers")                                                                     //logic for if user wants to use the power function
	{
		cout << "Please enter a number and what power you would like to raise it to: ";
		cin >> number;
		if (cin.peek() == '\n')                                                                 //if user does not enter an exponant it will default to 2
			p = 2;
		else                                                                                    //otherwise it will assign the exponant
			cin >> p;
		
		power(number, p);                                                                       //sending the numbers to the funcion
		cout << "The answer is: "<< powersolution << "\n";                                      //printing out the function

	}

	else if (choice == "cts")                                                                   //If user chooses the conver to seconds fucntion
	{
		while (ctsSolution >= 0)                                                                //creating loop to continue asking for hours, minutes and seconds
		{
			cout << "Please enter the hour, minutes and seconds (hh:mm:ss): ";                  //asking for hours, minutes and seconds
			cin >> h >> c1 >> m >> c2 >> s;

			if (h < 0)                                                                          //if hours is negative this will break the loop
				break;
			
			hms_to_secs(h, m, s);                                                               //sneidng hours, minutes and seconds to be converted to seconds
			
			
		}
	}

	else if (choice == "swap")                                                                  //if user chooses to swap numbers
	{
		cout << "Please enter 2 numbers to swap: ";                                             //asking for the numbers to swap
		cin >> pass1 >> pass2;                      
		 
		swap(pass1, pass2);                                                                    //sending the numbers to swap function

	}

	else  
	{
		cout << "Please try again\n";                                                          //if user does not enter in the correct fucntion
	}

	system("pause");
	
}

double power(double number, int p)                                                            //power function
{

	powersolution = pow(number, p);                                                           //using a power call to calcuate the numbers

	return powersolution;                                                                     //sending back the solution
}

long int hms_to_secs(int h, int m, int s)                                                     //hms_to_secs function
{
	
	ctsSolution = (h * 60 * 60) + (m * 60) + s;                                               //calculations to convert to seconds

	cout << "The amount of seconds is: " << ctsSolution << "\n";                              //printing out results

	return ctsSolution;                                                                       //Sending back solution for the loop

	
}


void swap(int &pass1, int &pass2)                                                             //swap function - not sure if this needed user input but i made it to show how it works
{
	int pass3 = 0;                                                                            //swapping the numbers
	pass3 = pass1;
	pass1 = pass2;
	pass2 = pass3;
	 
	cout << "The swapped numbers are: " << pass1 << " and " << pass2 << "\n";                 //printing out the variables in the same order to show they have been swapped
}
