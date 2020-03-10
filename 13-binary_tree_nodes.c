#include "binary_trees.h"

/**
 *binary_tree_nodes - get number of nodes in the binary tree
 *@tree: pointer to binary tree
 *
 *Return: number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t n_nodes_r, n_nodes_l;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	n_nodes_l = binary_tree_nodes(tree->left);
	n_nodes_r = binary_tree_nodes(tree->right);
	return (1 + n_nodes_l + n_nodes_r);
}
