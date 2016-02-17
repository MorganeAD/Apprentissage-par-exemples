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
 # This file is the main Makefile of the model library
##

#-----------------------------------------------------------------------
lib: libmodel.a

libmodel.a: function_model.o
	-rm libmodel.a
	ar -r libmodel.a model.o
	-mkdir ../libs
	cp -p libmodel.a ../libs

function_model.o: model.c type_model.h function_model.h
	gcc -c -Wall -O3 -I ../headers model.c

clean: 
	-rm *.o
	-rm lib*.a
