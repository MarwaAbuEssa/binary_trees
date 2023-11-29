#include "binary_trees.h"

/**
 * binary_tree_depth - depth of node at binary tree.
 * @tree: node to measure the depth.
 *
 * Return: 0 If tree is NULL or depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
