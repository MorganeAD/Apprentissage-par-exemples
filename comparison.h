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
 * @todo #0000 []
 * @bug #0000 []
 */

/**
 * @file comparison.h
 * @brief 
 *
 * This file contains the prototype of the functions related to comparison
 * between a model and an character.
 */

/*-----------------------------------------------------------------------*/

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

ptr_stereotype typeComparison(ptr_stereotype s, ptr_character c);
/** @brief influencesComparison
 *
 * Do a comparison of influences between the stereotype and an character in
 * order to enlarge, or not, the stereotype.
 * @param type1 [ptr_tree]
 * @param type2 [ptr_tree]
 * @return stereotype [ptr_tree]
 */

ptr_stereotype influencesComparison(ptr_stereotype s, ptr_character c);

/** @brief alignementsComparison
 *
 * Do a comparison of alignments between the stereotype and an character in
 * order to enlarge, or not, the stereotype.
 * @param type1 [ptr_tree]
 * @param type2 [ptr_tree]
 * @return stereotype [ptr_tree]
 */

ptr_stereotype alignmentsComparison(ptr_stereotype s, ptr_character c);

/*-----------------------------------------------------------------------*/
/*                         COMPARISON FUNCTIONS                          */
/*-----------------------------------------------------------------------*/

/** @brief comparison
 *
 * Do a comparison between the model and an character in order to enlarge,
 * or not, the model.
 * @param model [ptr_stereotype]
 * @param character [ptr_character]
 * @return model [ptr_stereotype]
 */

ptr_stereotype comparison(ptr_stereotype s, ptr_character c);

/** @brief modelGenerator
 *
 * Generate models and add them to the row of models. Add models came from
 * a comparison between a character and existing models. This function will
 * add new models to a row called "stereotypesRowAux" which will be linked to
 * "stereotypesRow" at the end of the function. "rowBrowser" will be used to
 * browse the stereotypesRow (ie. the original models row).
 * @param stereotypesRow [ptr_row]
 * @param character [ptr_character]
 * @return  [ptr_row]
 */

ptr_row modelGenerator(ptr_row stereotypesRow, ptr_character c);