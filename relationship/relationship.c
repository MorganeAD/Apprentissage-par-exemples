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
 * @file relationship.c
 * @brief
 *
 * Define all the functions related to examples.
 */

/*-----------------------------------------------------------------------*/

#ifndef LSTDIO
#define LSTDIO
#include <stdio.h>
#endif 

#ifndef LMALLOC
#define LMALLOC
#include <malloc.h>
#endif 

#ifndef LTREE
#define LTREE
#include "type_tree.h"
#include "function_tree.h"
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

/*-----------------------------------------------------------------------*/

/** @brief createRelationship
 *
 * Create a new relationship (see the "type_relationship.h" file).
 * @param c1 [character*]
 * @param c2 [character*]
 * @param r [int]
 * @return tmp [ptr_relationship]
 */

ptr_relationship createRelationship(character* c1 , character* c2, int r)
{
	ptr_relationship tmp=(ptr_relationship)malloc(sizeof(relationship));
	tmp->ch1=c1;
	tmp->ch2=c2;
	tmp->relation=r;
	return tmp;
} 

/** @brief getCh1
 *
 * Give the character1 of the relationship.
 * @param r [ptr_relationship]
 * @return r->ch1 [character*]
 */

ptr_character getCh1(ptr_relationship r)
{
	return r->ch1;
}

/** @brief getCh2
 *
 * Give the character2 of the relationship.
 * @param r [ptr_relationship]
 * @return r->ch2 [character*]
 */

ptr_character getCh2(ptr_relationship r)
{
	return r->ch2;
}

/** @brief getRelation
 *
 * Give the relation of the relationship.
 * @param r [ptr_relationship]
 * @return r->relation [int]
 */

int getRelation(ptr_relationship r)
{
	return r->relation;
}

/** @brief displayRelationship
 *
 * Display the relationship.
 * @param r [ptr_relationship]
 * @return [void]
 */

void displayRelationship(ptr_relationship r)
{
	printf("[");
	displayCharacter(r->ch1);

	if (r->relation == 0)
	{
		printf(" serves ");
	}
	else
	{
		printf(" tracks ");
	}
	displayCharacter(r->ch2);
	printf("]");
}
