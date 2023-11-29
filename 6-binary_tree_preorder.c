#include "binary_trees.h"
/**
 * binary_tree_preorder - nodes pre-order traversal
 * @tree: pointer to root of tree
 * @func: func pointer to each node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
