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
 * @file comparison.c
 * @brief 
 *
 * This file describes all the functions to compare between a model and an
 * character.
 */

/*-----------------------------------------------------------------------*/

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

#ifndef COMP
#define COMP
#include "comparison.h"
#endif 

#define MAX_ALIGNMENT 4

/*-----------------------------------------------------------------------*/


/** @brief searchAlignment
 *
 * Do a research of an alignment into a list of alignment (see the
 * "type_character.c" file).
 * @param tree [int]
 * @param list [pointer]
 * @return isInto [int]
 */

int searchAlignment(int alignment, int list[MAX_ALIGNMENT])
{
	int index, isInto;
	
	index=0;
	isInto=0;
	while(isInto==0 && alignment!=list[index] && index<=MAX_ALIGNMENT-1)
	{
		index++;
		if(alignment==list[index])
		{
			isInto=1;
		}
	}
	return isInto;
}
	

/** @brief comparison
 *
 * Do a comparison between the model and an character in order to enlarge,
 * or not, the model.
 * @param model [ptr_model]
 * @param character [ptr_character]
 * @return model [ptr_model]
 */

ptr_model comparison(ptr_model model, ptr_character character)
{
	/* Comparison of types.*/
	model->type=commonFather(model->type, character->type);

	/* Comparison of influences.*/
	if(model->minInfluence>character->influence)
	{
		model->minInfluence=character->influence;
	}
	else if(model->maxInfluence<character->influence)
	{
		model->maxInfluence=character->influence;
	}
	
	/* Comparison of alignments.*/
	if(model->index<MAX_ALIGNMENT-1
		&& searchAlignment(character->alignment, model->alignment)==0)
	{
		model->index++;
		model->alignment[model->index]=character->alignment;
	}
	return model;
}

/** @brief comparison
 *
 * Do a comparison between an character and another character in order to
 * generate models.
 * @param character1 [ptr_character]
 * @param character2 [ptr_character]
 * @return model [ptr_model]
 */
/*
ptr_model comparisonBis(ptr_character character1, ptr_character character2)
{
	
}
*/
