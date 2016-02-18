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

#ifndef LROW
#define LROW
#include "type_row.h"
#include "function_row.h"
#endif 

#ifndef LCHR
#define LCHR
#include "type_character.h"
#include "function_character.h"
#endif 

#ifndef LSTR
#define LSTR
#include "type_stereotype.h"
#include "function_stereotype.h"
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

#ifndef LMDL
#define LMDL
#include "type_model.h"
#include "function_model.h"
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
	
	ptr_stereotype s1;
	s1=initStereotype(c1);
	displayStereotype(s1);
	printf("\n");

	printf("Comparison between model and character 2...\n");
	compSC(s1, c2);
	displayStereotype(s1);
	printf("\n");

	printf("Comparison between model and character 3...\n");
	ptr_stereotype s2;
	s2=initStereotype(c1);
	compSC(s2, c3);
	displayStereotype(s2);
	printf("\n");

	printf("Test of the example\n");

	ptr_example e1;
	e1 = createEmptyExample();
	displayExample(e1);
	printf("\n\n");
	addFirstCharacter(e1, c1);
	displayExample(e1);
	printf("\n\n");
	addSecondCharacter(e1, c2, 0);
	displayExample(e1);
	printf("\n\n");
	addCharacter(e1, c3, 1);
	displayExample(e1);
	printf("\n\n");
	addCharacter(e1, c4, 0);
	displayExample(e1);
	printf("\n\n");

	printf("Test of the model\n");
	ptr_relationship r1;
	r1 = createRelationship(s1, s2, 0);

	ptr_relationship r2;
	r2 = createRelationshipOneObject(s1);

	ptr_relationship r3;
	r3 = createRelationship(s1, s1, 0);

	ptr_relationship r4;
	r4 = createRelationshipOneObject(s2);

	ptr_model m1;
	m1 = createEmptyModel();
	displayModel(m1);
	printf("\n\n");
	addRelatioship(m1, r1);
	displayModel(m1);
	printf("\n\n");
	addRelatioship(m1, r2);
	displayModel(m1);
	printf("\n\n");
	addRelatioship(m1, r3);
	displayModel(m1);
	printf("\n\n");
	addRelatioship(m1, r4);
	displayModel(m1);
	printf("\n\n");

	printf("Test of the compCC\n");
	displayStereotype(compCC(c1, c3));
	printf("\n");
	printf("\n");

	printf("Test of deleteRelation from a row\n");
	deleteRelationshipInModRelRow(m1, r4);
	displayModel(m1);
	printf("\n");
	printf("\n");



	printf("Test of addToRowFromRow\n");

	ptr_row rs1;
	rs1 = createEmpty();
	addToRow(rs1, r1);
	addToRow(rs1, r2);
	addToRow(rs1, r3);
	addToRow(rs1, r4);

	addRelatioshipFromRow(m1, rs1);
	displayModel(m1);
	printf("\n");
	printf("\n");

	return 0;
}
