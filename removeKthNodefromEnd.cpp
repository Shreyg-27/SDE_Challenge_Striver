Node* removeKthNode(Node* head, int K)

{

    // Fisrt of all assign the dummy node "n".

    Node*n= new Node();

    n->next= head;

  // Now assign the two pointers p1 and p2 and initialize with dummy node.

    Node* p1= n;

    Node* p2= n;

// Now move the p1 pointer upto the given value of "K".

    for(int i=1; i<=K; i++){

      p1= p1->next;

    }

    // Now move the p1 and p2 pointers by one step till p1 reach to the null. 

    while(p1->next!=NULL){

        p1= p1->next;

        p2= p2->next;

 

    }

    // As the p1 reach to the null next of p2 points the next of next of p2 and then return the next of new node.

    p2->next= p2->next->next;

    return n->next;

}
