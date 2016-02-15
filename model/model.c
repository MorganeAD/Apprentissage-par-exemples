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

#include <stdio.h>
#include <malloc.h>

#include "type_tree.h"
#include "function_tree.h"

#include "type_character.h"
#include "function_character.h"

#include "type_model.h"
#include "function_model.h"

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
	
	printf("Current model :\n");
	printf("<type : %d> ", model->type->value);
	printf("<influence : from %d to %d> ", model->minInfluence, model->maxInfluence);

	// A "for" loop is needed to display the list of alignments.
	printf("<alignments : ");
	for(count=0 ; count<=model->index ; count++)
	{
		printf("%d", model->alignment[count]);
		if(count<model->index)
		{
			printf(" ; ");
		}
	}
	printf(">\n\n");
}
