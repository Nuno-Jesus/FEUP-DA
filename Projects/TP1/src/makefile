FLAGS := -Wunused -Wall

all: van order sorter utils link

van: van.cpp	
	g++ -c $(FLAGS) van.cpp

order: order.cpp
	g++ -c $(FLAGS) order.cpp

utils: utils.cpp
	g++ -c $(FLAGS) utils.cpp

sorter: sorter.cpp
	g++ -c $(FLAGS) sorter.cpp

link:	main.cpp van.o order.o utils.o sorter.o
	g++ $(FLAGS) main.cpp van.o order.o utils.o sorter.o

clean:
	rm a.out
	rm order.o
	rm van.o
	rm utils.o
	rm sorter.o