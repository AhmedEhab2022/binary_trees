#include "binary_trees.h"

/**
 * binary_tree_height - the main function
 * to calculate the height of the binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: the height of the binary tree, otherwise 0
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree == NULL)
		return (0);

	if (tree->right)
		r = 1 + binary_tree_height(tree->right);

	if (tree->left)
		l = 1 + binary_tree_height(tree->left);

	return ((l > r) ? l : r);
}

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: the size of a binary tree, otherwise 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t n_left, n_right;

	if (tree == NULL)
		return (0);

	n_left = binary_tree_size(tree->left);
	n_right = binary_tree_size(tree->right);

	return (1 + n_left + n_right);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 *
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0, perfect_size = 0;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	perfect_size = (1 << (height + 1)) - 1;

	if (perfect_size == binary_tree_size(tree))
		return (1);

	return (0);
}
