#include<iostream>
using namespace std;

//��char��int����������򣬹��򣺴Ӵ�С������ѡ������

//�������õ��Ľ��������߼�
template<class T>
void mySwap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

//ѡ��������߼�
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
				//�����±�
				max = j;
			}
		}
		if (max != i)
		{
			//��������
			mySwap(arr[max], arr[i]);
		}
	}

}

//�������Ԫ�ص�ģ��
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
	int num = sizeof(charArr) / sizeof(char);//���������С
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