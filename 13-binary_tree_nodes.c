#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * @tree: pointer to root node of tree
 * Return: 0 if tree NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t node = 0;

	if (tree)
	{
		node += (tree->left || tree->right) ? 1 : 0;
		node += binary_tree_nodes(tree->left);
		node += binary_tree_nodes(tree->right);
	}
	return (node);
}
