#include "cardfunctions.h"
#include <iostream>
#include <windows.h>

int input() 
{
	int choice;

	do
	{
		std::cout << "***Credit card validator (VISA, MasterCard, American Express, Discover Cards, etc.) (Luhn's alg.)***\n\n";
		std::cout << "1. American Express\n2. Other\n3. Close the program\n4. Clear console\nYour option: ";

		std::cin >> choice;

		if (choice == 3) { exit(1); }

		if (choice == 4) { consoleClear(); }

		if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
		{
			std::cerr << "Wrong option, error!Try again!\n\n";
			std::cin.clear();
			std::cin.ignore();
		}

	} while (choice != 1 && choice != 2 && choice != 3);

	return choice;
}

void consoleClear() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

std::string getCardNumber(int num)
{
	std::cout << "Enter your card number: ";
	std::string cardNumber;
	std::getline(std::cin, cardNumber);

	// Checking validity of card length (including both variants with or without whitespaces (max 3))
	// AMEX Variant
	if (num == 1) 
	{
		if (cardNumber.length() != 17 && cardNumber.length() != 15) { std::cerr << "Wrong card number, error!\n"; exit(1); }
	}
	// Others Variant
	else if (num == 2) 
	{
		if (cardNumber.length() != 19 && cardNumber.length() != 16) { std::cerr << "Wrong card number, error!\n"; exit(1); }
	}

	if (isStringNumber(cardNumber)) { return cardNumber; }
	else { std::cerr << "Card number contains not only numbers!\n"; exit(1); }
}

bool isStringNumber(const std::string& string)
{
	int strLength{ static_cast<int>(string.length()) };

	auto begin{ &string[0] };
	auto end{ begin + strLength };

	for (auto ptr{ begin }; ptr != end; ++ptr)
	{
		// Checking for whitespaces
		if ((*ptr == ' ')) { continue; }
		// Main condition
		if ((*ptr) < '0' || (*ptr) > '9') { return false; }
	}

	return true;
}

int notDoubledNumberSum(const std::vector<int>& vector) {
	int sum = 0;

	// Iterators for vector
	auto begin{ &vector.front() };
	auto end{ &vector.back() };
	
	int temp = 0;
	// AMEX Algorithm				
	if (vector.size() == 15) 
	{	// Difference (begin instead of begin + 1, < instead of <=)
		for (auto ptr{ begin }; ptr <= end; ptr += 2)
		{
			sum += (*ptr);
		}
	}
	// Others algorithm				// Difference (<= instead of <)
	else if (vector.size() == 16) 
	{ 
		for (auto ptr{ begin + 1 }; ptr <= end; ptr += 2) 
		{ 
			sum += (*ptr); 
		} 
	}

	return sum;
}

int doubledNumberSum(const std::vector<int>& vector)
{
	int sum = 0;
	std::vector<int>::size_type vec_sz{ vector.size() };

	// Iterators for vector
	auto begin{ &vector.front() };
	auto end{ &vector.back() };

	int temp = 0;

	// AMEX algorithm
	if (vector.size() == 15)
	{				
		// Difference (< end instead of end - 1)
		for (auto ptr{ begin + 1}; ptr < end; ptr += 2)
		{
			temp = (*ptr) * 2;

			if (temp > 9 && temp < 100)
			{
				sum += temp / 10 % 10;
				sum += temp % 10;
			}
			else { sum += temp; }
		}
	}
	// Others algorithm
	else if (vector.size() == 16)
	{				// Difference (end - 1 instead of < end)
		for (auto ptr{ begin }; ptr <= end - 1; ptr += 2)
		{
			temp = (*ptr) * 2;

			if (temp > 9 && temp < 100)
			{
				sum += temp / 10 % 10;
				sum += temp % 10;
			}
			else { sum += temp; }
		}
	}

	return sum;
}

void cardNumberConvert(const std::string& string, std::vector<int>& vector)
{
	int count{ 0 };

	// Main loop for converting string into vector elements for sum
	while (count < string.length())
	{
		// Whitespace check
		if (string[count] == ' ')
		{
			count++;
			continue;
		}
		// Converting each symbol into integer
		vector.push_back((((int)string[count]) - 48));
		++count;
	}

}

