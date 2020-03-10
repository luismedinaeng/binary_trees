#include "binary_trees.h"

/**
 *binary_tree_preorder - prints binary tree by preorder
 *@tree: constant binary tree
 *@func: func to print node's value
 *
 *Return: nothing, it's a void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, *func);
	binary_tree_preorder(tree->right, *func);
}
