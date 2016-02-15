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
