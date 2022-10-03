/****************************************************************
Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
 'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.
Example :
Given this linked list: 1 -> 2 -> 3 -> 4 -> 5

For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5

For k = 3, you should return: 3 -> 2 -> 1 -> 5 -> 4

*****************************************************************/
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *kReverse(Node *head, int k)
{
	//Write your code here
    if(head ==NULL || k==0){
        return head;
    }
    
    
    Node *next =NULL;
    Node *curr =head;
    Node *prev =NULL;
    int count =0;
    
    while(curr!=NULL && count <k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr =next;
        count++;
    }
    
    if(next!=NULL){
        head ->next = kReverse(next,k);
    }
    return prev; 
}
