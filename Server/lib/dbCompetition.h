#ifndef DBCOMPETITION_H
#define DBCOMPETITION_H

#include <QString>
#include <QSqlDatabase>
#include <QtSql/QtSql>
#include "data.h"

class dbCompetition : public QObject
{
	Q_OBJECT
public:
	dbCompetition(const QString& competitionName,
	              const QString& level, const QString& judge,
	              const QString& bookkeeper, const QString& city, QObject *parent = nullptr);
	//virtual ~dbCompetition();
	explicit dbCompetition(QObject *parent = nullptr);

	void exec(QString str);
	void dbCategory();

private:
	QString name;
	QString cleanedName;
	QSqlDatabase db;
	QSqlQuery query;
	Data data;

	QString cleanName(QString text);
	void recordSql(const QString& str);
};

#endif // DBCOMPETITION_H
