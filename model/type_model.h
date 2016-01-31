/**
 * Polytech Marseille
 * Case 925 - 163, avenue de Luminy
 * 13288 Marseille CEDEX 9
 *
 * Ce fichier est l'oeuvre d'eleves de Polytech Marseille. Il ne peut etre
 * reproduit, utilise ou modifie sans l'avis express de ses auteurs.
 */

/**
 * @author BENMILOUD--JOSSELIN Alexis <alexis.benmiloud.josselin@gmail.com>
 * @author ALONSO Morgane <alonso.morgane@gmail.com>
 *
 * @version 0.0.1 / 25/01/2016
 * @todo
 * @bug
 */

/**
 * @file type_model.h
 * @brief 
 *
 * Description, sujet traite
 * trace d'execution'
 */


/** @brief model
 *
 * "model" structure's definition.
 * @field type [element*] is the character's type.
 * @field minInfluence [int] is the fame's lower limit.
 * @field maxInfluence [int] is the fame's upper limit.
 * @field alignment [pointer] is the character's alignment.
 * @field index [int] is the alignment's list index.
 * @name model
 * @pointer ptr_model
 */

typedef struct model
{
	struct element* type;
	int minInfluence;
	int maxInfluence;
	int alignment[4];
	int index;
}model, *ptr_model;