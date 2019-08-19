OBJS = main.o FixedPoint2.o input.o

all: fixed_point.exe

fixed_point.exe: $(OBJS)
	g++ -o fixed_point.exe $(OBJS)

main.o: FixedPoint2.hpp input.hpp
FixedPoint.o: FixedPoint2.hpp
input.o: input.hpp

clean:
	del fixed_point.exe $(OBJS)
