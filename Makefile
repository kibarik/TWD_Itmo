WORKDIR = ButtonsScore
#2019-03-05_PeopleDB
FILES = ButtonsScore/ButtonsScore.cpp GetCategories/GetCategories.cpp
#PYFILES = 2019-03-05_PeopleDB.py
all:
	cd $(WORKDIR)
	g++ $(FILES)
#	python $(WORKDIR)/$(PYFILES)
