/**
 * Polytech Marseille
 * Case 925 - 163, avenue de Luminy
 * 13288 Marseille CEDEX 9
 *
 * Ce fichier est l'oeuvre d'eleves de Polytech Marseille. Il ne peut etre
 * reproduit, utilise ou modifie sans l'avis express de ses auteurs.
 */

/**
 * @author ALONSO Morgane <alonso.morgane@gmail.com>
 * @author BENMILOUD--JOSSELIN Alexis <alexis.benmiloud.josselin@gmail.com>
 *
 * @version 0.0.1 / 2016/01/25
 * @todo #0000 []
 * @bug #0000 []
 */

/*-----------------------------------------------------------------------*/

/**
 * @file class.c
 * @brief 
 *
 * This file contains the prototype of the functions related to reverse hierarchy tree
 */

#include "type_element.h"
#include "function_element.h"

#include "class.h"

/*-----------------------------------------------------------------------*/

/** @brief initClass
 *
 * Initialise all the element of the reverse hierarchy tree
 * @param void
 * @return void
 */

void initClass(void)
{
	character=createTheDaddy(1);

	force=createSon(2, character);
	weak=createSon(6, character);

	jedi=createSon(3, force);
	sith=createSon(5, force);

	council=createSon(4, jedi);

	droid=createSon(7, weak);
	bandit=createSon(10, weak);
	senator=createSon(12, weak);

	combat=createSon(8, droid);
	pacific=createSon(9, droid);

	chasseur=createSon(11, bandit);
}