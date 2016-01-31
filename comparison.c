/**
 * Polytech Marseille
 * Case 925 - 163, avenue de Luminy
 * 13288 Marseille CEDEX 9
 *
 * Ce fichier est l'oeuvre d'eleves de Polytech Marseille. Il ne peut etre
 * reproduit, utilise ou modifie sans l'avis express de ses auteurs.
 */

/**
 * @author BENMILOUD--JOSSELIN Alexis <alexis.benmiloud.josselin@gmail.com>
 * @author ALONSO Morgane <alonso.morgane@gmail.com>
 *
 * @version 0.0.1 / 25/01/2016
 * @todo
 * @bug
 */

/**
 * @file comparison.c
 * @brief 
 *
 * Description, sujet traite
 * trace d'execution'
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#include "type_element.h"
#include "function_element.h"

#include "type_example.h"
#include "function_example.h"

#include "type_model.h"
#include "function_model.h"

/*----------------------------------------------------------------------*/
/*                         COMPARISON SECTION                           */
/*----------------------------------------------------------------------*/

/** @brief search
 *
 * Do a research of an element into a list.
 * @param element [int] is the element.
 * @param list [pointer] is the list.
 * @return [int] represent a boolean value.
 */

int search(int number, int list[4])
{
	int index, isInto;
	
	index=0;
	isInto=0;
	while(isInto==0 && number!=list[index] && index<=3)
	{
		index++;
		if(number==list[index])
		{
			isInto=1;
		}
	}
	return isInto;
}
	

/** @brief comparison
 *
 * Do a comparison between the model and an example in order to enlarge,
 * or not, the model.
 * @param model [ptr_model] is the original model.
 * @param example [ptr_example] is the original model.
 * @return model [ptr_model] is the new model.
 */

ptr_model comparison(ptr_model model, ptr_example example)
{
	// Comparison of types.
	model->type=commonFather(model->type, example->type);

	// Comparison of influences.
	if(model->minInfluence>example->influence)
	{
		model->minInfluence=example->influence;
	}
	else if(model->maxInfluence<example->influence)
	{
		model->maxInfluence=example->influence;
	}
	
	// Comparison of alignments.
	if(model->index<3 && search(example->alignment, model->alignment)==0)
	{
		model->index++;
		model->alignment[model->index]=example->alignment;
	}
	return model;
}

//------------------------------------------------------------------------