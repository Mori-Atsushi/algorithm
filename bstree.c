/* E1237 森篤史 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int x;
	struct node *left;
	struct node *right;
} node_t;

node_t * root;

void search(int a, node_t *root) {
	if(root == NULL)
		printf("2分探索木に整数%dは存在しません。\n", a);
	else if(a == root->x)
		printf("2分探索木に整数%dは存在します。\n", a);
	else if(a < root->x)
		search(a, root->left);
	else
		search(a, root->right);
}

node_t *talloc(void) {
	return((node_t *) malloc(sizeof(node_t)));
}

node_t *insert(int a, node_t *root) {
	if(root == NULL) {
		root = talloc();
		root->x = a;
		root->left = NULL;
		root->right = NULL;
	} else if(a == root->x) {
		printf("整数%dはすでに2分探索木に挿入されています。\n", a);
	} else if(a < root->x) {
		root->left = insert(a, root->left);
	} else {
		root->right = insert(a, root->right);
	}
	return(root);
}

char children_type(node_t *ptr) {
	if(ptr->left == NULL) {
		if(ptr->right == NULL)
			return('n');
		else
			return('r');
	} else if(ptr->right == NULL) {
		if(ptr->left == NULL)
			return('l');
		else
			return('b');
	}
	return '0';
}

node_t *delete_node(node_t *ptr) {
	char c;
	node_t *p, *parent_of_p;

	c = children_type(ptr);

	if(c == 'n')
		ptr = NULL;
	else if(c == 'l')
		ptr = ptr->left;
	else if(c == 'r')
		ptr = ptr->right;
	else {
		p = ptr->right;
		if((children_type(p) == 'r') || (children_type(p) == 'n')) {
			p->left = ptr->left;
			ptr = p;
		} else {
			while(p->left != NULL) {
				parent_of_p = p;
				p = p->left;
			}
			parent_of_p->left = p->right;
			p->left = ptr->left;
			p->right = ptr->right;
			ptr = p;
		}
	}
	return(ptr);
}

node_t *delete_item(int a, node_t *root) {
	if(root == NULL)
		printf("整数%dは2分探索木に存在しません。\n", a);
	else if(a == root->x)
		root = delete_node(root);
	else if(a < root->x)
		root->left = delete_item(a, root->left);
	else
		root->right = delete_item(a, root->right);
	return(root);
}

void print_inorder(node_t *root) {
	if(root != NULL) {
		print_inorder(root->left);
		printf("%d\n", root->x);
		print_inorder(root->right);
	}
}

int main(void) {
	char c;
	int a;
	root = NULL;

	while(1) {
		printf("コマンド：");
		scanf(" %c", &c);
		switch(c) {
			case 's':
				scanf("%d", &a);
				search(a, root);
				break;
			case 'i':
				scanf("%d", &a);
				root = insert(a, root);
				break;
			case 'd':
				scanf("%d", &a);
				root = delete_item(a, root);
				break;
			case 'p':
				print_inorder(root);
				break;
			case 'q':
				return 0;
			default:
				printf("s, i, d, p, またはqを入力してください。\n");
		}
	}

	return 0;
}