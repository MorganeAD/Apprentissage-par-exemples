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
 # This file is the main Makefile of the example library
##

#-----------------------------------------------------------------------
lib: libexample.a

libexample.a: function_example.o
	-rm libexample.a
	ar -r libexample.a example.o
	-mkdir ../libs
	cp -p libexample.a ../libs

function_example.o: example.c function_example.h type_example.h
	gcc -c -Wall -O3 -I ../headers example.c

clean: 
	-rm *.o
	-rm lib*.a
