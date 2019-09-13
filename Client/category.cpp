#include "category.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QString>
#include <QDebug>

//MySQL connection data--------------------------
#define HOST "localhost"
#define USER "root"
#define DBNAME "categories"
#define PASS ""
#define PORT NULL
#define LOCALENCODING "set names utf8"
#define FIELDS "SELECT name, birth, club FROM `"
#define CONTESTSSTART 7

/*
Чтобы снизить нагрузку на сервер, клиент будет работать
через локальную копию категорий. Это позволяет снизить
Количество запросов к базе.

В дальнейшем localCategories будет автоматически
обновляться как-только на сервере происходят изменения
*/
    static QVector<Category> LOCALcategories = getCategTemplate();

//-------------------------------------------------------------


QVector <QString> split(QString str, char delim) { //техническая функция
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

QVector <Category> getCategories() { //функция обращения к БД
    QSqlDatabase conn = QSqlDatabase::addDatabase("QMYSQL");
    conn.setHostName(HOST);
    conn.setDatabaseName(DBNAME);
    conn.setUserName(USER);
    conn.setPassword(PASS);

    //assert (conn.open()); //ошибка подключения к БД в виде окошка

    //QTextCodec * myTextCodec = QTextCodec::codecForName("UTF-8");   // Устанавливаем кодировку сервера НЕ ТОЧНО ЧТО РАБОТАЕТ

    QSqlQuery res; //создаем упращение для вызова, вместо QSqlQuery query.exec()

    res.exec(LOCALENCODING); // Устанавливаем кодировку для корректного выполнения запросов на русском языке
    res.exec("SHOW TABLES"); // Делаем запрос к базе и получаем список таблиц
    QVector <Category> categs; // Создаём массив категорий

    if (res.size() > 0) { // Если есть результаты
        while (res.next()) { // Цикл проходит по всем полученным результатам
            Category temp;
            QVector <QString> tempData = split(res.value(0).toString(), ' '); //определение модели (туль, спарринг и т.п)

			//задаем имя для QML перед определением мода, в последующем опционально добавляем вес(для спарринга)
			temp.qmlName = tempData[0] +' '+ tempData[1] +'-'+ tempData[2] +" г.р. "+
			        tempData[3]+ tempData[5] + " - "+ tempData[4]+ tempData[6]+' ';

			//ВНИМАНИЕ! textMode в дальнейшем используется в ParticipantsWindow.qml-> start.onClicked() при изменении подправить qml
			if (tempData[CONTESTSSTART] == "1"){
                temp.mode = Category::MODE::PERSONAL_TUL;
                temp.textMode = "Туль личный";
				temp.qmlName += temp.textMode;
            }
            else if (tempData[CONTESTSSTART + 1] == "1"){
                temp.mode = Category::MODE::TEAM_TUL;
				temp.textMode = "Туль командный";
				temp.qmlName += temp.textMode;
            }
            else if (tempData[CONTESTSSTART + 2] == "1"){
                temp.mode = Category::MODE::TRADITIONAL_TUL;
                temp.textMode = "Туль традиционный";
				temp.qmlName += temp.textMode;
            }
            else if (tempData[CONTESTSSTART + 3] == "1"){
                temp.mode = Category::MODE::PERSONAL_SPARRING;
                temp.textMode = "Спарринг личный";
				temp.qmlName +=  tempData[CONTESTSSTART+9]+ " Кг " + temp.textMode;
            }
            else if (tempData[CONTESTSSTART + 4] == "1"){
                temp.mode = Category::MODE::TEAM_SPARRING;
				temp.textMode = "Спарринг командный";
				temp.qmlName += temp.textMode;

            }
            else if (tempData[CONTESTSSTART + 5] == "1"){
                temp.mode = Category::MODE::TRADITIONAL_SPARRING;
                temp.textMode = "Спарринг традиционный";
				temp.qmlName += temp.textMode;
            }

			else if (tempData[CONTESTSSTART + 6] == "1"){
				temp.mode = Category::MODE::IMPACT_FORCE;
				temp.textMode = "Силовое разбивание";
				temp.qmlName += temp.textMode;
			}

			else if (tempData[CONTESTSSTART + 7] == "1"){
				temp.mode = Category::MODE::TRADITIONAL_SPARRING;
				temp.textMode = "Спец. техника";
				temp.qmlName += temp.textMode;
			}

			temp.name = res.value(0).toString(); // Задаём имя категории
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

    //setlocale(LC_//    QTextStream cout(stdout); cout.setCodec("utf8"); //русская категорвкаALL,"Russian"); //русская локализация вывода std::cout
    for(const Category& category : categories){
		qDebug() << "->" << category.qmlName ;

        qDebug()<< "--> We find: " << categories.size() << " categories";
        qDebug() << "--> mode id: " << category.textMode;
        qDebug() << "--> Totaly: " << category.participants.size() << " sportsmens in category";

        for(const Participant& Sportsmen: category.participants){
            qDebug() << "---->sportsmen:" << Sportsmen.name << " "
                        << Sportsmen.birth << " "
                        << Sportsmen.club << " ";
            }
        qDebug() << "---------------------------------------------------------"<<endl;
    }

    return 0;
}

QVector <Category> getCategTemplate() {
    QVector <Category> categs;
    QString categsNames[] = {
        "м 2000 2001 10-7 гуп 1 0 0 0 0 0 0 0 0",
        "м 2000 2002 10-6 гуп 0 1 0 0 0 0 0 0 0",
        "м 2000 2002 10-8 гуп 0 0 1 0 0 0 0 0 0",
        "м 2000 2003 10-4 гуп 0 0 0 1 0 0 0 0 0",
        "м 2000 2004 10-2 гуп 0 0 0 0 1 0 0 0 0",
        "м 2000 2005 10-5 гуп 0 0 0 0 0 1 0 0 0",
        "м 2000 2006 10-1 гуп 0 0 0 0 0 0 1 0 0",
        "м 2000 2006 10-3 гуп 0 0 0 0 0 0 0 1 0",
        "м 2000 2008 1-5 дан 0 0 0 0 0 0 0 0 1"
    };
    QString humans[9][3][3] = {
        {
            {"Талашин Иван Иванович", "2003-12-16", "РОДИНА"},
            {"Талашин Иван Иванович", "2003-12-16", "РОДИНА"},
            {"", "", ""}
        },
        {
            {"Талашин Иван Иванович1", "2003-12-16", "РОДИНА"},
            {"", "", ""},
            {"", "", ""}
        },
        {
            {"Талашин Иван Иванович2", "2003-12-16", "РОДИНА"},
            {"", "", ""},
            {"", "", ""}
        },
        {
            {"Талашин Иван Иванович3", "2003-12-16", "РОДИНА"},
            {"", "", ""}
        },
        {
            {"Талашин Иван Иванович4", "2003-12-16", "РОДИНА"},
            {"", "", ""},
            {"", "", ""}
        },
        {
            {"Талашин Иван Иванович5", "2003-12-16", "РОДИНА"},
            {"", "", ""},
            {"", "", ""}
        },
        {
            {"Талашин Иван Иванович6", "2003-12-16", "РОДИНА"},
            {"", "", ""},
            {"", "", ""}
        },
        {
            {"Талашин Иван Иванович7", "2003-12-16", "РОДИНА"},
            {"", "", ""},
            {"", "", ""}
        },
        {
            {"Талашин Иван Иванович8", "2006-12-16", "РОДИНА"},
            {"Талашин Иван Иванович9", "2003-12-16", "РОДИНА"},
            {"Талашин Иван Иванович10", "2003-12-16", "РОДИНА"},
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

//------------------------CategoryAPI functions-----------------



QList<QString> CategoryAPI::setQmlCategoriesNames(){ //передаем имена категорий для отображения в QML
    QList <QString> CategoriesNames;

	for (const Category& category : LOCALcategories) {
		CategoriesNames << category.qmlName;
    };

    return CategoriesNames;
};

//функция для передачи всех участников в окно CategoryWindow.qml
QList<QString> CategoryAPI::setQmlParticipantsNames(const QString& categoryName){
   QList<QString> now;
   Category category;

   for (qint8 i = 0; i<LOCALcategories.size(); ++i) { //перебор по всем категория в локальном хранилище
	   if(LOCALcategories.at(i).qmlName == categoryName){//ищем нашу категорию
		   category = LOCALcategories[i];
		   qDebug() << "<setQMLParticipantsNames> OK:" << LOCALcategories.at(i).qmlName
		            << " opened!" <<" participants: " << LOCALcategories.at(i).participants.size();
	   }
   }

   for(const Participant& participant: category.participants){
	   //qDebug()<<participant.name<<"\n"<< participant.club;
	   now.push_back(participant.name+"\n"+ participant.club);
   };

   return now;

};

/* вариант с попарным разделением участников в очередь QQueue(QPair<QString, QString>)
 *
   for(const Participant& participant: category.participants){
	   if (i%2==0){
		   qDebug() << temp << "<->" << participant.name;
		   now.push_back(qMakePair(temp, participant.name));
		   temp.clear();
	   }
	   else if(i==category.participants.size()) { //для заполнения нечетного кол-ва людей
		   now.push_back(qMakePair(participant.name, temp));
		   qDebug() << "Нечет! " << participant.name << "<->" << temp;
		   break;
	  }
	   else temp = participant.name;

	   i++;
   };

*/
