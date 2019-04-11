#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct list {
	char name[32];
	int point;
	struct list *next;
};

struct list *ins_char(char *name, int point, struct list *lists)
{
	struct list *head;
	struct list *item;
	struct list *temp;

	item = (struct list *)malloc(sizeof(struct list));
	strcpy(item->name, name);
	item->point = point;
	temp = lists;
	if (temp == NULL) {
		item->next = NULL;
		return item;
	} else if (temp->next == NULL) {
		if (strcmp(item->name, temp->name) < 0) {
			item->next = temp;
			head = item;
			return head;
		} else {
			temp->next = item;
			item->next = NULL;
			return temp;
		}
	} else {
		head = temp;
		while (temp != NULL) {	// `temp-.nuxt != NULL`で回す
			while (true) {
				//先頭との比較
				//temp->nextとの比較
				//次に回す
				if (head == temp
				    && (strcmp(item->name, temp->name) <= 0)) {
					item->next = temp;
					head = item;
					return head;
				} else if (temp->next == NULL
					   ||
					   ((strcmp(temp->name, item->name) <=
					     0)
					    &&
					    (strcmp
					     (item->name,
					      temp->next->name) <= 0))) {
					item->next = temp->next;
					temp->next = item;
					return head;
				}
				temp = temp->next;
			}
		}
	}
	return head;
}

struct list *ins_point(struct list *inputs, struct list *outputs)
{
	struct list *temp;
	struct list *head;
	struct list *item;
	temp = outputs;

	item = (struct list *)malloc(sizeof(struct list));
	strcpy(item->name, inputs->name);
	item->point = inputs->point;

	if (temp == NULL) {	//0つのとき
		item->next = NULL;
		return item;
	} else if (temp->next == NULL) {	//1つのとき
		if (item->point >= temp->point) {
			item->next = temp;
			head = item;
			return head;
		} else {
			temp->next = item;
			item->next = NULL;
			return temp;
		}
	} else {		//2つのとき
		head = temp;
		//先頭の時
		//temp->next == NULLのとき || temp->nextとの比較
		//次に回す
		while (temp != NULL) {
			while (true) {
				if (head == temp
				    && (item->point >= temp->point)) {
					item->next = temp;
					head = item;
					return head;
				} else if (temp->next == NULL
					   || ((temp->point >= item->point)
					       && (item->point >=
						   temp->next->point))) {
					item->next = temp->next;
					temp->next = item;
					return head;
				}
				temp = temp->next;
			}
		}
	}
	return head;
}

void plists(struct list *lists)
{
	struct list *tmp = lists;
	while (tmp != NULL) {
		printf("name = %s, point = %d\n", tmp->name, tmp->point);
		tmp = tmp->next;
	}
}

int main(void)
{
	char buf[128];
	char name[32];
	int point;
	struct list *lists;
	struct list *point_sorted;
	int i;

	i = 0;
	lists = NULL;

	while (fgets(buf, sizeof(buf), stdin) != NULL) {
		sscanf(buf, "%s %d", name, &point);
		lists = ins_char(name, point, lists);
		i++;
	}
	printf("辞書順によるソート\n");
	plists(lists);
	point_sorted = NULL;
	while (lists != NULL) {
		point_sorted = ins_point(lists, point_sorted);
		lists = lists->next;
	}
	printf("数字順によるソート\n");
	plists(point_sorted);
	return 0;
}
