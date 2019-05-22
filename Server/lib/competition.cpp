#include "competition.h"
#include "xmlio.h"

Competition::Competition(QObject *parent) : QObject(parent)
{

}

QString Competition::checkEmpty(QString &var){
	var.isEmpty() ? var = _empty: var;
	return var;
}

//void Competition::setter(QString& out, QString& _inside, QString varName){
//	emit competitionChanged(varName + " = " + _inside);
//	_inside = out;
//	checkEmpty(_inside);
//}

void Competition::setName(const QString &name){
	emit competitionChanged("name = "+name);
	_name = name;
	checkEmpty(_name);
}

void Competition::setLevel(const QString &level){
	emit competitionChanged("level = "+level);
	_level = level;
	checkEmpty(_level);
}

void Competition::setJudge(const QString &judge){
	emit competitionChanged("main judge = " + judge);
	_theJudge = judge;
	checkEmpty(_theJudge );
}

void Competition::setBookkeeper(const QString &bookkeeper){
	emit competitionChanged("bookkeper = "+ bookkeeper);
	_bookkeeper = bookkeeper;
	checkEmpty(_bookkeeper);
}

void Competition::setCity(const QString &city){
	emit competitionChanged("city = "+ city);
	_city = city;
	checkEmpty(_city);
}

QDomElement Competition::competitionXML(QDomDocument& doc){
	XmlIO xml;

	QDomElement competition = doc.createElement("Competition"); //главный элемент <Competition></Competition>.

	doc.appendChild(competition);
	    competition.appendChild(xml.makeElement(doc, "name", _name));
		competition.appendChild(xml.makeElement(doc, "level", _level));
		competition.appendChild(xml.makeElement(doc, "judge", _theJudge));
		competition.appendChild(xml.makeElement(doc, "bookkeeper", _bookkeeper));
		competition.appendChild(xml.makeElement(doc, "city", _city));

	return competition;
};

bool Competition::save(const QString& path){
	XmlIO xml;
	QDomDocument doc("");
	QDomElement competition = competitionXML(doc); //создание структуры

	xml.save(_name, doc, path+"/"+_name);
	xml.viewXmlFiles("./");//просмотрим элементы в текущей папке

	emit competitionSaved();

	return true;
}
