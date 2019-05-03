#ifndef XMLIO_H
#define XMLIO_H

#include <QObject>

class XmlIO : public QObject
{
	Q_OBJECT

public:
	//добавление свойств к классу
//	Q_PROPERTY(QString source
//	           READ source
//	           WRITE setSource
//	           NOTIFY sourceChanged)
	explicit XmlIO(QObject *parent);

	//доступ к методам C++ из QML
	//Q_INVOKABLE QString get(const QString& strQuery);
	//Q_INVOKABLE bool write(const QString& data);

	QString source() { return mSource; }

public slots:
	void setSource(const QString& source) { mSource = source; }

signals:
	void sourceChanged(const QString& source);
	void error(const QString& msg);

private:
	QString mSource; //название файла
};

#endif // XMLIO_H
