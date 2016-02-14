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
 * @todo #0000
 * @bug #0000 [FIXED] : line 320 : Erreur de segmentation (core dumped)
 * after return(0).
 */

/**
 * @file main.c
 * @brief
 *
 * 
 */

/*-----------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "type_element.h"
#include "function_element.h"

#include "type_example.h"
#include "function_example.h"

#include "type_model.h"
#include "function_model.h"

#include "comparison.h"
#include "class.h"

/*-----------------------------------------------------------------------*/

int main(int argc, char* argv[])
{
	/* Creation of the tree of characters.*/
	initClass();

	printf("Example 1 :\n");
	ptr_example e1=createExample(senator, 1, 3);
	displayExample(e1);

	printf("Example 2 :\n");
	ptr_example e2=createExample(droid, 5, 2);
	displayExample(e2);

	printf("Example 3 :\n");
	ptr_example e3=createExample(jedi, 4, 2);
	displayExample(e3);

	printf("\nModel initialization...\n\n");
	
	ptr_model model;
	model=initModel(e1);
	displayModel(model);
	
	printf("Comparison between model and example 2...\n");
	comparison(model, e2);
	displayModel(model);

	printf("Comparison between model and example 3...\n");
	comparison(model, e3);
	displayModel(model);

	return 0;
}
// typedef enum elements {personnage,force,jedi,conseil,sith,samedi,dimanche} Jour_de_Semaine;
