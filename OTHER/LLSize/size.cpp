#include<iostream>

class ListNode{
	public:
		int val;
		ListNode* next;
		ListNode(int i):val(i),next(NULL){}

};

int LLsize(ListNode* a);

int main(){
	ListNode* head = new ListNode(0);
	ListNode* temp = head;

	for(int i = 0;i<9;i++){
		temp->next = new ListNode(i+1);
		temp = temp->next;
	}
	
	int size = LLsize(head);
	std::cout<<size<<std::endl;

	return 0;
}


int LLsize(ListNode* a){
	ListNode* loop = a;int i;
	for(i = 0;loop != NULL;i++){
		loop = loop->next;
	}
	return i;
}
