#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        *tree = new Node(val);
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
Node* LCA(Node *root, int , int );
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        #else
    #endif

    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);
        }
        int l,r;
        cin>>l>>r;
        cout<<LCA(root,l,r)->data<<endl;
    }
}

Node* LCA(Node *root, int n1, int n2)
{

    if (n1 > n2) {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
        
    if (root == NULL)
        return NULL;

    // cout << root->data << " " << n1 << " " << n2 << endl;
    
    if (root->data >= n1 && root->data <= n2)
        return root;
    
    if (root->data > n1)
        return root->left == NULL ? root: LCA(root->left, n1, n2);
    
    return root->right == NULL ? root: LCA(root->right, n1, n2);
}
