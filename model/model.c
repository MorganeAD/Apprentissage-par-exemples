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
 * @file model.c
 * @brief 
 *
 * This file contains all the functions to work with models.
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

#ifndef LMDL
#define LMDL
#include "type_model.h"
#include "function_model.h"
#endif 

/*-----------------------------------------------------------------------*/

/** @brief initModel
 *
 * Create the first model from an character.
 * @param character [ptr_character]
 * @return model [ptr_model]
 */

ptr_model initModel(ptr_character firstCharacter)
{
	ptr_model model=(ptr_model)malloc(sizeof(model));

	model->type=firstCharacter->type;
	model->minInfluence=firstCharacter->influence;
	model->maxInfluence=firstCharacter->influence;
	model->alignment[0]=firstCharacter->alignment;
	model->index=0;

	return model;
}

/** @brief displayModel
 *
 * Display the model.
 * @param model [ptr_model]
 * @return [void]
 */

void displayModel(ptr_model model)
{
	int count;
	printf("(Type : ");
	switch (model->type->value) 
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
	printf("Influence : from %d to %d; ", model->minInfluence, model->maxInfluence);

	// A "for" loop is needed to display the list of alignments.
	printf("Alignment : ");
	for(count=0 ; count<=model->index ; count++)
	{
		switch (model->alignment[count]) 
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
			default: 
				printf("Unknown");
		}		
		if(count<model->index)
		{
			printf(", ");
		}
	}
	printf(")");
}
