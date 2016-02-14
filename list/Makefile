lib: liblist.a

liblist.a: function_list.o
	-rm liblist.a
	ar -r liblist.a list.o
	-mkdir ../libs
	cp -p liblist.a ../libs

function_list.o: list.c function_list.h type_list.h
	gcc -c -Wall -O3 -I ../headers list.c

clean: 
	-rm *.o
	-rm lib*.a
