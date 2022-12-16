#include "binary_trees.h"

/**
 * array_to_bst - builds a binary search tree from an array
 * @array: pointer to first element in array
 * @size: number of elements of array
 * Return: pointer to root node of BST
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree;
	size_t num;

	tree = NULL;
	for (num = 0; num < size; num++)
		bst_insert(&tree, array[num]);
	if (num == size)
		return (tree);
	return (0);
}
