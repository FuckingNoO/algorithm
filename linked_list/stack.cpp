#include <iostream>
#include <sys/malloc.h>

#define MAX_SIZE 10
using std::cout;
using std::cin;


typedef int elementType;

typedef struct Stack{
	elementType total_size;
	elementType* array;
	elementType* top;
	elementType current_size;
} StackNode,*StkNode;

typedef struct list_Stack{
	elementType data;
	struct list_Stack* next;
}LStack,*lStack;

void l_isEmpty(lStack h){
	if(h->next==NULL)
		return true;
	return false;	
}

lStack l_create(){
	lStack head=(lStack)malloc(sizeof(LStack));
	if(head==NULL){
		cout<<"allocation failed"<<endl;
		exit(0);
	}
	header->next=NULL;
	header->data=0;
	return head;
}

void l_push(){
	//todo
}

void l_pop(){
	//todo

}
/**
 *
 */
bool is_empty(StkNode s){
	if(s->current_size==0)
		return true;
	return false;
}

/**
 *
 */

void create(StkNode* s){
	s->array=(elementType*)malloc(sizeof(elementType)*MAX_SIZE);
	if(s->array==NULL){
		cout<<"allocation failed"<<endl;
		exit(0);
	}
	s->total_size=MAX_SIZE;
	s->current_size=0;
}

/**
 *`
 */
void push(StkNode s, elementType e){
	if(s->current_size==s->total_size){
		cout<<"full"<<endl;
		exit(0);
	}
	s->array[s->current_size++]=e;
}

/**
 *
 */
void pop(){
	if(s->current_size==0){
		cout<<"empty"<<endl;
		exit(0);	
	}
	s->array[--s->current_size]='';

}


int main(int argc,int* argv[]){

	return 0;
}
