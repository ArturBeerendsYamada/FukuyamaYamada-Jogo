#Nome do Projeto
PROJ_NAME=nome_do_jogo

#Arquivos .cpp
CPP=$(wildcard ./source/*.cpp)

#Arquivos .h
H=$(wildcard ./headers/*.h)

#Objetos compilados
OBJ=$(subst .cpp,.opp,$(subst source,objects,$(CPP)))

#Compilador
CC=g++

#Flags do compilador
CC_FLAGS= -c		\
	  -W		\
	  -Wall		\
	  -pedantic	\
	  -std=c++11
		
#Flags sfml
SFML= -lsfml-graphics	\
      -lsfml-window	\
      -lsfml-system	

#Remover
RM = rm -r

all: objDir $(PROJ_NAME)
	@ ./$(PROJ_NAME)
	@ make clean

$(PROJ_NAME): $(OBJ)
	@ echo 'Building binary using G++ linker: $@'
	$(CC) $^ -o $@ $(SFML)
	@ echo 'Finished building binary: $@'
	@ echo ' '
./objects/%.opp: ./source/%.cpp ./headers/%.h 
	@ echo 'Building target using G++ compiler: $@'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' ' 
./objects/main.opp: ./source/main.cpp $(H)
	@ echo 'Building target using G++ compiler: $@'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' ' 

objDir:
	@ mkdir -p objects

clean:
	@ $(RM) ./objects/*.opp $(PROJ_NAME) 
	@ rmdir objects
