
#include<bits/stdc++.h>
using namespace std;
/* Link list node */
struct node *reverse (struct node *head, int k);
struct node
{
    int data;
    struct node* next;
}*head;
/* UTILITY FUNCTIONS */
/* Function to push a node */
  void insert()
{
    int n,value;
    cin>>n;
    struct node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            head=(struct node *) malloc( sizeof(struct node) );
            head->data=value;
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= (struct node *) malloc( sizeof(struct node) );
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
  printf(" ");
}
/* Drier program to test above function*/
int main(void)
{

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #else
    #endif
    /* Start with the empty list */
    int t,k,value,n;
     cin>>t;
     while(t--)
     {
     insert();
     cin>>k;
     head = reverse(head, k);
     printList(head);
     }
     return(0);
}


/*This is a function problem.You only need to complete the function given below*/
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
  struct node
  {
     int data;
     struct Node *next;
  }
*/

void reverseLinksRecursive(node *s, node *e) {

  cout << s->data << " X " << e->data << endl;


    if (s == e) {
        return;
    }
    
    node *now = s;
    
    reverseLinksRecursive(s->next, e);
    
    s->next->next = now;
}

struct node *reverseList(node *prev, node* rev_start, node *rev_end) {

    cout << "Z" << endl;

    reverseLinksRecursive(rev_start, rev_end);
    
    if (prev != NULL)
        prev->next = rev_end;
    
    return rev_start;
}

struct node *reverse (struct node *head, int k)
{ 
    if (k == 1)
      return head;

    node *start, *prev = NULL, *rev_start = head, *rev_end, *temp;
    int c = 1;
    
    while (head->next != NULL) {
        
        if (c < k) {
            c++;
            head = head->next;
            
        } else {
            c = 1;
            if (prev == NULL)
                start = head;
            temp = head->next;  
            prev = reverseList(prev, rev_start, head);
            cout << "last " << prev->data << endl;
            head = temp;
            rev_start = head;
        }
    }
    
    prev = reverseList(prev, rev_start, head);
    prev->next = NULL;
    
    return start;
}




