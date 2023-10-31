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
	size_t l = 1, r = 1;

	if (tree == NULL)
		return (0);

	if (tree->right)
		r += binary_tree_height(tree->right);

	if (tree->left)
		l += binary_tree_height(tree->left);

	return ((l > r) ? l : r);
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
	if (tree == NULL)
		return (1);

	int left_height = binary_tree_height(tree->left);
	int right_height = binary_tree_height(tree->right);

	if (left_height != right_height)
		return (0);

	return (binary_tree_is_perfect(tree->left) &&
		binary_tree_is_perfect(tree->right));
}
