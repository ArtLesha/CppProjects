OBJS = main.o game_logic.o Creature.o \
	   Player.o Monster.o random.o

all: adventure.exe

adventure.exe: $(OBJS)
	g++ -o adventure.exe $(OBJS)

main.o: game_logic.hpp
game_logic.o: game_logic.hpp random.hpp Player.hpp \
			  Monster.hpp Creature.hpp
Creature.o: Creature.hpp
Player.o: Player.hpp Creature.hpp
Monster.o: random.hpp Monster.hpp Creature.hpp
random.o: random.hpp

clean:
	del adventure.exe $(OBJS)
