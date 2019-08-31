#include "category.h"
#include <QtXml>
#include "xmlio.h"
#include <QDebug>
#include "dbConnection.h"

Category::Category(QObject *parent) : QObject(parent){

}

QString Category::boolToString(const bool& boolean){
	QString temp;
	boolean ? temp= "True" : temp = "False";
	return temp;
}

QString Category::checkEmpty(QString &var){
	var.isEmpty() ? var = _empty: var;
	return var;
}
//----------------сетеры для Q_PROPERTY------------
/*
	*Функция сеттеров:
	*	1. Вызвать сигнал categoryChanged и передать информационную строку
	*	2. Установить значение переменной структуры от QML _VAL = VAL
*/
void Category::setName(const QString& name)	{
	emit categoryChanged("name = " + name);
	_name=name;
	checkEmpty(_name);

}
//---верхний пример можно свернуть до строчки для удобства понимания
void Category::setGender(const QString& gender)	{
	emit categoryChanged("gender = " + gender);
	_gender = gender;
	checkEmpty(_name);

}

void Category::setMode	(const QString& mode){
	emit categoryChanged("mode = " + mode);
	_mode=mode;
	checkEmpty(_mode);
}

void Category::setYearFrom	(const QString& yearFrom){
	emit categoryChanged("yearFrom = " + yearFrom);
	_yearFrom = yearFrom;
	checkEmpty(_yearFrom);
}
void Category::setYearTo (const QString& yearTo){
	emit categoryChanged("yearTo = " + yearTo);
	_yearTo = yearTo;
	checkEmpty(_yearTo);
}
void Category::setWeightFrom (const QString& weightFrom) {
	emit categoryChanged("weightFrom = " + weightFrom);
	_weightFrom = weightFrom;
	checkEmpty(_weightFrom);
}
void Category::setWeightTo			(const QString& weightTo)		{
	emit categoryChanged("weightTo = " + weightTo);
	_weightTo = weightTo;
	checkEmpty(_weightTo);
}
void Category::setRoundStandart		(const QString& roundStandart)	{
	emit categoryChanged("roundStandart = " + roundStandart);
	_roundStandart = roundStandart;
	checkEmpty(_roundStandart);
}
void Category::setRoundFinal		(const QString& roundFinal)		{
	emit categoryChanged("roundFinal = " + roundFinal);
	_roundFinal = roundFinal;
	checkEmpty(_roundFinal);
}
void Category::setBeltFrom			(const QString& beltFrom)		{
	emit categoryChanged("beltFrom = " + beltFrom);
	_beltFrom= beltFrom;
	checkEmpty(_beltFrom);
}
void Category::setBeltTo			(const QString& beltTo)			{
	emit categoryChanged("beltTo = " + beltTo);
	_beltTo = beltTo;
	checkEmpty(_beltTo);
}
void Category::setIsDanFrom			(const bool& isDanFrom)			{
	emit categoryChanged("isDanFrom = " + boolToString(isDanFrom));
	_isDanFrom = isDanFrom;
}
void Category::setIsDanTo			(const bool& isDanTo)			{
	emit categoryChanged("isDanTo = " + boolToString(isDanTo));
	_isDanTo = isDanTo;

}
void Category::setTimeMinStandart	(const QString& timeMinStandart) {
	emit categoryChanged("timeMinStandart = " + timeMinStandart);
	_timeMinStandart = timeMinStandart;
	checkEmpty(_timeMinStandart);

}
void Category::setTimeSecStandart	(const QString& timeSecStandart) {
	emit categoryChanged("timeSecStandart = "+ timeSecStandart);
	_timeSecStandart = timeSecStandart;
	checkEmpty(_timeSecStandart);
}
void Category::setTimeMinFinal		(const QString& timeMinFinal)	{
	emit categoryChanged("timeMinFinal= "+ timeMinFinal);
	_timeMinFinal= timeMinFinal;
	checkEmpty(_timeMinFinal);
}

void Category::setTimeSecFinal		(const QString& timeSecFinal)	{
	emit categoryChanged("timeSecFinal = "+ timeSecFinal);
	_timeSecFinal= timeSecFinal;
	checkEmpty(_timeSecFinal);

}

void Category::save(const QString& path){
	qDebug() << "The save have started";
	/*
	* 1. Из категории передаются только новые параметры
	* 2. Обращение к БД происходит через dbCompetition.h
	* 3. Нужно использовать уже ранее инициализированное подключение объекта Competition
	*/

}


