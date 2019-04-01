#include<vector>
#include<iostream>
using namespace std;

void Merge(vector<int> &A, int l, int mid, int r) {
	int len1 = mid - l + 1;//左边序列长度
	int len2 = r - mid + 1;//右边序列长度

	vector<int> Left;
	vector<int> Right;

	for (int i = l; i <= mid; i++)//把左边序列copy到数组Left中，最后加一位INT_MAX
		Left.push_back(A[i]);
	Left.push_back(INT_MAX);

	for (int j = mid + 1; j <= r; j++)//把右边数组copy到数组Right中，最后加一位INT_MAX
		Right.push_back(A[j]);
	Right.push_back(INT_MAX);

	int k = l, i = 0, j = 0; //将较小的元素放到原数组中
	for (; k <= r; k++) {
		if (Left[i] < Right[j])
			A[k] = Left[i++];
		else
			A[k] = Right[j++];
	}
}

void Sort(vector<int> &A,int l,int r) {
	if (l < r) {
		int mid = (l + r) / 2;//找到分割点
		Sort(A, l, mid); //将左边序列排好序
		Sort(A, mid + 1, r);//将右边序列排好序
		Merge(A, l, mid, r);//将两个排好序的序列进行合并
	}
}


int main4() {
	vector<int> A = { 23,21,13,44,32,22,55,11,33,77,44 };

	Sort(A,0,A.size()-1);

	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";

	system("pause");
	return 0;
}