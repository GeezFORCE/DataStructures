/*
CPP Function that takes in a vector of integers and returns if it is a valid pre-order traversal
of a BST.
*/

bool validateBSTFromPreOrder(vector <int> &A){
    stack <int> st;
    int root = INT_MIN;
    for(int i = 0;  i < A.size(); i++){
        if(A.at(i) < root)
            return false;
        while(!st.empty() && st.top() < A.at(i)){
            root = st.top();
            st.pop();
        }
        st.push(A.at(i));
    }
    return true;
}

/*
Recursive Solution that makes better sense
*/

bool validateBSTFromPreOrder(vector <int> &A){
    size = A.size();
    if(size == 0 || size == 1)
        return false;
    int root = A.at(0);
    vector <int> left;
    vector <int> right;
    int st = 1;
    while(st < n && A.at(st) <= root){
        left.push_back(A.at(st));
        st++;
    }
    st = 1;
    while(st < n && A.at(st) > root){
        right.push_back(A.at(st));
        st++;
    }
    if(st != n)
        return false;
    return validateBSTFromPreOrder(left) && validateBSTFromPreOrder(right);
}