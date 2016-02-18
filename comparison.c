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
 * This file describes all the functions comparisons between characters and
 * stereotypes, stereotypes and stereotypes, examples and models etc.
 */

/*-----------------------------------------------------------------------*/

// #################
#ifndef LSTDIO
#define LSTDIO
#include <stdio.h>
#endif 
// #################

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

#ifndef LRLT
#define LRLT
#include "type_relationship.h"
#include "function_relationship.h"
#endif

#ifndef LEXP
#define LEXP
#include "type_example.h"
#include "function_example.h"
#endif

#ifndef LMDL
#define LMDL
#include "type_model.h"
#include "function_model.h"
#endif

#ifndef COMP
#define COMP
#include "comparison.h"
#endif 

#ifndef NULL
#define NULL 0
#endif

/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/
/*                             TOOL FUNCTIONS                            */
/*-----------------------------------------------------------------------*/

/** @brief typeComparison
 *
 * Do a comparison of types between the stereotype and an character in order to
 * enlarge, or not, the stereotype.
 * @param s [ptr_stereotype]
 * @param c [ptr_character]
 * @return tmp [ptr_tree]
 */

ptr_tree typeComparison(ptr_stereotype s, ptr_character c)
{
	ptr_tree tmp;
	tmp=commonFather(s->type, c->type);
	return tmp;
}

/** @brief influencesMinComparison
 *
 * Do a comparison of influences between the min influence of a stereotype and an character in
 * order to enlarge, or not, the stereotype.
 * @param s [ptr_stereotype]
 * @param c [ptr_character]
 * @return tmp [int]
 */

int influencesMinComparison(ptr_stereotype s, ptr_character c)
{
	int tmp;
	if(s->minInfluence > c->influence)
	{
		tmp = c->influence;
	}
	else
	{
		tmp = s->minInfluence;
	}
	return tmp;
}

/** @brief influencesMaxComparison
 *
 * Do a comparison of influences between the max influence of a stereotype and an character in
 * order to enlarge, or not, the stereotype.
 * @param s [ptr_stereotype]
 * @param c [ptr_character]
 * @return tmp [int]
 */

int influencesMaxComparison(ptr_stereotype s, ptr_character c)
{
	int tmp;
	if(s->maxInfluence < c->influence)
	{
		tmp = c->influence;
	}
	else
	{
		tmp = s->maxInfluence;
	}
	return tmp;
}

/** @brief alignementsComparison
 *
 * Do a comparison of alignments between the stereotype and an character in
 * order to enlarge, or not, the stereotype.
 * @param s [ptr_stereotype]
 * @param c [ptr_character]
 * @return tmp [int[]]
 */

void alignmentsComparison(int as[], ptr_stereotype s, ptr_character c)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		as[i]=s->alignments[i];
	}
	if(as[c->alignment-1]==0)
	{
		as[c->alignment-1]=1;
	}
}

/*-----------------------------------------------------------------------*/
/*                         COMPARISON FUNCTIONS                          */
/*-----------------------------------------------------------------------*/

/** @brief compSC
 *
 * Do a comparison between the stereotype and an character in order to enlarge,
 * or not, the stereotype.
 * @param stereotype [ptr_stereotype]
 * @param character [ptr_character]
 * @return stereotype [ptr_stereotype]
 */

ptr_stereotype compSC(ptr_stereotype s, ptr_character c)
{
	ptr_stereotype tmp;

	int tmpAlgn[4];
	alignmentsComparison(tmpAlgn, s, c);

	tmp = createStereotype(typeComparison(s, c),
		influencesMinComparison(s, c),
		influencesMaxComparison(s, c), 
		tmpAlgn);

	return tmp;
}

/** @brief compCC
 *
 * Do a comparison between two characters.
 * @param c1 [ptr_character]
 * @param c2 [ptr_character]
 * @return stereotype [ptr_stereotype]
 */

ptr_stereotype compCC(ptr_character c1, ptr_character c2)
{
	ptr_stereotype s;

	s=initStereotype(c1);
	compSC(s, c2);

	return s;
}

/** @brief compEM
 *
 * Do the comparison between the example e - a row of relations between two
 * characters - and the model m - a row of relations between two
 * stereotypes.
 * @param e [ptr_example]
 * @param m [ptr_model]
 * @return [void]
 */

/* ####################################################################
void compEM(ptr_example e, ptr_model m)
{
	ptr_row tmpExp, tmpMod;
	ptr_model modelAux;

	tmpExp=getExpRelRow(e);
	tmpMod=getModRelRow(m);
	modelAux=createEmptyModel();
	while(tmpExp!=createEmpty())
	{
		tmpMod=getModRelRow(m);
		while(tmpMod!=createEmpty())
		{
			compRmRe(modelAux,
				getData(tmpMod),
				getData(tmpExp));
			tmpMod=nextRow(tmpMod);
		}
		tmpExp=nextRow(tmpExp);
	}
	deleteGeneralModRel(modelAux);
	addToRow(getModRelRow(m), getModRelRow(modelAux));
}

####################################################################*/

/** @brief compRmRe
 *
 * Do the comparison between a relation from an example and a relation
 * from a model and add the new relations model into the row.
 * @param l [ptr_row]
 * @param rm [ptr_relationship]
 * @param re [ptr_relationship]
 * @return [void]
 */

void compRmRe(ptr_row l, ptr_relationship rm, ptr_relationship re)
{
	if (isRelationshipOneObject(re) && isRelationshipOneObject(rm))
	{
		addToRow(l, 
			createRelationshipOneObject(compSC(getData1(rm), getData1(re))));
	}
	else if(isRelationshipOneObject(re) && !isRelationshipOneObject(rm))
	{
		addToRow(l, 
			createRelationshipOneObject(compSC(getData1(rm), getData1(re))));
		addToRow(l, 
			createRelationshipOneObject(compSC(getData2(rm), getData1(re))));
	}
	else if(!isRelationshipOneObject(re) && isRelationshipOneObject(rm))
	{
		addToRow(l, 
			createRelationshipOneObject(compSC(getData1(rm), getData1(re))));
		addToRow(l, 
			createRelationshipOneObject(compSC(getData1(rm), getData2(re))));
	}
	else
	{
		if (getRelation(rm)==getRelation(re))
		{
			addToRow(l, 
				createRelationship(compSC(getData1(rm), getData1(re)), 
					compSC(getData2(rm), getData2(re)), 
					getRelation(rm)));
		}
		else
		{
			addToRow(l, 
				createRelationshipOneObject(compSC(getData1(rm), getData1(re))));
			addToRow(l, 
				createRelationshipOneObject(compSC(getData2(rm), getData1(re))));		
			addToRow(l, 
				createRelationshipOneObject(compSC(getData1(rm), getData2(re))));
			addToRow(l, 
				createRelationshipOneObject(compSC(getData2(rm), getData2(re))));		
		}
	}
}