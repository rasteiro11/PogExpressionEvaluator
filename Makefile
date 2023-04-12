EXPRESSION = ./exp
INTEGRAL = ./integral
PLOT = ./plot
SOURCES = main.cpp
SOURCES += $(EXPRESSION)/expression.cpp $(EXPRESSION)/lexicon.cpp $(EXPRESSION)/token.cpp
SOURCES += $(INTEGRAL)/integral.cpp
SOURCES += $(PLOT)/plot.cpp
OBJECTS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))


COMPILE : LINK 
	g++ -o main $(OBJECTS) 

LINK:
	g++ -c $(SOURCES)

clean:
	rm $(OBJECTS)
