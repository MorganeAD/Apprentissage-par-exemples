/** @brief element
 *
 * "element" structure's definition. It will be use to create a tree which
 * will describe all the character/s types.
 * @field value [int] is the element's value.
 * @field father [element*] is the element's father.
 * @name element
 * @pointer ptr_element
 */

typedef struct element
{
	int value;
	struct element* father;
}element , *ptr_element;