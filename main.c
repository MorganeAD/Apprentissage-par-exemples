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

#ifndef LSTDIO
#define LSTDIO
#include <stdio.h>
#endif 

#ifndef LSTDLIB
#define LSTDLIB
#include <stdlib.h>
#endif

#ifndef LTREE
#define LTREE
#include "type_tree.h"
#include "function_tree.h"
#endif 

#ifndef LLIST
#define LLIST
#include "type_list.h"
#include "function_list.h"
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

#ifndef LRLT
#define LRLT
#include "type_relationship.h"
#include "function_relationship.h"
#endif 

#ifndef LEXP
#define LEXP
#include "type_example.h"
#include "function_example.h"
#endif 

#ifndef COMP
#define COMP
#include "comparison.h"
#endif 
 
#ifndef CLASS
#define CLASS
#include "class.h"
#endif 

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
	
	ptr_model m1;
	m1=initModel(c1);
	displayModel(m1);
	printf("\n");

	printf("Comparison between model and character 2...\n");
	comparison(m1, c2);
	displayModel(m1);
	printf("\n");

	printf("Comparison between model and character 3...\n");
	comparison(m1, c3);
	displayModel(m1);
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
	// ptr_character cs1[4] = {c1, c2, c3, c4};
	// ptr_relationship rs1[3] = {r1, r2, r3};
	e1 = createEmptyExample();
	// e1 = addCharactersFromTab(e1, cs1);
	// e1 = addRelationsFromTab(e1, rs1);
	// displayExample(e1);

	e1 = addCharacter(e1, c1);
	e1 = addCharacter(e1, c2);
	e1 = addCharacter(e1, c3);
	e1 = addCharacter(e1, c4);
	e1 = addRelation(e1, r1);
	e1 = addRelation(e1, r2);
	e1 = addRelation(e1, r3);	


	displayExample(e1);
	printf("\n");

	displayCharacter(getCharacterI(e1, 3));
	printf("\n");

	return 0;
}