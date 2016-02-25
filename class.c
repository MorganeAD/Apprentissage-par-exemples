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

/*-----------------------------------------------------------------------*/

/**
 * @file class.c
 * @brief 
 *
 * This file contains the prototype of the functions related to reversed
 * hierarchy tree.
 */

#ifndef LTREE
#define LTREE
#include "type_tree.h"
#include "function_tree.h"
#endif 

#ifndef CLASS
#define CLASS
#include "class.h"
#endif 

/*-----------------------------------------------------------------------*/

/** @brief initClass
 *
 * Initialise all the tree of the reverse hierarchy tree
 * @param [void]
 * @return [void]
 */

void initClass(void)
{
	person=createTheDaddy(1);

	force=createSon(2, person);
	weak=createSon(6, person);

	jedi=createSon(3, force);
	sith=createSon(5, force);

	council=createSon(4, jedi);

	droid=createSon(7, weak);
	bandit=createSon(10, weak);
	senator=createSon(12, weak);

	combat=createSon(8, droid);
	pacific=createSon(9, droid);

	hunter=createSon(11, bandit);
}
