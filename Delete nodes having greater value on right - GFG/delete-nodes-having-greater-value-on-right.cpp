//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends

class Solution
{
    public:
    
    Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* nxt = nullptr;
    
    while (head != nullptr) {
        nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev; // Return the new head of the reversed list
}

    Node *compute(Node *head)
    {
        Node* ptr = reverse(head);
        Node* curr = ptr;
        while(curr->next != nullptr){
            if(curr->data > curr->next->data){
                curr->next = curr->next->next;
            }else {
                curr = curr->next;
            }
        }
        return reverse(ptr);
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends