/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     // base case 
     int length =1;
     if (head==NULL || head->next==NULL || k==0){
          return head;
     }
     Node* temp = head;
     while (temp->next!=NULL){
          ++length;
          temp = temp->next;
     }
     // make the circular ll 
     temp->next = head;
     // when k>length 
     k = k%length;
     int end = length-k; // top get to the end of the list 
     while (end--){
          temp = temp->next;     
     }
     //  breaking the last node and pointing it to null 
     head = temp->next;
     temp->next = NULL;
     return head;
}
