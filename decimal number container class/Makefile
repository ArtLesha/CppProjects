OBJS = main.o Decimal.o input.o

all: decimal.exe

decimal.exe: $(OBJS)
	g++ -o decimal.exe $(OBJS)

main.o: Decimal.hpp input.hpp
FixedPoint.o: Decimal.hpp
input.o: input.hpp

clean:
	del decimal.exe $(OBJS)
