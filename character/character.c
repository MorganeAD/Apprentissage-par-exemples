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
 * @version 0.0.1 / 2016/01/31
 * @todo #0000 []
 * @bug #0000 []
 */

/**
 * @file character.c
 * @brief
 *
 * Define all the functions related to characters.
 */

/*-----------------------------------------------------------------------*/

#ifndef STDIO
#define STDIO
#include <stdio.h>
#endif 

#include <malloc.h>

#include "type_tree.h"
#include "function_tree.h"

#include "type_character.h"
#include "function_character.h"

/*-----------------------------------------------------------------------*/

/** @brief createCharacter
 *
 * Create a new character (see the "type_character.h" file).
 * @param t [ptr_tree]
 * @param i [int]
 * @param a [int]
 * @return character [ptr_character]
 */

ptr_character createCharacter(ptr_tree t, int i, int a)
{
	ptr_character character=(ptr_character)malloc(sizeof(character));
	character->type=t;
	character->influence=i;
	character->alignment=a;
	return character;
} 

/** @brief getType
 *
 * Give the type of the character.
 * @param character [ptr_character]
 * @return character->type [int]
 */

ptr_tree getType(ptr_character character)
{
	return character->type;
}

/** @brief getInfluence
 *
 * Give the influence of the character.
 * @param character [ptr_character]
 * @return character->influence [int]
 */

int getInfluence(ptr_character character)
{
	return character->influence;
}

/** @brief getAlignment
 *
 * Give the alignment of the character.
 * @param character [ptr_character]
 * @return character->alignment [int]
 */

int getAlignment(ptr_character character)
{
	return character->alignment;
}

/** @brief displayCharacter
 *
 * Display the character.
 * @param character [ptr_character]
 * @return [void]
 */

void displayCharacter(ptr_character character)
{
	printf("(Type : ");
	switch (getValue(getType(character))) 
	{
		case 1 :
			printf("Person");
			break;
		case 2 :
			printf("Force");
			break;
		case 3 :
			printf("Jedi");
			break;
		case 4 :
			printf("Council");
			break;
		case 5 :
			printf("Sith");
			break;
		case 6 :
			printf("Weak");
			break;
		case 7 :
			printf("Droid");
			break;
		case 8 :
			printf("Combat");
			break;
		case 9 :
			printf("Pacific");
			break;			
		case 10 :
			printf("Bandit");
			break;
		case 11 :
			printf("Hunter");
			break;
		case 12 :
			printf("Senator");
			break;
		default: 
			printf("Unknown");
	}
	printf("; ");
	printf("Influence : %d; ", getInfluence(character));
	printf("Alignment : ");
	switch (getAlignment(character)) 
	{
		case 1 :
			printf("Vilain");
			break;
		case 2 :
			printf("Neutral");
			break;
		case 3 :
			printf("Kind");
			break;
		case 4 :
			printf("Good");
			break;
		default: 
			printf("Unknown");
	}
	printf(")");
}
