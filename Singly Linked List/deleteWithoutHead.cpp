//PROBLEM

/*
You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. 
The task is to delete the node. 
Pointer/ reference to head node is not given. 
Note: No head reference is given to you.
      Node to be deleted won't be the last node.
*/


// LOGIC
/*
Copy the contents of next pointer to the current pointer and then delete the next pointer.
*/

// CODE

void deleteNode(Node *node)
{
   node->data = node->next->data;
   Node *temp = node->next;
   node->next = node->next->next;
   delete temp;
}