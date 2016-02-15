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
 * @file type_tree.h
 * @brief
 *
 * This file describes the "tree" type.
 */

/*-----------------------------------------------------------------------*/

/** @brief tree
 *
 * "tree" structure's definition. It will be use to create a tree which
 * will describe all the character's types. The field value describes the
 * character's type.
 * @field value [int]
 * @field father [tree*]
 * @name tree
 * @pointer ptr_tree
 */

typedef struct tree
{
	int value;
	struct tree* father;
}tree , *ptr_tree;
