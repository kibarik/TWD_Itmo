// ButtonsScore.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#ifdef _WIN32
#include <conio.h>
#else
#include <ncurses.h>
#endif !_WINDOWS_

class Score {
	std::vector <uint8_t> history;
public:
	enum MODE {
		TUL, SPARRING
	} mode = MODE::TUL;

	int score() {
		int sum = 0;
		for (int i = 0; i < history.size(); i++)
			sum += history[i];
		if (mode)
			sum = 100 - sum;
		return sum;
	};

	void redo() { history.pop_back(); };
	
	void AddPoints(int points) { history.push_back(points); };
};

int main()
{
	Score red, blue;
	char ch;
	while ((ch = _getch()) != 27){
		switch (ch) {
			case 'f':
				red.AddPoints(1);
				break;
			case 'd':
				red.AddPoints(2);
				break;
			case 's':
				red.AddPoints(3);
				break;
			case 'a':
				red.redo;
				break;
			case 'j':
				blue.AddPoints(1);
				break;
			case 'k':
				blue.AddPoints(2);
				break;
			case 'l':
				blue.AddPoints(3);
				break;
			case ';':
				blue.redo();
				break;
			default:
				std::cout << "RED: " << red.score() << "\nBLUE: " << blue.score() << std::endl;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
