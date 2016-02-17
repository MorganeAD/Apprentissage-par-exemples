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

#include "type_row.h"
#include "function_row.h"

#include "comparison.h"

#define NULL 0
#define MAX_ALIGNMENT 4

/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/
/*                             TOOL FUNCTIONS                            */
/*-----------------------------------------------------------------------*/

/** @brief searchAlignment
 *
 * Do a research of an alignment into a row of alignment (see the
 * "type_character.c" file).
 * @param tree [int]
 * @param row [pointer]
 * @return isInto [int]
 */

int searchAlignment(int alignment, int row[])
{
	int i, find;
	
	i=0;
	find=0;
	while(!find && i<MAX_ALIGNMENT)
	{
		if(alignment==row[i])
		{
			find=1;
		}
		else
		{
			i++;
		}
	}
	return find;
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
	if(!searchAlignment(character->alignment, model->alignment))
	{
		model->alignment[model->nbAlign]=character->alignment;
		model->nbAlign++;
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

ptr_model comparison(ptr_model m, ptr_character c)
{
	/* Comparison of types.*/
	m=typeComparison(m, c);

	/* Comparison of influences.*/
	m=influencesComparison(m, c);

	/* Comparison of alignments.*/
	m=alignmentsComparison(m, c);
	
	return m;
}

/** @brief modelGenerator
 *
 * Generate models and add them to the row of models. Add models came from
 * a comparison between a character and existing models. This function will
 * add new models to a row called "modelsRowAux" which will be linked to
 * "modelsRow" at the end of the function. "rowBrowser" will be used to
 * browse the modelsRow (ie. the original models row).
 * @param modelsRow [ptr_row]
 * @param character [ptr_character]
 * @return  [ptr_row]
 */

ptr_row modelGenerator(ptr_row modelsRow, ptr_character character)
{
	ptr_row  modelsRowAux, rowBrowser;
	ptr_model toAdd;

	modelsRowAux=createEmpty();
	rowBrowser=modelsRow;
	while(rowBrowser->next!=NULL)
	{
		toAdd=modelsRow->data;

		/* Comparison of types.*/
		toAdd=typeComparison(toAdd, character);

		/* Add the "toAdd" model to the row of models "modelsRowAux".*/
		addToRow(modelsRowAux, toAdd);

		/* Comparison of influences.*/
		toAdd=influencesComparison(toAdd, character);

		/* Add the "toAdd" model to the row of models "modelsRowAux".*/
		addToRow(modelsRowAux, toAdd);
	
		/* Comparison of alignments.*/
		toAdd=alignmentsComparison(toAdd, character);

		/* Add the "toAdd" model to the row of models "modelsRowAux".*/
		addToRow(modelsRowAux, toAdd);

		/*---------------------------------------------------------------*/
		/* Now, the program will do the same thing but without the
		comparison of alignments.*/
		
		/* Re-initialization of the "toAdd" model.*/
		toAdd=modelsRow->data;

		/* Comparison of influences.*/
		toAdd=influencesComparison(toAdd, character);

		/* Add the "toAdd" model to the row of models "modelsRowAux".*/
		addToRow(modelsRowAux, toAdd);

		/* Comparison of alignments.*/
		toAdd=alignmentsComparison(toAdd, character);

		/* Add the "toAdd" model to the row of models "modelsRowAux".*/
		addToRow(modelsRowAux, toAdd);

		/*---------------------------------------------------------------*/
		/* Now, the program will do the same thing but without the
		comparison of alignments and influences.*/

		/* Re-initialization of the "toAdd" model.*/
		toAdd=modelsRow->data;

		/* Comparison of alignments.*/
		toAdd=alignmentsComparison(toAdd, character);

		/* Add the "toAdd" model to the row of models "modelsRowAux".*/
		addToRow(modelsRowAux, toAdd);

		/* Now the program will do same same comparisons but with the
		following existing model.*/
		rowBrowser=rowBrowser->next;
	}

	/* At the end, the program add the model obtained by the example
	itself.*/
	toAdd=initModel(character);
	addToRow(modelsRowAux, toAdd);

	/* The last thing to do is to link the new row of models to the
	original one.*/
	rowBrowser->next=modelsRowAux;
	return modelsRow;

}
