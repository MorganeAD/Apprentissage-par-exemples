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
 * @todo #0000 []
 * @bug #0000 []
 */

/**
 * @file function_stereotype.c
 * @brief 
 *
 * This file contains the prototype of all functions related to stereotypes.
 */

/*-----------------------------------------------------------------------*/

/** @brief createStereotype
 *
 * Create the first stereotype from parameters
 * @param t [ptr_tree]
 * @param minI [int]
 * @param maxI [int]
 * @param as [int[]]
 * @return stereotype [ptr_stereotype]
 */

ptr_stereotype createStereotype(ptr_tree t, int minI, int maxI, int as[]);

/** @brief initstereotype
 *
 * Create the first stereotype from an character.
 * @param character [ptr_character]
 * @return stereotype [ptr_stereotype]
 */

ptr_stereotype initStereotype(ptr_character c);

/** @brief displaystereotype
 *
 * Display the stereotype.
 * @param stereotype [ptr_stereotype]
 * @return [void]
 */

void displayStereotype(ptr_stereotype s);

/** @brief getStereotypeType
 *
 * Give the type of the stereotype.
 * @param s [ptr_stereotype]
 * @return s->type [ptr_tree]
 */

ptr_tree getStereotypeType(ptr_stereotype s);
/** @brief getMinInfluence
 *
 * Give the minInfluence of the stereotype.
 * @param s [ptr_stereotype]
 * @return s->minInfluence [int]
 */

int getMinInfluence(ptr_stereotype s);

/** @brief getMaxInfluence
 *
 * Give the maxInfluence of the stereotype.
 * @param s [ptr_stereotype]
 * @return s->maxInfluence [int]
 */

int getMaxInfluence(ptr_stereotype s);

/** @brief getAlignments
 *
 * Give the array of alignement.
 * @param s [ptr_stereotype]
 * @return s->alignment [int[]]
 */

int* getAlignments(ptr_stereotype s);

/** @brief sameTypes
 *
 * Tell if two stereotypes have the same type.
 * @param s1 [ptr_stereotype]
 * @param s2 [ptr_stereotype]
 * @return same [int]
 */

int sameTypes(ptr_stereotype s1, ptr_stereotype s2);
/** @brief sameInfluences
 *
 * Tell if two stereotypes have the same influences.
 * @param s1 [ptr_stereotype]
 * @param s2 [ptr_stereotype]
 * @return same [int]
 */

int sameInfluences(ptr_stereotype s1, ptr_stereotype s2);

/** @brief sameAlignments
 *
 * Tell if two stereotypes have the same alignments.
 * @param s1 [ptr_stereotype]
 * @param s2 [ptr_stereotype]
 * @return ok [int]
 */
 
int sameAlignments(ptr_stereotype s1, ptr_stereotype s2);

/** @brief equalStereotypes
 *
 * Tell if two stereotype are equal.
 * @param s1 [ptr_stereotype]
 * @param s2 [ptr_stereotype]
 * @return areEqual [int]
 */

int equalStereotypes(ptr_stereotype s1, ptr_stereotype s2);
