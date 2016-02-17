/**
 * Polytech Marseille
 * Case 925 - 163, avenue de Luminy
 * 13288 Marseille CEDEX 9
 *
 * This row is the work of students from Polytech Marseille. It can not be
 * reproduced, modified or used without the express opinion of its authors.
 */

/**
 * @author ALONSO Morgane <alonso.morgane@gmail.com>
 * @author BENMILOUD--JOSSELIN Alexis <alexis.benmiloud.josselin@gmail.com>
 *
 * @version 0.0.1 / 2016/02/17
 * @todo #0000 [] Adapt functions to models and characters.
 * @bug #0000 []
 */

/**
 * @row function_row.c
 * @brief
 *
 * This file give the prototype of all the functions related to rows.
 */

/*-----------------------------------------------------------------------*/

/** @brief createEmpty
 *
 * Create the empty row.
 * @param [void]
 * @return NULL [ptr_list]
 */

ptr_row createEmpty();

/** @brief isEmpty
 *
 * Tell if the row is empty.
 * @param l [ptr_row]
 * @return l->valeur==NULL && l->next==NULL [int]
 */

int isEmpty(ptr_row l);

/** @brief getData
 *
 * Give the data of the first list of the list.
 * @param l [ptr_row]
 * @return list->data [void*]
 */

void* getData(ptr_row l);

/** @brief nextRow
 *
 * Give the following list of the list.
 * @param list [ptr_list]
 * @return list->next [ptr_list]
 */

ptr_row nextRow(ptr_row l);

/** @brief addToRow
 *
 * Add the element to the list.
 * @param l [ptr_row]
 * @param n [void*]
 * @return [void]
 */

void addToRow(ptr_row l, void* n);

/** @brief getElementI
 *
 * Give the element at the position i
 * @param list [ptr_queue]
 * @param n [int]
 * @return tmp->data [void*]
 */

void* getElementI(ptr_row q, int n);
