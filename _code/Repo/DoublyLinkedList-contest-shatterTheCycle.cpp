#include<iostream>
using namespace std;

class Node {

public:
    int data;
    Node *next;
    
    Node(int d) {
        data = d;
        next = NULL;
    }
};

void printList(Node *h) {

	Node *e = h;

	do {
		cout << h->data << " ";
		h = h->next;

	} while (h != e);

	cout << endl;
}

Node *findMid(Node *h) {

	Node *r = h->next, *t = h;

	while (r != h) {

		t = t->next;

		r = r->next;
		if (r == h)
			break;
		r = r->next;
	}

	return t;
}

int main() {

    #ifndef ONLINE_JUDGE
	    freopen("../input.txt", "r", stdin);
	    freopen("../output.txt", "w", stdout);
    #else
    #endif

	int t;
	cin >> t;
	
	while (t--) {
	    int n;
	    cin >> n;
	    
	    int ip;
	    Node *head, *start = NULL, *newNode;


	    while (n--) {
	        cin >> ip;

	        newNode = new Node(ip);

	        if (start == NULL) {
	        	start = newNode;
	        } else {
	        	head->next = newNode;
	        }

	        head = newNode;
	    }

	    // Join last and first
	    head->next = start;

	    // printList(start);

	    Node *mid = findMid(start);
	    // cout << mid->data;

	    printList(mid);
	   
	}
	
	return 0;
}