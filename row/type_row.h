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
 * @version 0.0.1 / 2016/02/17
 * @todo #0000 []
 * @bug #0000 []
 */

/**
 * @file type_row.c
 * @brief
 *
 * This file describes the "link" structure which is used to create rows.
 */

/*-----------------------------------------------------------------------*/

/** @brief typeFile
 *
 * "row" structure's definition.
 * exmaple or a model.
 * @field data [void*]
 * @field next [pointer]
 * @name row
 * @pointer ptr_row
 */

typedef struct typeRow
{
	void* data;
	struct typeRow* next;
}row , *ptr_row ;
