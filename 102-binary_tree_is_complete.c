#include "binary_trees.h"

levelorder_queue_t *init_node(binary_tree_t *node);
void empty_node_queue(levelorder_queue_t *head);
void que_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * init_node - init a new node.
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
 * empty_node_queue - empty  queue.
 * @head: head of queue.
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
 *
 * Description: exits with a status code of 1.
 */
void que_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new;

	new = init_node(node);
	if (new == NULL)
	{
		empty_node_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}

/**
 * pop - Pops queue.
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
 * binary_tree_is_complete - Checks tree is complete.
 * @tree: root node.
 *
 * Return: 0 or  1.
 *
 * Description: exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = init_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				empty_node_queue(head);
				return (0);
			}
			que_push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				empty_node_queue(head);
				return (0);
			}
			que_push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}
	return (1);
}
