#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to root node of tree to measure height
 * Return: 0 if tree NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l =  tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * binary_tree_level - perform a function on a specific level of a binary tree
 * @tree: pointer to root node of tree
 * @l: level of tree to perform function
 * @func: function
 *
 * Return: void
 */

void binary_tree_level(const binary_tree_t *tree, size_t l, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (l == 1)
		func(tree->n);
	else if (l > 1)
	{
		binary_tree_level(tree->left, l - 1, func);
		binary_tree_level(tree->right, l - 1, func);
	}
}

/**
 * binary_tree_levelorder - traverses a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 *
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height(tree);
	for (i = 1; i <= height; i++)
		binary_tree_level(tree, i, func);
}
