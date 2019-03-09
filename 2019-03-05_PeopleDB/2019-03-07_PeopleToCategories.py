from os import listdir
from datetime import date
import mysql.connector as mysql

defaultTable = (
	"CREATE TABLE `%s` ("
		" `name` tinytext NOT NULL,"
		" `sex` bit(1) DEFAULT NULL,"
		" `birth` date DEFAULT NULL,"
		" `techQualification` tinytext,"
		" `weight` int(11) DEFAULT NULL,"
		" `personal tul` bit(1) NOT NULL DEFAULT b'0',"
		" `group tul` tinyint(1) NOT NULL DEFAULT '0',"
		" `tradition tul` tinyint(1) NOT NULL DEFAULT '0',"
		" `personal sprint` tinyint(1) NOT NULL DEFAULT '0',"
		" `group sprint` tinyint(1) NOT NULL DEFAULT '0'"
		") ENGINE=InnoDB DEFAULT CHARSET=utf8;"
	)

def GetTemplate(file):
	categories = {}
	categories["мужчины (от 18) туль 10-7 гуп"] = ("SELECT * FROM `humans` WHERE ("
	                                               "`birth` > " +
	                                               str(date.today()) + ");")

	return categories

def main():
	templates = []
	try:
		mainDB = mysql.connect( user = "root",
  	                        password = "",
		                        host = "localhost",
                            database = "participants")
		templates.append(
			                mysql.connect( user = "root",
  	                                 password = "",
		                                 host = "localhost",
                                     database = "template_0")
		                )
	except mysql.Error as err:
		print(err)
		raise err

	mainCursor = mainDB.cursor()
	categCursor = templates[0].cursor()
	
	#print(GetTemplate(0).items())
	for key, val in GetTemplate(0).items():
		query = val
		categCursor.execute(defaultTable, key)
		mainCursor.execute(query)

		for entry in mainCursor:
			print(str("|").join([entry[0], str(entry[1]), str(entry[2])]))
	mainCursor.close()

if __name__ == "__main__":
	main()
