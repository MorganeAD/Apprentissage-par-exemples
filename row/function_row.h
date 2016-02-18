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
 * @return tmp [ptr_list]
 */

ptr_row createEmpty();

/** @brief isEmpty
 *
 * Tell if the row is empty.
 * @param this [ptr_row]
 * @return this->data==NULL && this->next==NULL [int]
 */

int isEmpty(ptr_row this);

/** @brief getData
 *
 * Give the data of the first list of the list.
 * @param this [ptr_row]
 * @return list->data [void*]
 */

void* getData(ptr_row this);

/** @brief nextRow
 *
 * Give the following list of the list.
 * @param this [ptr_list]
 * @return list->next [ptr_list]
 */

ptr_row nextRow(ptr_row this);

/** @brief addToRow
 *
 * Add the element to the list.
 * @param this [ptr_row]
 * @param n [void*]
 * @return [void]
 */

void addToRow(ptr_row this, void* n);

/** @brief getDataI
 *
 * Give the element at the position i
 * @param this [ptr_row]
 * @param n [int]
 * @return tmp->data [void*]
 */

void* getDataI(ptr_row this, int n);

/** @brief getLastData
 *
 * Give the last element
 * @param this [ptr_row]
 * @return tmp->data [void*]
 */

void* getLastData(ptr_row this);

/** @brief deleteObject
 *
 * Delete the Object from the row
 * @param this [ptr_row]
 * @param r [void*]
 * @return [void]
 */

void deleteObject(ptr_row this, void* r);

/** @brief addToRowFromRow
 *
 * Add all the object of the row r to the row this
 * @param this [ptr_row]
 * @param r [void*]
 * @return [void]
 */

void addToRowFromRow(ptr_row this, ptr_row r);