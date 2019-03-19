<<<<<<< HEAD
#include "pch.h"
#include <iostream>
=======
﻿#include <iostream>
>>>>>>> develop
#include <vector>
#ifdef _WIN32
#include <conio.h>
#else
#include <ncurses.h>
#endif !_WINDOWS_

class Score {
private:
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

<<<<<<< HEAD
	void redo() { history.pop_back(); };
=======
	void redo() { history.size() ? history.pop_back():void(NULL); };
>>>>>>> develop
	
	void AddPoints(int points) { history.push_back(points); };
};

int main()
{
	Score red, blue;
	char ch;
	#ifdef _WIN32
	while ((ch = _getch()) != 27) { // 27 - код клавиши Escape
	#else
	while((ch = getch()) != 27) {
	#endif
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
				red.redo();
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
