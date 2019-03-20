//#include "pch.h"
#include <vector>
#include <iostream>
#include <mysql.h>
#include <string.h>

#define HOST "localhost"
#define USER "root"
#define PASS "lasjbdkashbdabsg123t1762dlm12393y4hfbkwsd8ye283heHIBUSDUIAH&@rnq2987y238"
#define PORT NULL
#define LOCALENCODING "set names utf8"
#define FIELDS "SELECT name, birth, club FROM `"

struct Participant {
public:
	std::string name, birth, club;
};

std::vector <std::string> split(std::string str, char delim) {
	std::vector <std::string> result;
	std::string temp;
	for (unsigned int i = 0; i < str.length(); i++) {
		if (str[i] == delim) {
			result.push_back(temp);
			temp = "";
			continue;
		}
		temp += str[i];
	}
	if (temp != "")
		result.push_back(temp);
	return result;
}

class Category {
public:
	std::string name;
	enum MODE {
		PERSONAL_TUL, PERSONAL_SPARRING, TEAM_TUL, TEAM_SPARRING, TRADITIONAL_TUL, TRADITIONAL_SPARRING
	} mode;
	std::vector <Participant> participants;
	Participant &operator[](size_t index) {
		return participants[index];
	}

	std::vector <Participant> &operator()() {
		return participants;
	}
};

std::vector <Category> getCategories() {
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

	if ((conn = mysql_init(NULL)) == NULL) { // Если не удалось инициализировать MySQL
		std::cout << "Error with mysql_init();" << std::endl;
		exit(1);
	}

	if (mysql_real_connect(conn, HOST, USER, PASS, "categories", PORT, NULL, NULL) == NULL) { // Если не удалось соединиться с сервером
		std::cout << "Error with mysql_real_connect();" << std::endl;
		exit(1);
	}

	mysql_set_character_set(conn, "utf8_general_ci"); // Устанавливаем кодировку сервера
	mysql_query(conn, LOCALENCODING); // Устанавливаем кодировку для корректного выполнения запросов на русском языке
	mysql_query(conn, "SHOW TABLES"); // Делаем запрос к базе и получаем список таблиц
	std::vector <Category> categs; // Создаём массив категорий

	if (res = mysql_store_result(conn)) { // Если есть результаты
		while (row = mysql_fetch_row(res)) { // Цикл проходит по всем полученным результатам
			Category temp;
			std::vector <std::string> tempData = split(row[0], ' ');
			if (tempData[5] == "1")
				temp.mode = Category::MODE::PERSONAL_TUL;
			else if (tempData[6] == "1")
				temp.mode = Category::MODE::TEAM_TUL;
			else if (tempData[7] == "1")
				temp.mode = Category::MODE::TRADITIONAL_TUL;
			else if (tempData[8] == "1")
				temp.mode = Category::MODE::PERSONAL_SPARRING;
			else if (tempData[9] == "1")
				temp.mode = Category::MODE::TEAM_SPARRING;
			else if (tempData[10] == "1")
				temp.mode = Category::MODE::TRADITIONAL_SPARRING;

			temp.name = std::string(row[0]); // Задаём имя категории
			categs.push_back(temp); // Добавляем категорию
		}
		for (int i = 0; i < categs.size(); i++) {
			const char *query = static_cast<std::string>(FIELDS + categs[i].name + "`;").c_str(); // Формируем текст запроса
			mysql_query(conn, static_cast<const char*>(query)); // Посылаем запрос в БД
			if (res = mysql_store_result(conn)) { // Если запрос вернул не пустой результат
				while (row = mysql_fetch_row(res)) { // Проходим по всем результатам
					// Заполняем поля участника
					Participant temp;
					temp.name = row[0];
					temp.birth = row[1];
					temp.club = row[2];
					categs[i].participants.push_back(temp); // Заносим участника в базу
				}
			}
		}
	}
	else
		std::cout << mysql_error(conn) << std::endl;
	mysql_close(conn);
	return categs;
}

std::vector <Category> getCategTemplate() {
	std::vector <Category> categs;
	std::string categsNames[] = {
		"м 2000 2001 10-7 гуп 1 0 0 0 0 0 0 0 0",
		"м 2000 2002 10-6 гуп 1 0 0 0 0 0 0 0 0",
		"м 2000 2002 10-8 гуп 1 0 0 0 0 0 0 0 0",
		"м 2000 2003 10-4 гуп 1 0 0 0 0 0 0 0 0",
		"м 2000 2004 10-2 гуп 1 0 0 0 0 0 0 0 0",
		"м 2000 2005 10-5 гуп 1 0 0 0 0 0 0 0 0",
		"м 2000 2006 10-1 гуп 1 0 0 0 0 0 0 0 0",
		"м 2000 2006 10-3 гуп 1 0 0 0 0 0 0 0 0",
		"м 2000 2008 1-5 дан 1 0 0 0 0 0 0 0 0"
	};
	std::string humans[9][2][3] = {
		{
			{"Талашин Иван Иванович", "2003-12-16", "РОДИНА"},
			{"", "", ""}
		},
		{
			{"Талашин Иван Иванович1", "2003-12-16", "РОДИНА"},
			{"", "", ""}
		},
		{
			{"Талашин Иван Иванович2", "2003-12-16", "РОДИНА"},
			{"", "", ""}
		},
		{
			{"Талашин Иван Иванович3", "2003-12-16", "РОДИНА"},
			{"", "", ""}
		},
		{
			{"Талашин Иван Иванович4", "2003-12-16", "РОДИНА"},
			{"", "", ""}
		},
		{
			{"Талашин Иван Иванович5", "2003-12-16", "РОДИНА"},
			{"", "", ""}
		},
		{
			{"Талашин Иван Иванович6", "2003-12-16", "РОДИНА"},
			{"", "", ""}
		},
		{
			{"Талашин Иван Иванович7", "2003-12-16", "РОДИНА"},
			{"", "", ""}
		},
		{
			{"Талашин Иван Иванович8", "2006-12-16", "РОДИНА"},
			{"Талашин Иван Иванович8", "2003-12-16", "РОДИНА"}
		},
	};

	for (size_t i = 0; i < 9; i++)
	{
		Category temp;
		temp.name = categsNames[i];
		temp.mode = Category::MODE(i % 2);
		for (int j = 0; j < 2; j++) {
			if (humans[i][j][0] != "") {
				Participant tempPart;
				tempPart.name = humans[i][j][0];
				tempPart.birth = humans[i][j][1];
				tempPart.club = humans[i][j][2];
				temp.participants.push_back(tempPart);
			}
		}
		categs.push_back(temp);
	}

	return categs;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	std::vector <Category> categories = getCategTemplate();
	//std::cout << categories[2][0].name.c_str() << std::endl;
	/*
	categories.length() - Количество категорий
	categories[i].name - Имя категории с индексом i
	categories[i].length() - Количество людей в категории с индексом i
	categories[i][j].name - Имя человека с индексом j в категории с индексом i
	categories[i][j].birth - Дата рождения человека с индексом j в категории с индексом i
	categories[i][j].club - Клуб человека с индексом j в категории с индексом i
	*/
	return 0;
}