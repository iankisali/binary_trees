#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to root node of tree
 * @value: value to search in the tree
 * Return: pointer to the node containing a value equals to value or NULL
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree && value < tree->n)
		return (bst_search(tree->left, value));
	if (tree && value > tree->n)
		return (bst_search(tree->right, value));
	return ((bst_t *)tree);
}
