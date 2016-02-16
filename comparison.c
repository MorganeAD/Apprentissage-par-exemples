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
 * @version 0.0.2 / 2016/02/15
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

#include "type_tree.h"
#include "function_tree.h"

#include "type_character.h"
#include "function_character.h"

#include "type_model.h"
#include "function_model.h"

#include "type_list.h"
#include "function_list.h"

#include "comparison.h"

#define NULL 0
#define MAX_ALIGNMENT 4

/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/
/*                             TOOL FUNCTIONS                            */
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

/** @brief typeComparison
 *
 * Do a comparison of types between the model and an character in order to
 * enlarge, or not, the model.
 * @param type1 [ptr_tree]
 * @param type2 [ptr_tree]
 * @return model [ptr_tree]
 */

ptr_model typeComparison(ptr_model model, ptr_character character)
{
	model->type=commonFather(model->type, character->type);
	return model;
}

/** @brief influencesComparison
 *
 * Do a comparison of influences between the model and an character in
 * order to enlarge, or not, the model.
 * @param type1 [ptr_tree]
 * @param type2 [ptr_tree]
 * @return model [ptr_tree]
 */

ptr_model influencesComparison(ptr_model model, ptr_character character)
{
	if(model->minInfluence>character->influence)
	{
		model->minInfluence=character->influence;
	}
	else if(model->maxInfluence<character->influence)
	{
		model->maxInfluence=character->influence;
	}

	return model;
}

/** @brief alignementsComparison
 *
 * Do a comparison of alignments between the model and an character in
 * order to enlarge, or not, the model.
 * @param type1 [ptr_tree]
 * @param type2 [ptr_tree]
 * @return model [ptr_tree]
 */

ptr_model alignmentsComparison(ptr_model model, ptr_character character)
{
	if(model->index<MAX_ALIGNMENT-1
		&& searchAlignment(character->alignment, model->alignment)==0)
	{
		model->index++;
		model->alignment[model->index]=character->alignment;
	}

	return model;
}

/*-----------------------------------------------------------------------*/
/*                         COMPARISON FUNCTIONS                          */
/*-----------------------------------------------------------------------*/

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
	model=typeComparison(model, character);

	/* Comparison of influences.*/
	model=influencesComparison(model, character);

	/* Comparison of alignments.*/
	model=alignmentsComparison(model, character);
	
	return model;
}

/** @brief modelGenerator
 *
 * Generate models and add them to the list of models. Add models came from
 * a comparison between a character and existing models. This function will
 * add new models to a list called "modelsListAux" which will be linked to
 * "modelsList" at the end of the function. "listBrowser" will be used to
 * browse the modelsList (ie. the original models list).
 * @param modelsList [ptr_list]
 * @param character [ptr_character]
 * @return  [ptr_list]
 */

ptr_list modelGenerator(ptr_list modelsList, ptr_character character)
{
	ptr_list  modelsListAux, listBrowser;
	ptr_model toAdd;

	modelsListAux=createEmpty();
	listBrowser=modelsList;
	while(listBrowser->next!=NULL)
	{
		toAdd=modelsList->data;

		/* Comparison of types.*/
		toAdd=typeComparison(toAdd, character);

		/* Add the "toAdd" model to the list of models "modelsListAux".*/
		modelsListAux=addToList(modelsListAux, toAdd);

		/* Comparison of influences.*/
		toAdd=influencesComparison(toAdd, character);

		/* Add the "toAdd" model to the list of models "modelsListAux".*/
		modelsListAux=addToList(modelsListAux, toAdd);
	
		/* Comparison of alignments.*/
		toAdd=alignmentsComparison(toAdd, character);

		/* Add the "toAdd" model to the list of models "modelsListAux".*/
		modelsListAux=addToList(modelsListAux, toAdd);

		/*---------------------------------------------------------------*/
		/* Now, the program will do the same thing but without the
		comparison of alignments.*/
		
		/* Re-initialization of the "toAdd" model.*/
		toAdd=modelsList->data;

		/* Comparison of influences.*/
		toAdd=influencesComparison(toAdd, character);

		/* Add the "toAdd" model to the list of models "modelsListAux".*/
		modelsListAux=addToList(modelsListAux, toAdd);

		/* Comparison of alignments.*/
		toAdd=alignmentsComparison(toAdd, character);

		/* Add the "toAdd" model to the list of models "modelsListAux".*/
		modelsListAux=addToList(modelsListAux, toAdd);

		/*---------------------------------------------------------------*/
		/* Now, the program will do the same thing but without the
		comparison of alignments and influences.*/

		/* Re-initialization of the "toAdd" model.*/
		toAdd=modelsList->data;

		/* Comparison of alignments.*/
		toAdd=alignmentsComparison(toAdd, character);

		/* Add the "toAdd" model to the list of models "modelsListAux".*/
		modelsListAux=addToList(modelsListAux, toAdd);

		/* Now the program will do same same comparisons but with the
		following existing model.*/
		listBrowser=listBrowser->next;
	}

	/* At the end, the program add the model obtained by the example
	itself.*/
	toAdd=initModel(character);
	modelsListAux=addToList(modelsListAux, toAdd);

	/* The last thing to do is to link the new list of models to the
	original one.*/
	listBrowser->next=modelsListAux;
	return modelsList;

}
