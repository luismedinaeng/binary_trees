#include "binary_trees.h"

int binary_tree_is_avl_values(const binary_tree_t *tree, int min_v, int max_v);

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_avl_values(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_is_avl_values - Checks if a binary tree is a valid AVL
 * @tree: Pointer to the root node of the tree to check
 * @min_v: Minimun value to check the childs
 * @max_v: Maximum value to check the childs
 *
 * Return: 1 if is a valid AVL, otherwise 0
 */
int binary_tree_is_avl_values(const binary_tree_t *tree, int min_v, int max_v)
{
	int tree_balance = binary_tree_balance(tree);

	if (tree == NULL)
		return (1);
	if ((tree->n > min_v && tree->n < max_v) &&
			(tree_balance >= -1  && tree_balance <= 1))
		return (binary_tree_is_avl_values(tree->left, min_v, tree->n) &&
							binary_tree_is_avl_values(tree->right, tree->n, max_v));
	return (0);
}

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
