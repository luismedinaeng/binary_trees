#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: Performs a left-rotation on a binary tree
 *
 * Return: A pointer to the new root of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *r_node;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	r_node = tree->right;
	r_node->parent = tree->parent;

	tree->right = r_node->left;
	if (tree->right != NULL)
		tree->right->parent = tree;

	r_node->left = tree;
	tree->parent = r_node;

	return (r_node);
}
