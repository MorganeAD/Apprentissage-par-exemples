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
 # This file is the main Makefile of the project Supervised Learning
##

#-----------------------------------------------------------------------

# 1. if add a lib foo
# 2. if add a foo.c

# 1. add -lfoo
# 2. add foo.o 
all: install main.o comparison.o class.o
	gcc -o run main.o comparison.o class.o list/list.o -L libs -ltree -lcharacter -lmodel -llist -lrelationship -lexample

main.o: main.c
	gcc -c -Wall -O3 -I headers main.c

comparison.o: comparison.h comparison.c
	gcc -c -Wall -O3 -I headers comparison.c

class.o:
	gcc -c -Wall -O3 -I headers class.c

# 2. uncomment
# foo.o:
# 	gcc -c -Wall -O3 -I headers foo.c

install: installheaders installlibs

# 1. add libfoo
installlibs: libtree libcharacter libmodel liblist librelationship libexample

libtree:
	cd tree && $(MAKE) lib

libcharacter:
	cd character && $(MAKE) lib

libmodel:
	cd model && $(MAKE) lib

liblist:
	cd list && $(MAKE) lib

librelationship: 
	cd relationship && $(MAKE) lib

libexample: liblist
	cd example && $(MAKE) lib

# 1. uncomment
# libfoo: 
# 	cd foo && $(MAKE) lib

# 1. add type_foo.h function_foo.h
installheaders: type_tree.h function_tree.h type_character.h function_character.h type_model.h function_model.h type_list.h function_list.h type_relationship.h function_relationship.h type_example.h function_example.h

# Trees :

type_tree.h:
	-mkdir headers
	cp -p tree/type_tree.h headers

function_tree.h:
	-mkdir headers
	cp -p tree/function_tree.h headers

# Characters :

type_character.h:
	-mkdir headers
	cp -p character/type_character.h headers

function_character.h:
	-mkdir headers
	cp -p character/function_character.h headers

# Models :

type_model.h:
	-mkdir headers
	cp -p model/type_model.h headers	

function_model.h:
	-mkdir headers
	cp -p model/function_model.h headers

# Lists :

type_list.h:
	-mkdir headers
	cp -p list/type_list.h headers

function_list.h:
	-mkdir headers
	cp -p list/function_list.h headers

# Relationship :

type_relationship.h:
	-mkdir headers
	cp -p relationship/type_relationship.h headers

function_relationship.h:
	-mkdir headers
	cp -p relationship/function_relationship.h headers

# Example :

type_example.h: type_list.h function_list.h
	-mkdir headers
	cp -p example/type_example.h headers

function_example.h: type_list.h function_list.h
	-mkdir headers
	cp -p example/function_example.h headers

# 1. uncomment
# type_foo.h:
# 	-mkdir headers
# 	cp -p foo/type_foo.h headers

# function_foo.h:
# 	-mkdir headers
# 	cp -p foo/function_foo.h headers

# Clean :

clean: 
	-rm *.o
	cd tree && $(MAKE) clean 
	cd character && $(MAKE) clean
	cd model && $(MAKE) clean
	cd list && $(MAKE) clean
	cd relationship && $(MAKE) clean
	cd example && $(MAKE) clean
# 1. uncomment 
# cd foo && $(MAKE) clean

veryclean: clean
	-rm run
	-rm -rf headers
	-rm -rf libs
