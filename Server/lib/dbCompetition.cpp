#include "dbCompetition.h"
//#include <QSqlDatabase>
#include <QDebug>
#include <QObject>
#include <QFile>

dbCompetition::dbCompetition(const QString& competitionName,
                             const QString& level, const QString& judge,
                             const QString& bookkeeper, const QString& city, QObject *parent) : QObject(parent)
{
	db = QSqlDatabase::addDatabase("QMYSQL");

	//all datas used from lib/data.cpp -> class Data.
	db.setHostName(data.host);
	db.setPort(data.port);
	db.setUserName(data.user);
	db.setPassword(data.password);
	query = QSqlQuery(db);

	name = competitionName;
	cleanedName = cleanName(competitionName);


	if (false == db.open())
		throw QString("can't open/create DB");

	if (false == db.tables().contains(competitionName)){
		//QString createDb = "CREATE DATABASE '"+ (competitionName)+ "' CHARACTER SET utf8 COLLATE utf8_general_ci;";
		//exec(createDb);
		exec("CREATE DATABASE IF NOT EXISTS "+cleanedName+" DEFAULT CHARACTER SET utf8;");
		//exec(createDb); //устанавливаем кодировку
		exec("USE "+cleanedName+";"); //переключаемся на новую бд

		exec("CREATE TABLE IF NOT EXISTS `property` (" // создаем таблицу свойств
		     "`name` tinytext CHARACTER SET utf8 COMMENT 'имя соревнований',"
		     "`level` int(11) DEFAULT NULL COMMENT 'уровень соревнований',"
		     "`judge` tinytext CHARACTER SET utf8 COMMENT 'главный судья',"
		     "`bookkeeper` tinytext CHARACTER SET utf8 COMMENT 'главный бухгалтер',"
		     "`city` tinytext CHARACTER SET utf8 COMMENT 'город проведения');");

		//если есть прошлые записи - удаляем. Чтобы не возникало проблем.
		exec("TRUNCATE property");
		//заполняем таблицу property
		exec("INSERT INTO `property`"
		     " (`name`, `level`, `judge`, `bookkeeper`, `city`) VALUES "
		     "('"+competitionName+"', '"+level+"', '"+judge+"', '"+bookkeeper+"', '"+city+"');");
	}

}
//------------------------------------------------------------------
void dbCompetition::dbCategory(){

}

//-------------------------------------------------------------------
void dbCompetition::exec(QString str){
	query.clear();
	if (false == query.exec(str))
		throw QString("DB Error -> can't exec: " + str);

	recordSql(str);

};

void dbCompetition::recordSql(const QString& str){
	QFile file;
	QString fileName = cleanedName+".sql";

	file.setFileName(fileName);
	if (file.exists()){//уже существует с таким именем

		//TODO доработать метод сохранения.
		//if(!file.open(QIODevice::Append | QIODevice::Text))
		if(!file.open(QIODevice::WriteOnly))
			    qDebug()<<"Error openning file to append";
		QTextStream add(&file);
		add.setCodec("UTF-8");
		add << str << "\n\n"; //дополняем файл новым вводом
	}
	else {
		if(!file.open(QIODevice::WriteOnly))
			qDebug()<<"Error openning file to write";
		QTextStream write(&file);
		write.setCodec("UTF-8");
		write <<str;
	}

	file.close();

}

QString dbCompetition::cleanName(QString text){
	text.replace(" ", "_");
	text.replace("-", "_");
	text.remove('.');
	text = text.trimmed();
	text = text.toUpper();

	qDebug()<<"Execute Database with name:"<<text;

	return text;
}
