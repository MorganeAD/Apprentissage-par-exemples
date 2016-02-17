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
	tmp->alignment[0]=c->alignment;
	tmp->nbAlign=1;

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
	int count;
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

	// A "for" loop is needed to display the list of alignments.
	printf("Alignment : ");
	for(count=0 ; count<s->nbAlign; count++)
	{
		switch (s->alignment[count]) 
		{
			case 1 :
				printf("Vilain");
				break;
			case 2 :
				printf("Neutral");
				break;
			case 3 :
				printf("Kind");
				break;
			case 4 :
				printf("Good");
				break;
			// default: 
			// 	printf("Unknown");
		}		
		if(count < s->nbAlign-1)
		{
			printf(", ");
		}
	}
	printf(")");
}
