EXPRESSION = ./exp
INTEGRAL = ./integral
SOURCES = main.cpp
SOURCES += $(EXPRESSION)/expression.cpp $(EXPRESSION)/lexicon.cpp $(EXPRESSION)/token.cpp
SOURCES += $(INTEGRAL)/integral.cpp
OBJECTS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))


COMPILE : LINK 
	g++ -o main $(OBJECTS) 

LINK:
	g++ -c $(SOURCES)

clean:
	rm $(OBJECTS)
