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

/** @brief createEmptyExample
 *
 * Create a new emptry example (see the "type_example.h" file).
 * @param [void]
 * @return tmp [ptr_example]
 */

ptr_example createEmptyExample(void);

/** @brief getRelations
 *
 * Give the row of the relationships
 * @param e [ptr-example]
 * @return e->relations [ptr_row]
 */

ptr_row getRelations(ptr_example e);

/** @brief getRelationI
 *
 * Give the relationship at the position i
 * @param e [ptr-example]
 * @param n [int]
 * @return e->relations[n] [ptr_relationship]
 */

ptr_relationship getRelationI(ptr_example e, int n);

/** @brief getCharacterI
 *
 * Give the character at the position i
 * @param e [ptr-example]
 * @param n [int]
 * @return e->relations[i]->data1 [ptr_character]
 */

ptr_character getCharacterI(ptr_example e, int n);

/** @brief addFirstCharacter
 *
 * Add a character into the row characters
 * @param e [ptr_example]
 * @param c [ptr_character]
 * @return tmp [ptr_example]
 */

void addFirstCharacter(ptr_example e, ptr_character c);

/** @brief addSecondCharacter
 *
 * Add a character into the row characters
 * @param e [ptr_example]
 * @param c [ptr_character]
 * @return tmp [ptr_example]
 */

void addSecondCharacter(ptr_example e, ptr_character c, int r);

/** @brief addCharacter
 *
 * Add a character into the row characters
 * @param e [ptr_example]
 * @param c [ptr_character]
 * @return tmp [ptr_example]
 */

void addCharacter(ptr_example e, ptr_character c, int r);

/** @brief displayExample
 *
 * Display the example.
 * @param e [ptr_example]
 * @return [void]
 */

void displayExample(ptr_example e);