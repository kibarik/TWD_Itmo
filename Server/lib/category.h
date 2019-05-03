#ifndef CATEGORY_H
#define CATEGORY_H
#pragma once

#include <QString>
#include <utility>
#include <QObject>


class Category : public QObject{
	Q_OBJECT

	//соединяем QML характеристики с нашей структурой
	Q_PROPERTY(QString gender		 READ	gender			WRITE setGender				NOTIFY categoryChanged)
	Q_PROPERTY(QString mode			 READ	mode			WRITE setMode				NOTIFY categoryChanged)
	Q_PROPERTY(QString yearFrom		 READ	yearFrom		WRITE setYearFrom			NOTIFY categoryChanged)
	Q_PROPERTY(QString yearTo		 READ	yearTo			WRITE setYearTo				NOTIFY categoryChanged)
	Q_PROPERTY(QString weightFrom	 READ	weightFrom		WRITE setWeightFrom			NOTIFY categoryChanged)
	Q_PROPERTY(QString weightTo		 READ	weightTo		WRITE setWeightTo			NOTIFY categoryChanged)
	Q_PROPERTY(QString roundStandart READ	roundStandart	WRITE setRoundStandart		NOTIFY categoryChanged)
	Q_PROPERTY(QString roundFinal	 READ	roundFinal		WRITE setRoundFinal			NOTIFY categoryChanged)
	Q_PROPERTY(QString name			 READ	name			WRITE setName				NOTIFY categoryChanged)

	//еще дописать пару для установки времени

public:
	explicit Category(QObject *parent = 0); //явное наследование от родителя, обязательно для QML древа

	QString name()			{return _name;}
	QString gender()		{return _gender;}
	QString mode()			{return _mode;}
	QString yearFrom()		{return _yearFrom;}
	QString yearTo()		{return _yearTo;}
	QString weightFrom()	{return _weightFrom;}
	QString weightTo()		{return _weightTo;}
	QString roundStandart() {return _roundStandart;}
	QString roundFinal()	{return _roundFinal;}


public slots:	//сеттеры описаны в category.cpp
	void setName			(const QString& name)			{_name=name;}
	void setGender			(const QString& gender)			{_gender = gender;}
	void setMode			(const QString& mode)			{_mode=mode;}
	void setYearFrom		(const QString& yearFrom)		{_yearFrom = yearFrom;}
	void setYearTo			(const QString& yearTo)			{_yearTo = yearTo;}
	void setWeightFrom		(const QString& weightFrom)		{_weightFrom = weightFrom;}
	void setWeightTo		(const QString& weightTo)		{_weightTo = weightTo;}
	void setRoundStandart	(const QString& roundStandart)	{_roundStandart = roundStandart;}
	void setRoundFinal		(const QString& roundFinal)		{_roundFinal = roundFinal;}



signals:
	void categoryChanged (const QString& what);

private:
	    QString _name = "";
		QString _gender = "";
		QString _mode = "";
		QString _yearFrom = "", _yearTo = "";
		QString _weightFrom = "", _weightTo = "";
		QString _roundStandart = "", _roundFinal = "";
//		QPair<qint8, qint8> _timeStandart; // <min, sec>
//		QPair<qint8, qint8> _timeFinal; // <min, sec>
};

//--------------------общие функции работы с категориями--------------------


#endif // CATEGORY_H
