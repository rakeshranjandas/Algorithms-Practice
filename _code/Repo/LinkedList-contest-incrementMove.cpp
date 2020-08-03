#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node *insertNode(Node *prev, int data) {
    Node *nn = new Node();
    nn->data = data;
    
    if (prev == NULL)
        return nn;
    else {
        prev->next = nn;
        return nn;
    }
}

void printList(Node *h) {
    while (h != NULL) {
        cout << h->data << " ";
        h = h->next;
    }
    
    cout << endl;
}

void change(Node *h) {
	if (h == NULL || h->next == NULL || h->next->next == NULL)
		return;

	Node *h1 = h, *h2 = h->next, *h3 = h->next->next;

	while (h3 != NULL) {

		if (h1->data == h2->data && h3->data == 100) {
			h1->data = 100;
			h2->data = (h2->data/10) + h2->data;
		}

		h1 = h2;
		h2 = h3;
		h3 = h3->next;
	}
}

void separate(Node *h) {

	
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
	    
	    Node *head = NULL, *start = NULL;
	    int ip;
	    
	    while (n--) {
	        cin >> ip;
	        head = insertNode(head, ip);    
	        if (start == NULL)
	            start = head;
	    }
	    
	    // printList(start);
	    change(start);
	   	printList(start);

	   	separate(start);
	   	printList(start);
	}
	
	return 0;
}