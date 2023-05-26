#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node * next;
};
struct node *start = NULL;


struct node *insert_beg(struct node * start){
	int x;
	printf("Basa hangi sayiyi eklemek istiyorsun ?");
	scanf("%d",&x);
	struct node * newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode ->val = x;
	if(start==NULL){
		start=newnode;
		start->next=NULL;
	}
	else{
		newnode ->next = start;
		start = newnode;
	}
	return start;
}

struct node * insert_end(struct node * start){
	int x;
	printf("Sona hangi sayiyi eklemek istiyorsun ?\n");
	scanf("%d",&x);
	struct node * newnode, *ptr;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode ->val = x;
	newnode ->next = NULL;
	if(start==NULL){
		start=newnode;
	}
	else{
		ptr = start;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=newnode;
	}

	return start;
}

struct node * insert_after(struct node * start){
	int x, y;
	printf("Hangi sayiyi eklemek istiyorsun ?\n");
	scanf("%d",&x);
	printf("Hangi sayidan sonraya gelsin ?\n");
	scanf("%d",&y);
	struct node * newnode, *ptr, *preptr;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode ->val = x;
	preptr=start;
	ptr=start->next;
	while(ptr!=NULL&&preptr->val!=y){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=newnode;
	newnode->next=ptr;
	
	return start;
	
}

struct node* del_beg(struct node * start){
	if(start==NULL){
		printf("Bastan silinecek eleman bulunmamakta.\n");
	}
	else{
		struct node * ptr;
		ptr = start;
		start = start->next;
		free(ptr);
	}
	return start;
}

struct node * del_node(struct node * start){
	int x;
	printf("Hangi sayi silinsin ?\n");
	scanf("%d",&x);
	struct node *ptr, *preptr;
	ptr= start;
	if (ptr->val=x){
		start=del_beg(start);
		return start;
	}
	else{
		while(ptr !=NULL && ptr->val!=x){
			preptr=ptr;
			ptr=ptr->next;
		}
		if(ptr!=NULL){
			preptr->next=ptr->next;
			free(ptr);
		}
		return start;
	}
}

void display(struct node * start){
	if(start==NULL) printf("Yazdirilacak eleman yok.");
	else{
		struct node * ptr; 
		ptr=start;
		while(ptr->next!=NULL){
			printf("%d ",ptr->val);
			ptr=ptr->next;
		}
		printf("%d ",ptr->val);
	}
	printf("\n");
}

struct node* del_end(struct node * start){
	if(start==NULL){
		printf("Sondan silinecek bir eleman yok\n");
	}
	else if(start->next!=NULL){
		struct node * ptr;
		ptr = start;
		while(ptr->next->next!=NULL){
			ptr=ptr->next;
		}
		free(ptr->next);
		ptr->next=NULL;
		return start;
	}
	else{
		start=del_beg(start);
		return start;
	}
	return start;
}

int main() {
	start = insert_beg(start);
	start = insert_end(start);
	start = insert_after(start);
	display(start);
	start=del_beg(start);
	display(start);
	start=del_end(start);
	display(start);
	start=del_node(start);
	display(start);
}
