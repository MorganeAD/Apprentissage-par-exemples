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
 * @file type_model.h
 * @brief 
 *
 * This file describes the "model" structure.
 */

/*-----------------------------------------------------------------------*/

/** @brief model
 *
 * "model" structure's definition. A model is composed of a character type
 * called "type", a minimal and a maximal influence and an array of
 * alignments.
 * @field type [tree *]
 * @field minInfluence [int]
 * @field maxInfluence [int]
 * @field alignment [pointer]
 * @field index [int]
 * @name model
 * @pointer ptr_model
 */

typedef struct model
{
	struct tree *type;
	int minInfluence;
	int maxInfluence;
	int alignment[4];
	int index;
}model, *ptr_model;
