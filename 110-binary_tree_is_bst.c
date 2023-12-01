#include "binary_trees.h"
#include "limits.h"

/**
 * is_valid - if is a valid binary search tree.
 * @tree: root node.
 * @lo: smallest node.
 * @hi: largest node.
 *
 * Return: 1, or, 0.
 */
int is_valid(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_valid(tree->left, lo, tree->n - 1) &&
			is_valid(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - if tree valid for binary search.
 * @tree: root node.
 *
 * Return: 1 or 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_valid(tree, INT_MIN, INT_MAX));
}
