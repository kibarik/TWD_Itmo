#ifndef COMPETITION_H
#define COMPETITION_H
#pragma once

#include <QObject>
#include <QString>

class Competition : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString name		READ name		WRITE setName	NOTIFY competitionChanged)
	Q_PROPERTY(QString level	READ level		WRITE setLevel	 NOTIFY competitionChanged)
	Q_PROPERTY(QString theJudge READ theJudge   WRITE setJudge NOTIFY competitionChanged)
	//Q_PROPERTY(QString bookkeeper READ _bookkeper WRITE setBookkeper NOTIFY competitionChanged)

public:
	explicit Competition(QObject *parent = nullptr);

	//getters for Q_PROPERTY

	QString name()		 {return _name;}
	QString level()		 {return _level;}
	QString theJudge()	 {return _theJudge;}
	QString bookkeeper() {return _bookkeeper;}
	QString city()		 {return _city;}


	//setters for Q_PROPERTY
	void setter (QString& out, QString& _inside, QString varName );
	void setName		(const QString& name);
	void setLevel		(const QString& level);
	void setJudge		(const QString& judge);
//	void setBookkeeper	(const QString& bookkeeper);

	//class functions
	void makeCompetition();
	void makeConfig();
	void makeCompetitionDir();
	QString checkEmpty(QString &var);

signals:
	void competitionChanged(const QString what);

public slots:


private:
	QString _empty = "M";
	QString _name = _empty;
	QString _level  = _empty;
	QString _theJudge = _empty;
	QString _bookkeeper = _empty;
	QString _city = _empty;

};

#endif // COMPETITION_H
