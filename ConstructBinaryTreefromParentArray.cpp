// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector <int> &v)
{
    sort( v.begin() , v.end() );
    for( int i=0 ; i<v.size() ; i++ )
        cout<< v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root)
{
    vector <int> v;
    queue <Node*> q;
    
    q.push(root);
    
    Node* next_row = NULL;
    
    while(!q.empty())
    {
        Node* n = q.front();
        q.pop();
        
        if(n==next_row)
        {
            sort_and_print(v);
            next_row = NULL;
        }
        
        v.push_back(n->data);
        
        if(n->left)
        {
            q.push(n->left);
            if(next_row == NULL) next_row = n->left;
        }
        
        if(n->right)
        {
            q.push(n->right);
            if(next_row == NULL) next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node *createTree(int parent[], int n);

/* Driver program to test above function*/


 // } Driver Code Ends
/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution{
  public:
  Node* cre(int g){
      Node* t = new Node(g);
      return t;
  }
    //Function to construct binary tree from parent array.
    Node *createTree(int a[], int n)
    {   Node* h=NULL;
       int g =0;
   vector<Node*> s;
   int j = 1,d[n];
   for(int i=0;i<n; ++i)
   
{  Node* t = cre(i);
    s.push_back(t);
      d[i] = 0;}
  
   for(int i=0; i<n; ++i){
       
           if(a[i] == -1){
           
          h=  s[i]; 
            
           
               continue;
           }
     
           
         
          if(! d[a[i]] && s[a[i]])     
        { s[a[i]]->left = s[i];


          d[a[i]]++;
        }
          else if (s[a[i]])
          s[a[i]]->right = s[i];
           
      
       
    } return h;}
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>> n;
        int a[n];
        for( int i=0 ; i<n ; i++ )
            cin>> a[i];
            
        Solution ob;
        
        Node *res = ob.createTree(a,n);
        
        printLevelOrder(res);
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends
