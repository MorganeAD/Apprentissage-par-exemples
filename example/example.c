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

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "type_element.h"
#include "function_element.h"

#include "type_example.h"
#include "function_example.h"

/*-----------------------------------------------------------------------*/

/** @brief createExample
 *
 * Create a new example (see the "type_example.h" file).
 * @param t [ptr_element]
 * @param i [int]
 * @param a [int]
 * @return example [ptr_example]
 */

ptr_example createExample(ptr_element t, int i, int a)
{
	ptr_example example=(ptr_example)malloc(sizeof(example));
	example->type=t;
	example->influence=i;
	example->alignment=a;
	return example;
} 

/** @brief getType
 *
 * Give the type of the example.
 * @param example [ptr_example]
 * @return example->type [int]
 */

ptr_element getType(ptr_example example)
{
	return example->type;
}

/** @brief getInfluence
 *
 * Give the influence of the example.
 * @param example [ptr_example]
 * @return example->influence [int]
 */

int getInfluence(ptr_example example)
{
	return example->influence;
}

/** @brief getAlignment
 *
 * Give the alignment of the example.
 * @param example [ptr_example]
 * @return example->alignment [int]
 */

int getAlignment(ptr_example example)
{
	return example->alignment;
}

/** @brief displayExample
 *
 * Display the example.
 * @param example [ptr_example]
 * @return [void]
 */

void displayExample(ptr_example example)
{
	printf("<type : %d> ", getValue(getType(example)));
	printf("<influence : %d> ", getInfluence(example));
	printf("<alignment : %d>\n", getAlignment(example));
}
