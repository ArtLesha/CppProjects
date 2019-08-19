OBJS = main.o input.o arithmetic.o

all: calculator.exe

calculator.exe: $(OBJS)
	g++ -o calculator.exe $(OBJS)

main.o: input.hpp arithmetic.hpp
input.o: input.hpp
arithmetic.o: arithmetic.hpp

clean:
	del calculator.exe $(OBJS)
