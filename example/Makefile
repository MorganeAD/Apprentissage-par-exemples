lib: libexample.a

libexample.a: function_example.o
	-rm libexample.a
	ar -r libexample.a example.o
	-mkdir ../libs
	cp -p libexample.a ../libs

function_example.o: example.c type_example.h function_example.h
	gcc -c -Wall -O3 -I ../headers example.c

clean: 
	-rm *.o
	-rm lib*.a
