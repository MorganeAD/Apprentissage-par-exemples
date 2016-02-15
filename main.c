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
 * @todo #0000
 * @bug #0000 [FIXED] : line 320 : Erreur de segmentation (core dumped)
 * after return(0).
 */

/**
 * @file main.c
 * @brief
 *
 * Main file of the project.
 */

/*-----------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "type_tree.h"
#include "function_tree.h"

#include "type_character.h"
#include "function_character.h"

#include "type_model.h"
#include "function_model.h"

#include "comparison.h"
#include "class.h"

/*-----------------------------------------------------------------------*/

int main(int argc, char* argv[])
{
	/* Creation of the tree of characters.*/
	initClass();

	printf("Character 1 :\n");
	ptr_character e1=createCharacter(senator, 1, 3);
	displayCharacter(e1);

	printf("Character 2 :\n");
	ptr_character e2=createCharacter(droid, 5, 2);
	displayCharacter(e2);

	printf("Character 3 :\n");
	ptr_character e3=createCharacter(jedi, 4, 2);
	displayCharacter(e3);

	printf("\nModel initialization...\n\n");
	
	ptr_model model;
	model=initModel(e1);
	displayModel(model);
	
	printf("Comparison between model and character 2...\n");
	comparison(model, e2);
	displayModel(model);

	printf("Comparison between model and character 3...\n");
	comparison(model, e3);
	displayModel(model);

	return 0;
}
// typedef enum trees {personnage,force,jedi,conseil,sith,samedi,dimanche} Jour_de_Semaine;
