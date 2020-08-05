/*
Find the intersection point of 2 linked lists
*/

int intersectPoint(Node* head1, Node* head2)
{
    int countOne = 0, countTwo = 0;
    Node *temp = head1, *alt1 = head1, *alt2 = head2;
    while(temp != NULL){
        countOne++;
        temp = temp->next;
    }
    temp = head2;
    while(temp != NULL){
        countTwo++;
        temp = temp->next;
    }
    int difference = countOne > countTwo ? countOne - countTwo : countTwo - countOne;
    int k = difference;
    if(countOne >= countTwo){
        while(k > 0 && alt1){
            alt1 = alt1->next;
            k--;
        }
    }
    else{
        while(k > 0 && alt2){
            alt2 = alt2->next;
            k--;
        }
    }
    while(alt1 && alt2){
        if(alt1 == alt2)
            return alt1->data;
        alt1 = alt1->next;
        alt2 = alt2->next;
    }
    return -1;
}