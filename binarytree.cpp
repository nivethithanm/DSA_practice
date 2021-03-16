

//Given a binary tree, find its minimum depth.

int minDepth(Node *node) {
    
    // Your code here
    //Node* left = node->left;
    //Node* right = node->right;
    
    if (node == NULL){
        return 0;
    }
    
    if (node->left == NULL && node->right == NULL){
        return 1;
    }
    
    else if (node->right != NULL && node->left != NULL){
        if (minDepth(node->right) > minDepth(node->left)){
            
            return minDepth(node->left)+1;
        }
        else
        {
            return minDepth(node->right)+1;
        }
    }
    else if (node-> right != NULL){
        return minDepth(node->right)+1;
    }
    
    else{
        return minDepth(node->left)+1;
    }
}


//Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST. 

Node* insert(Node* root, int Key)
{
    
    // Your code here
    if (root->left == NULL && Key < root-> data){
        root-> left = new Node(Key);
    }
    else if (root->right == NULL && Key > root-> data){
        root-> right = new Node(Key);
    }
    else if (root->left != NULL && Key < root-> data){
        insert(root->left, Key);
    }
     else if (root->right != NULL && Key > root-> data){
        insert(root->right, Key);
    }
    
    
}


//Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.

Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   while (root != NULL){
       
       if (root->data > n1 && root-> data > n2){
           root = root->left;
       }
       
       else if (root->data < n1 && root->data < n2){
           root = root->right;
           
       }
       
       else
        break;
       
   }
   
   return root;
   
}


//Given a Binary Search Tree and a node value X. Delete the node with the given value X from the BST. If no node with value x exists, then do not make any change. 

// Return the root of the modified BST after deleting the node with value X
Node* minValueNode(Node* node)
{
    Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

Node *deleteNode(Node *root,  int X)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted is 
    // smaller than the root's
    // key, then it lies in left subtree
    if (X < root->data)
        root->left = deleteNode(root->left, X);
 
    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (X > root->data)
        root->right = deleteNode(root->right, X);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        Node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


