#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

void printList(node *h) {
    while (h != NULL) {
        cout << h->data << " ";
        h = h->next;
    }
    
    cout << endl;
}

node* ksum(node* head, int k) {

	if (head == NULL || k == 1)
		return head;

	node *h = head->next, *prev = head;
	int sum = head->data, i = 1;

	while (h != NULL) {
		// cout << h->data << " " << endl;

		sum += h->data;

		if (i % k == k-1) {
				// cout << "sum = " << sum << endl;

			prev->data = sum;
			prev->next = h->next;
			prev = prev->next;
			sum = 0;
			// cout << "new sum = " << sum << endl;
		}

		h = h->next;
		i++;
	}

	if (prev != NULL) {
		prev->data = sum;
		prev->next = NULL;
	}

	return head;
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
	    int n, k;
	    cin >> n >> k;
	    
	    int ip;
	    node *start = NULL, *nn, *prev = NULL;
	    
	    while (n--) {
	        cin >> ip;
	        nn= new node();
	        nn->data = ip;
	        nn->next = NULL;
	        
	        if (prev == NULL) {
	            prev = nn;
	            start = nn;
	            
	        } else {
	            prev->next = nn;
	            prev = nn;
	        }
	    }
	    
	    // printList(start);

	    node * res = ksum(start, k);
	    printList(res);
	}
	
	return 0;
}