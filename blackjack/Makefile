OBJS = main.o blackjack.o input.o \
	   Deck.o Card.o

all: blackjack.exe

blackjack.exe: $(OBJS)
	g++ -o blackjack.exe $(OBJS)

main.o: blackjack.hpp input.hpp
blackjack.o: blackjack.hpp input.hpp \
			 Deck.hpp Card.hpp
input.o: input.hpp
Deck.o: Deck.hpp Card.hpp
Card.o: Card.hpp

clean:
	del blackjack.exe $(OBJS)
