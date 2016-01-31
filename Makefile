all: install main.o
	gcc -o run main.o -L libs -lelement

main.o: main.c
	gcc -c -Wall -O3 -I headers main.c

install: installheaders installlibs

installlibs: libelement

libelement:
	cd element && $(MAKE) lib

installheaders: type_element.h function_element.h

type_element.h:
	-mkdir headers
	cp -p element/type_element.h headers

function_element.h:
	-mkdir headers
	cp -p element/function_element.h headers

clean: 
	-rm *.o
	cd element && $(MAKE) clean 

veryclean: clean
	-rm run
	-rm -rf headers
	-rm -rf libs