#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to root node of tree
 *
 * Return: 0 if tree is NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int l, r;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);
	l = binary_tree_is_full(tree->left);
	r = binary_tree_is_full(tree->right);
	return (l * r);
}
