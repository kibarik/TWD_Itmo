#ifndef dbConnection_H
#define dbConnection_H

#include <QString>
#include <QSqlDatabase>
#include <QtSql/QtSql>
#include "data.h"

/*
 * Класс отвечает за функции обращения к БД
 * К этому объекту ссылаются классы Category.h и Competition.h
 * в функции save()
*/

class DbConnection : public QObject
{
	Q_OBJECT
public:
	//DbConnection(QObject *parent = nullptr);
	//virtual ~DbConnection();
	explicit DbConnection(QObject *parent = nullptr);

	void exec(QString str);
	void dbCategory(); //send category to Database
	void sendCompetition(const QString& competitionName,
	                     const QString& level, const QString& judge,
	                     const QString& bookkeeper, const QString& city);

private:
	Data data; //data like passwords, host and other
	QSqlDatabase db;
	QString cleanedName;
	QSqlQuery query;

	QString cleanName(QString text);
	void recordSql(const QString& str);
	void connect();
};

#endif //
