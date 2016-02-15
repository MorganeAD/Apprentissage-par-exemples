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
 * @version 0.0.1 / 2016/02/14
 * @todo #0000 []
 * @bug #0000 []
 */

/**
 * @file type_list.c
 * @brief
 *
 * This file describes the "link" structure which is used to create lists.
 */

/*-----------------------------------------------------------------------*/

/** @brief link
 *
 * "list" structure's definition. List are lists's element which will be
 * used to store models (see the type_model.c) and characters (see the
 * type_character.c). The field data is a generic pointer that point to an
 * exmaple or a model.
 * @field data [pointer]
 * @field next [pointer]
 * @name list
 * @pointer ptr_list
 */

typedef struct list
{
	void* data;
	struct list* next;
}list, *ptr_list;
