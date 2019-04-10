#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	temp  = lists;

	if (temp == NULL) {	//0個の時
		lists = item;
		item->next = NULL;
	} else if (temp->next == NULL) {	//1個の時                       
		if (strcmp(name, temp->name) < 0) {
			head = item;
			item->next = temp;
		} else {
			temp->next = item;
			item->next = NULL;
			head = item;
		}
	}else{
		while(temp != NULL){//2個以上の時
			if(strcmp(name, temp->name) > 0){
				item->next = temp->next;
				temp->next = item;	
			}else if(temp->next == NULL){
				item->next = NULL;
				temp->next = item;
			}
		}
	}
	return head;
}

int main(void)
{
	char buf[128];
	char name[32];
	int point;
	struct list *lists;
	int i;
	
	i = 0;
	lists = NULL;

	while(fgets(buf, sizeof(buf), stdin) != NULL){
#ifdef DEBUG
		printf("i = %d  ",i);
#endif
		sscanf(buf, "%s %d", name, &point);
		lists = ins_char(name, point, lists);
		i++;
#ifdef DEBUG
		printf("input name = %s, point = %d\n",name,point);
#endif
#ifdef DEBUG
		printf("end?\n");
#endif
	}
	return 0;
}
