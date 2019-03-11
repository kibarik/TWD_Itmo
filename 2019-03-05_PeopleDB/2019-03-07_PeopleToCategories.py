from os import listdir
from datetime import date
import mysql.connector as mysql

defaultTable = (
		"CREATE TABLE IF NOT EXISTS `{tabName}` ("
		  "`name` tinytext NOT NULL COMMENT 'имя',"
		  "`sex` tinyint(1) NOT NULL DEFAULT '1' COMMENT 'пол',"
		  "`birth` date DEFAULT NULL COMMENT 'дата рождения',"
		  "`sportQualification` tinytext COMMENT 'спортивная квалификация',"
		  "`gup` tinyint(4) DEFAULT NULL COMMENT 'гуп',"
		  "`dan` tinyint(4) DEFAULT NULL COMMENT 'дан',"
		  "`weight` int(11) DEFAULT NULL COMMENT 'вес',"
		  "`personal tul` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'туль личный',"
		  "`team tul` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'туль командный',"
		  "`tradition tul` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'туль традиционный',"
		  "`personal sparring` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'спарринг личный',"
		  "`team sparring` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'спарринг командный',"
		  "`tradition sparring` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'традиционный спарринг',"
		  "`impact force` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'сила удара',"
		  "`specTech` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'спецтехника'"
		") ENGINE=InnoDB DEFAULT CHARSET=utf8;"
	)

#Класс со всеми параметрами категорий
def parseCategory(categoryStr):
	contests = [
	             "personal tul", "team tul", "tradition tul",
	             "pesonal sparring", "team sparring", "tradition sparring",
	             "impact force", "specTech"
	           ]
	sex = {'м':1, 'ж':0}

	params = categoryStr.split()
	category = {}
	category["sex"] = sex[params[0]]
	category["birthFrom"] = params[1] + "-01-01"
	category["birthTo"] = params[2] + "-12-31"
	category["gupFrom"] = None
	category["danFrom"] = None

	#Определяем техническую квалификацию
	if params[4] == "гуп":
		if len(params[3].split("-")) == 2:
			category["gupFrom"] = params[3].split("-")[1]
			category["gupTo"] = params[3].split("-")[0]
		else:
			category["gupFrom"] = category["gupTo"] = params[3]
	else:
		if len(params[3].split("-")) == 2:
			category["danFrom"] = params[3].split("-")[0]
			category["danTo"] = params[3].split("-")[1]
		else:
			category["danFrom"] = category["danTo"] = params[3]

	#Определяем тип соревнований
	category["contest"] = None
	for i in range(5, 5 + len(contests)):
		if params[i] == '1':
			category["contest"] = contests[i - 5]
			break

	#Определяем весовую категорию
	category["weightFrom"] = None
	if params[5  + len(contests)] != '0':
		category["weightFrom"] = params[5 + len(contests)].split("-")[0]
		category["weightTo"] = params[5 + len(contests)].split("-")[1]

	return category

def GetTemplate(fileName):
	categories = {}
	file = open(fileName, 'r', encoding = "Windows-1251")
	for line in file:
		if line:
			params = parseCategory(line)
			query = ("SELECT * FROM `humans` WHERE ("
								"`sex`={sex} AND `birth`>='{birthFrom}' AND `birth`<='{birthTo}'"
			        ).format( sex = params["sex"],
			                  birthFrom = params["birthFrom"],
			                  birthTo = params["birthTo"]
			                )
			if params["gupFrom"] != None:
				query += " AND `gup`>={gupFrom} AND `gup`<={gupTo}".format(
				            gupFrom = params["gupFrom"],
				            gupTo = params["gupTo"]
				          )
			elif params["danFrom"] != None:
				query += " AND `dan`>={danFrom} AND `dan`<={danTo}".format(
				            danFrom = params["danFrom"],
				            danTo = params["danTo"]
				          )
			if params["contest"] != None:
				query += " AND `" + params["contest"] + "`=1"
			categories[line.replace("\n", "").replace("\r", "")] = query + ")"
	file.close()
	return categories

def main():
	templates = []
	try:
		mainDB = mysql.connect( user = "root",
  	                        password = "lasjbdkashbdabsg123t1762dlm12393y4hfbkwsd8ye283heHIBUSDUIAH&@rnq2987y238",
		                        host = "localhost",
                            database = "participants")
		categoriesDB = mysql.connect( user = "root",
		                         password = "lasjbdkashbdabsg123t1762dlm12393y4hfbkwsd8ye283heHIBUSDUIAH&@rnq2987y238",
		                         host = "localhost",
		                         database = "categories")
	except mysql.Error as err:
		print(err)
		raise err

	mainCursor = mainDB.cursor()
	categCursor = categoriesDB.cursor()
	
	#print(GetTemplate(0).items())
	for key, val in GetTemplate("categories.txt").items():
		query = val
		categCursor.execute(defaultTable.format(tabName = key))
		mainCursor.execute(query)

		for entry in mainCursor:
			query = "INSERT INTO `" + key + "` ("
			fieldsList = [
			               "name", "sex", "birth", "sportQualification", "gup", "dan", "weight", 
			               "personal tul", "team tul", "tradition tul", "personal sparring",
			               "team sparring", "tradition sparring", "impact force", "specTech"
				]
			values = []
			for i in range(0, len(fieldsList)):
				if entry[i]:
					query += "`" + fieldsList[i] + "`,"
					values.append(entry[i])
			values[2] = str(values[2])
			query = query[:-1] + ") VALUES ("
			query += str(values)[1:-1] + ")"
			categCursor.execute(query)
	categCursor.close()
	mainCursor.close()
	mainDB.close()
	categoriesDB.close()

if __name__ == "__main__":
	main()
