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
 * This file describes all the functions to compare between a model and an
 * character.
 */

/*-----------------------------------------------------------------------*/

/** @brief typeComparison
 *
 * Do a comparison of types between the stereotype and an character in order to
 * enlarge, or not, the stereotype.
 * @param s [ptr_stereotype]
 * @param c [ptr_character]
 * @return tmp [ptr_tree]
 */

ptr_tree typeComparison(ptr_stereotype s, ptr_character c);

/** @brief influencesMinComparison
 *
 * Do a comparison of influences between the min influence of a stereotype and an character in
 * order to enlarge, or not, the stereotype.
 * @param s [ptr_stereotype]
 * @param c [ptr_character]
 * @return tmp [int]
 */

int influencesMinComparison(ptr_stereotype s, ptr_character c);

/** @brief influencesMaxComparison
 *
 * Do a comparison of influences between the max influence of a stereotype and an character in
 * order to enlarge, or not, the stereotype.
 * @param s [ptr_stereotype]
 * @param c [ptr_character]
 * @return tmp [int]
 */

int influencesMaxComparison(ptr_stereotype s, ptr_character c);

/** @brief alignementsComparison
 *
 * Do a comparison of alignments between the stereotype and an character in
 * order to enlarge, or not, the stereotype.
 * @param s [ptr_stereotype]
 * @param c [ptr_character]
 * @return tmp [int[]]
 */

void alignmentsComparison(int as[], ptr_stereotype s, ptr_character c);

/** @brief min
 *
 * Give the minimum value between two integers.
 * @param a [int]
 * @param b [int]
 * @return a [int]
 */

int min(int a, int b);

/** @brief max
 *
 * Give the maximum value between two integers.
 * @param a [int]
 * @param b [int]
 * @return a [int]
 */

int max(int a, int b);

/** @brief deleteGeneralModRel
 *
 * Delete the most general relationships of a model.
 * @param m [ptr_model]
 * @return [void]
 */

void deleteGeneralModRel(ptr_row l);

/** @brief compSC
 *
 * Do a comparison between the stereotype and an character in order to enlarge,
 * or not, the stereotype.
 * @param stereotype [ptr_stereotype]
 * @param character [ptr_character]
 * @return stereotype [ptr_stereotype]
 */

ptr_stereotype compSC(ptr_stereotype s, ptr_character c);

/** @brief compCC
 *
 * Do a comparison between two characters.
 * @param c1 [ptr_character]
 * @param c2 [ptr_character]
 * @return stereotype [ptr_stereotype]
 */

ptr_stereotype compCC(ptr_character c1, ptr_character c2);

/** @brief compSS
 *
 * Compare two stereotype and return a model.
 * @param s1 [ptr_stereotype]
 * @param s2 [ptr_stereotype]
 * @return newS [ptr_stereotype]
 */

ptr_stereotype compSS(ptr_stereotype s1, ptr_stereotype s2);

/** @brief compEM
 *
 * Do the comparison between the example e - a row of relations between two
 * characters - and the model m - a row of relations between two
 * stereotypes.
 * @param e [ptr_example]
 * @param m [ptr_model]
 * @return [void]
 */

void compEM(ptr_example e, ptr_model m);

/** @brief compRmRe
 *
 * Do the comparison between a relation from an example and a relation
 * from a model and add the new relations model into the row.
 * @param l [ptr_row]
 * @param rm [ptr_relationship]
 * @param re [ptr_relationship]
 * @return [void]
 */

void compRmRe(ptr_row l, ptr_relationship rm, ptr_relationship re);
