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
 * Main file of the project. It contains the benchmark of the project.
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

#define SETVERT printf("\e[32m");
#define SETJAUNE printf("\e[33m");
#define SETBLANC printf("\e[0m");
#define SETROUGE printf("\e[31m");
#define SETBLEU printf("\e[34m");

/*-----------------------------------------------------------------------*/

int main(int argc, char* argv[])
{
	char checkpoint;
	int vilain, neutral, kind, good;

	/* Definition of alignments : */
	vilain=1;
	neutral=2;
	kind=3;
	good=4;

	/* Creation of the tree of characters : */
	initClass();
	SETVERT
	printf("Initialization of characters :\n");
	SETBLANC
	ptr_character c1=createCharacter(sith, 2, vilain);
	displayCharacter(c1);
	printf("\n");
	ptr_character c2=createCharacter(council, 4, good);
	displayCharacter(c2);
	printf("\n");
	ptr_character c3=createCharacter(jedi, 3, kind);
	displayCharacter(c3);
	printf("\n");
	ptr_character c4=createCharacter(council, 4, neutral);
	displayCharacter(c4);
	printf("\n");
	ptr_character c5=createCharacter(weak, 5, kind);
	displayCharacter(c5);
	printf("\n");
	ptr_character c6=createCharacter(person, 1, good);
	displayCharacter(c6);
	printf("\n");
	ptr_character c7=createCharacter(combat, 3, vilain);
	displayCharacter(c7);
	printf("\n");
	ptr_character c8=createCharacter(droid, 5, vilain);
	displayCharacter(c8);
	printf("\n");
	ptr_character c9=createCharacter(hunter, 2, kind);
	displayCharacter(c9);
	printf("\n");
	ptr_character c10=createCharacter(pacific, 5, vilain);
	displayCharacter(c10);
	printf("\n");
	ptr_character c11=createCharacter(combat, 2, good);
	displayCharacter(c11);
	printf("\n");
	ptr_character c12=createCharacter(bandit, 1, vilain);
	displayCharacter(c12);
	printf("\n");
	ptr_character c13=createCharacter(droid, 1, vilain);
	displayCharacter(c13);
	printf("\n");
	ptr_character c14=createCharacter(person, 1, vilain);
	displayCharacter(c14);
	printf("\n");
	ptr_character c15=createCharacter(person, 2, vilain);
	displayCharacter(c15);
	printf("\n");
	ptr_character c16=createCharacter(force, 1, kind);
	displayCharacter(c16);
	printf("\n");
	ptr_character c17=createCharacter(force, 1, good);
	displayCharacter(c17);
	printf("\n");
	ptr_character c18=createCharacter(force, 1, neutral);
	displayCharacter(c18);
	printf("\n");
	ptr_character c19=createCharacter(hunter, 1, neutral);
	displayCharacter(c19);
	printf("\n");
	ptr_character c20=createCharacter(sith, 2, vilain);
	displayCharacter(c20);
	printf("\n");
	ptr_character c21=createCharacter(combat, 2, good);
	displayCharacter(c21);
	printf("\n");
	ptr_character c22=createCharacter(sith, 1, vilain);
	displayCharacter(c22);
	printf("\n");
	ptr_character c23=createCharacter(droid, 1, vilain);
	displayCharacter(c23);
	printf("\n");
	ptr_character c24=createCharacter(person, 1, vilain);
	displayCharacter(c24);
	printf("\n");
	ptr_character c25=createCharacter(weak, 2, kind);
	displayCharacter(c25);
	printf("\n");
	ptr_character c26=createCharacter(force, 1, kind);
	displayCharacter(c26);
	printf("\n");
	ptr_character c27=createCharacter(force, 1, good);
	displayCharacter(c27);
	printf("\n");
	ptr_character c28=createCharacter(force, 1, neutral);
	displayCharacter(c28);
	printf("\n");
	ptr_character c29=createCharacter(hunter, 1, neutral);
	displayCharacter(c29);
	printf("\n");
	ptr_character c30=createCharacter(sith, 2, vilain);
	displayCharacter(c30);
	printf("\n");

	/*-------------------------------------------------------------------*/
	/*                                TEST 1                             */
	/*-------------------------------------------------------------------*/

	SETVERT
	printf("Preparing some stereotypes...\n");
	ptr_stereotype s1;
	s1 = initStereotype(c1);
	ptr_stereotype s2;
	s2 = compSC(s1, c2);
	ptr_stereotype s3;
	s3=initStereotype(c3);
	ptr_stereotype s4;
	s4 = compSC(s3, c4);

	printf("Preparing the examples...\n");
	ptr_example e1;
	e1 = createEmptyExample();
	addFirstCharacter(e1, c1);
	addSecondCharacter(e1, c2, 0);
	addCharacter(e1, c4, 1);
	addCharacter(e1, c5, 1);
	addCharacter(e1, c6, 0);
	addCharacter(e1, c7, 1);
	addCharacter(e1, c8, 0);
	addCharacter(e1, c9, 0);
	addCharacter(e1, c10, 1);
	addCharacter(e1, c11, 1);
	addCharacter(e1, c12, 0);
	addCharacter(e1, c13, 1);
	addCharacter(e1, c14, 1);
	addCharacter(e1, c15, 1);
	addCharacter(e1, c16, 0);
	addCharacter(e1, c17, 0);
	addCharacter(e1, c18, 0);
	addCharacter(e1, c19, 1);
	addCharacter(e1, c20, 1);
	addCharacter(e1, c21, 1);
	addCharacter(e1, c22, 0);
	addCharacter(e1, c23, 1);
	addCharacter(e1, c24, 1);
	addCharacter(e1, c25, 1);
	addCharacter(e1, c26, 0);
	addCharacter(e1, c27, 0);
	addCharacter(e1, c28, 0);
	addCharacter(e1, c29, 1);
	addCharacter(e1, c30, 1);

	addCharacter(e1, c10, 1);
	addCharacter(e1, c11, 1);
	addCharacter(e1, c12, 0);
	addCharacter(e1, c13, 1);
	addCharacter(e1, c14, 1);
	addCharacter(e1, c15, 1);
	addCharacter(e1, c16, 0);
	addCharacter(e1, c17, 0);
	addCharacter(e1, c18, 0);
	addCharacter(e1, c19, 1);
	addCharacter(e1, c20, 1);
	addCharacter(e1, c21, 1);
	addCharacter(e1, c22, 0);
	addCharacter(e1, c23, 1);
	addCharacter(e1, c24, 1);
	addCharacter(e1, c25, 1);
	addCharacter(e1, c26, 0);
	addCharacter(e1, c27, 0);
	addCharacter(e1, c28, 0);
	addCharacter(e1, c29, 1);
	addCharacter(e1, c30, 1);

	addCharacter(e1, c10, 1);
	addCharacter(e1, c11, 1);
	addCharacter(e1, c12, 0);
	addCharacter(e1, c13, 1);
	addCharacter(e1, c14, 1);
	addCharacter(e1, c15, 1);
	addCharacter(e1, c16, 0);
	addCharacter(e1, c17, 0);
	addCharacter(e1, c18, 0);
	addCharacter(e1, c19, 1);
	addCharacter(e1, c20, 1);
	addCharacter(e1, c21, 1);
	addCharacter(e1, c22, 0);
	addCharacter(e1, c23, 1);
	addCharacter(e1, c24, 1);
	addCharacter(e1, c25, 1);
	addCharacter(e1, c26, 0);
	addCharacter(e1, c27, 0);
	addCharacter(e1, c28, 0);
	addCharacter(e1, c29, 1);
	addCharacter(e1, c30, 1);

	printf("Preparing the models...\n");
	SETJAUNE
	ptr_relationship r1;
	r1 = createRelationship(s1, s2, 0);
	ptr_relationship r2;
	r2 = createRelationshipOneObject(s3);
	ptr_relationship r3;
	r3 = createRelationship(s3, s4, 1);
	ptr_relationship r4;
	r4 = createRelationship(s1, s4, 0);
	ptr_model m1;
	m1 = createEmptyModel();
	addRelatioship(m1, r1);
	addRelatioship(m1, r2);
	addRelatioship(m1, r3);
	addRelatioship(m1, r4);
	printf("L'exemple : \n");
	displayExample(e1);
	printf("\n\n");

	printf("Le modèle : \n");
	displayModel(m1);
	printf("\n\n");
	SETBLANC
	/* CHECKPOINT ! */
	checkpoint=scanf("%c", &checkpoint);

	/* Main function of the project. */
	SETJAUNE
	printf("Comparing the example with the model...\n");
	SETBLANC
	compEM(e1, m1);
	printf("La nouvelle liste de modèles après toutes les comparaisons :\n");
	displayModel(m1);
	printf("\n");

	return 0;
}
