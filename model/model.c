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
 * @file model.c
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
/*                            MODEL SECTION                             */
/*----------------------------------------------------------------------*/



/** @brief initModel
 *
 * Create the first model.
 * @param example [ptr_example] is the future new model.
 * @return model [ptr_model] is the new model.
 */

ptr_model initModel(ptr_example firstExample)
{
	ptr_model model=(ptr_model)malloc(sizeof(model));

	model->type=firstExample->type;
	model->minInfluence=firstExample->influence;
	model->maxInfluence=firstExample->influence;
	model->alignment[0]=firstExample->alignment;
	model->index=0;

	return model;
}

/** @brief displayModel
 *
 * Display the model.
 * @param model [ptr_model] is the model to display.
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