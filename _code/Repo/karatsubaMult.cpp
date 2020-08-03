#include <iostream>
#include <bits/stdc++.h>
using namespace std;  

string trimLZeros(string s) {
	int i = 0;
	for (; s[i] == '0' && i < s.length() - 1; i++) {};

	return s.substr(i);
}

int makeEqualLength(string* xx, string* yy) {
	int xxl = (*xx).length();
	int yyl = (*yy).length();

	if (xxl > yyl)
		(*yy).insert(0, xxl - yyl, '0');
	else
		(*xx).insert(0, yyl - xxl, '0');

	return max(xxl, yyl);
}

string addString(string x, string y) {

	//cout << "addString " << x << " " << y << " = ";

	string sumStr = "";
	int carry = 0;
	int iNum, jNum, ijNum;

	for (int i = x.length() - 1, j = y.length() - 1;
		i >=0 || j >= 0; i--, j--) {

		if (i < 0)
			iNum = 0;
		else
			iNum = x[i] - '0';

		if (j < 0)
			jNum = 0;
		else
			jNum = y[j] - '0';

		ijNum = iNum + jNum + carry;

		//cout << "i" << iNum << endl;
		//cout << "j" << jNum << endl;

		sumStr.insert(0, 1, (ijNum%10 + '0'));
		carry = ijNum / 10;


		//cout << "ijNum " << ijNum << endl;
		//cout << "sumStr " << sumStr << endl;
		//cout << "carry " << carry << endl;
	}

	if (carry)
		sumStr.insert(0, 1, ('0' + carry));


	//cout << sumStr << endl;

	return trimLZeros(sumStr);
}

string minusString(string x, string y) {
	//cout << "minusString " << x << " " << y << " = ";
	string minusStr = "";
	int iNum, jNum, ijNum;

	for (int i = x.length() - 1, j = y.length() - 1;
		i >=0 || j >= 0; i--, j--) {

		if (i < 0)
			iNum = 0;
		else
			iNum = x[i] - '0';

		if (j < 0)
			jNum = 0;
		else
			jNum = y[j] - '0';

		if (iNum < jNum) {
			iNum += 10;
			x[i-1]--;
		}

		ijNum = iNum - jNum;
		minusStr.insert(0, 1, ijNum + '0');
	}

	//cout << minusStr << endl;
	return trimLZeros(minusStr);	
}

string powTen(string x, int exp) {
	
	return x.append(exp, '0');
}

string karatsubaMult(string x, string y) {
	cout << "karatsubaMult " << x << " " << y << " = " << endl;

	int prod;
	string prodStr = "";


	// Base case when string length is 16
	if (x.length() < 2 && y.length() < 2) {
		int xNum = atoi(x.c_str());
		int yNum = atoi(y.c_str());
			cout << "rret  " << to_string(xNum * yNum) << endl;
		return to_string(xNum * yNum);
	}

	// Base case when string length is 1
	if (x.length() == 1 && y.length() == 1) {
		prod = (x[0] - '0') * (y[0] - '0');

		if (prod >= 10)
			prodStr.append(1, ((prod/10) + '0'));

		prodStr.append(1, ((prod % 10) + '0'));
		return prodStr;
	}

	int l = makeEqualLength(&x, &y);
	int lH = l / 2;
	int lL = l - lH;

	string xH = x.substr(0, lH), xL = x.substr(lH);
	string yH = y.substr(0, lH), yL = y.substr(lH);

	//cout << xH << " - " << endl;
	//cout << xL << " - " << endl;
	//cout << yH << " - " << endl;
	//cout << yL << " - " << endl;

	string a = karatsubaMult(xH, yH);
	string b = karatsubaMult(xL, yL);
	string c = karatsubaMult(addString(xH, xL), addString(yH, yL));
	string d = minusString(c, addString(a, b));

	prodStr = addString(powTen(a, 2 * lL), addString(powTen(d, lL), b));

	//cout << "return " << prodStr << endl;

	return trimLZeros(prodStr);
}

int main() {
	// #ifndef ONLINE_JUDGE
	// 	freopen("../input.txt", "r", stdin);
	// 	freopen("../output.txt", "w", stdout);
	// 	#else
	// #endif
		
	int t;
	cin >> t;

	while (t--) {
	    string s1, s2;
	    cin >> s1 >> s2;

	    bool neg = false;
	    if (s1[0] == '-' && s2[0] != '-') {
	    	neg = true;
	    	s1 = s1.substr(1);

	    } else if (s2[0] == '-' && s1[0] != '-') {
			neg = true;
	    	s2 = s2.substr(1);

	    } else if (s2[0] == '-' && s1[0] == '-') {
	    	s1 = s1.substr(1);
	    	s2 = s2.substr(1);
	    }

	    cout << (neg ? "-" : "") << karatsubaMult(s1, s2) << endl;
	    // //cout << addString("28", "4876") << endl;
	}

	return 0;
}