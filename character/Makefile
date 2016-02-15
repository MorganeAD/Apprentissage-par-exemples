lib: libcharacter.a

libcharacter.a: function_character.o
	-rm libcharacter.a
	ar -r libcharacter.a character.o
	-mkdir ../libs
	cp -p libcharacter.a ../libs

function_character.o: character.c type_character.h function_character.h
	gcc -c -Wall -O3 -I ../headers character.c

clean: 
	-rm *.o
	-rm lib*.a
