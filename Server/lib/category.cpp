 #include "category.h"
#include <QtXml>
#include "xmlio.h"
#include <QDebug>

Category::Category(QObject *parent) : QObject(parent){

}

QString Category::boolToString(const bool& boolean){
	QString temp;
	boolean ? temp= "True" : temp = "False";
	return temp;
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
}
//---верхний пример можно свернуть до строчки для удобства понимания
void Category::setGender			(const QString& gender)			{emit categoryChanged("gender = " + gender);						_gender = gender;}
void Category::setMode				(const QString& mode)			{emit categoryChanged("mode = " + mode);							_mode=mode;}
void Category::setYearFrom			(const QString& yearFrom)		{emit categoryChanged("yearFrom = " + yearFrom);					_yearFrom = yearFrom;}
void Category::setYearTo			(const QString& yearTo)			{emit categoryChanged("yearTo = " + yearTo);						_yearTo = yearTo;}
void Category::setWeightFrom		(const QString& weightFrom)		{emit categoryChanged("weightFrom = " + weightFrom);				_weightFrom = weightFrom;}
void Category::setWeightTo			(const QString& weightTo)		{emit categoryChanged("weightTo = " + weightTo);					_weightTo = weightTo;}
void Category::setRoundStandart		(const QString& roundStandart)	{emit categoryChanged("roundStandart = " + roundStandart);			_roundStandart = roundStandart;}
void Category::setRoundFinal		(const QString& roundFinal)		{emit categoryChanged("roundFinal = " + roundFinal);				_roundFinal = roundFinal;}
void Category::setBeltFrom			(const QString& beltFrom)		{emit categoryChanged("beltFrom = " + beltFrom);					_beltFrom= beltFrom;}
void Category::setBeltTo			(const QString& beltTo)			{emit categoryChanged("beltTo = " + beltTo);						_beltTo = beltTo;}
void Category::setIsDanFrom			(const bool& isDanFrom)			{emit categoryChanged("isDanFrom = " + boolToString(isDanFrom));	_isDanFrom = isDanFrom;}
void Category::setIsDanTo			(const bool& isDanTo)			{emit categoryChanged("isDanTo = " + boolToString(isDanTo));		_isDanTo = isDanTo;}
void Category::setTimeMinStandart	(const QString& timeMinStandart) {emit categoryChanged("timeMinStandart = " + timeMinStandart);		_timeMinStandart = timeMinStandart;}
void Category::setTimeSecStandart	(const QString& timeSecStandart) {emit categoryChanged("timeSecStandart = "+ timeSecStandart);		_timeSecStandart = timeSecStandart;}
void Category::setTimeMinFinal		(const QString& timeMinFinal)	{emit categoryChanged("timeMinFinal= "+ timeMinFinal);				_timeMinFinal= timeMinFinal;}
void Category::setTimeSecFinal		(const QString& timeSecFinal)	{emit categoryChanged("timeSecFinal = "+ timeSecFinal);				_timeSecFinal= timeSecFinal;}
//void Category::setSaved				(const bool& categoryName)		{emit categorySaved("Category saved");								save()};	}

bool Category::save(){
	XmlIO xml;
	QDomDocument doc("Category");

	QDomElement category = categoryXML(doc); //создание структуры категории в XML
	xml.save(_name, doc, "XML");
	emit categorySaved();

	return true;
};

QDomElement Category::categoryXML(QDomDocument& doc){ //функция для создания и заполнения XML документа

	_name = _mode + " "+_gender + " " +
	        _yearFrom + "-" + _yearTo + " " +
	        _beltFrom +" "+ boolToString(_isDanFrom) + " " + _beltTo + " " + boolToString(_isDanTo) + " " +
	        _weightFrom + "-" +_weightTo + " " +
	        _roundStandart +"-"+ _roundFinal + " " +
	        _timeMinStandart +"-"+ _timeSecStandart +" "+ _timeMinFinal +"-"+ _timeSecFinal;
	XmlIO xml;

	//регистрируем структуру. Приведен пример выложен в PROJECT/DOC/Documents/category.xml
	//Эти элементы состоят из вложенных, поэтому они предварительно создаются для последующего создания вложений
	QDomElement category = doc.createElement("Category");
	QDomElement year = doc.createElement("year"); //содержит вложенные элементы
	QDomElement weight = doc.createElement("weight");
	QDomElement round = doc.createElement("round");
	QDomElement timeStandart = doc.createElement("timeStandart");
	QDomElement timeFinal = doc.createElement("timeFinal");

//	 qDebug() << _mode << " " << _gender << " " << _yearFrom << "-" << _yearTo << " "<< _beltFrom << " " <<_isDanFrom << " Дан " << _beltTo << " " <<_isDanTo << " Дан " << _weightFrom << "-" << _weightTo << " " <<
//	           _roundStandart + _roundFinal + " " +
//	           _timeMinStandart << " "<< _timeSecStandart <<" "<< _timeMinFinal << " "<<_timeSecFinal;

	doc.appendChild(category);
	    category.appendChild(xml.makeElement(doc, "name", _name));
		category.appendChild(xml.makeElement(doc, "mode", _mode));
		category.appendChild(xml.makeElement(doc, "gender", _gender));

		category.appendChild(year);
		    year.appendChild(xml.makeElement(doc, "yearFrom", _yearFrom));
			year.appendChild(xml.makeElement(doc, "yearTo", _yearTo));

		category.appendChild(weight);
		    weight.appendChild(xml.makeElement(doc, "weightFrom", _weightFrom));
			weight.appendChild(xml.makeElement(doc, "weightTo", _weightTo));

		category.appendChild(round);
		    round.appendChild(xml.makeElement(doc, "roundStandart", _roundStandart));
			round.appendChild(xml.makeElement(doc, "roundFinal", _roundFinal));

		category.appendChild(timeStandart);
		    timeStandart.appendChild(xml.makeElement(doc, "standartMin", _timeMinStandart));
			timeStandart.appendChild(xml.makeElement(doc, "standadrtSec", _timeSecStandart));

		category.appendChild(timeFinal);
		    timeFinal.appendChild(xml.makeElement(doc, "finalMin", _timeMinFinal));
			timeFinal.appendChild(xml.makeElement(doc, "finalSec", _timeSecFinal));

		qDebug() << _name;
	return category; //первое в XML структуре
};


