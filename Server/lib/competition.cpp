#include "competition.h"
//#include "xmlio.h"
#include "dbCompetition.h"

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


bool Competition::save(const QString& path){
	try {
		dbCompetition competition(_name, _level,
		                      _theJudge, _bookkeeper,
		                      _city);
		return true;
	} catch (QString& er) {
		qDebug()<< "An error when save competition in execute: "<< er;
	}

}


//	competition.exec("CREATE TABLE `"++ " "+2000+" "+2008 10 1 гуп гуп 1 0 0 0 0 0 0 0 0 0` "
//	                 "`name` tinytext NOT NULL COMMENT 'имя',"
//	                 "`sex` tinyint(1) NOT NULL DEFAULT '1' COMMENT 'пол',"
//	                 "`birth` date DEFAULT NULL COMMENT 'дата рождения',"
//	                 "`sportQualification` tinytext COMMENT 'спортивная квалификация',"
//	                 "`gup` tinyint(4) DEFAULT NULL COMMENT 'гуп',"
//	                 "`dan` tinyint(4) DEFAULT NULL COMMENT 'дан',"
//	                 "`weight` int(11) DEFAULT NULL COMMENT 'вес',"
//	                 "`personal tul` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'туль личный',"
//	                 "`team tul` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'туль командный',"
//	                 "`tradition tul` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'туль традиционный',"
//	                 "`personal sparring` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'спарринг личный',"
//	                 "`team sparring` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'спарринг командный',"
//	                 "`tradition sparring` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'традиционный спарринг',"
//	                 "`impact force` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'сила удара',"
//	                 "`specTech` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'спецтехника',"
//	                 "`club` tinytext COMMENT 'Имя клуба') ENGINE=InnoDB DEFAULT CHARSET=utf8;");

/*Вариант с сохранением через XML файл.
 * Отказался от XML в пользу .sql файла
 *
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

	xml.save(_name, doc, path+"/"+_name.toUpper());
	xml.viewXmlFiles("./");//просмотрим элементы в текущей папке

	emit competitionSaved();

	return true;
}
*/
