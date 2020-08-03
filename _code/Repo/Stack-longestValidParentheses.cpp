#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printStack(stack<string> st) {
    string s = "";
    while (!st.empty()) {
        s = st.top() + " " + s;
        st.pop();
    }

    cout << s << endl;
}

int longestValid(string s) {
    stack<string> st;
    int max_valid = 0;
    st.push(to_string(0));

    for (char x: s) {
        // cout << "----" << x << endl;
        // printStack(st);

        if (x == '(')
            st.push("(");

        else {

            if (st.top().compare("(") == 0) {
                // If top is (, then occurence of ()
                // Pop (, push 2 denoting valid substring of 2
                st.pop();
                if (st.top().compare("(") != 0) {
                    int new_valid_length = stoi(st.top()) + 2;
                    st.pop();
                    st.push(to_string(new_valid_length));
                    max_valid = max(max_valid, new_valid_length);

                } else {
                    st.push("2");
                    max_valid = max(max_valid, 2);                    
                }

            } else if (st.size() == 1) {
                // First invalid )
                // Reinitialise stack
                st.pop();
                st.push(to_string(0));

            } else {
                int new_valid_length = stoi(st.top()) + 2;
                st.pop();
                st.pop();

                if (st.top().compare("(") != 0) { 
                    int new_valid_length_2 = stoi(st.top()) + new_valid_length;
                    st.pop();
                    st.push(to_string(new_valid_length_2));
                    max_valid = max(max_valid, new_valid_length_2);

                } else {
                    st.push(to_string(new_valid_length));
                    max_valid = max(max_valid, new_valid_length);   
                }
            }
        }
    }

    return max_valid;
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
	    string s;
	    cin >> s;
	    
	    cout << longestValid(s) << endl;
	}
	
	return 0;
}