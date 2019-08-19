OBJS = main.o input.o

all: sort.exe

sort.exe: $(OBJS)
	g++ -o sort.exe $(OBJS)

main.o: sort.hpp input.hpp
input.o: input.hpp

clean:
	del sort.exe $(OBJS)
