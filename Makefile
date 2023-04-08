all:
	g++ -c ./token/token_record.cpp 
	g++ -c ./token/token.cpp
	g++ -c ./lexicon/lexicon.cpp
	g++ main.cpp token_record.o token.o lexicon.o

clean:
	rm *.o
