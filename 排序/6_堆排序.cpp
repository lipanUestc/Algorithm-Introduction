#include <iostream>
#include <vector>

using namespace std;

/*
一些知识：
二叉树中，节点i的左儿子节点为2i，右儿子为2i+1。
设二叉树总共有n个节点，则从n/2+1开始都是叶子节点。
上面说的二叉树，根节点都是从1号开始。
*/


//调整i、2i、2i+1这三个节点的小结构
void HeapAdjust(vector<int> &A, int size, int i) {
	//假设对于根节点i，它的左右子树都已经为最大堆了
	int largest = i; //初始化largest为第i号节点
	if (2 * i <= size && A[2 * i] > A[largest]) //当左子树存在，且大于largest时
		largest = 2 * i;
	if (2 * i + 1 <= size && A[2 * i + 1] > A[largest]) //过了这一步就找到，根节点和左右子节点中最大的，编号放在largest中
		largest = 2 * i + 1;

	if (largest != i) { //当最大的不是现在的根节点时，进行交换调整，然后再调用本方法保证换完的子树还是最大堆
		swap(A[i], A[largest]);
		HeapAdjust(A, size, largest);
	}
}

//构造最大堆
void HeapConstruct(vector<int> &A) {
	int size = A.size() - 1;//为保证根节点从编号1开始，我定义数组A为总节点个数再加一。所以这里size就是总节点个数。
	for (int i = size / 2; i >= 1; i--) { //从最后一个非叶子节点开始向前。自底向上构造最大堆，保证i节点的左右子树均为最大堆。
		HeapAdjust(A, size, i);
	}
}

//堆排序
void HeapSort(vector<int> &A) {
	for (int i = A.size() - 1; i >= 2; i--) {
		swap(A[1], A[i]);//因为是已经排好序的最大堆，所以A[1]就是最大元素，将A[1]放在数组最后
		HeapAdjust(A, i-1, 1); //将数组元素个数减一再次调整为最大堆。每次调整就找到余下元素中的最大值。
	}
}

//打印二叉树，没写好。。
void HeapPrint(vector<int> &A) {
	int size = A.size() - 1;
	int height = 0;
	int max_height = floor(log2(size));
	for (int k = 0; k < (max_height - height) * 2-1; k++) {
		cout << " ";
	}
	for (int i = 1; i <= size; i++) {
		cout << " " << A[i];
		if (i == pow(2, height+1)-1) {
			cout << "\n";
			height++;
			for (int k = 0; k < (max_height - height) * 2 - 1; k++) {
				cout << " ";
			}
		}
	}
}

int main5() {
	vector<int> A = { 0,23,21,13,44,32,22,55,11,33,77,44 };
	HeapConstruct(A);//构建最大堆

	//HeapPrint(A);

	HeapSort(A);//堆排序

	for (int i = 1; i < A.size(); i++)
		cout << A[i] << " ";

	system("pause");
	return 0;
}
