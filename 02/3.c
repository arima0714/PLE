/*
入力：通常の数式(今回は文字式のため数字の関連で分岐をする必要はない
出力：入力を逆ポーランド記法にしたもの
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char data_type;
typedef struct node_tag {
	data_type data;
	struct node_tag *next;
} node_type;

void initialize(node_type ** pp)
{
	*pp = NULL;
}

int ret_rank(char ch)
{
	if (ch == '=') {
		return 0;
	} else if (ch == ')') {
		return 1;
	} else if ((ch == '+') || (ch == '-')) {
		return 2;
	} else if ((ch == '/') || (ch == '*')) {
		return 3;
	} else if (ch == '(') {
		return 4;
	} else {
		return 5;
	}
}

int is_empty(node_type * p)
{
	if (p == NULL) {
		return true;
	} else {
		return false;
	}
}

data_type top(node_type * p)
{
	if (p == NULL) {
		return '\0';
	} else {
		return p->data;
	}
}

node_type *new_node(data_type x, node_type * p)
{
	node_type *temp;
	temp = (node_type *) malloc(sizeof(node_type));
	if (temp == NULL) {
		return NULL;
	} else {
		temp->data = x;
		temp->next = p;
		return temp;
	}
}

int push(data_type x, node_type ** pp)
{
	node_type *temp;
	temp = new_node(x, *pp);
	if (temp == NULL) {
		return false;
	}
	*pp = temp;
	return true;
}

int pop(node_type ** pp)
{
	node_type *temp;
	if (*pp != NULL) {
		temp = (*pp)->next;
		free(*pp);
		*pp = temp;
		return true;
	} else {
		return false;
	}
}

void reverse_polish()
{
	char ch;
	char read_str[128];
	char out_ch;
	int i;
	node_type *stack;
	initialize(&stack);

	i = 0;

	while ((ch = getchar()) != EOF) {
		read_str[i++] = ch;
		if (i >= 128 - 1) {
			break;
		}
		if(ch == ' ' || ch == '\n' ||ch == '\0') continue;
		while (!is_empty(stack) && (ret_rank(top(stack)) != 4)
		       && (ret_rank(ch) <= ret_rank(top(stack)))) {
			out_ch = top(stack);
			if (out_ch != '\n' && out_ch != '\0' && out_ch != EOF) {
				printf("%c", top(stack));
			}
			pop(&stack);
		}
		if (ret_rank(ch) != 1) {
			push(ch, &stack);
		} else {
			pop(&stack);
		}
	}
	while (is_empty(stack) == false) {
		out_ch = top(stack);
		if (out_ch != '\n' && out_ch != '\0' && out_ch != EOF) {
			printf("%c", top(stack));
		}
		pop(&stack);
	}
	printf("%c", read_str[i - 1]);
	return;
}

int main(void)
{
	reverse_polish();
	return 0;

}
