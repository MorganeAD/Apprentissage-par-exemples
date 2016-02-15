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
 # This file is the main Makefile of the list library
##

#-----------------------------------------------------------------------
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
