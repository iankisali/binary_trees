#include "binary_trees.h"

/**
 * insert_node - node value insertion in avl
 * @tree: double pointer to root node of avl tree
 * @parent: parent node of avl
 * @new: double poitter left or right insertion
 * @value: inseetion value
 * Return: pointer to new root after insertion or 0
 */

avl_t *insert_node(avl_t **tree, avl_t *parent, avl_t **new, int value)
{
	int val;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));
	if ((*tree)->n > value)
	{
		(*tree)->left = insert_node(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (0);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = insert_node(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (0);
	}
	else
		return (*tree);

	val = binary_tree_balance(*tree);
	if (val > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (val > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (val < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (val < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - inserts a value into an AVL tree.
 * @tree: type **pointer to the root node of the AVL tree to insert into.
 * @value: value to store in the node to be inserted
 * Return: inserted node, or NULL if fails.
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	insert_node(tree, *tree, &new, value);
	return (new);
}
