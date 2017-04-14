CC=g++
CFLAGS= -std=c++11 -Wall -c -g -w
LDFLAGS=
SOURCES= $(wildcard src/*.cpp)
HEADERS= $(wildcard src/*.h)
OBJECTS= $(patsubst src/%.cpp,obj/%.o,$(SOURCES)) 
EXECUTABLE= main

all: $(SOURCES) $(EXECUTABLE) 
    
$(EXECUTABLE): $(OBJECTS)
	$(CC)  -o $@ $(OBJECTS) $(LDFLAGS)

$(OBJECTS): | obj

obj:
	@mkdir -p $@
	
obj/%.o : src/%.cpp $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@