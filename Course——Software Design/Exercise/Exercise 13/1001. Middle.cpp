#include <stdio.h>
#include <algorithm>
using namespace std;
 
struct ListNode{
	int val;
	ListNode *next;
	ListNode():val(0), next(NULL){};
	ListNode(int val):val(val), next(NULL){}
};
int mid[1000000]; 
//you just need submit this function
int middleItem(ListNode *head){
	ListNode *loc = head;
	int cnt = 1;
	while ( loc->next != NULL )
	{
		mid[cnt++] = loc->val;
		loc = loc->next;
	}  
	return mid[cnt/2];
	
}
 
int main(){
	int size = rand() % 100000 + 1;
	ListNode *dummy = new ListNode(0);
	ListNode *prev = dummy;
	int middleValue = 0;
	for (int i = 0; i < size; i++){
		int val = rand() % 100000;
		if (i == (size - 1) / 2) middleValue = val;
		ListNode *temp = new ListNode(val);
		prev->next = temp;
		prev = temp;
	}
 
	if (middleItem(dummy->next) == middleValue){
		puts("YES");
	} else{
		puts("NO");
	}
	return 0;
}
