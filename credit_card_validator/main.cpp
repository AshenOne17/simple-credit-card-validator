#include <iostream>
#include <string>
#include <vector>
#include "cardfunctions.h"

int main(int argc, char** argv) 
{
	using namespace std;
	
	while (cin) 
	{
		
		int choice = input();
		
		cin.ignore();
		string cNumberString{ getCardNumber(choice) };

		vector<int> cNumber;

		cardNumberConvert(cNumberString, cNumber);
		
		int firstSum{ notDoubledNumberSum(cNumber) };
		int secondSum{ doubledNumberSum(cNumber) };
		int totalSum = firstSum + secondSum;

		// Luhn's algorithm main condition
		if ((totalSum % 10) == 0) { cout << "Your card is valid!\n\n"; }
		else { cout << "Error! Your card is not valid!\n\n"; }
	}

}