#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next, *prev;
    
    Node (int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

struct Node *sortDoubly(struct Node *head);

//Position this line where user code will be pasted.
void insert(struct Node **head, int data)
{
    struct Node *temp = new Node (data);
    if (!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
void print(struct Node *head)
{
    struct Node *temp = head;
    while (head)
    {
        cout<<head->data<<' ';
        temp = head;
        head = head->next;
    }
    cout<<endl;
    while (temp)
    {
        cout<<temp->data<<' ';
        temp = temp->prev;
    }
    cout<<endl;
}
// Utility function to swap two integers
void swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}
// Driver program
int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #else
    #endif

    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
    return 0;
}

void printList(Node* node, Node *end = NULL) {
    while (node != end) {
        // printf("%d (", node->data);
        cout << "<" << node << ">" << node->data << " ";
        node = node->next;
    }
    printf("\n");
}

Node *findMid(Node *head, Node *end = NULL) {
    if (head == end || head->next == end)
        return head;
    
    Node *fast = head->next->next;
    
    while (fast != end) {
        head = head->next;
        
        fast = fast->next;
        if (fast == end)
            break;
        fast = fast->next;
    }
    
    return head;
}

Node *insertList(Node *h, int data) {
    
    Node *newNode = new Node(data);
    
    if (h != NULL)
        h->next = newNode;
    
    return newNode;
}

void mergeList(Node *h1, Node *e1, Node *h2, Node *e2) {

    cout << "inside mergeList " << endl;
    cout << h1 << " - " << e1 << ", " << h2 << " - " << e2 << endl;


    cout << "----------" << endl;
    printList(h1, e1);
    cout << endl;
    printList(h2, e2);
    cout << "----------"<< endl;
    
    // Merge to a new list
    Node *head = NULL, *start = NULL, *saved_h1 = h1;
    
    while (h1 != e1 && h2 != e2) {

        if (h1->data <= h2->data) {
            head = insertList(head, h1->data);
            h1 = h1->next;
            
        } else {
            head = insertList(head, h2->data);
            h2 = h2->next;
        }
        
        if (start == NULL)
            start = head;
    }
    
    while (h1 != e1) {
        head = insertList(head, h1->data);
        h1 = h1->next;
    }
    
    while (h2 != e2) {
        head = insertList(head, h2->data);
        h2 = h2->next;
    }
    

    h1 = saved_h1;
    // Copy to original list
    while (start != NULL) {
        h1->data = start->data;
        h1 = h1->next;
        start = start->next;
    }

    cout << "merged -- ";
    printList(saved_h1, e2);
}

void mergeSortRecursive(Node *head, Node *end) {

    cout << "inside mergeSortRecursive " << "(" << head << "," << end << ")\n";
    printList(head, end);

    
    if (head == end || head->next == end) {
        cout << "returned " << head->data << endl;
        return;
    }
    
    Node *mid = findMid(head, end);

    cout << " -- mid " << mid->data << endl;
    
    mergeSortRecursive(head, mid->next);
    mergeSortRecursive(mid->next, end);
    
    mergeList(head, mid->next, mid->next, end);
}

/* Function to mergesort the linked list
   It should return head of the modified list  */
// Node* mergeSort(Node* head) {
//     mergeSortRecursive(head, NULL);
//     return head;
// }

// void convertToDoubly(Node *h, Node *n) {
//     if (n->next == NULL)
//         return;

//     convertToDoubly(h, h->next);
//     h->next->prev = h;
// }

struct Node *sortDoubly(struct Node *head)
{
    mergeSortRecursive(head, NULL);
    // convertToDoubly(head, NULL);

    return head;
}

