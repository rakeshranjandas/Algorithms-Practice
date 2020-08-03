#include<bits/stdc++.h>
using namespace std;
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
void printBoundary(Node *root);
int height(struct Node *root)
{
    if(root==NULL)
        return 0;
    int l = 1+height(root->left);
    int r=1+height(root->right);
    if(l>r)
        return l;
    else
        return r;
}
/* Driver program to test above functions*/
int main()
{

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #else
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

   int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        Node *child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
    printBoundary(root);
   cout<<endl;
  }
    return 0;
}

void dfs(Node *node, bool is_left_view, vector<int> *v,
    int *max_height, int height) {

    if (node == NULL)
        return;

    if (height > *max_height) {
        *max_height = height;
        (*v).push_back(node->data);
    }

    if (is_left_view) {
        dfs(node->left, is_left_view, v, max_height, height+1);
        dfs(node->right, is_left_view, v, max_height, height+1);

    }   else {
        dfs(node->right, is_left_view, v, max_height, height+1);
        dfs(node->left, is_left_view, v, max_height, height+1);
    }
}

void printVector(vector<int> v) {
    for (auto x: v)
        cout << x << " ";
    cout << endl;
}

void printBoundary(Node *root)
{
    vector<int> lv, rv;
    int left_max_height = -1, right_max_height = -1;

    dfs(root, true, &lv, &left_max_height, 0);
    dfs(root, false, &rv, &right_max_height, 0);

    // printVector(lv);
    // printVector(rv);

    int right_v_end = right_max_height == left_max_height ? 0 : 1;

    for (int i = 0; i < lv.size(); i++)
        cout << lv[i] << " ";

    for (int i = rv.size()-1-right_v_end; i > 0; i--)
        cout << rv[i] << " ";
}









