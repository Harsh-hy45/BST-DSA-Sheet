#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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


int KthSmallestElement(Node *root, int k);

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



int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

       getline(cin, s);
       int k = stoi(s);
      //  getline(cin, s);

       cout << KthSmallestElement(root, k) << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


/*Complete the function below

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

// Return the Kth smallest element in the given BST 

int KthSmallestElement(Node *root, int K)
{
    int ks=INT_MIN;
    Node*curr=root;
    Node*pre;
    int c=0;
    while(curr)
    {
        if(curr->left==NULL)
        {
            c++;
            if(c==K)
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
            if(c==K)
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