/****************************************************************

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

*****************************************************************/

int findIntersection(Node *firstHead, Node *secondHead)

{

   if(firstHead == NULL || secondHead == NULL) return -1;

   

   Node* temp1 = firstHead;

   Node* temp2 = secondHead;

   

   while(temp1!=NULL){

       temp2 = secondHead;

       while(temp2!=NULL){

           if(temp2!=NULL && temp1!=NULL && temp2 == temp1) return temp1->data;

           else temp2 = temp2->next;

       }

       temp1 = temp1->next;

   }

   

   return -1;

}
