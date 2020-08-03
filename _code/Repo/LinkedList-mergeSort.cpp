#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
//Position this line where user code will be pasted.
void printList(Node* node, Node *end = NULL) {
    while (node != end) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

Node* mergeSort(Node* head);

int main() {

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #else
    #endif

    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}

Node *findMid(Node *head, Node* end) {
    if (head->next == end)
        return head;
    
    Node *fast = head->next, *slow = head;
    
    while (fast->next != end) {
        slow = slow->next;
        
        fast = fast->next;
        if (fast->next == end)
            break;
            
        fast = fast->next;
    }
    
    return slow;
}

Node *merge(Node *head, Node *mid, Node *end) {

    // cout << " to merge " << head->data << " " << mid->data << " "  << (end==NULL ? 0 : end->data) << endl;
    // printList(head, mid->next);
    // printList(mid->next, end);

    Node *merged_head = NULL;
    Node *a = head, *a_end = mid->next, *b = mid->next, *b_end = end;
    Node *next_connect, *merged_list;
    
    while (a != a_end && b != b_end) {
        
        if (a->data <= b->data) {
            next_connect = a;
            a = a->next;
            
        } else {
            next_connect = b;
            b = b->next;
        }
            
        if (merged_head == NULL) {
            merged_head = next_connect;
            merged_list = next_connect;

        } else {
            merged_list->next = next_connect;
            merged_list = merged_list->next;
        }
    }
    
    if (a != a_end) {
        merged_list->next = a;
        mid->next = end;
    }
    
    if (b != b_end)
        merged_list->next = b;
    
    return merged_head;
}

Node *endNode(Node *h, Node *e = NULL) {
    if (h == e)
        return h;

    while (h->next != e)
        h = h->next;

    return h;
}

Node* _mergeSort(Node *prev, Node *head, Node *end) {

    // cout << " mergeSort in " << endl;
    // printList(head, end);
    
    if (head->next == end) {
        // cout << "    returned" << head->data << endl;
        return head;
    }
        
    Node *mid = findMid(head, end);
    // cout << mid->data << " mid" << endl;

    Node *start_b = mid->next;
    
    // cout << "left ";
    Node *merged_a = _mergeSort(prev, head, start_b);

    Node *end_a = endNode(merged_a, start_b);

    // cout << "right ";
    Node *merged_b = _mergeSort(end_a, start_b, end);
    
    // cout << "orig ";
    // printList(merged_a, end);

    // cout << "end a " << end_a->data << endl;

    Node *merged_head = merge(merged_a, end_a, end);



    // cout << "merged = ";
    // printList(merged_head, end);
    
    if (prev != NULL)
        prev->next = merged_head;
        
    return merged_head;
}

/* Function to mergesort the linked list
   It should return head of the modified list  */
Node* mergeSort(Node* head) {
    // printList(head);
    return _mergeSort(NULL, head, NULL);
}
