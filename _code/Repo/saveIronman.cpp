#include <iostream>
#include <cstring>
using namespace std;  

string addStrings(string s1, string s2) {
    
    string sumString = "";
    
    int i, j, iNum, jNum, sum;
    char sumChar;
    int carry = 0;
    
    for (i = s1.length() - 1, j = s2.length() - 1; i >= 0 || j >= 0; i--,j--) {

    	if (i < 0)
    		iNum = 0;
    	else
    		iNum = s1[i] - '0';

    	if (j < 0)
    		jNum = 0;
    	else
    		jNum = s2[j] - '0';
    	

        sum = iNum + jNum + (carry ? 1 : 0);

        carry = sum / 10;
        sum %= 10;

		// cout << "sum = " << sum << endl;
		// cout << "i = " << i << endl;
		// cout << "j = " << j << endl;
		// cout << "iNum = " << iNum << endl;
		// cout << "jNum = " << jNum << endl;

        sumChar = ('0' + sum);
        sumString = sumChar + sumString;
    }

    if (carry)
    	sumString = "1" + sumString;

    return sumString;
}

string multiplyStringsOneDigit(string s, char c) {
	string prodString = "";
	int carry = 0, prod, cNum = c - '0', m;
	char prodC;

	for (int i = s.length() - 1; i >= 0; i--) {

		m = s[i] - '0';
		prod = m * cNum + carry;
		carry = prod / 10;
		prod %= 10;
		prodC = (prod + '0');
		prodString = prodC + prodString;
	}

	if (carry) {
		prodC = (carry + '0');
		prodString = prodC + prodString;
	}

	// cout << s << "X" << c << "=" << prodString << endl;

	return prodString;
}

string multiplyStrings(string s1, string s2) {
	// return addStrings(s1, s2);
	// return multiplyStringsOneDigit(s1, s2[0]);

	string prod = "";

	for (int i = 0; i < s2.length(); i++) {

		prod = prod.append("0");
		prod = addStrings(multiplyStringsOneDigit(s1, s2[i]), prod);
	}

	int i;
	for (i = 0; i < prod.length() && prod[i] == '0'; i++) {};
	prod = prod.substr(i, prod.length() - i);
	// cout << "i=" << i << endl;

	return prod;
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
	    string s1, s2;
	    cin >> s1 >> s2;



	   	cout << multiplyStrings(s1, s2) << endl;
	}

	return 0;
}