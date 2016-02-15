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
 * @file type_relationship.h
 * @brief
 *
 * This file describes the "relationship" type.
 */

/*-----------------------------------------------------------------------*/

/** @brief relationship
 *
 * "relationship" structure's definition. relationships will be between to character in an example or a model. An relationship is composed of a
 * character1, a character2 and an int which represents the kind of the relationship (0 : to verse, 1 : to track).
 * @field ch1 [character*]
 * @field ch2 [character*]
 * @field relation [int]
 * @name relationship
 * @pointer ptr_relationship
 */

typedef struct relationship
{
	struct character* ch1;
	struct character* ch2;
	int relation;
}relationship, *ptr_relationship;