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
 * @file function_character.h
 * @brief
 *
 * This files gives the prototype of all the function related to characters.
 */

/*-----------------------------------------------------------------------*/

/** @brief createCharacter
 *
 * Create a new character (see the "type_character.h" file).
 * @param t [ptr_tree]
 * @param i [int]
 * @param a [int]
 * @return character [ptr_character]
 */

ptr_character createCharacter(ptr_tree t, int i, int a);

/** @brief getType
 *
 * Give the type of the character.
 * @param character [ptr_character]
 * @return character->type [int]
 */

ptr_tree getType(ptr_character character);

/** @brief getInfluence
 *
 * Give the influence of the character.
 * @param character [ptr_character]
 * @return character->influence [int]
 */

int getInfluence(ptr_character character);

/** @brief getAlignment
 *
 * Give the alignment of the character.
 * @param character [ptr_character]
 * @return character->alignment [int]
 */

int getAlignment(ptr_character character);

/** @brief displayCharacter
 *
 * Display the character.
 * @param character [ptr_character]
 * @return [void]
 */

void displayCharacter(ptr_character character);
