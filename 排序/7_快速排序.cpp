#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int Partition(vector<int> &A,int l,int r) {
	int pivot = A[r]; //取最右侧元素作为划分元素
	int i = l; //i记录第一个大于等于pivot的位置
	int j = l; //j记录正在比较的元素位置

	for (; j < r; j++) { //遍历排序所有r之前的元素
		if (A[j] < pivot) {
			swap(A[i], A[j]);
			i++;
		}
	}
	swap(A[i], A[r]);//出循环的时候i就对应pivot应在的位置

	return i;
}

void QuickSort(vector<int> &A, int l, int r) {
	if (l < r) {
		//下面两行打乱数据至随机分布，从而取得期望的算法效率
		int random = rand() % (r - l + 1) + l;
		swap(A[random], A[r]);

		int mid = Partition(A, l, r);
		QuickSort(A, l, mid - 1);
		QuickSort(A, mid + 1, r);
	}
}

int main6() {
	srand((unsigned)time(NULL));

	vector<int> A = { 0,23,21,13,44,32,22,55,11,33,77,44 };

	QuickSort(A, 0, A.size() - 1);

	for (int i = 1; i < A.size(); i++)
		cout << A[i] << " ";

	system("pause");
	return 0;
}