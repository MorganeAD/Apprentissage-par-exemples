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

#ifndef STDIO
#define STDIO
#include <stdio.h>
#endif 

#include <stdlib.h>
#include <malloc.h>

#include "type_tree.h"
#include "function_tree.h"

#include "type_character.h"
#include "function_character.h"

#include "type_model.h"
#include "function_model.h"

#include "type_relationship.h"
#include "function_relationship.h"

#include "type_list.h"
#include "function_list.h"

#include "type_example.h"
#include "function_example.h"

#include "comparison.h"
#include "class.h"

/*-----------------------------------------------------------------------*/

int main(int argc, char* argv[])
{
	/* Creation of the tree of characters.*/
	initClass();

	printf("Character 1 :\n");
	ptr_character c1=createCharacter(senator, 1, 3);
	displayCharacter(c1);
	printf("\n");

	printf("Character 2 :\n");
	ptr_character c2=createCharacter(droid, 5, 2);
	displayCharacter(c2);
	printf("\n");

	printf("Character 3 :\n");
	ptr_character c3=createCharacter(jedi, 4, 2);
	displayCharacter(c3);
	printf("\n");

	printf("Character 4 :\n");
	ptr_character c4=createCharacter(council, 1, 1);
	displayCharacter(c4);
	printf("\n");

	printf("Character 5 :\n");
	ptr_character c5=createCharacter(bandit, 3, 1);
	displayCharacter(c5);
	printf("\n");

	printf("\nModel initialization...\n\n");
	
	ptr_model model;
	model=initModel(c1);
	displayModel(model);
	printf("\n");

	printf("Comparison between model and character 2...\n");
	comparison(model, c2);
	displayModel(model);
	printf("\n");

	printf("Comparison between model and character 3...\n");
	comparison(model, c3);
	displayModel(model);
	printf("\n");

	printf("Test of the relationship\n");
	ptr_relationship r1;
	r1 = createRelationship(c1, c2, 0);
	displayRelationship(r1);
	printf("\n");

	ptr_relationship r2;
	r2 = createRelationship(c2, c3, 0);
	displayRelationship(r2);
	printf("\n");

	ptr_relationship r3;
	r3 = createRelationship(c3, c4, 0);
	displayRelationship(r3);
	printf("\n");

	ptr_example e1;
	ptr_character cs1[4] = {c1, c2, c3, c4};
	ptr_relationship rs1[3] = {r1, r2, r3};
	e1 = createEmptyExample();
	e1 = addCharactersFromTab(e1, cs1);
	e1 = addRelationsFromTab(e1, rs1);
	displayExample(e1);
	printf("\n");

	return 0;
}
// typedef enum trees {personnage,force,jedi,conseil,sith,samedi,dimanche} Jour_de_Semaine;
