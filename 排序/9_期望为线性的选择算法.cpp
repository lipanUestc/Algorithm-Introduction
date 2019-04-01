#include <iostream>
#include <vector>

using namespace std;

/*
原理：
基于快速排序，但只对目标元素所在的那半边执行。最坏时间为O(n^2),期望为O(n)
*/

int Partition_copy(vector<int> &A,int l,int r) {
	if (l == r) return l;
	
	int pivot = A[r];
	int i = l;
	int j = l;

	for (; j < r; j++) {
		if (A[j] <= pivot) {
			swap(A[i], A[j]);
			i++;
		}
	}
	swap(A[i], A[r]);

	return i;
}

int FindKthElement(vector<int> &A, int l, int r, int k) {
	int mid = Partition_copy(A, l, r);
	if (mid == k)
		return A[mid];
	else if (mid > k)
		return FindKthElement(A, l, mid - 1, k);
	else
		return FindKthElement(A, mid + 1, r, k);
}



int main() {
	vector<int> A = {23,21,13,44,32,22,55,11,33,77,44 };

	int fifth = FindKthElement(A, 0, A.size() - 1, 4);
	cout << "The 5th element is: " << fifth << endl;
	system("pause");
	return 0;
}