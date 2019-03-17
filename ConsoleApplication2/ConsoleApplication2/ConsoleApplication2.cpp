#include "pch.h"
#include "Array.h"
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

class Category {
public:
	std::string name;
	Array <Participant> participants;
	Participant &operator[](size_t index) {
		return participants[index];
	}

	Array <Participant> &operator()() {
		return participants;
	}
};

Array <Category> getCategories() {
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
	Array <Category> categs; // Создаём массив категорий

	if (res = mysql_store_result(conn)) { // Если есть результаты
		while (row = mysql_fetch_row(res)) { // Цикл проходит по всем полученным результатам
			categs.append(); // Добавляем категорию
			categs.last().name = std::string(row[0]); // Задаём её имя
		}
		for (int i = 0; i < categs.length(); i++) {
			const char *query = static_cast<std::string>(FIELDS + categs[i].name + "`;").c_str(); // Формируем текст запроса
			mysql_query(conn, static_cast<const char*>(query)); // Посылаем запрос в БД
			if (res = mysql_store_result(conn)) { // Если запрос вернул не пустой результат
				while (row = mysql_fetch_row(res)) { // Проходим по всем результатам
					// Заполняем поля участника
					categs[i].participants.append();
					categs[i].participants.last().name = row[0];
					categs[i].participants.last().birth = row[1];
					categs[i].participants.last().club = row[2];
				}
			}
		}
	}
	else
		std::cout << mysql_error(conn) << std::endl;
	mysql_close(conn);
	return categs;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Array <Category> categories = getCategories();
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