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
 * @param element1 [void*]
 * @param element2 [void*]
 * @param relation [int]
 * @return tmp [ptr_relationship]
 */

ptr_relationship createRelationship(void* element1, void* element2, int r);

/** @brief createRelationshipOneObject
 *
 * Create a new relationship with one object using the "-1" relation (ie.
 * "no relation") (see the "type_relationship.h" file).
 * @param element1 [void*]
 * @return tmp [ptr_relationship]
 */

ptr_relationship createRelationshipOneObject(void* element1);

/** @brief getData1
 *
 * Give the data1 of the relationship.
 * @param relation [ptr_relationship]
 * @return relation->data1 [character*]
 */

void* getData1(ptr_relationship relation);

/** @brief getData2
 *
 * Give the data2 of the relationship.
 * @param relation [ptr_relationship]
 * @return relation->data2 [character*]
 */

void* getData2(ptr_relationship relation);


/** @brief getRelation
 *
 * Give the relation of the relationship.
 * @param r [ptr_relationship]
 * @return r->relation [int]
 */

int getRelation(ptr_relationship r);

/** @brief isRelationshipOneObject
 *
 * Tell is a relationship is composed of one object, ie. there is no
 * relation in the relationship.
 * @param r [ptr_relationship]
 * @return answer [int]
 */

int isRelationshipOneObject(ptr_relationship r);

/** @brief modifyRelation
 *
 * Change a relation of one object by adding another object. An object can
 * be a model or a character.
 * @param object [void*]
 * @param r [int]
 * @return  [void]
 */

void modifyRelation(ptr_relationship r, void* element, int newRelation);
