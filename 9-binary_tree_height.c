#include "binary_trees.h"
#include <cmath>

/**
 * calcHeight - calcHeight of the given binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height
 * @counter: counter to calculate the height and store the height in it
 * 
 * Return: the counter that has the value of the height
*/
size_t calcHeight(const binary_tree_t *tree, size_t counter)
{
	size_t leftValue, rightValue;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (counter);

	leftValue = calcHeight(tree->left, counter + 1);
	rightValue = calcHeight(tree->right, counter + 1);
	return (max(leftValue, rightValue));
}

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
	size_t height;

	if (tree == NULL)
		return (0);

	height = calcHeight(tree, 0);
	return (height);
}
