#include "category.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QString>

//MySQL connection data
#define HOST "localhost"
#define USER "root"
#define DBNAME "categories"
#define PASS "dreamroad"
#define PORT NULL
#define LOCALENCODING "set names windows-1251"
#define FIELDS "SELECT name, birth, club FROM `"

QVector <QString> split(QString str, char delim) {
	QVector <QString> result;
	QString temp;
	for (int i = 0; i < str.length(); i++) {
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

QVector <Category> getCategories() {

    QSqlDatabase conn = QSqlDatabase::addDatabase("QMYSQL");
    conn.setHostName(HOST);
	conn.setDatabaseName(DBNAME);
    conn.setUserName(USER);
    conn.setPassword(PASS);

    if (!conn.open()) { // Если не удалось подключиться к БД
        std::cout << "MySQL ERROR connection();" << std::endl;
        exit(1);
    }

	//QTextCodec * myTextCodec = QTextCodec::codecForName("UTF-8");   // Устанавливаем кодировку сервера НЕ ТОЧНО ЧТО РАБОТАЕТ

	QSqlQuery res; //создаем упращение для вызова, вместо QSqlQuery query.exec()

	res.exec(LOCALENCODING); // Устанавливаем кодировку для корректного выполнения запросов на русском языке
	res.exec("SHOW TABLES"); // Делаем запрос к базе и получаем список таблиц
	QVector <Category> categs; // Создаём массив категорий

	if (res.size() > 0) { // Если есть результаты
		while (res.next()) { // Цикл проходит по всем полученным результатам
            Category temp;
						temp.name = res.value(0).toString(); // Задаём имя категории
						QVector <QString> tempData = split(res.value(0).toString(), ' ');
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

            categs.push_back(temp); // Добавляем категорию
        }
		for (int i = 0; i < categs.size(); i++) {
			const QString query = static_cast<QString>(FIELDS + categs[i].name + "`;"); // Формируем текст запроса
			res = QSqlQuery(query, conn);
			res.exec(); // Посылаем запрос в БД
			if (res.size() > 0) { // Если запрос вернул не пустой результат
				while (res.next()) { // Проходим по всем результатам
                    // Заполняем поля участника
                    Participant temp;
					temp.name = res.value(0).toString();
					temp.birth = res.value(1).toString();
					temp.club = res.value(2).toString();
                    categs[i].participants.push_back(temp); // Заносим участника в базу
                }
            }
        }
    }
    else
		std::cout << "No categories in database " << DBNAME << "!!!" << std::endl;
	conn.close();
    return categs;
}

int printCategories(const QVector <Category>& categories)
{
    setlocale(LC_ALL, "Rus");
    for(auto& category : categories){
		std::cout << "->" << category.name.toStdString() << std::endl;
        std::cout<< "--> size is:" << categories.size() << std::endl;
        std::cout << "--> mode id:" << category.mode <<' '<< std::endl;
        std::cout << "--> Totaly: " << category.participants.size() << " sportsmens in category" << std::endl;

        for(const Participant& Sportsmen: category.participants){
			std::cout << "---->sportsmen:" << Sportsmen.name.toStdString() << ' '
			            << Sportsmen.birth.toStdString() << ' '
			            << Sportsmen.club.toStdString() << ' '
                        << std::endl;
            }
        std::cout << "---------------------------------------------------------"<<std::endl;
    }

    return 0;
}

QVector <Category> getCategTemplate() {
	QVector <Category> categs;
	QString categsNames[] = {
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
	QString humans[9][2][3] = {
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