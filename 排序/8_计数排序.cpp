#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
原理：直接按对应取值计算个数，按个数直接放入对应位置。没有两个数字的比较过程。

第八章的所有排序都是非比较排序，直接按值来放入指定位置，不要两两比较。
*/


//A是要排序的原始数组，B是存放排序后的输出结果，k指的是原始数组中的最大值
void CountSort(vector<int> &A, vector<int> &B, int k) {
	vector<int> C(k+1, 0); //C[i]表示数值i在原始数组中出现的个数
	int size = A.size();

	for (int i = 0; i < size; i++) {//遍历A中的所有元素，记录各元素出现次数到C中
		C[A[i]] += 1;
	}

	for (int j = 1; j <= k; j++) { //将C[j]中的值更新为小于等于j的元素个数
		C[j] += C[j - 1];
	}

	for (int i = 0; i < size; i++) { //遍历A中所有元素，将每一元素直接放在B中正确位置
		B[C[A[i]] - 1] = A[i];
		C[A[i]] -= 1;//为避免有重复元素，这个将A[i]-1，下次同样的元素会放在前一个位置
	}

}

int main7() {
	vector<int> A = {23,21,13,44,32,22,55,11,33,77,44 };
	int size = A.size();

	int largest = A[0];
	for (int i = 1; i < size; i++)
		if (A[i] > largest) largest = A[i];

	vector<int> B(size, 0);

	CountSort(A, B, largest);

	for (int i = 0; i < B.size(); i++)
		cout << B[i] << " ";

	system("pause");
	return 0;
}