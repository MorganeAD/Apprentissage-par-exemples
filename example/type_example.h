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
 *
 * @version 0.0.1 / 31/01/2016
 * @todo
 * @bug
 */

/**
 * @file type_example.h
 * @brief
 *
 * Give the prototype the the "example" type.
 */

/*----------------------------------------------------------------------*/

/** @brief example
 *
 * "example" structure's definition. Examples will be compared to a model
 * (see the model section).
 * @field type [element*] is the character's type.
 * @field influence [int] is the character's fame.
 * @field alignment [int] is the character's alignment.
 * @name example
 * @pointer ptr_example
 */

typedef struct example
{
	struct element* type;
	int influence;
	int alignment;
}example, *ptr_example;
