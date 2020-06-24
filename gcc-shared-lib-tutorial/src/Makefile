ROOT_DIR:=$(dir $(realpath $(firstword $(MAKEFILE_LIST))))

IDIR =./myfunctions/include
CC=gcc
CFLAGS=-I$(IDIR)

_DEPS = add.h result.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
ODIR=obj
_OBJ = add.o result.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

BIN_DIR =./mybin
SRC_DIR =./
MY_LIB =myfunctions

compile_all:
	mkdir -p $(BIN_DIR)/$(MY_LIB)
	$(CC) -c  $(SRC_DIR)/main.c  -o $(BIN_DIR)/main.o $(CFLAGS)
	## object files for shared libraries need to be compiled as position independent
	## code (-fPIC) because they are mapped to any position in the address space.
	$(CC) -c -fPIC $(SRC_DIR)/$(MY_LIB)/add.c    -o $(BIN_DIR)/$(MY_LIB)/add.o $(CFLAGS)
	$(CC) -c -fPIC $(SRC_DIR)/$(MY_LIB)/result.c -o $(BIN_DIR)/$(MY_LIB)/result.o $(CFLAGS)
	

## create a shared library without SONAME
shared:
	## it must be linked against libdl (with the -ldl flag)
	$(CC) $(SRC_DIR)/main_dlopen.c -ldl -o $(BIN_DIR)/dynamic-library-loader
	$(CC) -shared $(BIN_DIR)/$(MY_LIB)/add.o $(BIN_DIR)/$(MY_LIB)/result.o -o $(BIN_DIR)/$(MY_LIB)/lib$(MY_LIB).so
	$(CC)  $(BIN_DIR)/main.o -L$(BIN_DIR)/$(MY_LIB) -l$(MY_LIB) -o $(BIN_DIR)/use-shared-library

all: compile_all shared

.PHONY: clean

clean:
	@echo $(ROOT_DIR)
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 
	rm -rf $(BIN_DIR)
	rm -rf $(ODIR)