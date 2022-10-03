/****************************************************************
 You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.
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

Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
    if(M==0){
        return NULL;
    }
    if(N==0){
        return head;
    }
    Node *temp = head;
    while(temp!=NULL){
        int a =M;
        while(a!=1){
            temp = temp->next;
            a--;
            if(temp==NULL){
                return head;
            }
        }
        int b =N;
        while(b!=0){
            Node *todelete = temp->next;
            temp->next = temp->next->next;
            delete todelete;
            b--;
            if(temp->next==NULL){
                return head;
            }
        }
        temp = temp->next;
    }
    return head;
}
