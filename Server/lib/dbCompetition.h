#ifndef DBCOMPETITION_H
#define DBCOMPETITION_H

#include <QString>
#include <QSqlDatabase>
#include <QtSql/QtSql>

class dbCompetition : public QObject
{
	Q_OBJECT
public:
	dbCompetition(const QString& host, const QString& originName, const QString& competitionName,
	              const QString& level, const QString& judge,
	              const QString& bookkeeper, const QString& city, QObject *parent = nullptr);
	//virtual ~dbCompetition();
	explicit dbCompetition(QObject *parent = nullptr);

	void exec(QString str);
	bool dbCategory();
	bool saveCompetitionSql();
	bool localSave();


private:
	bool isConnect = true;
	QString name;
	QSqlDatabase db;
	QSqlQuery query;
};

#endif // DBCOMPETITION_H
