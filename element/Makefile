lib: libelement.a

libelement.a: function_element.o
	-rm libelement.a
	ar -r libelement.a element.o
	-mkdir ../libs
	cp -p libelement.a ../libs

function_element.o: element.c function_element.h type_element.h
	gcc -c -Wall -O3 element.c

clean: 
	-rm *.o
	-rm lib*.a