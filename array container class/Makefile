OBJS = main.o input.o

all: array.exe

array.exe: $(OBJS)
	g++ -o array.exe $(OBJS)

main.o: array.hpp array.inl
input.o: input.hpp

clean:
	del array.exe $(OBJS)
