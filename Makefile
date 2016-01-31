all: install main.o
	gcc -o run main.o -L libs -lelement -lexample

main.o: main.c
	gcc -c -Wall -O3 -I headers main.c

install: installheaders installlibs

installlibs: libelement libexample

libelement:
	cd element && $(MAKE) lib

libexample:
	cd example && $(MAKE) lib

installheaders: type_element.h function_element.h type_example.h function_example.h

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

clean: 
	-rm *.o
	cd element && $(MAKE) clean 

veryclean: clean
	-rm run
	-rm -rf headers
	-rm -rf libs
