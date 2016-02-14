/**
 * Polytech Marseille
 * Case 925 - 163, avenue de Luminy
 * 13288 Marseille CEDEX 9
 *
 * Ce fichier est l'oeuvre d'eleves de Polytech Marseille. Il ne peut etre
 * reproduit, utilise ou modifie sans l'avis express de ses auteurs.
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
 * between a model and an example.
 */

/*-----------------------------------------------------------------------*/

/** @brief searchAlignment
 *
 * Do a research of an alignment into a list of alignment (see the
 * "type_example.c" file).
 * @param element [int]
 * @param list [pointer]
 * @return isInto [int]
 */

int searchAlignment(int alignment, int list[4]);

/** @brief comparison
 *
 * Do a comparison between the model and an example in order to enlarge,
 * or not, the model.
 * @param model [ptr_model]
 * @param example [ptr_example]
 * @return model [ptr_model]
 */

ptr_model comparison(ptr_model model, ptr_example example);
