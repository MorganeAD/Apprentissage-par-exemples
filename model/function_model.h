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
 * @file function_character.h
 * @brief
 *
 * This files gives the prototype of all the function related to characters.
 */

/*-----------------------------------------------------------------------*/

/** @brief createEmptyModel
 *
 * Create a empty model
 * @param [void]
 * @return tmp [ptr_model]
 */

ptr_model createEmptyModel(void);

/** @brief addRelatioship
 *
 * Add a new relationship of stereotype in the row
 * @param this [ptr_model m]
 * @param r [ptr_relationship]
 * @return [void]
 */

void addRelatioship(ptr_model this, ptr_relationship r);

/** @brief getModRelRow
 *
 * Give the row of relation's stereotype
 * @param this [ptr_model this]
 * @return this->modRelRow [ptr_row]
 */

ptr_row getModRelRow(ptr_model this);

/** @brief deleteRelationshipInModRelRow
 *
 * Delete a relationship from the row of relationships in the model
 * @param this [ptr_model this]
 * @param r [ptr_relationship r]
 * @return [void]
 */

void deleteRelationshipInModRelRow(ptr_model this, ptr_relationship r);

/** @brief displayModel
 *
 * Display the model
 * @param this [ptr_model m]
 * @return [void]
 */

/** @brief addRelatioshipFromRow
 *
 * Add relationships from a row into ModRelRow
 * @param this [ptr_model this]
 * @param r [ptr_row r]
 * @return [void]
 */

void addRelationshipFromRow(ptr_model this, ptr_row r);

void displayModel(ptr_model this);
