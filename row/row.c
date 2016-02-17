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
 * @row row.c
 * @brief
 *
 * This file describes all the functions related to rows.
 */

/*-----------------------------------------------------------------------*/

#ifndef LSTDIO
#define LSTDIO
#include <stdio.h>
#endif 

#ifndef LSTDLIB
#define LSTDLIB
#include <stdlib.h>
#endif 

#ifndef LASRT
#define LASRT
#include <assert.h>
#endif 

#ifndef LQUE
#define LQUE
#include "type_row.h"
#include "function_row.h"
#endif 

/*-----------------------------------------------------------------------*/

/** @brief createEmpty
 *
 * Create the empty row.
 * @param [void]
 * @return NULL [ptr_list]
 */

ptr_row createEmpty()
{
	ptr_row tmp;
	tmp=(ptr_row)malloc(sizeof(row));
	tmp->data=NULL;
	tmp->next=NULL;
	return tmp;
}

/** @brief isEmpty
 *
 * Tell if the row is empty.
 * @param q [ptr_row]
 * @return q->data==NULL && q->next==NULL [int]
 */

int isEmpty(ptr_row q)
{
	return q->data==NULL && q->next==NULL;
}

/** @brief getData
 *
 * Give the data of the first list of the list.
 * @param l [ptr_row]
 * @return list->data [void*]
 */

void* getData(ptr_row q)
{
	assert(!isEmpty(q));
	return q->data;
}

/** @brief nextRow
 *
 * Give the following list of the list.
 * @param list [ptr_list]
 * @return list->next [ptr_list]
 */

ptr_row nextRow(ptr_row q)
{
	assert(!isEmpty(q));
	return q->next;
}

/** @brief addToRow
 *
 * Add the element to the list.
 * @param q [ptr_row]
 * @param n [void*]
 * @return [void]
 */

void addToRow(ptr_row q, void* n)
{
	ptr_row parcours;
	parcours=q;
	if (isEmpty(q))
	{
		q->data=n;
		q->next=createEmpty();
	}
	else
	{
		while(!isEmpty(parcours))
		{
			parcours=parcours->next;
		}
		parcours->data=n;
		parcours->next=createEmpty();
	}
}

/** @brief getDataI
 *
 * Give the element at the position i
 * @param list [ptr_queue]
 * @param n [int]
 * @return tmp->data [void*]
 */

void* getDataI(ptr_row q, int n)
{
	ptr_row tmp = q;
	int i;
	for (i = 0; i < n; i++)
	{
		tmp = nextRow(tmp);
	}
	return getData(tmp);
}

/** @brief getLastData(ptr_row q, int n)
 *
 * Give the last element
 * @param list [ptr_queue]
 * @return tmp->data [void*]
 */

void* getLastData(ptr_row q)
{
	ptr_row tmp = q;
	while(!isEmpty(nextRow(tmp)))
	{
		tmp = nextRow(tmp);
	}
	return getData(tmp);
}