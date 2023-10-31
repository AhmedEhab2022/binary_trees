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
 * binary_tree_balance - measures the balance factor of a binary tree.
 *
 * @tree: pointer to the root node of the tree to measure the balance factor.
 *
 * Return: balance factor of a binary tree, or 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_height(tree->left) -
				binary_tree_height(tree->right));
}

