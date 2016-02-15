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
 * @file example.c
 * @brief
 *
 * Define all the functions related to examples.
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

#include "type_relationship.h"
#include "function_relationship.h"

#include "type_example.h"
#include "function_example.h"

// #include "type_list.h"
// #include "function_list.h"

/*-----------------------------------------------------------------------*/

/** @brief createEmptyExample
 *
 * Create a new emptry example (see the "type_example.h" file).
 * @param [void]
 * @return tmp [ptr_example]
 */

ptr_example createEmptyExample(void)
{
	ptr_example tmp=(ptr_example)malloc(sizeof(example));
	tmp->characters=createEmpty();
	tmp->relations=createEmpty();
	return tmp;
} 

/** @brief getCharacterI
 *
 * Give the character at the position i
 * @param e [ptr-example]
 * @param i [int]
 * @return e->characters[i] [ptr_character]
 */

ptr_character getCharacterI(ptr_example e, int n)
{
	return (ptr_character) getElementI(e->characters, n);
}

/** @brief getRelationI
 *
 * Give the relationship at the position i
 * @param e [ptr-example]
 * @param i [int]
 * @return e->relations[i] [ptr_relationship]
 */

ptr_relationship getRelationI(ptr_example e, int n)
{
	return (ptr_relationship) getElementI(e->relations, n);
}

/** @brief addCharacter
 *
 * Add a character into the list characters
 * @param e [ptr_example]
 * @param c [ptr_character]
 * @return tmp [ptr_example]
 */

ptr_example addCharacter(ptr_example e, ptr_character c)
{
	ptr_example tmp = createEmptyExample();
	tmp->characters = addToList(tmp->characters, c);
	return tmp;
}

/** @brief addRelation
 *
 * Add a relationship into the list relations
 * @param e [ptr_example]
 * @param r [ptr_relationship]
 * @return tmp [ptr_example]
 */

ptr_example addRelation(ptr_example e, ptr_relationship r)
{
	ptr_example tmp = createEmptyExample();
	tmp->relations = addToList(tmp->relations, r);
	return tmp;
}

/** @brief addCharactersFromTab
 *
 * Add characters from a array into the list characters
 * @param e [ptr_example]
 * @param cs [ptr_character[]]
 * @return tmp [ptr_example]
 */

ptr_example addCharactersFromTab(ptr_example e, ptr_character* cs)
{
	ptr_example tmp = createEmptyExample();
	int i;
	for (i = 0; i < (sizeof(cs)/sizeof(cs[0])); i++)
	{
		tmp->characters = addToList(tmp->characters, cs[i]);
	}
	return tmp;
}

/** @brief addRelationsFromTab
 *
 * Add relationships from a array into the list relations
 * @param e [ptr_example]
 * @param rs [ptr_relationship[]]
 * @return tmp [ptr_example]
 */

ptr_example addRelationsFromTab(ptr_example e, ptr_relationship* rs)
{
	ptr_example tmp = createEmptyExample();
	int i;
	for (i = 0; i < (sizeof(rs)/sizeof(rs[0])); i++)
	{
		tmp->relations = addToList(tmp->relations, rs[i]);
	}
	return tmp;
}

/** @brief displayExample
 *
 * Display the example.
 * @param e [ptr_example]
 * @return [void]
 */

void displayExample(ptr_example e)
{
	ptr_list tmp;
	tmp = e->characters;
	printf("Characters : \n");
	while(!isEmpty(tmp))
	{
		displayCharacter(headList(tmp));
		tmp=nextList(tmp);
	}
	tmp = e->relations;
	printf("Relationships : \n");
	while(!isEmpty(tmp))
	{
		displayRelationship((relationship*)headList(tmp));
		tmp=nextList(tmp);
	}
}
