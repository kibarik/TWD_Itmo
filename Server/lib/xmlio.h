#ifndef XMLIO_H
#define XMLIO_H
#pragma once

#include <QtXml>

class XmlIO{
public:
	enum ErrorCode {
		EMPTY_VALUE,
		COULD_NOT_SAVE,
		COULD_NOT_CREATE_DIR,
		COULD_NOT_VIEW_XML
	};

	class XmlException : public std::exception { //класс ошибок
	public:
		explicit XmlException( ErrorCode code) : e_code(code) {}
		~XmlException() noexcept {}

		const char* what() const noexcept {
		   switch( e_code ) {
		       case EMPTY_VALUE: return "Empty value name when try to make XML structure!";
		       case COULD_NOT_SAVE: return "Program couldn't save XML!";
		       case COULD_NOT_CREATE_DIR: return "Program couldn't create dir for XML!";
		       case COULD_NOT_VIEW_XML: return "Program couldn't view XML files in dir!";
		default: return "Some Error in XML files";
		   }
		}
	private:
		    ErrorCode e_code;
	};

	QDomElement makeElement(QDomDocument& domDoc, const QString& strName, const QString& node);
	bool save(const QString& CategoryFullName, const QDomDocument& doc,  const QString& addDirName);
	bool makeDir(const QString& dirName);
	void viewXmlFiles(const QString& path);

private:

};

#endif
