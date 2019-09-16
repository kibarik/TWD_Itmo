#include "dbConnection.h"
//#include <QSqlDatabase>
#include <QDebug>
#include <QObject>
#include <QFile>

DbConnection::DbConnection(QObject *parent) : QObject(parent)
{
	db = QSqlDatabase::addDatabase("QMYSQL");

	//all datas used from lib/data.cpp -> class Data.
	db.setHostName(data.host);
	db.setPort(data.port);
	db.setUserName(data.user);
	db.setPassword(data.password);
	query = QSqlQuery(db);

	qDebug()<<"DbConnection established";
}

//----------------------------------------------------------------------
void DbConnection::dbCategory(){
	connect();
}

void DbConnection::sendCompetition(	const QString& competitionName,	 const QString& level,
                                    const QString& judge,			 const QString& bookkeeper,
                                    const QString& city)
{
	cleanedName = cleanName(competitionName);
	connect();
	if (false == db.tables().contains(competitionName)){ //если таблица не содержи

		exec("CREATE DATABASE IF NOT EXISTS "+cleanedName+" DEFAULT CHARACTER SET utf8;");
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
	    db.close();
}


//-------------------------------------------------------------------
void DbConnection::exec(QString str){
	query.clear();
	if (false == query.exec(str))
		throw QString("DB Error -> can't exec: " + str);
	recordSql(str);
}

void DbConnection::recordSql(const QString& str){
	QFile file;
	QString fileName = cleanedName+".sql";

	file.setFileName(fileName);
	if (file.exists()){//уже существует с таким именем

		//TODO доработать метод сохранения.
		if(!file.open(QIODevice::Append | QIODevice::Text))
		//if(!file.open(QIODevice::Append))
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
		qDebug() << "To "<< fileName << " recorded: "<< str;
	}

	file.close();

}

QString DbConnection::cleanName(QString text){
	text.replace(" ", "_");
	text.replace("-", "_");
	text.remove("\"");
	text.remove("\'");
	text.remove('.');
	text.remove(',');
	text.remove(';');
	text = text.trimmed();
	text = text.toUpper();

	qDebug()<<"Name cleaned: "<<text;

	return text;
}

void DbConnection::connect(){
	if (false == db.open())
		throw QString("can't open/create DB");
}
