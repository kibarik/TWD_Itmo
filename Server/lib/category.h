#ifndef CATEGORY_H
#define CATEGORY_H
#pragma once

#include <QString>
#include <QObject>
#include <QtXml>
#include "dbConnection.h"

/*
 * Описание категории и класса
 * Класс категории используется в QML в меню создания соревнований QML/MC_Step2Cateogory.qml
*/

class Category : public QObject{
	Q_OBJECT

	//соединяем QML характеристики с нашей структурой.
	Q_PROPERTY(QString gender		 READ	gender			WRITE setGender				NOTIFY categoryChanged)
	Q_PROPERTY(QString mode			 READ	mode			WRITE setMode				NOTIFY categoryChanged)
	Q_PROPERTY(QString yearFrom		 READ	yearFrom		WRITE setYearFrom			NOTIFY categoryChanged)
	Q_PROPERTY(QString yearTo		 READ	yearTo			WRITE setYearTo				NOTIFY categoryChanged)
	Q_PROPERTY(QString weightFrom	 READ	weightFrom		WRITE setWeightFrom			NOTIFY categoryChanged)
	Q_PROPERTY(QString weightTo		 READ	weightTo		WRITE setWeightTo			NOTIFY categoryChanged)
	Q_PROPERTY(QString roundStandart READ	roundStandart	WRITE setRoundStandart		NOTIFY categoryChanged)
	Q_PROPERTY(QString roundFinal	 READ	roundFinal		WRITE setRoundFinal			NOTIFY categoryChanged)
	Q_PROPERTY(QString name			 READ	name			WRITE setName				NOTIFY categoryChanged)
	Q_PROPERTY(QString beltFrom		 READ	beltFrom		WRITE setBeltFrom			NOTIFY categoryChanged)
	Q_PROPERTY(QString beltTo		 READ	beltTo			WRITE setBeltTo				NOTIFY categoryChanged)
	Q_PROPERTY(bool isDanFrom		 READ	isDanFrom		WRITE setIsDanFrom			NOTIFY categoryChanged)
	Q_PROPERTY(bool isDanTo			 READ	isDanTo			WRITE setIsDanTo			NOTIFY categoryChanged)
	Q_PROPERTY(QString timeMinStandart READ	timeMinStandart	WRITE setTimeMinStandart	NOTIFY categoryChanged)
	Q_PROPERTY(QString timeMinFinal	 READ	timeMinFinal	WRITE setTimeMinFinal		NOTIFY categoryChanged)
	Q_PROPERTY(QString timeSecStandart READ	timeSecStandart	WRITE setTimeSecStandart	NOTIFY categoryChanged)
	Q_PROPERTY(QString timeSecFinal	 READ	timeSecFinal	WRITE setTimeSecFinal		NOTIFY categoryChanged)
//	Q_PROPERTY(bool isSaved			 READ	isSaved			WRITE setSaved				NOTIFY categorySaved)

public:
	explicit Category(QObject *parent = nullptr); //явное наследование от родителя, обязательно для QML древа

	//геттеры для Q_PROPERTY
	QString name()				{return _name;}
	QString gender()			{return _gender;}
	QString mode()				{return _mode;}
	QString yearFrom()			{return _yearFrom;}
	QString yearTo()			{return _yearTo;}
	QString weightFrom()		{return _weightFrom;}
	QString weightTo()			{return _weightTo;}
	QString roundStandart()		{return _roundStandart;}
	QString roundFinal()		{return _roundFinal;}
	QString beltFrom()			{return _beltFrom;}
	QString beltTo()			{return _beltTo;}
	bool	isDanFrom()			{return _isDanFrom;}
	bool	isDanTo()			{return _isDanTo;}
	QString timeMinStandart()	{return _timeMinStandart;}
	QString timeMinFinal()		{return _timeMinFinal;}
	QString timeSecStandart()	{return	_timeSecStandart;}
	QString timeSecFinal()		{return _timeSecFinal;}

	/*сеттеры вся суть ->
	 * 1. испустить сигнал categoryChanged() с сообщением для логирования.
	 * 2. Передать параметр из QML в C++ структуру.
	*/
	void setName			(const QString& name);
	void setGender			(const QString& gender);
	void setMode			(const QString& mode);
	void setYearFrom		(const QString& yearFrom);
	void setYearTo			(const QString& yearTo);
	void setWeightFrom		(const QString& weightFrom);
	void setWeightTo		(const QString& weightTo);
	void setRoundStandart	(const QString& roundStandart);
	void setRoundFinal		(const QString& roundFinal);
	void setBeltFrom		(const QString& beltFrom);
	void setBeltTo			(const QString& beltTo);
	void setIsDanFrom		(const bool& isDanFrom);
	void setIsDanTo			(const bool& isDanTo);
	void setTimeMinStandart (const QString& timeMinStandart);
	void setTimeSecStandart (const QString& timeSecStandart);
	void setTimeMinFinal	(const QString& timeMinFinal);
	void setTimeSecFinal	(const QString& timeSecFinal);

	QString boolToString(const bool& temp);
	QString checkEmpty( QString& var);

	//database functions
	void exportToDB();
	void importFromDB();


public slots:
	void save(const QString& path = "./");

signals:
	void categoryChanged (const QString& what);
	void categorySaved();

protected:
	    QString _empty = "N";
		//первоначально проинициализирует словом EMPTY, чтобы видеть пустые ячейки при названии категории. Удобно для доработки

		QString _gender = _empty;
		QString _mode = _empty;
		QString _yearFrom = _empty, _yearTo = _empty;

		QString _beltFrom = _empty, _beltTo = _empty;
		bool _isDanFrom = false, _isDanTo=false;

		QString _weightFrom = _empty, _weightTo = _empty;
		QString _roundStandart = _empty, _roundFinal = _empty;
		QString _timeMinStandart = _empty, _timeSecStandart=_empty; //не использую QTime, чтобы избежать лишних преобразований. В БД только числа нужны
		QString _timeMinFinal=_empty, _timeSecFinal=_empty;

		QString _name;
};


#endif // CATEGORY_H
