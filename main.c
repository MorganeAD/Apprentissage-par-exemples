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

	int vilain = 1;
	int neutral = 2;
	int kind = 3;
	int good = 4;

	printf("initialization of characters :\n");
	ptr_character c1=createCharacter(sith, 2, vilain);
	displayCharacter(c1);
	printf("\n");

	ptr_character c2=createCharacter(council, 2, good);
	displayCharacter(c2);
	printf("\n");

	ptr_character c3=createCharacter(jedi, 3, kind);
	displayCharacter(c3);
	printf("\n");

	ptr_character c4=createCharacter(council, 3, good);
	displayCharacter(c4);
	printf("\n");

	ptr_character c5=createCharacter(force, 4, kind);
	displayCharacter(c5);
	printf("\n");

	ptr_character c6=createCharacter(jedi, 3, good);
	displayCharacter(c6);
	printf("\n");

	ptr_character c7=createCharacter(bandit, 1, neutral);
	displayCharacter(c7);
	printf("\n\n");

	printf("\nModel initialization...\n");
	
	ptr_stereotype s1;
	s1 = initStereotype(c1);
	displayStereotype(s1);
	printf("\n\n");

	printf("Comparison between model and character 2...\n");
	ptr_stereotype s2;
	s2 = compSC(s1, c2);
	displayStereotype(s2);
	printf("\n\n");

	printf("Comparison between model and character 3...\n");
	ptr_stereotype s3;;
	s3 = compSC(s1, c3);
	displayStereotype(s2);
	printf("\n\n");

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

	printf("+------------------+\n");
	printf("| Test of compReRm |\n");
	printf("+------------------+\n");
	ptr_relationship re1 = createRelationship(c3, c4, 0);
	ptr_relationship re2 = createRelationshipOneObject(c5);
	ptr_relationship re3 = createRelationshipOneObject(c7);
	ptr_relationship re4 = createRelationship(c5, c6, 1);

	ptr_stereotype s4;
	s4 = initStereotype(c5);
	ptr_stereotype s5;
	s5 = initStereotype(c7);
	ptr_stereotype s6;
	s6 = initStereotype(c5);
	ptr_stereotype s7;
	s7 = initStereotype(c6);
	ptr_stereotype s8;
	s8 = initStereotype(c1);
	ptr_stereotype s9;
	s9 = initStereotype(c2);

	ptr_relationship rm1 = createRelationshipOneObject(s4);
	ptr_relationship rm2 = createRelationshipOneObject(s5);
	ptr_relationship rm3 = createRelationship(s6, s7, 1);
	ptr_relationship rm4 = createRelationship(s8, s9, 1);

	ptr_model m2 = createEmptyModel();
	ptr_row l1 = createEmpty();

	printf("-- Test with rel-exemple 2 objects and rel-model 1 object --\n");
	compRmRe(l1, rm1, re1);
	addRelatioshipFromRow(m2, l1);
	displayModel(m2);
	free(l1);
	l1 = createEmpty();
	free(m2);
	m2 = createEmptyModel();
	printf("\n\n");

	printf("-- Test with rel-exemple 1 object and rel-model 1 object --\n");
	compRmRe(l1, rm2, re2);
	addRelatioshipFromRow(m2, l1);
	displayModel(m2);
	free(l1);
	l1 = createEmpty();
	free(m2);
	m2 = createEmptyModel();
	printf("\n\n");

	printf("-- Test with rel-exemple 1 object and rel-model 2 objects --\n");
	compRmRe(l1, rm3, re3);
	addRelatioshipFromRow(m2, l1);
	displayModel(m2);
	free(l1);
	l1 = createEmpty();
	free(m2);
	m2 = createEmptyModel();
	printf("\n\n");

	printf("-- Test with rel-exemple 2 object and rel-model 2 objects with diff relationship --\n");
	compRmRe(l1, rm3, re1);
	addRelatioshipFromRow(m2, l1);
	displayModel(m2);
	free(l1);
	l1 = createEmpty();
	free(m2);
	m2 = createEmptyModel();
	printf("\n\n");

	printf("-- Test with rel-exemple 2 object and rel-model 2 objects with same relationship --\n");
	compRmRe(l1, rm4, re4);
	addRelatioshipFromRow(m2, l1);
	displayModel(m2);
	free(l1);
	l1 = createEmpty();
	free(m2);
	m2 = createEmptyModel();
	printf("\n\n");

	return 0;
}
