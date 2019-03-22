#include "Category.h"

//MySQL connection data
#define HOST "localhost"
#define USER "root"
#define PASS "lasjbdkashbdabsg123t1762dlm12393y4hfbkwsd8ye283heHIBUSDUIAH&@rnq2987y238"
#define PORT NULL
#define LOCALENCODING "set names utf8"
#define FIELDS "SELECT name, birth, club FROM `"


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

//std::vector <Category> getCategories() {
//    MYSQL *conn;
//    MYSQL_RES *res;
//    MYSQL_ROW row;

//    if ((conn = mysql_init(NULL)) == NULL) { // Если не удалось инициализировать MySQL
//        std::cout << "Error with mysql_init();" << std::endl;
//        exit(1);
//    }

//    if (mysql_real_connect(conn, HOST, USER, PASS, "categories", PORT, NULL, NULL) == NULL) { // Если не удалось соединиться с сервером
//        std::cout << "Error with mysql_real_connect();" << std::endl;
//        exit(1);
//    }

//    mysql_set_character_set(conn, "utf8_general_ci"); // Устанавливаем кодировку сервера
//    mysql_query(conn, LOCALENCODING); // Устанавливаем кодировку для корректного выполнения запросов на русском языке
//    mysql_query(conn, "SHOW TABLES"); // Делаем запрос к базе и получаем список таблиц
//    std::vector <Category> categs; // Создаём массив категорий

//    if (res = mysql_store_result(conn)) { // Если есть результаты
//        while (row = mysql_fetch_row(res)) { // Цикл проходит по всем полученным результатам
//            Category temp;
//            std::vector <std::string> tempData = split(row[0], ' ');
//            if (tempData[5] == "1")
//                temp.mode = Category::MODE::PERSONAL_TUL;
//            else if (tempData[6] == "1")
//                temp.mode = Category::MODE::TEAM_TUL;
//            else if (tempData[7] == "1")
//                temp.mode = Category::MODE::TRADITIONAL_TUL;
//            else if (tempData[8] == "1")
//                temp.mode = Category::MODE::PERSONAL_SPARRING;
//            else if (tempData[9] == "1")
//                temp.mode = Category::MODE::TEAM_SPARRING;
//            else if (tempData[10] == "1")
//                temp.mode = Category::MODE::TRADITIONAL_SPARRING;

//            temp.name = std::string(row[0]); // Задаём имя категории
//            categs.push_back(temp); // Добавляем категорию
//        }
//        for (int i = 0; i < categs.size(); i++) {
//            const char *query = static_cast<std::string>(FIELDS + categs[i].name + "`;").c_str(); // Формируем текст запроса
//            mysql_query(conn, static_cast<const char*>(query)); // Посылаем запрос в БД
//            if (res = mysql_store_result(conn)) { // Если запрос вернул не пустой результат
//                while (row = mysql_fetch_row(res)) { // Проходим по всем результатам
//                    // Заполняем поля участника
//                    Participant temp;
//                    temp.name = row[0];
//                    temp.birth = row[1];
//                    temp.club = row[2];
//                    categs[i].participants.push_back(temp); // Заносим участника в базу
//                }
//            }
//        }
//    }
//    else
//        std::cout << mysql_error(conn) << std::endl;
//    mysql_close(conn);
//    return categs;
//}*/

//int printCategories(const std::vector <Category>& categories)
//{
//    setlocale(LC_ALL, "Rus");
//    for(auto& category : categories){
//        std::cout << "->"<< category.name << std::endl;
//        std::cout<< "--> size is:" << categories.size() << std::endl;
//        std::cout << "--> mode id:" << category.mode <<' '<< std::endl;
//        std::cout << "--> Totaly: " << category.participants.size() << " sportsmens in category" << std::endl;

//        for(const Participant& Sportsmen: category.participants){
//            std::cout << "---->sportsmen:" << Sportsmen.name << ' '
//                        << Sportsmen.birth << ' '
//                        << Sportsmen.club << ' '
//                        << std::endl;
//            }
//        std::cout << "---------------------------------------------------------"<<std::endl;
//    }

//    return 0;
//}

Category::MODE getMode(const Category& category){
  return category.mode;
}

std::vector<Participant> getParticipants(const Category& category){
      return category.participants;
}

