// Midterm2of2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#define ask(X) cout<<#X" =? "; cin>>(X);

using namespace std;

template<class t>
size_t search(t *A, t X, size_t First, size_t Last) {
	if (First == Last) return Last;
	size_t Half = (First + Last) / 2;
	if (X < A[Half]) return search(A, X, Half+1, Last);
	return search(A, X, First, Half);
}

#define loop while(true)
void print_greater(int A[10], int X){
	size_t GreaterElement = search(A, X, 0, 9);
	cout << "Greater than " << X << " are (";
	loop{
		if (A[GreaterElement] > X) cout << "(" << A[GreaterElement] << ")";
		if (!GreaterElement) break;
		--GreaterElement;
	}
	cout << ") \n";
}

void main()
{
	int A[10] = { 93, 88, 62, 31, 11, 9, 7, 6, 5, 4 };
	int ValueToSearch;
	ask(ValueToSearch);
	print_greater(A, ValueToSearch);
}

