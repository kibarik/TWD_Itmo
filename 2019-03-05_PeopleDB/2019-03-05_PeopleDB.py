from os import listdir
import mysql.connector

class Participant(dict):
	def __init__(self, positions, params):
		for name, val in positions.items():
			if val != None:
				self[name] = params[val]
		if positions["name"] != None:
			self["name"] = "'" + self["name"] + "'"
		if positions["birth"] != None:
			self["birth"] = "'" + str("-").join(list(reversed(self["birth"].split(".")))) + "'"
		if positions["sex"] != None:
			if self["sex"].lower() == "ж":
				self["sex"] = "0"
			elif self["sex"].lower() == "м":
				self["sex"] = "1"
			else:
				input("Error with file format!!!")
				exit(1)
		if positions["techQualification"] != None:
			if self["techQualification"].split(" ")[1] == "гуп":
				self["gup"] = self["techQualification"].split(" ")[0]
			else:
				self["dan"] = self["techQualification"].split(" ")[0]
			self.pop("techQualification", None)

		for boolVal in [
				            "personal tul", "team tul", "tradition tul",
			              "personal sparring", "team sparring", "tradition sparring",
			              "impact force", "specTech"
			             ]:
			if positions[boolVal] != None:
				if self[boolVal] == "+":
					self[boolVal] = "1"
				elif self[boolVal] == "-":
					self[boolVal] = "0"
				else:
					input("Error with file format!!!")
					exit(1)
		if self["weight"] == "0":
			self["weight"] = "NULL"

	def getAllValues(self, start = 0, to = None):
		if to == None:
			to = len(self.keys())
		if to < 0:
			to = len(self.keys()) + to

		query = ""
		i = 0
		for val in self.values():
			i += 1
			if i <= start:
				continue
			if i > to:
				break
			query += val + ","
		return query[:-1]

	def getAllNames(self, start = 0, to = None):
		if to == None:
			to = len(self.keys())
		if to < 0:
			to = len(self.keys()) + to

		query = ""
		i = 0
		for name in self.keys():
			i += 1
			if i <= start:
				continue
			if i > to:
				break
			query += "`" + name + "`,"
		return query[:-1]

def main():
	try:
		db = mysql.connector.connect( user = "root",
		                              password = "lasjbdkashbdabsg123t1762dlm12393y4hfbkwsd8ye283heHIBUSDUIAH&@rnq2987y238",
		                              host = "localhost",
		                              database = "participants")
	except mysql.connector.Error as err:
		print(err)
		raise err

	positions = { # Задаёт очерёдность столбцов в файлах с таблицами
		"name": 0,
		"sex": 1,
		"birth": 2,
		"techQualification": 5,
		"weight": 7,
		"personal tul": 9,
		"team tul": None,
		"tradition tul": None,
		"personal sparring": None,
		"team sparring": None,
		"tradition sparring": None,
		"impact force": None,
		"specTech": None
	}

	fileNames = []
	participant = None
	for fileName in listdir(path = "./tables/"):
		if fileName.endswith(".csv"):
			fileNames.append("tables/" + fileName)
	for fileName in fileNames:
		FIRST_LINE = True
		file = open(fileName, "r", encoding="Windows-1251")
		for line in file:
			if (not line) or line[0] == '0':
				file.close()
				break
			if FIRST_LINE == False:
				participant = Participant(positions, line[:-1].split(";"))
				query = "INSERT INTO `humans`(" + participant.getAllNames() + ") VALUES (" + participant.getAllValues() +");"
				#print(participant.getAllNames())
				cursor = db.cursor()
				cursor.execute(query)
				cursor.fetchone()
				cursor.close()
			else:
				FIRST_LINE = False
	db.commit()
	db.close()

if __name__ == "__main__":
	main()
