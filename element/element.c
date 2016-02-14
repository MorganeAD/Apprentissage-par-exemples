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
 * @file element.c
 * @brief
 *
 * This file contains all the functions related to elements.
 */

/*-----------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "type_element.h"
#include "function_element.h"

/*-----------------------------------------------------------------------*/

/** @brief isTheDaddy
 *
 * Tell if an element is the daddy. The daddy's father is "NULL"
 * @param element [ptr_element]
 * @return boolean [int]
 */

int isTheDaddy(ptr_element element)
{
	return element->father==NULL;
}

/** @brief createTheDaddy
 *
 * Create a the father of the tree.
 * @param val [int]
 * @return daddy [ptr_element]
 */

ptr_element createTheDaddy(int val)
{
	ptr_element daddy=(ptr_element)malloc(sizeof(element));
	daddy->value=val;
	daddy->father=NULL;
	return daddy;
}

/** @brief createSon
 *
 * Create a son.
 * @param val [int]
 * @param dad [ptr_element] 
 * @return son [ptr_element]
 */

ptr_element createSon(int val, ptr_element dad)
{
	ptr_element this=(ptr_element)malloc(sizeof(element));
	this->value=val;
	this->father=dad;
	return this;
}

/** @brief hisFather
 *
 * Give the father of the element.
 * @param son [ptr_example]
 * @return son->father [ptr_element]
 */

ptr_element hisFather(ptr_element son)
{
	return son->father;
}

/** @brief getValue
 *
 * Give the value of an element of a tree.
 * @param element [ptr_example]
 * @return element->value [int]
 */

int getValue(ptr_element element)
{
	return element->value;
}

/** @brief displayBranch
 *
 * Display the branch of an element of a tree.
 * @param branch [ptr_element]
 * @return [void]
 */

void displayBranch(ptr_element branch)
{
	ptr_element tmp=branch;
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
 * Find the common father of two elements.
 * @param son1 [ptr_element]
 * @param son2 [ptr_element]
 * @return j [ptr_element]
 */

ptr_element commonFather(ptr_element son1, ptr_element son2)
{
	ptr_element i=son1;
	ptr_element j=son2;
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
