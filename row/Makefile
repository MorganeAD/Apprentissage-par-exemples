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
 # This file is the main Makefile of the row library
##

#-----------------------------------------------------------------------
lib: librow.a

librow.a: function_row.o
	-rm librow.a
	ar -r librow.a row.o
	-mkdir ../libs
	cp -p librow.a ../libs

function_row.o: row.c function_row.h type_row.h
	gcc -c -Wall -O3 row.c

clean: 
	-rm *.o
	-rm lib*.a
