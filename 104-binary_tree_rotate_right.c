#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to root node of tree
 * Return: pointer to root node
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	root = tree->left;
	if (root->right)
	{
		tree->left = root->right;
		root->right->parent = tree;
	}
	else
		tree->left = NULL;

	root->right = tree;
	root->parent = tree->parent;
	tree->parent = root;

	return (root);
}
