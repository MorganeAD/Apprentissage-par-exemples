/**
 * Polytech Marseille
 * Case 925 - 163, avenue de Luminy
 * 13288 Marseille CEDEX 9
 *
 * This file is the work of students from Polytech Marseille. It can not be
 * reproduced, modified or used without the express opinion of its authors.
 */

/**
 * @author ALONSO Morgane <alonso.morgane@gmail.com>
 * @author BENMILOUD--JOSSELIN Alexis <alexis.benmiloud.josselin@gmail.com>
 *
 * @version 0.0.1 / 2016/01/31
 * @todo #0000 []
 * @bug #0000 []
 */

/**
 * @file tree.c
 * @brief
 *
 * This file contains all the functions related to trees.
 */

/*-----------------------------------------------------------------------*/

#ifndef LSTDIO
#define LSTDIO
#include <stdio.h>
#endif 

#ifndef LSTDLIB
#define LSTDLIB
#include <stdlib.h>
#endif 

#ifndef LTREE
#define LTREE
#include "type_tree.h"
#include "function_tree.h"
#endif 

/*-----------------------------------------------------------------------*/

/** @brief isTheDaddy
 *
 * Tell if an tree is the daddy. The daddy's father is "NULL"
 * @param tree [ptr_tree]
 * @return boolean [int]
 */

int isTheDaddy(ptr_tree tree)
{
	return tree->father==NULL;
}

/** @brief createTheDaddy
 *
 * Create a the father of the tree.
 * @param val [int]
 * @return daddy [ptr_tree]
 */

ptr_tree createTheDaddy(int val)
{
	ptr_tree daddy=(ptr_tree)malloc(sizeof(tree));
	daddy->value=val;
	daddy->father=NULL;
	return daddy;
}

/** @brief createSon
 *
 * Create a son.
 * @param val [int]
 * @param dad [ptr_tree] 
 * @return son [ptr_tree]
 */

ptr_tree createSon(int val, ptr_tree dad)
{
	ptr_tree this=(ptr_tree)malloc(sizeof(tree));
	this->value=val;
	this->father=dad;
	return this;
}

/** @brief hisFather
 *
 * Give the father of the tree.
 * @param son [ptr_example]
 * @return son->father [ptr_tree]
 */

ptr_tree hisFather(ptr_tree son)
{
	return son->father;
}

/** @brief getValue
 *
 * Give the value of an tree of a tree.
 * @param tree [ptr_example]
 * @return tree->value [int]
 */

int getValue(ptr_tree tree)
{
	return tree->value;
}

/** @brief displayBranch
 *
 * Display the branch of an tree of a tree.
 * @param branch [ptr_tree]
 * @return [void]
 */

void displayBranch(ptr_tree branch)
{
	ptr_tree tmp=branch;
	printf("%d -> ", getValue(tmp));
	while(!isTheDaddy(tmp))
	{
		tmp=hisFather(tmp);
		printf("%d -> ", getValue(tmp));
	}
	printf("\n");
}

/** @brief commonFather
 *
 * Find the common father of two trees.
 * @param son1 [ptr_tree]
 * @param son2 [ptr_tree]
 * @return j [ptr_tree]
 */

ptr_tree commonFather(ptr_tree son1, ptr_tree son2)
{
	ptr_tree i=son1;
	ptr_tree j=son2;
	int find=0;

	while(!find && !isTheDaddy(i))
	{
		j=son2;
		while(!find && !isTheDaddy(j))
		{
			if (i==j)
			{
				find=1;
			}
			else 
			{
				j=hisFather(j);
			}
		}
		i=hisFather(i);
	}
	return j;
}
