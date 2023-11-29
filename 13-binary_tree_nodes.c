#include "binary_trees.h"

/**
 * binary_tree_nodes - nodes with at least 1 child
 * @tree: tree to count nodes
 *
 * Return: 0 if null tree or count of nodes at least 1
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree)
	{
		nodes += (!tree->left && !tree->right) ? 1 : 0;
		nodes += binary_tree_nodes(tree->left);
		nodes += binary_tree_nodes(tree->right);
	}
	return (leaves);
}
