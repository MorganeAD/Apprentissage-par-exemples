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
 * @file example.c
 * @brief
 *
 * Define all the functions related to examples.
 */

/*-----------------------------------------------------------------------*/

#ifndef STDIO
#define STDIO
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

#ifndef LROW
#define LROW
#include "type_row.h"
#include "function_row.h"
#endif 

#ifndef LCHR
#define LCHR
#include "type_character.h"
#include "function_character.h"
#endif 

#ifndef LRLT
#define LRLT
#include "type_relationship.h"
#include "function_relationship.h"
#endif 

#ifndef LEXP
#define LEXP
#include "type_example.h"
#include "function_example.h"
#endif 

/*-----------------------------------------------------------------------*/

/** @brief createEmptyExample
 *
 * Create a new emptry example (see the "type_example.h" file).
 * @param [void]
 * @return tmp [ptr_example]
 */

ptr_example createEmptyExample(void)
{
	ptr_example tmp=(ptr_example)malloc(sizeof(example));
	tmp->exRelRow=createEmpty();
	return tmp;
} 

/** @brief getExRelRow
 *
 * Give the row of the relationships
 * @param e [ptr-example]
 * @return e->exRelRow [ptr_row]
 */

ptr_row getExRelRow(ptr_example e)
{
	return e->exRelRow;
}

/** @brief getRelationI
 *
 * Give the relationship at the position i
 * @param e [ptr-example]
 * @param n [int]
 * @return e->exRelRow[n] [ptr_relationship]
 */

ptr_relationship getRelationI(ptr_example e, int n)
{
	return (ptr_relationship)getDataI(getExRelRow(e), n);
}

/** @brief getCharacterI
 *
 * Give the character at the position i
 * @param e [ptr-example]
 * @param n [int]
 * @return e->exRelRow[i]->data1 [ptr_character]
 */

ptr_character getCharacterI(ptr_example e, int n)
{
	ptr_relationship tmp = getRelationI(e, n);
	return getData1(tmp);
}

/** @brief addFirstCharacter
 *
 * Add a character into the row characters
 * @param e [ptr_example]
 * @param c [ptr_character]
 * @return tmp [ptr_example]
 */

void addFirstCharacter(ptr_example e, ptr_character c)
{
	ptr_relationship tmp = createRelationshipOneObject(c);
	addToRow(getExRelRow(e), tmp);
}

/** @brief addSecondCharacter
 *
 * Add a character into the row characters
 * @param e [ptr_example]
 * @param c [ptr_character]
 * @return tmp [ptr_example]
 */

void addSecondCharacter(ptr_example e, ptr_character c, int r)
{
	modifyRelation(getData(getExRelRow(e)), c, r);
}

/** @brief addCharacter
 *
 * Add a character into the row characters
 * @param e [ptr_example]
 * @param c [ptr_character]
 * @return tmp [ptr_example]
 */

void addCharacter(ptr_example e, ptr_character c, int r)
{
	ptr_relationship tmp = createRelationship(getData2(getLastData(getExRelRow(e))),c , r);
	addToRow(getExRelRow(e), tmp);
}

/** @brief displayExample
 *
 * Display the example.
 * @param e [ptr_example]
 * @return [void]
 */

void displayExample(ptr_example e)
{
	ptr_row tmp;
	tmp = getExRelRow(e);
	printf("{");
	if (isEmpty(tmp))
	{
		printf("Empty!");
	}
	else if (isRelationshipOneObject(getData(tmp)))
	{
		displayCharacter(getData1(getData(tmp)));
	}
	else
	{
		while(!isEmpty(tmp))
		{
			printf("[");
			displayCharacter(getData1(getData(tmp)));
			if (getRelation(getData(tmp)) == 0)
			{
				printf(" serves ");
			}
			else
			{
				printf(" tracks ");
			}
			displayCharacter(getData2(getData(tmp)));
			printf("]");
			tmp = nextRow(tmp);
			if (!isEmpty(tmp))
			{
				printf("\n");
			}
		}
	}
	printf("}");
}
