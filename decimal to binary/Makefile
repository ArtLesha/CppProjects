OBJS = main.o decToBin.o input.o

all: decToBin.exe

decToBin.exe: $(OBJS)
	g++ -o decToBin.exe $(OBJS)

main.o: decToBin.hpp input.hpp
decToBin.o: decToBin.hpp
input.o: input.hpp

clean:
	del decToBin.exe $(OBJS)
