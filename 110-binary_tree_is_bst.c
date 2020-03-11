#include "binary_trees.h"

int binary_tree_is_bst_values(const binary_tree_t *tree, int min_v, int max_v);

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if is a valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_bst_values(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_is_bst_values - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min_v: Minimun value to check the childs
 * @max_v: Maximum value to check the childs
 *
 * Return: 1 if is a valid BST, otherwise 0
 */
int binary_tree_is_bst_values(const binary_tree_t *tree, int min_v, int max_v)
{
	if (tree == NULL)
		return (1);
	if (tree->n > min_v && tree->n < max_v)
		return (binary_tree_is_bst_values(tree->left, min_v, tree->n) &&
						binary_tree_is_bst_values(tree->right, tree->n, max_v));
	return (0);
}
