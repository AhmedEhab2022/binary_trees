#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: first node
 * @second: second node
 *
 * Return: lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				const binary_tree_t *second)
{
	binary_tree_t *first_parent, *second_parent;

	if (first == NULL || second == NULL)
		return NULL;

	if (first == second)
		return ((binary_tree_t *)first);

	first_parent = first->parent;
	second_parent = second->parent;

	if (first_parent == NULL || first == second_parent)
		return (binary_trees_ancestor(first, second_parent));

	if (second_parent == NULL || first_parent == second)
		return (binary_trees_ancestor(first_parent, second));

	return (binary_trees_ancestor(first_parent, second_parent));
}
