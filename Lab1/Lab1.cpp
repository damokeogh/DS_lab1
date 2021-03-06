// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "UnorderedArray.h"
#include <iostream>

using namespace std;

template < typename T0>
int scalarProduct(T0 a, T0 b);
int vector1[3] = { 2, 2, 2 };
int vector2[3] = { 1, 1, 1 };
int product = 0;




int main()
{
	//Q1
	product = scalarProduct(vector1, vector2);
	cout << product << endl;
	//cout << scalarProduct(vector1, vector2); better?

	//Q2
	UnorderedArray<int> testArray(5, 5);
	for (int i = 0; i < 5; i++)
	{
		testArray.push(i*2);
	}
	cout << testArray.search(2) << endl;

	//Q3
	testArray.remove(0);
	cout << testArray.search(2);

	//Q4


	

}

//Q1 Implementation
template < typename T0>
int scalarProduct(T0 a, T0 b)
{
	return  (a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
