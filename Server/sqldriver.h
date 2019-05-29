#ifndef SQLDRIVER_H
#define SQLDRIVER_H


class sqldriver
{
public:
	sqldriver();
	bool createDB();
	bool saveCategorySql();
	bool saveCompetitionSql();
	bool localSave();
};

#endif // SQLDRIVER_H
