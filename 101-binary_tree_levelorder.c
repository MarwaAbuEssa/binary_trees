#include "binary_trees.h"

levelorder_queue_t *init_node(binary_tree_t *node);
void empty_node_queue(levelorder_queue_t *head);
void que_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * init_node - init a new node for queue.
 * @node: new node.
 *
 * Return: NULL or new node.
 */
levelorder_queue_t *init_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * empty_node_queue - empty levelorder_queue_t.
 * @head: head of the queue.
 */
void empty_node_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * que_push - pushes nodes into a levelorder_queue_t.
 * @node: binary tree node
 * @head: head of the queue.
 * @tail: tail of the queue.
 * @func: func for node.
 *
 * Description:  exits with a status code 1 if failed.
 */
void que_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = init_node(node->left);
		if (new == NULL)
		{
			empty_node_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right != NULL)
	{
		new = init_node(node->right);
		if (new == NULL)
		{
			empty_node_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 * pop - Pop of levelorder_queue_t.
 * @head: head of queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_levelorder - Traverses a binary tree
 * @tree: pointer to root node.
 * @func: function for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = init_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		que_push(head->node, head, &tail, func);
		pop(&head);
	}
}
