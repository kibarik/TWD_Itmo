from os import listdir
from xlrd import open_workbook, xldate_as_datetime
import mysql.connector

PASSWORD = "45214521"

class Participant(dict):
	def __init__(self, positions, params):
		for name, val in positions.items():
			if val != None:
				self[name] = params[val]
		if positions["name"] != None:
			self["name"] = "'" + self["name"] + "'"
		if positions["club"] != None:
			self["club"] = "'" + self["club"] + "'"
		if positions["birth"] != None:
			self["birth"] = "'" + str("-").join(list(reversed(self["birth"].split(".")))) + "'"
		if positions["sex"] != None:
			if self["sex"].lower() == "ж":
				self["sex"] = "0"
			elif self["sex"].lower() == "м":
				self["sex"] = "1"
			else:
				input("Sex. Error with file format!!!")
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
					input(boolVal + ". Error with file format!!!")
					exit(1)
		if positions["weight"] != None:
			if self["weight"] == "0" or self["weight"] == "":
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
		                              password = PASSWORD,
		                              host = "localhost",
		                              database = "participants")
	except mysql.connector.Error as err:
		print(err)
		raise err

	positions = { # Задаёт очерёдность столбцов в файлах с таблицами
		"name": 0,
		"sex": 1,
		"birth": 2,
		"techQualification": 4,
		"weight": 5,
		"personal tul": 7,
		"team tul": None,
		"tradition tul": None,
		"personal sparring": None,
		"team sparring": None,
		"tradition sparring": None,
		"impact force": None,
		"specTech": None,
		"club": 11
	}

	fileNames = []
	participant = None
	for fileName in listdir(path = "./tables/"):
		fileNames.append("tables/" + fileName)
	for fileName in fileNames:
		if fileName.endswith(".csv"):
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
		elif fileName.endswith(".xlsx") or fileName.endswith(".xls"):
			workbook = open_workbook(fileName)
			sheet = workbook.sheet_by_index(0)
			for rownum in range(6, sheet.nrows):
				cells = sheet.row_values(rownum)
				if cells[2] == "":
					break
				cells[4] = str(xldate_as_datetime(cells[4], workbook.datemode)).split(" ")[0]
				cells = [str(val) for val in cells]
				participant = Participant(positions, cells[2:])
				#print(participant.getAllNames())
				#print(participant.getAllValues())
				query = "INSERT INTO `humans`(" + participant.getAllNames() + ") VALUES (" + participant.getAllValues() +");"
				cursor = db.cursor()
				cursor.execute(query)
				cursor.fetchone()
				cursor.close()

	db.commit()
	db.close()

if __name__ == "__main__":
	main()
