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
 * @version 0.0.1 / 2016/01/31
 * @todo #0000 []
 * @bug #0000 []
 */

/**
 * @file function_element.h
 * @brief
 *
 * This file contains the prototype of all functions related to elements
 */

/*-----------------------------------------------------------------------*/

/** @brief isTheDaddy
 *
 * Tell if an element is the daddy. The daddy's father is "NULL"
 * @param element [ptr_element]
 * @return boolean [int]
 */

int isTheDaddy(ptr_element element);

/** @brief createTheDaddy
 *
 * Create a the father of the tree.
 * @param val [int]
 * @return daddy [ptr_element]
 */

ptr_element createTheDaddy(int val);

/** @brief createSon
 *
 * Create a son.
 * @param val [int]
 * @param dad [ptr_element] 
 * @return son [ptr_element]
 */

ptr_element createSon(int val, ptr_element dad);

/** @brief hisFather
 *
 * Give the father of the element.
 * @param son [ptr_example]
 * @return son->father [ptr_element]
 */

ptr_element hisFather(ptr_element son);

/** @brief getValue
 *
 * Give the value of an element of a tree.
 * @param element [ptr_example]
 * @return element->value [int]
 */

int getValue(ptr_element element);

/** @brief displayBranch
 *
 * Display the branch of an element of a tree.
 * @param branch [ptr_element]
 * @return [void]
 */

void displayBranch(ptr_element branch);

/** @brief commonFather
 *
 * Find the common father of two elements.
 * @param son1 [ptr_element]
 * @param son2 [ptr_element]
 * @return j [ptr_element]
 */

ptr_element commonFather(ptr_element son1, ptr_element son2);
