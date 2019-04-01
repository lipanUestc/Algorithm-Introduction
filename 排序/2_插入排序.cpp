#include<vector>
#include<iostream>
using namespace std;

/*
注意：插入排序将插入元素与排好序的序列比较时，既可以从后往前，也可以从前往后。
*/
void InsertSort(vector<int> &A) {
	int len = A.size();
	for (int i = 1; i < len; i++) {//共插入比长度少一次，因为第一个元素默认排好序了;A[i]表示当前要插入的元素
		int key = A[i];
		int j = i - 1;
		for (; j >= 0 && A[j] > key; j--) {//从第i-1个元素开始到第0个元素，一个一个和当前元素比；因为前边已经排好序，一直到第一个小于等于当前元素的位置
			A[j + 1] = A[j];
		}
		A[j + 1] = key;//A[j]表示当前正在与key比较的元素，跳出循环时A[j]指向第一个比key小的元素，它后边就是要插入的位置
	}
}

int main3() {
	vector<int> A = { 23,21,13,44,32,22,55,11,33,77,44 };

	InsertSort(A);

	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";

	system("pause");
	return 0;
}