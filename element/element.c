#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#include "type_element.h"
#include "function_element.h"

/*----------------------------------------------------------------------*/
/*                           ELEMENT SECTION                            */
/*----------------------------------------------------------------------*/

/** @brief isTheDaddy
 *
 * Tell if an element is the daddy.
 * @param element [ptr_element] is the element. 
 * @return element->father [ptr_element] represent a boolean value
 */

int isTheDaddy(ptr_element element)
{
	return element->father==NULL;
}

/** @brief createTheDaddy
 *
 * Create a the father of the tree.
 * @param val [int] is the father's value. 
 * @return daddy [ptr_element] is the daddy.
 */

ptr_element createTheDaddy(int val)
{
	ptr_element daddy=(ptr_element)malloc(sizeof(element));
	daddy->value=val;
	daddy->father=NULL;
	return daddy;
}

/** @brief createSon
 *
 * Create a son.
 * @param val [int] is the son's value. 
 * @param dad [ptr_element] is the father. 
 * @return son [ptr_element] is the son.
 */

ptr_element createSon(int val, ptr_element dad)
{
	ptr_element this=(ptr_element)malloc(sizeof(element));
	this->value=val;
	this->father=dad;
	return this;
}

/** @brief hisFather
 *
 * Give the father of an element of a tree.
 * @param son [ptr_example] is the element. 
 * @return son->father [ptr_element] is element's father.
 */

ptr_element hisFather(ptr_element son)
{
	return son->father;
}

/** @brief getValue
 *
 * Give the value of an element of a tree.
 * @param element [ptr_example] is the element. 
 * @return element->value [int] is element's value.
 */

int getValue(ptr_element element)
{
	return element->value;
}

/** @brief displayBranch
 *
 * Display the branch of an element of a tree.
 * @param branch [ptr_element] is the branch to display.
 * @return [void]
 */

void displayBranch(ptr_element branch)
{
	ptr_element tmp=branch;
	printf("%d -> ", getValue(tmp));
	while(!isTheDaddy(tmp))
	{
		tmp=hisFather(tmp);
		printf("%d -> ", getValue(tmp));
	}
	printf("\n");
}

/** @brief commonFather
 *
 * Find the common father of two elements of a tree.
 * @param son1 [ptr_element] is the first son.
 * @param son2 [ptr_element] is the second son.
 * @return j [ptr_element] is common father's pointer.
 */

ptr_element commonFather(ptr_element son1, ptr_element son2)
{
	ptr_element i=son1;
	ptr_element j=son2;
	int find=0;

	while(!find && !isTheDaddy(i))
	{
		j=son2;
		while(!find && !isTheDaddy(j))
		{
			if (i==j)
			{
				find=1;
			}
			else 
			{
				j=hisFather(j);
			}
		}
		i=hisFather(i);
	}
	return j;
}