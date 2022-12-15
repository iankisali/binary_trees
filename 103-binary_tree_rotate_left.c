#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to root node of tree
 * Return: pointer to new root
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	root = tree->right;

	if (root->left)
	{
		tree->right = root->left;
		root->left->parent = tree;
	}
	else
	{
		tree->right = NULL;
	}
	root->left = tree;
	root->parent = tree->parent;
	tree->parent = root;

	return (root);
}
