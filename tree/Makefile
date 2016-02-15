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
 # This file is the main Makefile of the tree library
##

#-----------------------------------------------------------------------
lib: libtree.a

libtree.a: function_tree.o
	-rm libtree.a
	ar -r libtree.a tree.o
	-mkdir ../libs
	cp -p libtree.a ../libs

function_tree.o: tree.c function_tree.h type_tree.h
	gcc -c -Wall -O3 tree.c

clean: 
	-rm *.o
	-rm lib*.a
