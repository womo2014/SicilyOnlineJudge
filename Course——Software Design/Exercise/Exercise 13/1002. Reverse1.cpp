#include <stdio.h>

#include <algorithm>

using namespace std;
 
struct ListNode{
	int val;
	ListNode *next;
	ListNode():val(0), next(NULL){};
	ListNode(int val):val(val), next(NULL){}
};
 

 
//you just need submit this function
ListNode* reverse(ListNode *head, int m, int n)
{
    int *a = new int[101];
    ListNode* ans=head;
    ListNode* prev=ans;
    int i=0;
    while(head!=NULL)
    {
        a[i]=head->val;
        head=head->next;
        i++;
    }
    int count=i;    
    for(int i=1;i<count;i++)
    {
        if(i>=(m-1) && i<=n-1)
        {
            ListNode * temp=new ListNode(a[m+n-2-i]);
            ans->next=temp;
            ans=temp;
        }   
        else
        {
            ListNode * temp = new ListNode(a[i]);
            ans->next=temp;
            ans=temp;
        }
    }   
    return prev;
}

 
bool check(ListNode *head, int arr[], int size){
	for (int i = 0; i < size; i++){
		if (!head) return false;
		if (head->val != arr[i]) return false;
		head = head->next;
	}
	return true;
}
 
int main(){
	int size = rand() % 100000 + 1;
	int m = rand() % size + 1, n = rand() % size + 1;
	if (m > n) swap(n, m);
	ListNode *dummy = new ListNode(0);
	ListNode *prev = dummy;
	int arr[size + 1];
	for (int i = 0; i < size; i++){
		int val = rand() % 100000;
		arr[i] = val;
		ListNode *temp = new ListNode(val);
		prev->next = temp;
		prev = temp;
	}
 
	ListNode *head = reverse(dummy->next, m, n);
	reverse(arr + m - 1, arr + n);
	if (check(head, arr, size)){
		puts("YES");
	} else{
		puts("NO");
	}
	return 0;
}