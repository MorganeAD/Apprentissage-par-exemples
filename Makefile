all: install main.o comparison.o
	gcc -o run main.o comparison.o -L libs -lelement -lexample -lmodel -llist

main.o: main.c
	gcc -c -Wall -O3 -I headers main.c

comparison.o: comparison.h comparison.c
	gcc -c -Wall -O3 -I headers comparison.c

install: installheaders installlibs

installlibs: libelement libexample libmodel liblist

libelement:
	cd element && $(MAKE) lib

libexample:
	cd example && $(MAKE) lib

libmodel:
	cd model && $(MAKE) lib

liblist:
	cd list && $(MAKE) lib

installheaders: type_element.h function_element.h type_example.h function_example.h type_model.h function_model.h type_list.h function_list.h

# Elements :

type_element.h:
	-mkdir headers
	cp -p element/type_element.h headers

function_element.h:
	-mkdir headers
	cp -p element/function_element.h headers

# Examples :

type_example.h:
	-mkdir headers
	cp -p example/type_example.h headers

function_example.h:
	-mkdir headers
	cp -p example/function_example.h headers

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
	cd element && $(MAKE) clean 
	cd example && $(MAKE) clean
	cd model && $(MAKE) clean
	cd list && $(MAKE) clean

veryclean: clean
	-rm run
	-rm -rf headers
	-rm -rf libs
