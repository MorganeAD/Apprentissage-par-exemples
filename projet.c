#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef struct element
{
	int value;
	struct element* father;
}element , *ptr_element;

int isTheDaddy(ptr_element this)
{
	return this->father==NULL;
}

ptr_element createTheDaddy(int val)
{
	ptr_element this = (ptr_element)malloc(sizeof(element));
	this->value = val;
	this->father = NULL;
}

ptr_element createSon(int val, ptr_element dad)
{
	ptr_element this = (ptr_element)malloc(sizeof(element));
	this->value = val;
	this->father = dad;
	return this;
}

ptr_element hisFather(ptr_element son)
{
	return son->father;
}

void printBranch(ptr_element this)
{
	ptr_element tmp = this;
	printf("%d -> ", getValue(tmp));
	while(!isTheDaddy(tmp))
	{
		tmp=hisFather(tmp);
		printf("%d -> ", getValue(tmp));
	}
	printf("\n");
}

ptr_element communFather(ptr_element son1, ptr_element son2)
{
	ptr_element i = son1;
	ptr_element j = son2;
	int find = 0;

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

int getValue(ptr_element this)
{
	return this->value;
}

typedef struct example
{
	struct element* type;
	int caracteristique;
	int alignement;
}example, *ptr_example;

ptr_example createExample(ptr_element t, int c, int a)
{
	ptr_example this = (ptr_example)malloc(sizeof(example));
	this->type=t;
	this->caracteristique=c;
	this->alignement=a;
	return this;
} 

ptr_element getType(ptr_example this)
{
	return this->type;
}

int getCaracterisque(ptr_example this)
{
	return this->caracteristique;
}

int getAlignement(ptr_example this)
{
	return this->alignement;
}

void printExample(ptr_example this)
{
	printf("<type : %d> ", getValue(getType(this)));
	printf("<caracteristique : %d> ", getCaracterisque(this));
	printf("<alignement : %d>\n", getAlignement(this));
}

main()
{
	ptr_element personnage = createTheDaddy(1);

	ptr_element force = createSon(2, personnage);
	ptr_element week = createSon(6, personnage);

	ptr_element jedi = createSon(3, force);
	ptr_element sith = createSon(5, force);

	ptr_element concil = createSon(4, jedi);

	ptr_element droid = createSon(7, week);
	ptr_element bandi = createSon(10, week);
	ptr_element senateur = createSon(12, week);

	ptr_element combat = createSon(8, droid);
	ptr_element pacific = createSon(9, droid);

	ptr_element chasseur = createSon(11, bandi);

	printBranch(combat);
	printBranch(senateur);

	printf("%d\n", getValue(communFather(combat,senateur)));
	printf("%d\n", getValue(communFather(sith,jedi)));

	ptr_example e1 = createExample(senateur, 1, 3);
	printExample(e1);

	ptr_example e2 = createExample(jedi, 5, 2);
	printExample(e2);	
}
// typedef enum elements {personnage,force,jedi,conseil,sith,samedi,dimanche} Jour_de_Semaine;