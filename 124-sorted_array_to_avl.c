#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to root node of avl or 0
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t mid;

	if (!array)
		return (0);
	mid = (size - 1) / 2;
	tree = binary_tree_node(NULL, array[mid]);
	sort_helper(&tree, array, -1, mid);
	sort_helper(&tree, array, mid, size);
	return (tree);
}

/**
 * sort_helper - helper that builds an AVL tree from an array
 * @root: double pointer to the root node of the subtree
 * @array: a pointer to the first element of the array to be converted
 * @low: lower bound index
 * @high: upper bound index
 */

void sort_helper(avl_t **root, int *array, size_t low, size_t high)
{
	avl_t *new = NULL;
	size_t mid;

	if (high - low > 1)
	{
		mid = (high - low) / 2 + low;
		new = binary_tree_node(*root, array[mid]);
		if (array[mid] > (*root)->n)
			(*root)->right = new;
		else if (array[mid] < (*root)->n)
			(*root)->left = new;
		sort_helper(&new, array, low, mid);
		sort_helper(&new, array, mid, high);
	}
}
