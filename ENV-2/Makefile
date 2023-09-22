All: main
	
main: main.o comp_num.o sort.o
	g++ main.o comp_num.o sort.o -o complex

main.o: main.cpp
	g++ -c main.cpp

comp_num.o: comp_num.cpp
	g++ -c comp_num.cpp

sort.o: sort.cpp
	g++ -c sort.cpp


Clean:
	rm complex.o
