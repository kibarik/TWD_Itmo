#include "dbCompetition.h"
//#include <QSqlDatabase>
#include <QDebug>
#include <QObject>

dbCompetition::dbCompetition(const QString& host, const QString& originName,const QString& competitionName,
                             const QString& level, const QString& judge,
                             const QString& bookkeeper, const QString& city, QObject *parent) : QObject(parent)
{
	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName(host);
	db.setUserName("twd");
	db.setPassword("twd_DatabaseUserPassword0");
	query = QSqlQuery(db);


	if (false == db.open())
		throw "can't open/create DB";

	if (false == db.tables().contains(competitionName)){
		//QString createDb = "CREATE DATABASE '"+ (competitionName)+ "' CHARACTER SET utf8 COLLATE utf8_general_ci;";
		//exec(createDb);
		exec("CREATE DATABASE IF NOT EXISTS "+competitionName+" DEFAULT CHARACTER SET utf8;");
		//exec(createDb); //устанавливаем кодировку
		exec("USE "+competitionName+";"); //переключаемся на новую бд

		exec("CREATE TABLE IF NOT EXISTS `property` (" // создаем таблицу свойств
		     "`name` tinytext CHARACTER SET utf8 COMMENT 'имя соревнований',"
		     "`level` int(11) DEFAULT NULL COMMENT 'уровень соревнований',"
		     "`judge` tinytext CHARACTER SET utf8 COMMENT 'главный судья',"
		     "`bookkeeper` tinytext CHARACTER SET utf8 COMMENT 'главный бухгалтер',"
		     "`city` tinytext CHARACTER SET utf8 COMMENT 'город проведения');");

		//заполняем таблицу property
		exec("INSERT INTO `property`"
		     " (`name`, `level`, `judge`, `bookkeeper`, `city`) VALUES "
		     "('"+originName+"', '"+level+"', '"+judge+"', '"+bookkeeper+"', '"+city+"');");
	}

}

void dbCompetition::exec(QString str){
	query.clear();
	if (false == query.exec(str))
		throw "DB Error -> can't exec: " + str;
};

