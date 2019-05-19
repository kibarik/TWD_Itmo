#include "competition.h"

Competition::Competition(QObject *parent) : QObject(parent)
{

}

QString Competition::checkEmpty(QString &var){
	var.isEmpty() ? var = _empty: var;
	return var;
}

void Competition::setter(QString& out, QString& _inside, QString varName){
	emit competitionChanged(varName + " = " + _inside);
	_inside = out;
	checkEmpty(_inside);
}

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
	emit competitionChanged("name = " + judge);
	_theJudge = judge;
	checkEmpty(_theJudge );
}

//void Competition::setBookkeeper(const QString &bookkeeper){
//	emit competitionChanged("name = "+name);
//	_name = name;
//	checkEmpty(_name);
//}

