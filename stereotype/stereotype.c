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
 * @version 0.0.1 / 2016/01/25
 * @todo #0000 []
 * @bug #0000 []
 */

/**
 * @file stereotype.c
 * @brief 
 *
 * This file contains all the functions to work with stereotypes.
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

#ifndef LCHR
#define LCHR
#include "type_character.h"
#include "function_character.h"
#endif

#ifndef LSTR
#define LSTR
#include "type_stereotype.h"
#include "function_stereotype.h"
#endif


/*-----------------------------------------------------------------------*/

/** @brief createStereotype
 *
 * Create the first stereotype from parameters
 * @param t [ptr_tree]
 * @param minI [int]
 * @param maxI [int]
 * @param as [int[]]
 * @return stereotype [ptr_stereotype]
 */

ptr_stereotype createStereotype(ptr_tree t, int minI, int maxI, int as[])
{
	ptr_stereotype tmp=(ptr_stereotype)malloc(sizeof(stereotype));

	tmp->type=t;
	tmp->minInfluence=minI;
	tmp->maxInfluence=maxI;

	int i;
	for (i = 0; i < 4; i++)
	{
		tmp->alignments[i]=as[i];
	}

	// *tmp->alignments=as;	
	return tmp;
}

/** @brief initstereotype
 *
 * Create the first stereotype from an character.
 * @param character [ptr_character]
 * @return stereotype [ptr_stereotype]
 */

ptr_stereotype initStereotype(ptr_character c)
{
	ptr_stereotype tmp=(ptr_stereotype)malloc(sizeof(stereotype));

	tmp->type=c->type;
	tmp->minInfluence=c->influence;
	tmp->maxInfluence=c->influence;
	for (int i = 0; i < 4; i++)
	{
		tmp->alignments[i]=0;
	}
	tmp->alignments[c->alignment-1]=1;

	return tmp;
}

/** @brief displaystereotype
 *
 * Display the stereotype.
 * @param stereotype [ptr_stereotype]
 * @return [void]
 */

void displayStereotype(ptr_stereotype s)
{
	printf("(Type : ");
	switch (s->type->value) 
	{
		case 1 :
			printf("Person");
			break;
		case 2 :
			printf("Force");
			break;
		case 3 :
			printf("Jedi");
			break;
		case 4 :
			printf("Council");
			break;
		case 5 :
			printf("Sith");
			break;
		case 6 :
			printf("Weak");
			break;
		case 7 :
			printf("Droid");
			break;
		case 8 :
			printf("Combat");
			break;
		case 9 :
			printf("Pacific");
			break;			
		case 10 :
			printf("Bandit");
			break;
		case 11 :
			printf("Hunter");
			break;
		case 12 :
			printf("Senator");
			break;
		default: 
			printf("Unknown");
	}
	printf("; ");
	printf("Influence : from %d to %d; ", s->minInfluence, s->maxInfluence);

	/* A "for" loop is needed to display the list of alignments. */
	printf("Alignment : ");
	int algnAlready = 0;
	if (s->alignments[0])
	{
		printf("Vilain");
		algnAlready = 1;
	}
	if (s->alignments[1])
	{
		if (algnAlready)
		{
			printf(", ");
		}
		printf("Neutral");
		algnAlready = 1;
	}
	if (s->alignments[2])
	{
		if (algnAlready)
		{
			printf(", ");
		}
		printf("Kind");
		algnAlready = 1;
	}
	if (s->alignments[3])
	{
		if (algnAlready)
		{
			printf(", ");
		}
		printf("Good");
	}
	printf(")");
}

/** @brief getStereotypeType
 *
 * Give the type of the stereotype.
 * @param s [ptr_stereotype]
 * @return s->type [ptr_tree]
 */

ptr_tree getStereotypeType(ptr_stereotype s)
{
	return s->type;
}

/** @brief getMinInfluence
 *
 * Give the minInfluence of the stereotype.
 * @param s [ptr_stereotype]
 * @return s->minInfluence [int]
 */

int getMinInfluence(ptr_stereotype s)
{
	return s->minInfluence;
}

/** @brief getMaxInfluence
 *
 * Give the maxInfluence of the stereotype.
 * @param s [ptr_stereotype]
 * @return s->maxInfluence [int]
 */

int getMaxInfluence(ptr_stereotype s)
{
	return s->maxInfluence;
}

/** @brief getAlignments
 *
 * Give the array of alignement.
 * @param s [ptr_stereotype]
 * @return s->alignment [int[]]
 */

int* getAlignments(ptr_stereotype s)
{
	return s->alignments;
}

/** @brief sameTypes
 *
 * Tell if two stereotypes have the same type.
 * @param s1 [ptr_stereotype]
 * @param s2 [ptr_stereotype]
 * @return same [int]
 */

int sameTypes(ptr_stereotype s1, ptr_stereotype s2)
{
	int same;

	same=1;
	if(getStereotypeType(s1)!=getStereotypeType(s2))
	{
		same=0;
	}
	return same;
}

/** @brief sameInfluences
 *
 * Tell if two stereotypes have the same influences.
 * @param s1 [ptr_stereotype]
 * @param s2 [ptr_stereotype]
 * @return same [int]
 */

int sameInfluences(ptr_stereotype s1, ptr_stereotype s2)
{
	int same;

	same=1;
	if(getMinInfluence(s1)!=getMinInfluence(s2) ||
		getMaxInfluence(s1)!=getMaxInfluence(s2))
	{
		same=0;
	}
	return same;
}

/** @brief sameAlignments
 *
 * Tell if two stereotypes have the same alignments.
 * @param s1 [ptr_stereotype]
 * @param s2 [ptr_stereotype]
 * @return ok [int]
 */
 
int sameAlignments(ptr_stereotype s1, ptr_stereotype s2)
{
	int ok, i;
	ok = 1;
	i = 0;
	while(ok && i < 4)
	{
		if (s1->alignments[i]!=s2->alignments[i])
		{
			ok = 0;
		}
		else
		{
			i++;
		}
	}
	return ok;
}

/** @brief equalStereotypes
 *
 * Tell if two stereotype are equal.
 * @param s1 [ptr_stereotype]
 * @param s2 [ptr_stereotype]
 * @return areEqual [int]
 */

int equalStereotypes(ptr_stereotype s1, ptr_stereotype s2)
{
	int areEqual;

	areEqual=1;
	if(!sameTypes(s1, s2) ||
		!sameInfluences(s1, s2) ||
		!sameAlignments(s1, s2))
	{
		areEqual=0;
	}
	return areEqual;
}
