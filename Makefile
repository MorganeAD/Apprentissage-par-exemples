all: install main.o comparison.o class.o
	gcc -o run main.o comparison.o class.o -L libs -ltree -lcharacter -lmodel -llist

main.o: main.c
	gcc -c -Wall -O3 -I headers main.c

comparison.o: comparison.h comparison.c
	gcc -c -Wall -O3 -I headers comparison.c

class.o:
	gcc -c -Wall -O3 -I headers class.c

install: installheaders installlibs

installlibs: libtree libcharacter libmodel liblist

libtree:
	cd tree && $(MAKE) lib

libcharacter:
	cd character && $(MAKE) lib

libmodel:
	cd model && $(MAKE) lib

liblist:
	cd list && $(MAKE) lib

installheaders: type_tree.h function_tree.h type_character.h function_character.h type_model.h function_model.h type_list.h function_list.h

# Trees :

type_tree.h:
	-mkdir headers
	cp -p tree/type_tree.h headers

function_tree.h:
	-mkdir headers
	cp -p tree/function_tree.h headers

# Characters :

type_character.h:
	-mkdir headers
	cp -p character/type_character.h headers

function_character.h:
	-mkdir headers
	cp -p character/function_character.h headers

# Models :

type_model.h:
	-mkdir headers
	cp -p model/type_model.h headers	

function_model.h:
	-mkdir headers
	cp -p model/function_model.h headers

# Lists :

type_list.h:
	-mkdir headers
	cp -p list/type_list.h headers

function_list.h:
	-mkdir headers
	cp -p list/function_list.h headers

# Clean :

clean: 
	-rm *.o
	cd tree && $(MAKE) clean 
	cd character && $(MAKE) clean
	cd model && $(MAKE) clean
	cd list && $(MAKE) clean

veryclean: clean
	-rm run
	-rm -rf headers
	-rm -rf libs
