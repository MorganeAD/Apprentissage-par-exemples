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

/** @brief min
 *
 * Give the minimum value between two integers.
 * @param a [int]
 * @param b [int]
 * @return a [int]
 */

int min(int a, int b)
{
	if(b<a)
	{
		a=b;
	}
	return a;
}

/** @brief max
 *
 * Give the maximum value between two integers.
 * @param a [int]
 * @param b [int]
 * @return a [int]
 */

int max(int a, int b)
{
	if(b>a)
	{
		a=b;
	}
	return a;
}

/** @brief deleteGeneralModRel
 *
 * Delete the most general relationships of a model.
 * @param m [ptr_model]
 * @return [void]
 */

void deleteGeneralModRel(ptr_row l)
{
	ptr_row rs1, rs2;
	ptr_stereotype tmp1, tmp2;

	rs1=l;
	while(!isEmpty(rs1))
	{
		rs2=nextRow(rs1);
		while(!isEmpty(rs2))
		{
			/* Verify if the relation of rs1 and rs2 are the same : */
			if(getRelation(getData(rs1))==getRelation(getData(rs2)))
			{
				/* Verify is there is no relation : */
				if(getRelation(getData(rs1))==-1)
				{
					tmp1=compSS(getData1(getData(rs1)), getData1(getData(rs2)));

					/* Delete the relation rs1 if it is too general : */
					if(equalStereotypes(tmp1, getData1(getData(rs1))))
					{
						deleteObject(l, getData(rs1));
					}

					/* Delete the relation rs2 if it is too general : */
					else if(equalStereotypes(tmp1, getData1(getData(rs2))))
					{
						deleteObject(l, getData(rs2));
					}
				}

				/* If relation != -1 : */
				else
				{
					tmp1=compSS(getData1(getData(rs1)), getData1(getData(rs2)));
					tmp2=compSS(getData2(getData(rs1)), getData2(getData(rs2)));

					/* Delete the relation rs2 if it is too general : */
					if(equalStereotypes(getData1(getData(rs2)), tmp1) &&
							equalStereotypes(getData2(getData(rs2)), tmp2))
					{
						deleteObject(l, getData(rs2));
					}
					/* Delete the relation rs1 if it is too general : */
					else if(equalStereotypes(getData1(getData(rs1)), tmp1) &&
					   equalStereotypes(getData2(getData(rs1)), tmp2))
					{
						deleteObject(l, getData(rs1));
					}
				}
			}

			/* If relation are not the same : */
			else if(getRelation(getData(rs1))==-1 &&
					getRelation(getData(rs2))!=-1)
			{
				tmp1=compSS(getData1(getData(rs1)), getData1(getData(rs2)));
				tmp2=compSS(getData1(getData(rs1)), getData2(getData(rs2)));

				if(equalStereotypes(getData1(getData(rs1)), tmp1) ||
				   equalStereotypes(getData1(getData(rs1)), tmp2))
				{
					deleteObject(l, getData(rs1));
				}
			}
			else if(getRelation(getData(rs2))==-1 &&
					getRelation(getData(rs1))!=-1)
			{
				tmp1=compSS(getData1(getData(rs1)), getData1(getData(rs2)));
				tmp2=compSS(getData2(getData(rs1)), getData1(getData(rs2)));

				if(equalStereotypes(getData1(getData(rs2)), tmp1) ||
				   equalStereotypes(getData1(getData(rs2)), tmp2))
				{
					deleteObject(l, getData(rs2));
				}
			}
			rs2=nextRow(rs2);
		}
		rs1=nextRow(rs1);
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

/** @brief compSS
 *
 * Compare two stereotype and return a model.
 * @param s1 [ptr_stereotype]
 * @param s2 [ptr_stereotype]
 * @return newS [ptr_stereotype]
 */

ptr_stereotype compSS(ptr_stereotype s1, ptr_stereotype s2)
{
	int i;
	int tmp[4]={0};
	ptr_stereotype newS;

	for(i=0 ; i<4 ; i++)
	{
		if(s1->alignments[i] || s2->alignments[i])
		{
			tmp[i]=1;
		}
	}

	newS=createStereotype(
					 commonFather(getStereotypeType(s1), getStereotypeType(s2)),
					 min(getMinInfluence(s1), getMinInfluence(s2)),
					 max(getMaxInfluence(s1), getMaxInfluence(s2)),
					 tmp);
					 
	return newS;
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

void compEM(ptr_example e, ptr_model m)
{
	ptr_row tmpExp, tmpMod;
	ptr_row modelAux;

	tmpExp=getExpRelRow(e);
	tmpMod=getModRelRow(m);
	modelAux=createEmpty();
	while(!isEmpty(tmpExp))
	{
		tmpMod=getModRelRow(m);
		while(!isEmpty(tmpMod))
		{
			compRmRe(modelAux,
				getData(tmpMod),
				getData(tmpExp));
			tmpMod=nextRow(tmpMod);
		}
		tmpExp=nextRow(tmpExp);
	}
	deleteGeneralModRel(modelAux);
	addToRowFromRow(getModRelRow(m), modelAux);
}

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
