#include<iostream>
#include <string>
using namespace std;

void makeStringsEqual(string &a, string &b) {

	int a_size = a.size(), b_size = b.size();

	if (a_size == b_size)
		return;

	string zeros(abs(a_size-b_size), '0');


	if (a_size < b_size)
		a.insert(0, zeros);
	else
		b.insert(0, zeros);
}

long long int convertToDecimal(string a) {
	long long int res = 0;
	for (int i = a.size()-1; i >= 0; i--)
		res += (1 << (a.size()-1-i)) * (a[i] - '0');

	return res;
}

string plusStr(string a, string b) {

	cout << "plusStr " << (a) << " + " << (b);
	// cout << "plusStr " << convertToDecimal(a) << " + " << convertToDecimal(b);

	makeStringsEqual(a, b);

	bool carry = false;
	int a_size = a.size(), sum;

	for (int i = a_size-1; i >= 0; i--) {
		sum = (a[i] - '0') + (b[i] - '0') + (carry ? 1 : 0);

		if (sum >= 2) {
			carry = true;

			if (sum == 3)
				b[i] = '1';
			else
				b[i] = '0';

		} else {
			carry = false;
			b[i] = sum + '0';
		}
	}

	if (carry)
		b = '1' + b;

	cout << " = " << (b) << endl;
	// cout << " = " << convertToDecimal(b) << endl;

	return b;
}

string minusStr(string a, string b) {

	cout << "minusStr " << convertToDecimal(a) << " - " << convertToDecimal(b);

	makeStringsEqual(a, b);

	bool carry = false;
	int a_size = a.size(), diff;

	for (int i = a_size-1; i >= 0; i--) {
		diff = (a[i] - '0') - (b[i] - '0') - (carry ? 1 : 0);

		if (diff < 0) {
			carry = true;

			if (diff == -2)
				b[i] = '0';
			else
				b[i] = '1';

		} else {
			carry = false;
			b[i] = diff + '0';
		}
	}

	cout << " = " << convertToDecimal(b) << endl;

	return b;
}

string multTwo(int n, string a) {
	string product = a + string(n, '0');
	cout << n << " ^ " << a << " = " << product << endl;
	return product;
}

string trimZeroes(string a) {
	int i = 0;
	while (i < a.size() && a[i] == '0')
		i++;
	return i == a.size() ? "0" : a.substr(i);
};

string karatsubaMult(string a, string b) {

	    cout << "start karatsubaMult " << a << " X " << b << endl;

	makeStringsEqual(a, b);
	int n = a.size();

	if (n == 1)
		return string(1, ((a[0]-'0') * (b[0]-'0') + '0'));

	string p = a.substr(0, n/2),
		   q = a.substr(n/2),
	       r = b.substr(0, n/2),
	       s = b.substr(n/2);

	cout << "     " << p << " " << q << endl;
	cout << "     " << r << " " << s << endl;

	string pr = karatsubaMult(p, r),
	       qs = karatsubaMult(q, s),
		   pq_rs = karatsubaMult(plusStr(p, q), plusStr(r, s));
    
    string mult_two_pr = multTwo(n, pr),
    	   pr_qs_sum = plusStr(pr, qs);

    string ps_qr = minusStr(pq_rs, pr_qs_sum);
    string mult_two_ps_qr = multTwo(n-n/2, ps_qr);

    string product = trimZeroes(plusStr(mult_two_pr, plusStr(mult_two_ps_qr, qs)));

    cout << "karatsubaMult " << a << " X " << b << " = " << product << endl;

    return product;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
		#else
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
	    string a, b;
	    cin >> a >> b;
	   	
	   	// Make equal length by left padding '0's
	   	makeStringsEqual(a, b);

	   	// cout << a << " " << b << endl;
	   	string k = karatsubaMult(a, b);

	   	cout << k << " " << convertToDecimal(k)<< endl;
	}

	// string s = "Ilu";
	// s.insert(0, "Hello ");
	// cout << s;

	// string k(9, 's');
	// cout << k;
	// cout << string(1, 'a');

	// string a = "Hello";
	// cout << a.substr(0, a.size()/2);

	// cout << minusStr("1111", "101");
	// cout << multTwo(3, "111");

	// cout << trimZeroes("011");
	// cout << convertToDecimal("100");

	return 0;
}