TARGET = rad
FLAGS =-std=c++11 -ggdb
EXT = cpp
INCLUDE = ./

%.o: %.$(EXT) 
	@echo "compiling: $*.c -> $@"
	g++ $(FLAGS) -c  $*.$(EXT) -o $@ -I$(INCLUDE)

all: $(TARGET) 

$(TARGET): $(TARGET).o 
	@echo "linking: $<.c -> $@"
	g++ $(FLAGS) $< -o $@


clean:
	rm *.o 

