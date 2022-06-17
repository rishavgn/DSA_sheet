// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    /*You are required to complete this method*/
    // 3 functions
    // 1. check if node is leaf or not
    // 2. find the height of the tree as this becomes the parameter to be compared(since this is the last leaf node)
    // 3. level order traversal and just give one check for leave node and if its leaf node it is equal to heigh or not
    bool isleafnode(Node *root)
    {
        if(root->left==NULL && root->right==NULL)
         return true;
        
      return false; 
    }
    
    int firstleafnode(Node *root)
    {
        if(root==NULL)
         return 0;
        // int level=1;
        int lh = firstleafnode(root->left);
        int rh = firstleafnode(root->right);
        // cout<<1+max(lh,rh);
        return 1+max(lh,rh);
    }
    bool check(Node *root)
    {
        //Your code here
        int flag=1;
       int storedlevel = firstleafnode(root);
        queue<Node*>q;
        q.push(root);
        int level=1;
        
        while(q.empty()==false)
        {
            int qsize=q.size();
            while(qsize--){
            Node* temp= q.front();
            if(isleafnode(temp)==true && level!=storedlevel)
            {
                flag=0;
            }
            if(temp->left!=NULL)
             q.push(temp->left);
             q.pop();
             
            if(temp->right!=NULL)
             q.push(temp->right);
             
            // cout<<level<<endl;
            }
          level++;     
        }
        return flag;
    }
};

// { Driver Code Starts.
// Driver program to test size function
int main()
{
    int t;
    cin>> t;
    getchar();
    while (t--)
    {
        string s;
        getline( cin, s );
        Node* head = buildTree( s );
        Solution obj;
        cout << obj.check(head) << endl;
    }
    return 0;
}
  // } Driver Code Ends