/*
Function to find the Kth Smallest Element in a BST
*/

/*
Can follow any iterative traversals
*/

int KthSmallestElementBST(TreeNode *A, int B){
    stack <TreeNode *> st;
    vector <int> value;
    st.push(A);
    while(!st.empty()){
        TreeNode *curr = st.top();
        st.pop();
        if(curr->val != -1)
            value.push_back(curr->val);
        if(curr->left)
            st.push(curr->left);
        if(curr->right)
            st.push(curr->right);
    }
    sort(value.begin(), value.end());
    /*for(auto i : value)
        cout<<i<<" ";
    cout<<endl*/
    return value[B - 1];
}

/*
NOTE :-
To return the Kth smallest element from the end , just subtract from the size of the vector
To return the largest element , return from the end
*/