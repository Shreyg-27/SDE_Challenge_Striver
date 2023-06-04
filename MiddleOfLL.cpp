/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    // Write your code here
    int count =0;
    Node* curr = head;
    while (curr!=NULL){
        count++;
        curr = curr->next;

    }
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    if (count%2==0){
        return slow->next;
    }
    else{
        return slow;
    }
}

