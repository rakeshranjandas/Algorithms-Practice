#include <iostream>
using namespace std;

void printArr(int *a, int len, string s) {
	cout << s << " : ";
	for (int i = 0; i < len; i++)
		cout << a[i];
	cout << endl;
}

void copyIntegerArray(int* fromArr, int fromArrLen, int* toArr, int toArrLen,
	int startIndex, int endIndex) {

	for (int i = startIndex, j = 0; i < endIndex && j < toArrLen; i++, j++) {
		toArr[j] = fromArr[i];
	}
}

int* karatsubaMultInt(int* s1, int *s2, int maxSLen, int* prod) {

	// Base case - when array length is 1
	if (maxSLen == 1) {
		int p = s1[0] * s2[0];
		prod[0] = p / 10;
		prod[1] = p % 10;
	}


	// Divide into two halves
	int lLen = maxSLen/2;
	int hLen = maxSLen - (maxSLen/2);

	int xL[lLen];
	copyIntegerArray(s1, maxSLen, xL, lLen, 0, lLen);

	int xH[hLen];
	copyIntegerArray(s1, maxSLen, xH, hLen, lLen, maxSLen);

	int yL[lLen];
	copyIntegerArray(s2, maxSLen, yL, lLen, 0, lLen);

	int yH[hLen];
	copyIntegerArray(s2, maxSLen, yH, hLen, lLen, maxSLen);

	printArr(xH, hLen, "xH");
	printArr(xL, lLen, "xL");
	printArr(yH, hLen, "yH");
	printArr(yL, lLen, "yL");

	// xH * yH
	int *a;
	a = (int*) malloc(sizeof(int) * 2 * hLen);
	karatsubaMult(xH, yH, hLen, a);

	// xL * yL
	int *b;
	b = (int*) malloc(sizeof(int) * 2 * lLen);
	karatsubaMult(xL, yL, lLen, b);

	// (xH + xL) * (yH + yL)
	int *c;
	c = (int*) malloc(sizeof(int) * 2 * maxSLen);
	karatsubaMult(xL, yL, maxSLen, b);



	return prod;
}

string karatsubaMult(string s1, string s2) {
	// Save sign of product
	bool neg1 = false, neg2 = false;

	// Operate karatsuba on integer arrays
	// Convert string to integer arrays
	int s1Len = s1.length(), s1Start = 0;
	if (s1[0] == '-') {
		neg1 = true;
		s1Len = s1.length() - 1;
		s1Start = 1;
	}

	int s2Len = s2.length(), s2Start = 0;
	if (s2[0] == '-') {
		neg2 = true;
		s2Len = s2.length() - 1;
		s2Start = 1;
	}

	int maxSLen = max(s1Len, s2Len);
	int s1Arr[maxSLen], s2Arr[maxSLen];
	int i = maxSLen - 1, s1i = s1.length() - 1,	s2i = s2.length() - 1;

	for (; i >= 0; i--, s1i--, s2i--) {
		if (s1i >= s1Start)
			s1Arr[i] = s1[s1i] - '0';
		else 
			s1Arr[i] = 0;

		if (s2i >= s2Start)
			s2Arr[i] = s2[s2i] - '0';
		else
			s2Arr[i] = 0;
	}

	printArr(s1Arr, maxSLen, "s1Len");

	printArr(s2Arr, maxSLen, "s2Len");

	// apply karatsubaMultInt
	int *prod;
	prod = (int *) malloc(sizeof(int) * 2 * maxSLen);
	karatsubaMultInt(s1Arr, s2Arr, maxSLen, prod);

	printArr(prod, 2*maxSLen, "prod");

	// Convert product into string. Use sign
	return "Yes";
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
		cout << karatsubaMult(s1, s2) << endl;
	}

	return 0;
}