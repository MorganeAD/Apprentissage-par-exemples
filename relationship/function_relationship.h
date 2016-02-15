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
 * @file function_relationship.h
 * @brief
 *
 * This files gives the prototype of all the function related to relationships.
 */

/*-----------------------------------------------------------------------*/

/** @brief createRelationship
 *
 * Create a new relationship (see the "type_relationship.h" file).
 * @param c1 [character*]
 * @param c2 [character*]
 * @param r [int]
 * @return relationship [ptr_relationship]
 */

ptr_relationship createRelationship(character* c1 , character* c2, int r);

/** @brief getCh1
 *
 * Give the character1 of the relationship.
 * @param r [ptr_relationship]
 * @return r->ch1 [character*]
 */

ptr_character getCh1(ptr_relationship r);

/** @brief getCh2
 *
 * Give the character2 of the relationship.
 * @param r [ptr_relationship]
 * @return r->ch2 [character*]
 */

ptr_character getCh2(ptr_relationship r);

/** @brief getRelation
 *
 * Give the relation of the relationship.
 * @param r [ptr_relationship]
 * @return r->relation [int]
 */

int getRelation(ptr_relationship r);

/** @brief displayRelationship
 *
 * Display the relationship.
 * @param r [ptr_relationship]
 * @return [void]
 */

void displayRelationship(ptr_relationship r);
