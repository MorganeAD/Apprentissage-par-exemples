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
 * @file function_example.h
 * @brief
 *
 * This files gives the prototype of all the function related to examples.
 */

/*-----------------------------------------------------------------------*/

/** @brief createExample
 *
 * Create a new example (see the "type_example.h" file).
 * @param t [ptr_element]
 * @param i [int]
 * @param a [int]
 * @return example [ptr_example]
 */

ptr_example createExample(ptr_element t, int i, int a);

/** @brief getType
 *
 * Give the type of the example.
 * @param example [ptr_example]
 * @return example->type [int]
 */

ptr_element getType(ptr_example example);

/** @brief getInfluence
 *
 * Give the influence of the example.
 * @param example [ptr_example]
 * @return example->influence [int]
 */

int getInfluence(ptr_example example);

/** @brief getAlignment
 *
 * Give the alignment of the example.
 * @param example [ptr_example]
 * @return example->alignment [int]
 */

int getAlignment(ptr_example example);

/** @brief displayExample
 *
 * Display the example.
 * @param example [ptr_example]
 * @return [void]
 */

void displayExample(ptr_example example);
