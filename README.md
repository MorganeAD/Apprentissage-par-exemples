# Supervised Learning
*Algorithmic project - Polytech 3A*

## Generalities

_Goal_ : Characterize a concept (find a feature) from examples ( and maybe counterexample) that respect the concept.

_Example_ : Characterize the concept of relationship between characters from *Star Wars* universe.

*Examples* : 

- E1 : \<characters 1 : type : senator; influence : 1; alignment : 3\>  
	\<characters 2 : type : droid; influence : 5; alignment : 2\>  
	\<relationship : characters 1 verses characters 2\>  
- E2 : \<characters 1 : type : jedi; influence : 4; alignment : 2\>  
	\<characters 2 : type : jedi; influence : 4; alignment : 2\>  
	\<relationship : characters 1 verses characters 2\>  

*Few models* :

- M1 : 

_Data Representation_:
The properties of the different characters and theirs values are :

- Class : cf. hierarchy tree
- Influence : digit values : 1 , 2, 3 and 4
- Alignment : discrete values : vilain, neutral, kind, good

*Hierarchy tree*
![](http://morganealonso.fr/~niouby/apprentissage/graph-characters.png)

The relationship between the characters are :
- to serve
- to track

_Strategy_:
The first example give the initial model.
For eatch step (comparison between a example and a current model):
- Calculate the list of objects' couple we need to compar
- For eatch list:
	- Calculate eatch object's couple, and generalise the value of commun properties
	- Treat the relationship
	- Test if the result is not more general than another one
- Test counterexamples

_Generalization_:
- Choose the commun properties
- For eatch value of properties
	- if they are discrete : remove repetition
	- if they are digit : create a interval
	- if they are hierarchical : calculate the lower commun root

_Approach_:
1. There is only one character in a example, no relationship. The problem is easier and determinist
2. Treat the relationship without generality test and counterexample neether
3. Add the generality test
4. Add the counterexamples
