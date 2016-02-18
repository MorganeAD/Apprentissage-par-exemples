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

#ifndef LROW
#define LROW
#include "type_row.h"
#include "function_row.h"
#endif 

/*-----------------------------------------------------------------------*/

/** @brief createEmpty
 *
 * Create the empty row.
 * @param [void]
 * @return tmp [ptr_list]
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
 * @param this [ptr_row]
 * @return this->data==NULL && this->next==NULL [int]
 */

int isEmpty(ptr_row this)
{
	return this->data==NULL && this->next==NULL;
}

/** @brief getData
 *
 * Give the data of the first list of the list.
 * @param this [ptr_row]
 * @return list->data [void*]
 */

void* getData(ptr_row this)
{
	assert(!isEmpty(this));
	return this->data;
}

/** @brief nextRow
 *
 * Give the following list of the list.
 * @param this [ptr_list]
 * @return list->next [ptr_list]
 */

ptr_row nextRow(ptr_row this)
{
	assert(!isEmpty(this));
	return this->next;
}

/** @brief addToRow
 *
 * Add the element to the list.
 * @param this [ptr_row]
 * @param n [void*]
 * @return [void]
 */

void addToRow(ptr_row this, void* n)
{
	ptr_row parcours;
	parcours=this;
	if (isEmpty(this))
	{
		this->data=n;
		this->next=createEmpty();
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
 * @param this [ptr_row]
 * @param n [int]
 * @return tmp->data [void*]
 */

void* getDataI(ptr_row this, int n)
{
	ptr_row tmp = this;
	int i;
	for (i = 0; i < n; i++)
	{
		tmp = nextRow(tmp);
	}
	return getData(tmp);
}

/** @brief getLastData
 *
 * Give the last element
 * @param this [ptr_row]
 * @return tmp->data [void*]
 */

void* getLastData(ptr_row this)
{
	ptr_row tmp = this;
	while(!isEmpty(nextRow(tmp)))
	{
		tmp = nextRow(tmp);
	}
	return getData(tmp);
}

/** @brief deleteObject
 *
 * Delete the Object from the row
 * @param this [ptr_row]
 * @param r [void*]
 * @return [void]
 */

void deleteObject(ptr_row this, void* r)
{
	assert(!isEmpty(this));
	ptr_row tmp = this;
	ptr_row old;
	while(!isEmpty(tmp) && getData(tmp)!=r)
	{
		tmp = nextRow(tmp);
	}
	if (isEmpty(tmp))
	{
		printf("Error : The object is not in the list, can't delete it\n");
	}
	else
	{
		if (isEmpty(nextRow(tmp)))
		{
			// deux petit malloc perdus...
			tmp = createEmpty();
		}
		else
		{	
			tmp->data = getData(nextRow(tmp));
			old = nextRow(tmp);
			tmp->next = nextRow(nextRow(tmp));
			free(old);
		}
	}
}

/** @brief addToRowFromRow
 *
 * Add all the object of the row r to the row this
 * @param this [ptr_row]
 * @param r [void*]
 * @return [void]
 */

void addToRowFromRow(ptr_row this, ptr_row r)
{
	ptr_row tmp = r;
	while(!isEmpty(tmp))
	{
		addToRow(this, getData(tmp));
		tmp = nextRow(tmp);
	}
}