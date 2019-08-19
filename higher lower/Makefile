OBJS = main.o higherLower.o input.o

all: higher_lower.exe

higher_lower.exe: $(OBJS)
	g++ -o higher_lower.exe $(OBJS)

main.o: higherLower.hpp input.hpp
higherLower.o: higherLower.hpp input.hpp
input.o: input.hpp

clean:
	del higher_lower.exe $(OBJS)
