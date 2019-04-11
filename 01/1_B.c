/* 
B : データ数が未知の場合にデータとしてポインタによる線形リスト構造を使用した場合

a. データの入力順に総和を求めたとき
b. データ入力後に、絶対値に関して昇順に並べ替えた後に総和を求めたとき
*/

#include <stdio.h>
#include <float.h>
#include <stdlib.h>

struct node {
	double content;
	struct node *next;
};

struct node *insert_rear(double num, struct node *nodes)
{
	struct node *item;
	struct node *top;

	top = nodes;

	item = (struct node *)malloc(sizeof(struct node));
	item->content = num;
	item->next = NULL;

	if (nodes == NULL) {
		nodes = item;
		return nodes;
	}

	while (nodes->next != NULL) {
		nodes = nodes->next;
	}

	nodes->next = item;

	return top;

}

double xabs(double num)
{
	if (num < 0) {
		num = num * -1;
	}
	return num;
}

double get_con(struct node *nodes, int num)
{
	struct node *temp;
	temp = nodes;
	for (int j = 0; j != num; j++) {
		temp = temp->next;
	}
	return temp->content;
}

void swap_con(struct node *nodes, int num1, int num2)
{
	struct node *temp1;
	struct node *temp2;
	double tmp;

	temp1 = nodes;
	temp2 = nodes;

	for (int i = 0; i != num1; i++) {
		temp1 = temp1->next;
	}
	for (int i = 0; i != num2; i++) {
		temp2 = temp2->next;
	}
	tmp = temp1->content;
	temp1->content = temp2->content;
	temp2->content = tmp;

}

void sort(struct node *nodes, int max_con)
{
	double num_i;
	double num_j;
	for (int j = 0; j < max_con; j++) {
		for (int i = 0; i < max_con; i++) {
			num_i = get_con(nodes, i);
			if (num_i < 0) {
				num_i = num_i * -1;
			}
			num_j = get_con(nodes, j);
			if (num_j < 0) {
				num_j = num_j * -1;
			}
			if (num_i > num_j) {
				swap_con(nodes, i, j);
			}
		}
	}
}

double a(struct node *nodes)
{
	double answer = 0;
	struct node *temp = nodes;
	while (temp != NULL) {
		answer += temp->content;
		temp = temp->next;
	}
	return answer;
}

double b(struct node *nodes)
{
	double answer = 0;
	sort(nodes, 20);
	for (int i = 0; i <= 20; i++) {
		answer += get_con(nodes, i);
#ifdef DEBUG
		printf("num[%d] = %f\n", i, get_con(nodes, i));
#endif
	}
	return answer;
}

int main(void)
{
	char buf[128];
	double input;
	struct node *list;
	int i;

	i = 0;
	list = NULL;

	while (fgets(buf, sizeof(buf), stdin) != NULL) {
		sscanf(buf, "%le", &input);
		list = insert_rear(input, list);
		i++;
	}
	printf("a() = %f\n", a(list));
	printf("b() = %f\n", b(list));
	return 0;
}

/*
参考URL : https://daeudaeu.com/programming/c-language/list-structure/

   */
