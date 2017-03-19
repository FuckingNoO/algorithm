#include <iostream>
#include <sys/malloc.h>
using namespace std;


typedef int elementType;

typedef struct LinkNode{
	struct LinkNode* next;
	elementType data;
} Link,*ptrLink;


/**
 * whether empty
 */
bool is_Empty(ptrLink L){
	if(L->next==NULL){
		return true;
	}
	return false;
}

/**
 * Linked_list creation
 */
ptrLink create(){
	ptrLink h;
	h=(ptrLink)malloc(sizeof(Link));
	if(h==NULL){
		cout<<"allocation failed"<<endl;
		return false;
	}
	h->data=0;
	h->next=NULL;
	return h;
}

/**
 * insert specific element
 */
bool is_insert(ptrLink L,elementType e){
	ptrLink p,h;
	h=L;
	p=(ptrLink)malloc(sizeof(Link));
	if(p==NULL){
		cout<<"allocation failed"<<endl;
		return false;
	}
	p->data=e;
	p->next=h->next;
	h->next=p;
	return true;
}

/**
 * delete the specific element 
 */
bool is_remove(ptrLink L, elementType e){
	ptrLink p,t;
	p=L;
	while(p!=NULL&&p->data!=e){
		t=p;
		p=p->next;
	}
	if(p==NULL){
		cout<<"没有这个元素"<<endl;
		return false;
	}
	t->next=p->next;
	free(p);
	return true;
}

/**
 * search specific element
 */
elementType search(ptrLink L,elementType e){
	ptrLink p;
	p=L;
	while(p!=NULL&&p->data!=e){
		p=p->next;
	}
	if(p==NULL){
		cout<<"没有这个元素！"<<endl;
		return NULL;
	}
	return p->data;
}

/**
 *print_Linked_List
 */
void print_Linked_List(ptrLink L){
	ptrLink p;
	p=L;
	while(p!=NULL){
		cout<<p->data<<endl;
		p=p->next;
	}
}

/**
 * free Linked_list
 */

void free_Linked_List(ptrLink L){
	//todo
}

int main(int argc,char* argv[]){
	ptrLink L;
	int n,x,s,r;
	L=create();	
	if(is_Empty(L)==true){
		cout<<"链表为空，请插入元素！"<<endl;
	}
	cout<<"请输入要插入的元素个数："<<endl;
	cin>>n;
	cout<<endl;
	cout<<"请依次输入这些数字"<<endl;
	while(n>0){
		cin>>x;
		if(is_insert(L,x)==true){
			cout<<"插入成功！"<<endl;
		}
		n--;
	}
	print_Linked_List(L);

	cout<<"请输入你想要查找的元素："<<endl;
	cin>>s;
	cout<<search(L,s)<<endl;
	cout<<"请输入你想要删除的元素："<<endl;
	cin>>r;
	if(is_remove(L,r)==true){
		cout<<"删除成功！"<<endl;
	}else{
		cout<<"删除失败！"<<endl;
		return 1;
	}
	print_Linked_List(L);
	return 0;
}
