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
			self["techQualification"] = "'" + self["techQualification"] + "'"

		for boolVal in ["personal tul", "group tul", "tradition tul", "power", "special technique"]:
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
		                              password = "",
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
		"group tul": None,
		"tradition tul": None,
		"personal sprint": None,
		"group sprint": None,
		"tradition sprint": None,
		"power": 10,
		"special technique": 11
	}

	fileNames = []
	participant = None
	for fileName in listdir(path = "./tables/"):
		if fileName.endswith(".csv"):
			fileNames.append("tables/" + fileName)
	for fileName in fileNames:
		FIRST_LINE = True
		file = open(fileName, "r")
		for line in file:
			if (not line) or line[0] == '0':
				file.close()
				break
			if FIRST_LINE == False:
				participant = Participant(positions, line[:-1].split(";"))
				query = "INSERT INTO `humans`(" + participant.getAllNames(0, -2) + ") VALUES (" + participant.getAllValues(0, -2) +");"
				#print(query)
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