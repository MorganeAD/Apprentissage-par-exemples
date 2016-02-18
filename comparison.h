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

/** @brief searchAlignment
 *
 * Do a research of an alignment into a row of alignment (see the
 * "type_character.c" file).
 * @param a [int]
 * @param row [int array]
 * @return isInto [int]
 */

int searchAlignment(int a, int row[]);

/** @brief typeComparison
 *
 * Do a comparison of types between the model and an character in order to
 * enlarge, or not, the model.
 * @param type1 [ptr_tree]
 * @param type2 [ptr_tree]
 * @return model [ptr_tree]
 */

void typeComparison(ptr_stereotype s, ptr_character c);
/** @brief influencesComparison
 *
 * Do a comparison of influences between the stereotype and an character in
 * order to enlarge, or not, the stereotype.
 * @param type1 [ptr_tree]
 * @param type2 [ptr_tree]
 * @return stereotype [ptr_tree]
 */

void influencesComparison(ptr_stereotype s, ptr_character c);

/** @brief alignementsComparison
 *
 * Do a comparison of alignments between the stereotype and an character in
 * order to enlarge, or not, the stereotype.
 * @param type1 [ptr_tree]
 * @param type2 [ptr_tree]
 * @return stereotype [ptr_tree]
 */

void alignmentsComparison(ptr_stereotype s, ptr_character c);

/*-----------------------------------------------------------------------*/
/*                         COMPARISON FUNCTIONS                          */
/*-----------------------------------------------------------------------*/

/** @brief compSC
 *
 * Do a comparison between the model and an character in order to enlarge,
 * or not, the model.
 * @param model [ptr_stereotype]
 * @param character [ptr_character]
 * @return model [ptr_stereotype]
 */

void compSC(ptr_stereotype s, ptr_character c);

/** @brief compCC
 *
 * Do a comparison between two characters.
 * @param c1 [ptr_character]
 * @param c2 [ptr_character]
 * @return stereotype [ptr_stereotype]
 */

ptr_stereotype compCC(ptr_character c1, ptr_character c2);

 /** @brief compEM
 *
 * Do the comparison between the example e - a row of relations between two
 * characters - and the model m - a row of relations between two
 * stereotypes.
 * @param e [ptr_example]
 * @param m [ptr_model]
 * @return m [ptr_row]
 */

ptr_model compEM(ptr_example e, ptr_model m);


