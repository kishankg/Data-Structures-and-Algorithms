//Do it using heap store the minimum in first and remove the lowest add it to pointer and push the pop()->next

// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;
// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
Node* mergeKLists(Node* arr[], int N);
/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;
           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;
           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Node *res = mergeKLists(arr,N);
		printList(res);
   }
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*Linked list Node structure
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 
/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */

struct CustomCompare
{
    bool operator()(const Node* A, const Node* B)
    {
        return A->data < B->data;
    }
};

Node * mergeKLists(Node *arr[], int N)
{
       // Your code here
       Node* head = new Node(0);
       
       priority_queue<Node*, vector<Node*>, CustomCompare> p;
       
       for(int i=1;i<N;i++)
       {
           head = merge
       }
       
       return head->next;
}

