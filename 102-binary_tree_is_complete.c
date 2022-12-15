#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: pointer to root node of tree
 *
 * Return: 0 if tree NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size += 1;
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}
	return (size);
}

/**
 * tree_is_complete - check if tree is complete
 * @tree: pointer to root node of tree
 * @i: index of node
 * @node: number of nodes
 * Return: 1 if tree is complete otherwise 0
 */

int tree_is_complete(const binary_tree_t *tree, int i, int node)
{
	if (tree == NULL)
		return (1);
	if (i >= node)
		return (0);
	return (tree_is_complete(tree->left, (2 * i) + 1, node) &&
		tree_is_complete(tree->right, (2 * i) + 2, node));
}

/**
 * binary_tree_is_complete - calls to tree_is_complete function
 * @tree: pointer to root node
 * Return: 1 if tree complete otherwise 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t node;

	if (tree == NULL)
		return (0);
	node = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, node));
}
