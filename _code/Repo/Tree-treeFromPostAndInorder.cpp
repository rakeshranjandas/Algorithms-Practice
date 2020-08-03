/* program to construct tree using inorder and postorder traversals */
#include<bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
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
/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node)
{
  if (node == NULL)
     return;
   /* then print the data of node */
  printf("%d ", node->data);
  /* first recur on left child */
  preOrder(node->left);
  /* now recur on right child */
  preOrder(node->right);
}
Node *buildTree(int in[], int post[], int n);
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        #else
    #endif
    int t,n;
    cin>>t;
    int in[1000], post[1000];
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>in[i];
        for(int i=0;i<n;i++)
            cin>>post[i];
        Node *root = buildTree(in, post, n);
        preOrder(root);
        cout<<endl;
    }
    return 0;
}


int searchInInorder(int in[], int l, int r, int n) {
    for (int i = l; i <= r; i++)
        if (in[i] == n)
            return i;
    
    return -1;
}

Node *buildTreeUtil(int in[], int l, int r, int pos[], int *pos_i) {

    // cout << *pos_i << " " << pos[*pos_i] << endl;
    // cout << " l " << l << " r " << r << endl;
    
    if (l > r)
        return NULL;
    
    int now_data = pos[*pos_i];
    *pos_i = *pos_i - 1;

    if (l == r)
        return new Node(in[l]);
    
    Node *now_node = new Node(now_data);
    
    int now_index_in = searchInInorder(in, l, r, now_data);
    // cout << " now_index_in " << now_index_in << endl;
    
    now_node->right = buildTreeUtil(in, now_index_in+1, r, pos, pos_i);
    now_node->left = buildTreeUtil(in, l, now_index_in-1, pos, pos_i);

    // cout << now_data 
    //     << " left " <<  (now_node->left == NULL ? 0 : now_node->left->data) 
    //     << " right " <<  (now_node->right == NULL ? 0 : now_node->right->data) << endl;
    
    return now_node;
}

Node *buildTree(int in[], int pos[], int n)
{
    int pos_i = n-1;
    return buildTreeUtil(in, 0, n-1, pos, &pos_i);
}