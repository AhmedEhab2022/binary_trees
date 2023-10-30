#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * 
 * @parent: pointer to node to insert the left-child in
 * @value: the value to store in the new node
 * 
 * Return: a pointer to the created node, or NULL on failure
 * or if parent is NULL 
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *tmp;

	if (parent == NULL)
		return (NULL);
	
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);
	
	if (parent->left == NULL)
		parent->left = new_node;
	else
	{
		tmp = parent->left;
		parent->left = new_node;
		new_node->left = tmp;
	}
	return (new_node);
}
