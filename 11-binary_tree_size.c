#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: the size of a binary tree, otherwise 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
		return (0);

	l = r = 0;
	if (tree->left)
		l += binary_tree_size(tree->left);

	if (tree->right)
		r += binary_tree_size(tree->right);

	return (l + r + 1);
}
