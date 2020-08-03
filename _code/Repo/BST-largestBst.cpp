#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
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
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);    
}
int largestBst(Node *root);
/* Driver program to test size function*/
int main()
{

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        #else
    #endif

  int t;
  scanf("%d", &t);
while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
    cout<<largestBst(root)<< endl;
  }
  return 0;
}

void preOrder(Node *root, int *v_min, int *v_max, int *max_size, int *cur_size) {
    if (root == NULL)
        return;
    
    int l_min = -1, l_max = -1, r_min = -1, r_max = -1, l_size = 0, r_size = 0;
    
    preOrder(root->left, &l_min, &l_max, max_size, &l_size);
    preOrder(root->right, &r_min, &r_max, max_size, &r_size);
    
    if (
        l_size >= 0 && r_size >= 0
        &&
        (
            (l_max == -1 && r_min == -1)                        // this is a leaf node, is a bst
            ||
            (l_max == -1 && r_min != -1 && root->data <= r_min)  // has no left child
            ||
            (l_max != -1 && r_min == -1 && l_max <= root->data)  // has no right child
            ||
            (l_max <= root->data && root->data <= r_min)        // has both children
        )
    ) {   
        *cur_size = l_size + r_size + 1;
        *max_size = max(*max_size, *cur_size);
        
    } else {
        *cur_size = -1;
    }
    
    *v_min = l_min == -1 ? root->data : l_min;
    *v_max = r_max == -1 ? root->data : r_max;
    
    // cout << root->data << " lsize = " << l_size << ", r_size = " << r_size 
    //     << ", (" << l_min << "," << l_max << ") (" << r_min << "," << r_max << ")"
    //     << endl;
}

int largestBst(Node *root)
{
    int max_size = 0, cur_size, v_min = -1, v_max = -1;
    preOrder(root, &v_min, &v_max, &max_size, &cur_size);
    return max_size;
}
