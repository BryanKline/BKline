CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

PA05 : PA05.o MrgSorter.o QkSorter.o BblSorter.o SorterClass.o SimpleVector.o StudentType.o SimpleTimer.o
	$(CC) $(LFLAGS) PA05.o MrgSorter.o QkSorter.o BblSorter.o SorterClass.o SimpleVector.o StudentType.o SimpleTimer.o -o PA05

PA05.o : PA05.cpp QkSorter.h MrgSorter.h BblSorter.h SorterClass.cpp StudentType.h SimpleTimer.h
	$(CC) $(CFLAGS) PA05.cpp

MrgSorter.o : MrgSorter.cpp MrgSorter.h SorterClass.cpp SorterClass.h SimpleVector.cpp SimpleVector.h
	$(CC) $(CFLAGS) MrgSorter.cpp

QkSorter.o : QkSorter.cpp QkSorter.h SorterClass.cpp SorterClass.h SimpleVector.cpp SimpleVector.h
	$(CC) $(CFLAGS) QkSorter.cpp

BblSorter.o : BblSorter.cpp BblSorter.h SorterClass.cpp SorterClass.h SimpleVector.cpp SimpleVector.h
	$(CC) $(CFLAGS) BblSorter.cpp

SorterClass.o : SorterClass.cpp SorterClass.h SimpleVector.cpp SimpleVector.h
	$(CC) $(CFLAGS) SorterClass.cpp

SimpleVector.o : SimpleVector.cpp SimpleVector.h
	$(CC) $(CFLAGS) SimpleVector.cpp

StudentType.o : StudentType.cpp StudentType.h
	$(CC) $(CFLAGS) StudentType.cpp

SimpleTimer.o : SimpleTimer.cpp SimpleTimer.h
	$(CC) $(CFLAGS) SimpleTimer.cpp

clean:
	\rm *.o PA05

