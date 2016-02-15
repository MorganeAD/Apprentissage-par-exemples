##
 # Polytech Marseille
 # Case 925 - 163, avenue de Luminy
 # 13288 Marseille CEDEX 9
 #
 # This file is the work of students from Polytech Marseille. It can not be
 # reproduced, modified or used without the express opinion of its authors.
 #


 # @author ALONSO Morgane <alonso.morgane@gmail.com>
 # @author BENMILOUD--JOSSELIN Alexis <alexis.benmiloud.josselin@gmail.com>
 #
 # @version 0.0.1 / 2016/01/31
 # @todo #0000 []
 # @bug #0000 []
 #

 #
 # @file Makefile
 # @brief
 #
 # This file is the main Makefile of the character library
##

#-----------------------------------------------------------------------
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
