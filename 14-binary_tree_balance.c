#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: The balance factor of the tree or 0 if the tree is null
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t height_l, height_r;
	int balance_f;

	if (tree == NULL)
		return (0);

	height_l = binary_tree_height(tree->left);
	height_r = binary_tree_height(tree->right);

	balance_f = (int)(height_l - height_r);
	balance_f += (tree->left ? 0 : -1);
	balance_f -= (tree->right ? 0 : -1);

	return (balance_f);
}

/**
 * binary_tree_height - print binary tree's height
 * @tree: pointer to the binary tree
 *
 * Return: size_t height value
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_r, height_l;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL || tree->right != NULL)
	{
		height_l = binary_tree_height(tree->left);
		height_r = binary_tree_height(tree->right);
		return (1 + (height_l > height_r ? height_l : height_r));
	}
	return (0);
}
