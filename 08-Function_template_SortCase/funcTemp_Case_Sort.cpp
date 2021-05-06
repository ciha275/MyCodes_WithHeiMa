#include<iostream>
using namespace std;

//对char和int数组进行排序，规则：从大到小，利用选择排序

//排序中用到的交换数据逻辑
template<class T>
void mySwap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

//选择排序的逻辑
template<class T>
void mySort(T arr[] , int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				//交换下标
				max = j;
			}
		}
		if (max != i)
		{
			//交换数据
			mySwap(arr[max], arr[i]);
		}
	}

}

//输出数组元素的模板
template<class T>
void printArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01()
{
	char charArr[] = "helloWorld";
	int num = sizeof(charArr) / sizeof(char);//计算数组大小
	mySort(charArr, num);

	printArray(charArr, num);

	double dbArr[] = {2.13, 5.67, 12.5, 37.68, 88.04, 120.0};
	int dbnum = sizeof(dbArr) / sizeof(double);
	mySort(dbArr, dbnum);

	printArray(dbArr, dbnum);

}


int main()
{
	test01();

}