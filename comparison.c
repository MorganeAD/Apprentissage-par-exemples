/**
 * Polytech Marseille
 * Case 925 - 163, avenue de Luminy
 * 13288 Marseille CEDEX 9
 *
 * Ce fichier est l'oeuvre d'eleves de Polytech Marseille. Il ne peut etre
 * reproduit, utilise ou modifie sans l'avis express de ses auteurs.
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
 * example.
 */

/*-----------------------------------------------------------------------*/

#include "type_element.h"
#include "function_element.h"

#include "type_example.h"
#include "function_example.h"

#include "type_model.h"
#include "function_model.h"

#include "comparison.h"

#define MAX_ALIGNMENT 4

/*-----------------------------------------------------------------------*/


/** @brief searchAlignment
 *
 * Do a research of an alignment into a list of alignment (see the
 * "type_example.c" file).
 * @param element [int]
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
 * Do a comparison between the model and an example in order to enlarge,
 * or not, the model.
 * @param model [ptr_model]
 * @param example [ptr_example]
 * @return model [ptr_model]
 */

ptr_model comparison(ptr_model model, ptr_example example)
{
	/* Comparison of types.*/
	model->type=commonFather(model->type, example->type);

	/* Comparison of influences.*/
	if(model->minInfluence>example->influence)
	{
		model->minInfluence=example->influence;
	}
	else if(model->maxInfluence<example->influence)
	{
		model->maxInfluence=example->influence;
	}
	
	/* Comparison of alignments.*/
	if(model->index<MAX_ALIGNMENT-1
		&& searchAlignment(example->alignment, model->alignment)==0)
	{
		model->index++;
		model->alignment[model->index]=example->alignment;
	}
	return model;
}

/** @brief comparison
 *
 * Do a comparison between an example and another example in order to
 * generate models.
 * @param example1 [ptr_example]
 * @param example2 [ptr_example]
 * @return model [ptr_model]
 */

ptr_model comparisonBis(ptr_example example1, ptr_example example2)
{
	ptr_model model;

	/* Comparison of types.*/
	

}
