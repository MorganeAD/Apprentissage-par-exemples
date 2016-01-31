/** @brief isTheDaddy
 *
 * Tell if an element is the daddy.
 * @param element [ptr_element] is the element. 
 * @return element->father [ptr_element] represent a boolean value
 */

int isTheDaddy(ptr_element element);

/** @brief createTheDaddy
 *
 * Create a the father of the tree.
 * @param val [int] is the father's value. 
 * @return daddy [ptr_element] is the daddy.
 */

ptr_element createTheDaddy(int val);

/** @brief createSon
 *
 * Create a son.
 * @param val [int] is the son's value. 
 * @param dad [ptr_element] is the father. 
 * @return son [ptr_element] is the son.
 */

ptr_element createSon(int val, ptr_element dad);

/** @brief hisFather
 *
 * Give the father of an element of a tree.
 * @param son [ptr_example] is the element. 
 * @return son->father [ptr_element] is element's father.
 */

ptr_element hisFather(ptr_element son);

/** @brief getValue
 *
 * Give the value of an element of a tree.
 * @param element [ptr_example] is the element. 
 * @return element->value [int] is element's value.
 */

int getValue(ptr_element element);

/** @brief displayBranch
 *
 * Display the branch of an element of a tree.
 * @param branch [ptr_element] is the branch to display.
 * @return [void]
 */

void displayBranch(ptr_element branch);

/** @brief commonFather
 *
 * Find the common father of two elements of a tree.
 * @param son1 [ptr_element] is the first son.
 * @param son2 [ptr_element] is the second son.
 * @return j [ptr_element] is common father's pointer.
 */

ptr_element commonFather(ptr_element son1, ptr_element son2);