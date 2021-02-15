#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

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
    Node* root = new Node(stoi(ip[0]));
        
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
            currNode->left = new Node(stoi(currVal));
                
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
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

int kthLargest(Node *root, int k);

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int k;
        cin>>k;
        getchar();
        
        cout << kthLargest( head, k ) << endl;
    }
    return 1;
}// } Driver Code Ends


/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
int countnodes(Node*root)
{
    int c=0;
    if(root==NULL)
    {
        return 0;
    }
    c++;
    c+=countnodes(root->left)+countnodes(root->right);
    return c;
}
int kthLargest(Node *root, int K)
{
     int ks=INT_MAX;
    Node*curr=root;
    Node*pre;
    int s=countnodes(root);
    int c=0;
    while(curr)
    {
        if(curr->left==NULL)
        {
            c++;
            if(c==s-K+1)
            {
                ks=curr->data;
            }
            curr=curr->right;
        }
        else
        {
        pre=curr->left;
        while((pre->right!=NULL)&&(pre->right!=curr))
        {
            pre=pre->right;
        }
        if(pre->right==NULL)
        {
            pre->right=curr;
            curr=curr->left;
        }
        else
        {
            c++;
            pre->right=NULL;
            if(c==s-K+1)
            {
                ks=curr->data;
            }
            curr=curr->right;
            
        }
        }
    }
    if(K>c)
    {
        return -1;
    }
    return ks;
}