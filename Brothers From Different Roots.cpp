#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

int countPairs(Node* root1, Node* root2, int x);

// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node* root1 = NULL;
        Node* root2 = NULL;
        int n1, n2, k;
        cin>>n1;
        for(int i=0; i<n1; i++)
        {
            cin>>k;
            insert(&root1, k);
        }
        cin>>n2;
        for(int i=0; i<n2; i++)
        {
            cin>>k;
            insert(&root2, k);
        }
        int s;
        cin>>s;
        cout<<countPairs(root1, root2, s)<<"\n";
    }
    return 0;
}


// } Driver Code Ends


//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/
// You are required to complete this function

 int bs(int n,vector<int>a,int x)
 {
     int l=0;int r=n-1;
     while(l<=r)
     {
         int mid=l+(r-l)/2;
         if(a[mid]==x)
         return mid;
         else if(a[mid]>x)
             {r=mid-1;}
        else if(a[mid]<x) {l=mid+1;}
     }
     return -1;
 }
 void inorder1(Node*root,vector<int>&a)
 {
     if(root)
     {
         inorder1(root->left,a);
         a.push_back(root->data);
         inorder1(root->right,a);
     }
 }
 void inorder2(Node*root,vector<int>&b)
 {
     if(root)
     {
         inorder2(root->left,b);
         b.push_back(root->data);
         inorder2(root->right,b);
     }
 }
int countPairs(Node* root1, Node* root2, int x)
{
  vector<int>a;
  vector<int>b;
  inorder1(root1,a);
  inorder2(root2,b);
  int c=0;
  for(int i=0;i<a.size();i++)
  {
      if(bs(b.size(),b,x-a[i])!=-1)
      {
          c++;
      }
  }
  return c;
}