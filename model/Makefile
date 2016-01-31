lib: libmodel.a

libmodel.a: function_model.o
	-rm libmodel.a
	ar -r libmodel.a model.o
	-mkdir ../libs
	cp -p libmodel.a ../libs

function_model.o: model.c function_model.h type_model.h
	gcc -c -Wall -O3 -I ../headers model.c

clean: 
	-rm *.o
	-rm lib*.a