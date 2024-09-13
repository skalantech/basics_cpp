################################################################################
# Declare some Makefile variables
################################################################################
CC = g++
LANG_STD = -std=c++20
COMPILER_FLAGS = -Wall -Wfatal-errors
INCLUDE_PATH = -I"./libs/"
SRC_FILES = ./src/*.cpp	
LINKER_FLAGS = ~/lua-5.4.6/src/liblua.a 
OBJ_NAME = luaTest

################################################################################
# Declare some Makefile rules
################################################################################
build:
	$(CC) $(COMPILER_FLAGS) $(LANG_STD) $(INCLUDE_PATH) $(SRC_FILES) $(LINKER_FLAGS) -o $(OBJ_NAME)

run:
	./$(OBJ_NAME)

clean:
	rm $(OBJ_NAME)
