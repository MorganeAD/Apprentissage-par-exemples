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
 * @version 0.0.2 / 2016/02/15
 * @todo #0000 []
 * @bug #0000 []
 */

/**
 * @file comparison.c
 * @brief 
 *
 * This file describes all the functions to compare between a stereotype and an
 * character.
 */

/*-----------------------------------------------------------------------*/

#ifndef LTREE
#define LTREE
#include "type_tree.h"
#include "function_tree.h"
#endif 

#ifndef LCHR
#define LCHR
#include "type_character.h"
#include "function_character.h"
#endif 

#ifndef LSTR
#define LSTR
#include "type_stereotype.h"
#include "function_stereotype.h"
#endif

#ifndef LROW
#define LROW
#include "type_row.h"
#include "function_row.h"
#endif 

#ifndef COMP
#define COMP
#include "comparison.h"
#endif 

#define NULL 0
#define MAX_ALIGNMENT 4

/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/
/*                             TOOL FUNCTIONS                            */
/*-----------------------------------------------------------------------*/

/** @brief searchAlignment
 *
 * Do a research of an alignment into a row of alignment (see the
 * "type_character.c" file).
 * @param a [int]
 * @param row [int array]
 * @return isInto [int]
 */

int searchAlignment(int a, int row[])
{
	int i, find;
	
	i=0;
	find=0;
	while(!find && i<MAX_ALIGNMENT)
	{
		if(a==row[i])
		{
			find=1;
		}
		else
		{
			i++;
		}
	}
	return find;
}

/** @brief typeComparison
 *
 * Do a comparison of types between the stereotype and an character in order to
 * enlarge, or not, the stereotype.
 * @param type1 [ptr_tree]
 * @param type2 [ptr_tree]
 * @return stereotype [ptr_tree]
 */

ptr_stereotype typeComparison(ptr_stereotype s, ptr_character c)
{
	s->type=commonFather(s->type, c->type);
	return s;
}

/** @brief influencesComparison
 *
 * Do a comparison of influences between the stereotype and an character in
 * order to enlarge, or not, the stereotype.
 * @param type1 [ptr_tree]
 * @param type2 [ptr_tree]
 * @return stereotype [ptr_tree]
 */

ptr_stereotype influencesComparison(ptr_stereotype s, ptr_character c)
{
	if(s->minInfluence>c->influence)
	{
		s->minInfluence=c->influence;
	}
	else if(s->maxInfluence<c->influence)
	{
		s->maxInfluence=c->influence;
	}

	return s;
}

/** @brief alignementsComparison
 *
 * Do a comparison of alignments between the stereotype and an character in
 * order to enlarge, or not, the stereotype.
 * @param type1 [ptr_tree]
 * @param type2 [ptr_tree]
 * @return stereotype [ptr_tree]
 */

ptr_stereotype alignmentsComparison(ptr_stereotype s, ptr_character c)
{
	if(!searchAlignment(c->alignment, s->alignment))
	{
		s->alignment[s->nbAlign]=c->alignment;
		s->nbAlign++;
	}

	return s;
}

/*-----------------------------------------------------------------------*/
/*                         COMPARISON FUNCTIONS                          */
/*-----------------------------------------------------------------------*/

/** @brief comparison
 *
 * Do a comparison between the stereotype and an character in order to enlarge,
 * or not, the stereotype.
 * @param stereotype [ptr_stereotype]
 * @param character [ptr_character]
 * @return stereotype [ptr_stereotype]
 */

ptr_stereotype comparison(ptr_stereotype s, ptr_character c)
{
	/* Comparison of types.*/
	s=typeComparison(s, c);

	/* Comparison of influences.*/
	s=influencesComparison(s, c);

	/* Comparison of alignments.*/
	s=alignmentsComparison(s, c);
	
	return s;
}

/** @brief stereotypeGenerator
 *
 * Generate stereotypes and add them to the row of stereotypes. Add stereotypes came from
 * a comparison between a character and existing stereotypes. This function will
 * add new stereotypes to a row called "stereotypesRowAux" which will be linked to
 * "stereotypesRow" at the end of the function. "rowBrowser" will be used to
 * browse the stereotypesRow (ie. the original stereotypes row).
 * @param stereotypesRow [ptr_row]
 * @param character [ptr_character]
 * @return  [ptr_row]
 */

ptr_row stereotypeGenerator(ptr_row stereotypesRow, ptr_character c)
{
	ptr_row  stereotypesRowAux, rowBrowser;
	ptr_stereotype toAdd;

	stereotypesRowAux=createEmpty();
	rowBrowser=stereotypesRow;
	while(rowBrowser->next!=NULL)
	{
		toAdd=stereotypesRow->data;

		/* Comparison of types.*/
		toAdd=typeComparison(toAdd, c);

		/* Add the "toAdd" stereotype to the row of stereotypes "stereotypesRowAux".*/
		addToRow(stereotypesRowAux, toAdd);

		/* Comparison of influences.*/
		toAdd=influencesComparison(toAdd, c);

		/* Add the "toAdd" stereotype to the row of stereotypes "stereotypesRowAux".*/
		addToRow(stereotypesRowAux, toAdd);
	
		/* Comparison of alignments.*/
		toAdd=alignmentsComparison(toAdd, c);

		/* Add the "toAdd" stereotype to the row of stereotypes "stereotypesRowAux".*/
		addToRow(stereotypesRowAux, toAdd);

		/*---------------------------------------------------------------*/
		/* Now, the program will do the same thing but without the
		comparison of alignments.*/
		
		/* Re-initialization of the "toAdd" stereotype.*/
		toAdd=stereotypesRow->data;

		/* Comparison of influences.*/
		toAdd=influencesComparison(toAdd, c);

		/* Add the "toAdd" stereotype to the row of stereotypes "stereotypesRowAux".*/
		addToRow(stereotypesRowAux, toAdd);

		/* Comparison of alignments.*/
		toAdd=alignmentsComparison(toAdd, c);

		/* Add the "toAdd" stereotype to the row of stereotypes "stereotypesRowAux".*/
		addToRow(stereotypesRowAux, toAdd);

		/*---------------------------------------------------------------*/
		/* Now, the program will do the same thing but without the
		comparison of alignments and influences.*/

		/* Re-initialization of the "toAdd" stereotype.*/
		toAdd=stereotypesRow->data;

		/* Comparison of alignments.*/
		toAdd=alignmentsComparison(toAdd, c);

		/* Add the "toAdd" stereotype to the row of stereotypes "stereotypesRowAux".*/
		addToRow(stereotypesRowAux, toAdd);

		/* Now the program will do same same comparisons but with the
		following existing stereotype.*/
		rowBrowser=rowBrowser->next;
	}

	/* At the end, the program add the stereotype obtained by the example
	itself.*/
	toAdd=initStereotype(c);
	addToRow(stereotypesRowAux, toAdd);

	/* The last thing to do is to link the new row of stereotypes to the
	original one.*/
	rowBrowser->next=stereotypesRowAux;
	return stereotypesRow;

}
