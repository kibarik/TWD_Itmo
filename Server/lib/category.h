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


private slots:	//сеттеры вся суть -> 1. испустить сигнал categoryChanged() с сообщением для логирования. 2. изменить параметр категории
	void setName			(const QString& name)			{emit categoryChanged("name = " + name);			_name=name;}
	void setGender			(const QString& gender)			{emit categoryChanged("gender = " + gender);		_gender = gender;}
	void setMode			(const QString& mode)			{emit categoryChanged("mode = " + mode);			_mode=mode;}
	void setYearFrom		(const QString& yearFrom)		{emit categoryChanged("yearFrom = " + yearFrom);	_yearFrom = yearFrom;}
	void setYearTo			(const QString& yearTo)			{emit categoryChanged("yearTo = " + yearTo);		_yearTo = yearTo;}
	void setWeightFrom		(const QString& weightFrom)		{emit categoryChanged("weightFrom = " + weightFrom); _weightFrom = weightFrom;}
	void setWeightTo		(const QString& weightTo)		{emit categoryChanged("weightTo = " + weightTo);	_weightTo = weightTo;}
	void setRoundStandart	(const QString& roundStandart)	{emit categoryChanged("roundStandart = " + roundStandart);	_roundStandart = roundStandart;}
	void setRoundFinal		(const QString& roundFinal)		{emit categoryChanged("roundFinal = " + roundFinal); _roundFinal = roundFinal;}

signals:
	void categoryChanged (const QString& what);

protected:
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
