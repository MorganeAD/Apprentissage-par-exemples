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
 # This file is the main Makefile of the stereotype library
##

#-----------------------------------------------------------------------
lib: libstereotype.a

libstereotype.a: function_stereotype.o
	-rm libstereotype.a
	ar -r libstereotype.a stereotype.o
	-mkdir ../libs
	cp -p libstereotype.a ../libs

function_stereotype.o: stereotype.c function_stereotype.h type_stereotype.h
	gcc -c -Wall -O3 -I ../headers stereotype.c

clean: 
	-rm *.o
	-rm lib*.a