from os import listdir
from datetime import date
import mysql.connector as mysql

HOST = "localhost"
USER = "root"
PASSWORD = "45214521"
MAINDB = "participants"
CATEGDB = "categories"

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
		  "`specTech` tinyint(1) NOT NULL DEFAULT '0' COMMENT 'спецтехника',"
		  "`club` tinytext DEFAULT NULL COMMENT 'Имя клуба'"
		") ENGINE=InnoDB DEFAULT CHARSET=utf8;"
	)

paramsPos = {
	"sex": 0,
	"birthFrom": 1,
	"birthTo": 2,
	"lvlFrom": 3,
	"lvlTo": 4,
	"lvlFromType": 5,
	"lvlToType": 6,
	"contestsStart": 7
}
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
	category["sex"] = sex[params[paramsPos["sex"]]]
	category["birthFrom"] = params[paramsPos["birthFrom"]] + "-01-01"
	category["birthTo"] = params[paramsPos["birthTo"]] + "-12-31"

	#Определяем техническую квалификацию
	category["lvlFromType"] = params[paramsPos["lvlFromType"]]
	category["lvlToType"] = params[paramsPos["lvlToType"]]
	category["lvlFrom"] = params[paramsPos["lvlFrom"]]
	category["lvlTo"] = params[paramsPos["lvlTo"]]


	#Определяем тип соревнований
	category["contest"] = None
	for i in range(0, len(contests)):
		if params[i + paramsPos["contestsStart"]] == '1':
			category["contest"] = contests[i]
			break

	#Определяем весовую категорию
	category["weightFrom"] = None
	if params[paramsPos["contestsStart"]  + len(contests)] != '0':
		category["weightFrom"] = params[paramsPos["contestsStart"] + len(contests) + 1].split("-")[0]
		category["weightTo"] = params[paramsPos["contestsStart"] + len(contests) + 1].split("-")[1]

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
			# Формирование условия по технической квалификации

			if params["lvlFromType"] == "гуп":
				query += " AND (`gup`<="
			elif params["lvlFromType"] == "дан":
				query += " AND (`dan`>="
			else:
				print("Error with lvlFromType: " + params["lvlFromType"])
				raise
			query += params["lvlFrom"]

			if params["lvlFromType"] == params["lvlToType"]:
				query += " AND "
			else:
				query += " OR "

			if params["lvlToType"] == "гуп":
				query += "`gup`>="
			elif params["lvlToType"] == "дан":
				query += "`dan`<="
			else:
				print("Error with lvlToType: " + params["lvlToType"])
				raise
			query += params["lvlTo"] + ")"

			if params["contest"] != None:
				query += " AND `" + params["contest"] + "`=1"
			categories[line.replace("\n", "").replace("\r", "")] = query + ")"
	file.close()
	return categories

def main():
	templates = []
	try:
		mainDB = mysql.connect( user = USER,
  	                        password = PASSWORD,
		                        host = HOST,
                            database = MAINDB)
		categoriesDB = mysql.connect( user = USER,
		                         password = PASSWORD,
		                         host = HOST,
		                         database = CATEGDB)
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
			               "team sparring", "tradition sparring", "impact force", "specTech", "club"
				]
			values = []
			for i in range(0, len(fieldsList)):
				if entry[i]:
					query += "`" + fieldsList[i] + "`,"
					values.append(entry[i])
			values[2] = str(values[2])
			query = query[:-1] + ") VALUES ("
			query += str(values)[1:-1] + ");"
			categCursor.execute(query)
	categCursor.close()
	mainCursor.close()
	mainDB.close()
	categoriesDB.commit()
	categoriesDB.close()

if __name__ == "__main__":
	main()
