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
 * @file function_tree.h
 * @brief
 *
 * This file contains the prototype of all functions related to trees
 */

/*-----------------------------------------------------------------------*/

/** @brief isTheDaddy
 *
 * Tell if an tree is the daddy. The daddy's father is "NULL"
 * @param tree [ptr_tree]
 * @return boolean [int]
 */

int isTheDaddy(ptr_tree tree);

/** @brief createTheDaddy
 *
 * Create a the father of the tree.
 * @param val [int]
 * @return daddy [ptr_tree]
 */

ptr_tree createTheDaddy(int val);

/** @brief createSon
 *
 * Create a son.
 * @param val [int]
 * @param dad [ptr_tree] 
 * @return son [ptr_tree]
 */

ptr_tree createSon(int val, ptr_tree dad);

/** @brief hisFather
 *
 * Give the father of the tree.
 * @param son [ptr_example]
 * @return son->father [ptr_tree]
 */

ptr_tree hisFather(ptr_tree son);

/** @brief getValue
 *
 * Give the value of an tree of a tree.
 * @param tree [ptr_example]
 * @return tree->value [int]
 */

int getValue(ptr_tree tree);

/** @brief displayBranch
 *
 * Display the branch of an tree of a tree.
 * @param branch [ptr_tree]
 * @return [void]
 */

void displayBranch(ptr_tree branch);

/** @brief commonFather
 *
 * Find the common father of two trees.
 * @param son1 [ptr_tree]
 * @param son2 [ptr_tree]
 * @return j [ptr_tree]
 */

ptr_tree commonFather(ptr_tree son1, ptr_tree son2);
