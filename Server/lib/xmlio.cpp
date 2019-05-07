#include "xmlio.h"

QDomElement XmlIO::makeElement(QDomDocument& domDoc, const QString& strName, const QString& node){
	QDomElement domElement = domDoc.createElement(strName);

	if(!node.isEmpty()){
		QDomText domText = domDoc.createTextNode(node);
		domElement.appendChild(domText);
		qDebug() << "Set node to XML element" << strName;
	}
	else {
		qDebug() <<"Empty node in XML element" << strName;
	}

	return domElement;
};

bool XmlIO::save (const QString& categoryFullName, const QDomDocument& doc, const QString& addDirName){
	QFile xmlFile;
	xmlFile.setFileName(categoryFullName + ".xml"); //сохранение в файл

	if ( !addDirName.isEmpty() ){ //создаем папку и переходим в нее
		QDir dir;
		makeDir(addDirName);
		xmlFile.setFileName(addDirName + "/" +categoryFullName + ".xml");
	}

	if(xmlFile.open(QIODevice::WriteOnly)){
		QTextStream out(&xmlFile);
		out.setCodec("UTF-8");

		out << QString(QStringLiteral( "<?xml version='1.0' encoding='utf-8'?>\n" )) << doc.toString();
		xmlFile.close();
	}
	else {
		throw XmlException( COULD_NOT_SAVE );
	}

	return true;
};

bool XmlIO::makeDir(const QString &dirName){
	QDir dir;

	if( !dir.mkdir(dirName) ){
		if(QDir(dirName).exists()) return true; //если папка уже существует, то все норм
		qDebug() << "Can't create directory in: " << dir.currentPath();
		return false;
	};

	return true;
}


