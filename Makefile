all: install main.o
	gcc -o run main.o -L libs -lelement -lexample -lmodel

main.o: main.c
	gcc -c -Wall -O3 -I headers main.c

install: installheaders installlibs

installlibs: libelement libexample libmodel

libelement:
	cd element && $(MAKE) lib

libexample:
	cd example && $(MAKE) lib

libmodel:
	cd model && $(MAKE) lib

installheaders: type_element.h function_element.h type_example.h function_example.h type_model.h function_model.h

type_element.h:
	-mkdir headers
	cp -p element/type_element.h headers

function_element.h:
	-mkdir headers
	cp -p element/function_element.h headers

type_example.h:
	-mkdir headers
	cp -p example/type_example.h headers

function_example.h:
	-mkdir headers
	cp -p example/function_example.h headers

type_model.h:
	-mkdir headers
	cp -p model/type_model.h headers	

function_model.h:
	-mkdir headers
	cp -p model/function_model.h headers

clean: 
	-rm *.o
	cd element && $(MAKE) clean 
	cd example && $(MAKE) clean
	cd model && $(MAKE) clean

veryclean: clean
	-rm run
	-rm -rf headers
	-rm -rf libs
