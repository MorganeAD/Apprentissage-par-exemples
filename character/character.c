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

#include <stdio.h>
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
	printf("<type : %d> ", getValue(getType(character)));
	printf("<influence : %d> ", getInfluence(character));
	printf("<alignment : %d>\n", getAlignment(character));
}
