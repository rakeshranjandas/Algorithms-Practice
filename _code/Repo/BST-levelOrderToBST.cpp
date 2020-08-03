//Initial Template for C++
#include <bits/stdc++.h>
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
void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}
Node* constructBst(int arr[], int n);
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
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}

#include<climits>

struct NodeInfo {
    int lo, hi;
    Node **n;
    NodeInfo(int l, int h, Node **nn) {
        lo = l;
        hi = h;
        n = nn;
    }
};

void createBSTFromLevel(int a[], int n, queue<NodeInfo> &q) {

    int i = 0;
    for (int i = 0; i < n; i++) {
        // cout << a[i] << endl;
        while (!q.empty()) {
            auto popped = q.front();
            q.pop();

            // cout << popped.lo << " - " << popped.hi << endl;

            if (popped.lo < a[i] && a[i] < popped.hi) {
                *(popped.n) = new Node(a[i]);
                q.push(NodeInfo(popped.lo, a[i], &(*popped.n)->left));
                q.push(NodeInfo(a[i], popped.hi, &(*popped.n)->right));

                // cout << "inserted" << endl;
                break;
            }
        }
    }
}

Node* constructBst(int arr[], int n)
{
    queue<NodeInfo> q;
    Node *root = NULL;
    NodeInfo newNodeInfo = NodeInfo(INT_MIN, INT_MAX, &root);
    q.push(newNodeInfo);
    createBSTFromLevel(arr, n, q);
    return root;
}