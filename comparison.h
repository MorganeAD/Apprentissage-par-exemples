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

/** @brief searchAlignment
 *
 * Do a research of an alignment into a list of alignment (see the
 * "type_character.c" file).
 * @param tree [int]
 * @param list [pointer]
 * @return isInto [int]
 */

int searchAlignment(int alignment, int list[4]);

/** @brief comparison
 *
 * Do a comparison between the model and an character in order to enlarge,
 * or not, the model.
 * @param model [ptr_model]
 * @param character [ptr_character]
 * @return model [ptr_model]
 */

ptr_model comparison(ptr_model model, ptr_character character);

/** @brief modelGenerator
 *
 * Generate models and add them to the list of models. Add models came from
 * a comparison between a character and existing models. This function will
 * add new models to a list called "modelsListAux" which will be linked to
 * "modelsList" at the end of the function. "listBrowser" will be used to
 * browse the modelsList (ie. the original models list).
 * @param modelsList [ptr_list]
 * @param character [ptr_character]
 * @return  [ptr_list]
 */

ptr_list modelGenerator(ptr_list modelsList, ptr_character character);
