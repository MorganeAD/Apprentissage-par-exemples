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

/** @brief getCharacterI
 *
 * Give the character at the position i
 * @param e [ptr-example]
 * @param i [int]
 * @return e->characters[i] [ptr_character]
 */

ptr_character getCharacterI(ptr_example e, int n);

/** @brief getRelationI
 *
 * Give the relationship at the position i
 * @param e [ptr-example]
 * @param i [int]
 * @return e->relations[i] [ptr_relationship]
 */

ptr_relationship getRelationI(ptr_example e, int n);
/** @brief addCharacter
 *
 * Add a character into the list characters
 * @param e [ptr_example]
 * @param c [ptr_character]
 * @return tmp [ptr_example]
 */

ptr_example addCharacter(ptr_example e, ptr_character c);

/** @brief addRelation
 *
 * Add a relationship into the list relations
 * @param e [ptr_example]
 * @param r [ptr_relationship]
 * @return tmp [ptr_example]
 */

ptr_example addRelation(ptr_example e, ptr_relationship r);

/** @brief addCharactersFromTab
 *
 * Add characters from a array into the list characters
 * @param e [ptr_example]
 * @param cs [ptr_character[]]
 * @return tmp [ptr_example]
 */

ptr_example addCharactersFromTab(ptr_example e, ptr_character cs[]);

/** @brief addRelationsFromTab
 *
 * Add relationships from a array into the list relations
 * @param e [ptr_example]
 * @param rs [ptr_relationship[]]
 * @return tmp [ptr_example]
 */

ptr_example addRelationsFromTab(ptr_example e, ptr_relationship rs[]);

/** @brief displayExample
 *
 * Display the example.
 * @param e [ptr_example]
 * @return [void]
 */

void displayExample(ptr_example e);