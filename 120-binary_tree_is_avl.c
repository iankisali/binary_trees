#include "binary_trees.h"

/**
 * binary_tree_is_avl - finds if a binary tree is an avl
 * @tree: pointer to root node of tree
 * Return: 1 if tree avl otherwise 0
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (avl_helper(tree, INT_MIN, INT_MAX));
}

/**
 * avl_helper - helper that finds if treeis av;
 * @tree: pointer to root node of tree
 * @max: maximum value
 * @min: minimum value
 * Return: 1 if tree avl otherwise 0
 */

int avl_helper(const binary_tree_t *tree, int min, int max)
{
	int right, left;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	if (abs(left - right) > 1)
		return (0);
	return (avl_helper(tree->left, min, tree->n - 1) &&
		avl_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree or 0 if NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (!tree)
		return (0);
	left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (left > right ? left : right);
}
