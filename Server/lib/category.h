#ifndef CATEGORY_H
#define CATEGORY_H
#pragma once

#include <QString>
#include <utility>
#include <QObject>

/*
 * Описание категории и класса
 * Класс категории используется в QML в меню создания соревнований QML/MC_Step2Cateogory.qml
 * Его задача сохранять параметры ввода до нажатия на кнопку "Сохранить".
 * После нажатия на "Сохранить" все значения структуры _VALUE передаются в поток и записываются в XML
 * В последующем XML файл используется для отображения категорий в окне MC_Step2Cateogory.qml -> 3.Просмотр категорий
 * Кроме того данные из XML сохраняются в специальный формат .txt и передаются в функцию заполнения MySQL БД
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

	//функции класса category.cpp
	QString boolToString(const bool& temp);

private slots:	//сеттеры вся суть -> 1. испустить сигнал categoryChanged() с сообщением для логирования. 2. Передать параметр из QML в C++
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

signals:
	void categoryChanged (const QString& what);

protected:
	    QString _name;
		QString _gender;
		QString _mode;
		QString _yearFrom, _yearTo;

		QString _beltFrom, _beltTo;
		bool _isDanFrom, _isDanTo;

		QString _weightFrom, _weightTo;
		QString _roundStandart, _roundFinal;
		QString _timeMinStandart, _timeSecStandart; //не использую QTime, чтобы избежать лишних преобразований. В БД только числа нужны
		QString _timeMinFinal, _timeSecFinal;
};


#endif // CATEGORY_H
