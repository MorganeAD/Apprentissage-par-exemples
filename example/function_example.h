/**
 * Polytech Marseille
 * Case 925 - 163, avenue de Luminy
 * 13288 Marseille CEDEX 9
 *
 * Ce fichier est l'oeuvre d'eleves de Polytech Marseille. Il ne peut etre
 * reproduit, utilise ou modifie sans l'avis express de ses auteurs.
 */

/**
 * @author BENMILOUD--JOSSELIN Alexis <alexis.benmiloud.josselin@gmail.com>
 *
 * @version 0.0.1 / 31/01/2016
 * @todo
 * @bug
 */

/**
 * @file function_example.h
 * @brief
 *
 * Give the prototype of all the function related to examples.
 */

/*-----------------------------------------------------------------------*/

/** @brief createExample
 *
 * Create a new example.
 * @param t [ptr_element] is the character's type. 
 * @param i [int] is the example's influence. 
 * @param a [int] is the example's alignment. 
 * @return example [ptr_example] is example's pointer.
 */

ptr_example createExample(ptr_element t, int i, int a);

/** @brief getType
 *
 * Give the type of an example.
 * @param example [ptr_example] is the example. 
 * @return example->type [int] is example's type.
 */

ptr_element getType(ptr_example example);

/** @brief getInfluence
 *
 * Give the influence of an example.
 * @param example [ptr_example] is the example. 
 * @return example->influence [int] is example's influence.
 */

int getInfluence(ptr_example example);

/** @brief getAlignment
 *
 * Give the alignment of an example.
 * @param example [ptr_example] is the example. 
 * @return example->alignment [int] is the example's alignment.
 */

int getAlignment(ptr_example example);

/** @brief displayExample
 *
 * Display the example.
 * @param example [ptr_example] is the example to display.
 * @return [void]
 */

void displayExample(ptr_example example);
