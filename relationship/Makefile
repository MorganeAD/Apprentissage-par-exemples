lib: librelationship.a

librelationship.a: function_relationship.o
	-rm librelationship.a
	ar -r librelationship.a relationship.o
	-mkdir ../libs
	cp -p librelationship.a ../libs

function_relationship.o: relationship.c type_relationship.h function_relationship.h
	gcc -c -Wall -O3 -I ../headers relationship.c

clean: 
	-rm *.o
	-rm lib*.a
