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
 * @version 0.0.1 / 2016/02/13
 * @todo #0000 []
 * @bug #0000 []
 */

/**
 * @file function_list.h
 * @brief
 *
 * This file contains the prototype of all functions related to lists.
 */

/*-----------------------------------------------------------------------*/

/** @brief createEmpty
 *
 * Create the empty list.
 * @param [void]
 * @return NULL [ptr_list]
 */

ptr_list createEmpty(void);

/** @brief isEmpty
 *
 * Tell if the list is empty.
 * @param list [ptr_list]
 * @return empty [int]
 */

int isEmpty(ptr_list list);

/** @brief addToList
 *
 * Add the element to the list.
 * @param list [ptr_list]
 * @param element [pointer]
 * @return pointer [ptr_list]
 */

ptr_list addToList(ptr_list list, void *element);

/** @brief headList
 *
 * Give the data of the first link of the list.
 * @param list [ptr_list]
 * @return list->data [pointer]
 */

int headList(ptr_list list);

/** @brief nextList
 *
 * Give the following link of the list.
 * @param list [ptr_list]
 * @return list->next [ptr_list]
 */

ptr_list nextList(ptr_list list);

/** @brief displayList
 *
 * Display the element of the list.
 * @param list [ptr_list]
 * @return [void]
 */

void displayList(ptr_list list, char type);

/** @brief lengthList
 *
 * Calculate the length of the list.
 * @param list [ptr_list]
 * @return length [int]
 */

int lengthList(ptr_list list);

/** @brief copyListAux
 *
 * copyList's auxiliary function.
 * @param list [ptr_list]
 * @return copiedList [ptr_list]
 */

ptr_list copyListAux(ptr_list list);

/** @brief copyList
 *
 * Give a copy of the list.
 * @param list [ptr_list]
 * @return copiedList [ptr_list]
 */

ptr_list copyList(ptr_list list);

/** @brief searchListe
 *
 * Tell if an element is in the list or not. If it is, the function will
 * return a list with this element as first link, otherwise, it will return
 * the empty list.
 * @param list [ptr_list]
 * @param element [pointer]
 * @return list [ptr_list]
 */

ptr_list searchList(ptr_list list, void *element);

/** @brief delete
 *
 * Delete an element of the list, if possible.
 * @param list [ptr_list]
 * @param element [pointer]
 * @return list [ptr_list]
 */

ptr_list delete(ptr_list list, void *element);
