#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<list>
#include<functional>
#include<algorithm>
#include<numeric>
#include <iomanip>
#include<queue>
#include<stack>
#include<ctime>
#include<cmath>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<array>
#include<memory>
#include<set>


//#include"dsq.h"
using namespace std;

//һ
//�������ݽṹ
class BiTreeNode
{
public:
	BiTreeNode(int _val, BiTreeNode* _left = nullptr, BiTreeNode* _right = nullptr)
	{
		val = _val;
		left = _left;
		right = _right;
	}
public:
	int val;
	BiTreeNode *left;
	BiTreeNode *right;
};

//��
//���ú���

//******��ӡvector
template<class T>
void printVector(vector<T> v)
{
	for (T i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}

//******��ӡvector
template<class T>
void printVector(vector<vector<T>> v)
{
	for (auto it1 = v.begin(); it1 != v.end(); it1++) {
		for (auto it2 = (*it1).begin(); it2 != (*it1).end(); it2++) {
			cout << (*it2) << " ";
		}
		cout << endl;
	}
}

//******����ͬһ���͵�������ַ�е�����
template<class T>
void swap(T *a, T *b)
{
	if (a == nullptr || b == nullptr)
	{
		cout << "swap address nullptr" << endl;
		return;
	}
	if (a == b)
		return;
	T temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}

//******��������غ���
class BiTreeFunc {
public:
	//ֱ�۴�ӡ������
	void printTree(BiTreeNode *head) {
		cout << ("Binary Tree:") << endl;;
		printInOrder(head, 0, "H", 17);
		cout << endl;
		//System.out.println();
	}
private:
	void printInOrder(BiTreeNode *head, int height, string to, int len) {
		if (head == nullptr) {
			return;
		}
		printInOrder(head->right, height + 1, "v", len);
		string val = to + to_string(head->val) + to;
		int lenM = val.length();
		int lenL = (len - lenM) / 2;
		int lenR = len - lenM - lenL;
		val = getSpace(lenL) + val + getSpace(lenR);
		cout << (getSpace(height * len) + val) << endl;
		//System.out.println(getSpace(height * len) + val);
		printInOrder(head->left, height + 1, "^", len);
	}

	string getSpace(int num) {
		string space = " ";
		string* buf = new string();
		for (int i = 0; i < num; i++) {
			buf->append(space);
		}
		return *buf;
	}
	//�������������

	//�������������

	//�������������

	//�������������
public:
	//1 �������
	/*
	���ӡ������ջ
	ȡ���ڵ�ʹ�ӡ��Ȼ��ѹ���Һ��ӣ���ѹ����
	��������
	*/
	void PreOrderPrint(BiTreeNode *root)
	{
		if (root == nullptr)
			return;
		stack<BiTreeNode *> s;
		s.push(root);

		while (!s.empty()) {
			BiTreeNode * cur = s.top();
			s.pop();
			cout << cur->val << "  ";
			if (cur->right)
				s.push(cur->right);
			if (cur->left)
				s.push(cur->left);
		}
		cout << endl;
		return;
	}
public:
	//2 �������
	/*
	�󣬸�����
	rootһֱ�ߵ�����ߣ��ſ�ʼ��ӡ������ұ��нڵ㣬��ô���ұ߿�ʼ��Ҫ�ߵ������

	*/
	void InOrderPrint(BiTreeNode* root)
	{
		if (root == nullptr)
			return;

		stack<BiTreeNode*> s;
		GoLeft(root, s);
		while (!s.empty()) {
			auto cur = s.top();
			cout << cur->val << " ";
			s.pop();
			GoLeft(cur->right, s);
		}
		cout << endl;
	}
private:
	void GoLeft(BiTreeNode *root, stack<BiTreeNode*> &s)
	{
		while (root != nullptr) {
			s.push(root);
			root = root->left;
		}
		return;
	}

public:
	//3 �������
	/*
	���ң���
	˼·1��
	ʹ������ջ��һ����ű�����˳����һ����������rootʵ�ֱ仯
	dataջһֱ�ȵ��������ݶ���ջ�ſ�ʼ��ӡ
	��������Ҫ�����У��ң����˳��ȫ��ѹ��dataջ
	���ǡ��С���ѹ�ڡ��ҡ������棬�޷���ã���������һ��helpջ��������á��С��������á��С�->left GoRight
	˼·2��
	�����У��ң����˳�򽫽ڵ���ջ��ȫ����ջ֮���ٴ�ӡ
	*/
	void PostOrderPrint(BiTreeNode* root)
	{
		stack<BiTreeNode* > help, s;
		GoRight(root, help, s);
		while (!help.empty()) {
			auto cur = help.top();
			help.pop();
			GoRight(cur->left, help, s);
		}
		while (!s.empty()) {
			cout << s.top()->val << " ";
			s.pop();
		}
		cout << endl;
	}
private:
	void GoRight(BiTreeNode* root, stack<BiTreeNode*> &help, stack<BiTreeNode*> &s)
	{
		while (root != nullptr) {
			help.push(root);
			s.push(root);
			root = root->right;
		}
		return;
	}
};
//***************************

//*****�ַ����ָ�
//��patternΪ�ָ�����str�ָ������vector<string>��
std::vector<std::string> splitWithStl(const std::string &str, const std::string &pattern)
{
	//1 std::string::npos;
	//2 string().find(string pattern);
	//3 string().substr(begin, num);
	std::vector<std::string> resVec;

	if ("" == str)
	{
		return resVec;
	}
	//�����ȡ���һ�����ݣ���
	std::string strs = str + pattern;

	size_t pos = strs.find(pattern);
	size_t curBegin = 0;
	size_t size = strs.size();

	while (pos != std::string::npos)
	{
		std::string x = strs.substr(curBegin, pos - curBegin);
		resVec.push_back(x);
		curBegin = pos + 1;
		pos = strs.find(pattern, curBegin);
	}
	return resVec;
}
//****************

//******����ĵ��ܷ����������
class POINT {
public:
	template<typename T>
	POINT(T a, T b)
	{
		x = (double)a;
		y = (double)b;
	}
	double x;
	double y;
};
//�ж� ������ ͼ��
class IsSquare {
public:
	bool isSquare(vector<POINT> p)
	{
		if (p.size() != 4) {
			cout << "isSquare��Ҫ�ĸ��������" << endl;
			return false;
		}
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++)
				if (p[i].x == p[j].x && p[i].y == p[j].y)
					return false;
		}
		if (dis(p[0], p[1]) == dis(p[2], p[3]) && mid(p[0], p[1], p[2], p[3]) && dis(p[0], p[2]) == dis(p[0], p[3]))
			return true;
		if (dis(p[0], p[2]) == dis(p[1], p[3]) && mid(p[0], p[2], p[1], p[3]) && dis(p[0], p[1]) == dis(p[0], p[3]))
			return true;
		if (dis(p[0], p[3]) == dis(p[1], p[2]) && mid(p[0], p[3], p[1], p[2]) && dis(p[0], p[1]) == dis(p[0], p[2]))
			return true;
		return false;
	}
private:
	double dis(POINT a, POINT b)
	{
		return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	}

	bool mid(POINT a, POINT b, POINT c, POINT d)
	{
		if (a.x + b.x == c.x + d.x && a.y + b.y == c.y + d.y) return true;
		return false;
	}
};

//��
//���ò�������
namespace getRandom
{
	vector<int> vector_int(int size, int low, int high) {//����ұ�
		vector<int> retV;
		retV.resize(size);
		for (int &i : retV) {
			i = rand() % (high - low + 1) + low;
		}
		return retV;
	}

	vector<vector<int>> vector_vector_int(int row, int col, int low, int high) {
		vector<vector<int>> retV;
		retV.resize(row);
		for (auto &i : retV) {
			i = vector_int(col, low, high);
		}
		return retV;
	}

	::string string(int size, char low = 'a', char high = 'z') {
		::string retV;
		for (int i = 0; i < size; ++i) {
			retV += rand() % (high - low + 1) + low;
		}
		return retV;
	}
}

namespace getDefault
{
	vector<vector<int>> vector_vector_int(int row, int col) {
		vector<vector<int>> retV;
		retV.resize(row);
		for (auto &i : retV) {
			i = vector<int>(col);
		}
		return retV;
	}


}


namespace valueForTest
{
	namespace BiTree {
		//1 ������
			//              1
			//         2       null
			//      3     4
		BiTreeNode n5(5, nullptr, nullptr), n4(4, nullptr, nullptr), n3(3, nullptr, &n5), n2(2, &n3, &n4), n1(1, &n2, nullptr);
		void showdata()
		{
			cout << "               1" << endl
				<< "      2" << endl
				<< " 3         4" << endl
				<< "    5" << endl;
		}
	}
}


//�� �����㷨 
//����Ҫ��һ��Ҫ���˼·�͹ؼ���

//1
//���ֲ��ң����ص�һ�����ڵ���target����������
namespace C4N1_binary_search
{
	int binary_search(int *a, int len, int target)
	{
		//0 �߽����������Ϊ��
		if (a == nullptr || len == 0)
		{
			cout << "����Ϊ��" << endl;
			return -1;
		}
		//1 ʹ���½���λ��
		int low = 0, high = len - 1, median = 0;

		while (low <= high)//2 ֻҪά�������������ڻ�������
		{
			median = high - (high - low) / 2;
			//cout << "median" << median << endl;
			if (a[median] < target)//3 a[low]�����һ�����ڵ���target����������
			{
				low = median + 1;
				//ֻ�����м�ֵС��Ŀ��ֵ��ʱ��low�Ż��ƶ�--������������ǵ�һ�����ڵ���target��ֵ
			}
			else//a[median] >= target
			{
				high = median - 1;//4 a[high]�����һ��С��target����������
			}
		}

		if (a[low] == target)
		{
			cout << "�ҵ��ˣ�����Ϊ��" << low << endl;
		}
		else
		{
			cout << "û�ҵ�����һ������" << target << "�����������ǣ�" << low << endl;
		}
		return low;
	}//end of my_binary_search()

	void test(void)
	{
		vector<int> arr;
		arr = getRandom::vector_int(1, 20, 10);
		vector<int> target;
		target = getRandom::vector_int(1, 20, 3);

		sort(arr.begin(), arr.end());
		for (auto it = arr.begin(); it != arr.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
		for (auto it = target.begin(); it != target.end(); it++)
		{
			cout << "target:" << *it << endl;
			binary_search(&(arr[0]), 10, *it);
		}
	}
}

//2
//��������
namespace C4N2_quick_sort
{
	void swap(int *a, int i, int j)
	{
		int temp = 0;
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		return;
	}

	pair<int, int> partition(int *a, const int left, const int right)
	{
		srand((unsigned int)time);
		int cur = left;
		int small = left, large = right;
		//�������partition��ֵ
		int pos = left + rand() % (right - left + 1);
		int pv = a[pos];
		//��������
		while (cur <= large)
		{
			if (a[cur] < pv)
			{
				//С�����򻥻���С����������
				swap(a, small, cur);
				++small;
				++cur;
			}
			else if (a[cur] > pv)
			{
				//�������򻥻���������������
				swap(a, large, cur);
				large--;
			}
			else
			{
				//��ȵĻ������С����
				++cur;
			}
		}//while end
		return make_pair(small, large);
	}

	void quick_sort(int *a, int left, int right)
	{
		//1 �жϵݹ��Ƿ���ֹ
		if (left >= right){
			return;
		}
		//2 ���ָ���ص�small��large�ֱ���С��������������һ����
		auto ret = partition(a, left, right);
		//3 ��������
		quick_sort(a, left, ret.first - 1);
		quick_sort(a, ret.second + 1, right);
	}

	void test()
	{
		vector<int> v;
		v = getRandom::vector_int(1, 20, 20);
		printVector(v);

		quick_sort(&(v[0]), 0, v.size() - 1);
		cout << endl;
		printVector(v);
	}
}

//��
//�����㷨��
//18����ʵ��ջ
namespace C5N18_1__array_stack
{
	class ArrayStack
	{
	public:
		ArrayStack(int _capacity)
		{
			if (_capacity < 0) {
				cout << "size less than 0" << endl;
				throw ArrayStack(0);
			}
			a = new int[_capacity];
			capacity = _capacity;
			index = 0;
		}

		void pop() {
			if (index == 0) {
				cout << "ջΪ�գ�popʧ��" << endl;
				return;
			}
			--index;
		}

		void push(int newval) {
			if (index == capacity) {
				cout << "ջ������pushʧ��" << endl;
				return;
			}
			a[index] = newval;
			++index;
		}

		int top() {
			return a[index - 1];
		}
	private:
		int index;
		int capacity;
		int *a;
	};

	void test()
	{
		ArrayStack s(3);
		s.pop();
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);

		cout << "s.top(): " << s.top() << endl;
	}
}

//18����ʵ�ֶ���
namespace C5N18_2_array_queue
{
	class ArrayQueue
	{
	public:
		//1 ��ʼ��
		ArrayQueue(int _capacity)
		{
			arr = new int[_capacity];
			capacity = _capacity;
			start = 0;
			end = 0;
			size = 0;
		}

		//2 push
		void push(int newval)
		{
			//1 �Ƿ���
			if (size == capacity)
			{
				cout << "��������, pushʧ��" << endl;
				return;
			}
			//2 δ��
			arr[end--] = newval;
			//�Ƿ�ص�ͷ��
			end = end < 0 ? (capacity - 1) : end;
			++size;
		}

		//3 pop
		void pop()
		{
			//1 �Ƿ��
			if (size == 0)
			{
				cout << "�����ѿ�, popʧ��" << endl;
				return;
			}
			//2 δ��
			--start;
			start = start < 0 ? (capacity - 1) : start;
			--size;
		}

		//4 front
		int front()
		{
			if (size == 0)
			{
				cout << "empty!" << endl;
				return -300000;
			}
			return arr[start];
		}
		//����
	private:
		int capacity;
		int start;
		int end;
		int size;
		int *arr;
	};

	void test()
	{
		ArrayQueue q(3);
		q.pop();
		q.front();
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		cout << "top: " << q.front() << endl;
		q.pop();
		cout << "top: " << q.front() << endl;

	}

}

//19getmin()ջ
namespace C5N19_getminStack
{
	class minStack
	{
	public:
		void push(int val)
		{
			if (Min.empty()) {
				Min.push(val);
			}
			else if (val < Min.top()) {
				Min.push(val);
			}
			else {
				Min.push(Min.top());
			}
			Data.push(val);
		}

		void pop()
		{
			if (Data.empty()) {
				cout << "empty pop failed" << endl;
				return;
			}
			Data.pop();
			Min.pop();
		}
		int getMin()
		{
			if (!Min.empty())
				return Min.top();
			else
				cout << "empty getMin failed" << endl;
			return -1;
		}

	private:
		stack<int> Data;
		stack<int> Min;

	};
	void test()
	{
		minStack s;
		s.push(2);
		s.push(1);
		s.push(3);
		cout << s.getMin() << endl;
		s.pop();
		s.pop();
		cout << s.getMin() << endl;
	}

}

//20����ʵ��ջ
namespace C5N20_queue_stack
{
	class queue_stack
	{
	public:
		//1 push
		void push(int newval)
		{
			setp();
			(*cur).push(newval);
		}

		//2 pop
		void pop()
		{
			setp();
			if ((*cur).empty())
			{
				cout << "ջΪ�գ�popʧ��" << endl;
				return;
			}
			while ((*cur).size() != 1)
			{
				//�ƶ�
				(*empty).push((*cur).front());
				(*cur).pop();
			}
			//�������һ��
			(*cur).pop();
		}

		//3 front
		int front()
		{
			setp();
			while ((*cur).size() != 1)
			{
				//�ƶ�
				(*empty).push((*cur).front());
				(*cur).pop();
			}
			int ret = (*cur).front();
			(*empty).push((*cur).front());
			(*cur).pop();

			return ret;
		}
	private:
		void setp()
		{
			//1 2�Կ� ʹ��q1
			if (q1.empty())
			{
				empty = &q1;
				cur = &q2;
			}
			else
			{
				empty = &q2;
				cur = &q1;
			}
		}

	private:
		queue<int> q1;
		queue<int>q2;
		queue<int> *cur;
		queue<int> *empty;
	};

	void test()
	{
		queue_stack s;
		s.pop();
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);

		cout << "s.top(): " << s.front() << endl;
		s.pop();
		cout << "s.top(): " << s.front() << endl;
	}
}

//21ջʵ�ֶ���
namespace C5N21_stack_queue
{
	class stack_queue
	{
		//���ݲ�����߾����Ǳ�
		//1 push��ʱ��һ��Ҫ��pushջ��
		//2 front��pop��ʱ��һ��Ҫ��popջ��

	public:
		//1 push
		void push(int newval)
		{
			movetopush();
			spush.push(newval);

		}
		//2 pop
		void pop()
		{
			movetopop();
			if (spop.empty())
			{
				cout << "stack�ѿ�" << endl;
				return;
			}
			spop.pop();
		}

		//3 front
		int front()
		{
			movetopop();
			if (spop.empty())
			{
				cout << "stackû��Ԫ��" << endl;
				return -30000;
			}
			return spop.top();
		}

	private:
		void movetopush()
		{
			if (!spush.empty())
			{
				return;
			}
			else
			{
				while (!spop.empty())
				{
					spush.push(spop.top());
					spop.pop();
				}
			}
		}

		void movetopop()
		{
			if (!spop.empty())
			{
				return;
			}
			else
			{
				while (!spush.empty())
				{
					spop.push(spush.top());
					spush.pop();
				}
			}
		}
	private:
		stack<int> spush;
		stack<int> spop;
	};
	void test()
	{
		stack_queue q;
		q.pop();
		q.front();
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		cout << "top: " << q.front() << endl;
		q.pop();
		cout << "top: " << q.front() << endl;
	}
}

//22è������
namespace C5N22_CatDogQueue
{



}

//23תȦ��ӡ����
//����������
	//1 ��A�㵽B���ӡһ����
	//2 ��A�㵽B���ӡһ������
	//3 ��A�㵽B���ӡ������Σ�ֱ��A��B����ȫ����ӡ��
namespace C5N23_CirclePrintMatrix
{
	class Solution {
	public:
		vector<int> printMatrix(vector<vector<int> > const  &matrix) {
			vector<int> retv;
			int a_x = 0, a_y = 0, b_x = 0, b_y = 0;
			int ROW_MAX = matrix.size();
			if (ROW_MAX == 0) {
				return retv;
			}
			int COL_MAX = matrix[0].size();
			if (COL_MAX == 0) {
				return retv;
			}

			b_x = ROW_MAX - 1;
			b_y = COL_MAX - 1;

			while (a_x <= b_x && a_y <= b_y) {
				PrintSqrAandB(matrix, a_x, a_y, b_x, b_y, retv);
			}
			return retv;
		}

	private:
		void PrintSqrAandB(vector<vector<int> > matrix, int &a_x, int &a_y, int &b_x, int &b_y, vector<int> &retv)
		{
			if (a_x == b_x) {
				PrintFromAtoB(matrix, a_x++, a_y++, b_x--, b_y--, retv);
				return;
			}
			if (a_y == b_y) {
				PrintFromAtoB(matrix, a_x++, a_y++, b_x--, b_y--, retv);
				return;
			}

			{
				PrintFromAtoB(matrix, a_x, a_y, a_x, b_y - 1, retv);
				PrintFromAtoB(matrix, a_x, b_y, b_x - 1, b_y, retv);
				PrintFromAtoB(matrix, b_x, b_y, b_x, a_y + 1, retv);
				PrintFromAtoB(matrix, b_x, a_y, a_x + 1, a_y, retv);
				a_x++;
				a_y++;
				b_x--;
				b_y--;
			}
		}
		void PrintFromAtoB(vector<vector<int> > matrix, int a_x, int a_y, int b_x, int b_y, vector<int> &retv)
		{
			if (a_x != b_x && a_y != b_y) {
				cout << "ֻ�ܴ�ӡֱ��" << endl;
				return;
			}
			if (a_x == b_x) {
				if (a_y <= b_y) {
					while (a_y <= b_y) {
						//cout << matrix[a_x][a_y] << " ";//************
						retv.push_back(matrix[a_x][a_y++]);
					}
				}
				else {
					while (a_y >= b_y) {
						//cout << matrix[a_x][a_y] << " ";//*************
						retv.push_back(matrix[a_x][a_y--]);
					}
				}
				return;
			}
			if (a_y == b_y) {
				if (a_x <= b_x) {
					while (a_x <= b_x) {
						//cout << matrix[a_x][a_y] << " ";//**************
						retv.push_back(matrix[a_x++][a_y]);
					}
				}
				else {
					while (a_x >= b_x) {
						//cout << matrix[a_x][a_y] << " ";//*******
						retv.push_back(matrix[a_x--][a_y]);
					}
				}
				return;
			}
		}
	};
}

//��ת����
namespace reverselist
{
	class SingleList
	{
	public:
		SingleList(int val, SingleList* next)
		{
			this->val = val;
			this->next = next;
		}
	public:
		int val;
		SingleList* next;
	};

	class DoubleList
	{
	public:
		DoubleList(int val, DoubleList* next)
		{
			this->val = val;
			this->next = next;
		}

	public:
		int val;
		DoubleList* next;
	};

	SingleList * reverseSList(SingleList **phead)
	{
		SingleList *cur = (*phead);
		SingleList *pre = nullptr;
		SingleList *next = nullptr;
		while (cur != nullptr)
		{
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		*phead = pre;
		return pre;
	}

	DoubleList *reverseDList(DoubleList **head)
	{

		DoubleList *cur = (*head);
		DoubleList *pre = nullptr;
		DoubleList *next = cur->next;

		return nullptr;
	}
	void Psinglelist(SingleList &head)
	{
		SingleList* cur = &head;
		while (cur != nullptr)
		{
			cout << cur->val << " ";
			cur = cur->next;
		}

	}

	void Pdoublelist(DoubleList &head)
	{

	}

	void test()
	{
		//��д������������Ҫ��
		SingleList l3(3, nullptr), l2(2, &l3), l1(1, &l2), head(0, &l1);
		SingleList * phead = &head;
		Psinglelist(*phead);

		cout << "��ת��";
		reverseSList(&phead);
		Psinglelist(*phead);
	}
}

//29�ж������Ƿ��л������ػ���ڵĵ�ַ
namespace C5N29_ListHasLoop
{
	//fast��slow����ָ��
	//fastһ����������slowһ����1��
	//fast��null�����޻�
	//fast==slow���л�
		//ͷ�ڵ�������㿪ʼһ���ߣ�ÿ��һ���������ĵط����ǻ������

	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
			val(x), next(NULL) {
		}
	};

	class Solution {
	public:
		ListNode * EntryNodeOfLoop(ListNode* pHead)
		{
			ListNode *fast = pHead, *slow = pHead;
			bool meet = false;
			while (fast != nullptr&&fast->next != nullptr) {
				fast = fast->next->next;
				slow = slow->next;

				if (fast == slow) {
					fast = pHead;
					while (fast != slow) {
						fast = fast->next;
						slow = slow->next;
					}
					return fast;
				}
			}
			return nullptr;
		}
	};

}

//33�ж����������Ƿ��ཻ
namespace C5N33_TwoListIntersect
{
	//1 �ж��Ƿ��л��������ػ�����ڽڵ��ַ


	//2-1 û�����ҵ�len1��len2����������len1-len2��Ȼ��һ����

	//2-2 һ���л�һ��û��
		//�϶����ཻ

	//2-3�����л�
		//1 loop1һֱ�ߣ�ֱ���ص�loop1Ҳû����loop2-->���ཻ

		//2 loop1 == loop2 -->�˻�Ϊ2-1

		//3 loop1!=loop2-->�ཻ
}

//34�ǵݹ����������
namespace C5N34_BiTree_print_no_digui
{
	//˼·�����ݴ�ӡ˳��˼��ָ��root����ƶ���ջ������rootʵ���ƶ�

	//1 �������
	/*
	���ӡ������ջ
	ȡ���ڵ�ʹ�ӡ��Ȼ��ѹ���Һ��ӣ���ѹ����
	��������
	*/
	void PreOrderPrint(BiTreeNode *root)
	{
		if (root == nullptr)
			return;
		stack<BiTreeNode *> s;
		s.push(root);

		while (!s.empty()) {
			BiTreeNode * cur = s.top();
			s.pop();
			cout << cur->val << "  ";
			if (cur->right)
				s.push(cur->right);
			if (cur->left)
				s.push(cur->left);
		}
		cout << endl;
		return;
	}

	//2 �������
	/*
	�󣬸�����
	rootһֱ�ߵ�����ߣ��ſ�ʼ��ӡ������ұ��нڵ㣬��ô���ұ߿�ʼ��Ҫ�ߵ������

	*/
	void GoLeft(BiTreeNode *root, stack<BiTreeNode*> &s)
	{
		while (root != nullptr) {
			s.push(root);
			root = root->left;
		}
		return;
	}

	void InOrderPrint(BiTreeNode* root)
	{
		if (root == nullptr)
			return;

		stack<BiTreeNode*> s;
		GoLeft(root, s);
		while (!s.empty()) {
			auto cur = s.top();
			cout << cur->val << " ";
			s.pop();
			GoLeft(cur->right, s);
		}
		cout << endl;
	}

	//3 �������
	/*
	���ң���
	˼·1��
	ʹ������ջ��һ����ű�����˳����һ����������rootʵ�ֱ仯
	dataջһֱ�ȵ��������ݶ���ջ�ſ�ʼ��ӡ
	��������Ҫ�����У��ң����˳��ȫ��ѹ��dataջ
	���ǡ��С���ѹ�ڡ��ҡ������棬�޷���ã���������һ��helpջ��������á��С��������á��С�->left GoRight
	˼·2��
	�����У��ң����˳�򽫽ڵ���ջ��ȫ����ջ֮���ٴ�ӡ
	*/
	void GoRight(BiTreeNode* root, stack<BiTreeNode*> &help, stack<BiTreeNode*> &s)
	{
		while (root != nullptr) {
			help.push(root);
			s.push(root);
			root = root->right;
		}
		return;
	}

	void PostOrderPrint(BiTreeNode* root)
	{
		stack<BiTreeNode* > help, s;
		GoRight(root, help, s);
		while (!help.empty()) {
			auto cur = help.top();
			help.pop();
			GoRight(cur->left, help, s);
		}
		while (!s.empty()) {
			cout << s.top()->val << " ";
			s.pop();
		}
		cout << endl;

	}
	void test()
	{
		auto a = valueForTest::BiTree::n1;
		valueForTest::BiTree::showdata();
		cout << "�������" << endl;
		PreOrderPrint(&a);
		cout << "�������" << endl;
		InOrderPrint(&a);
		cout << "�������" << endl;
		PostOrderPrint(&a);
	}
}

//36�ں���parentָ��Ķ������У���ӡĳ���ڵ�ĺ��
//��̣��������˳���е���һ���ڵ�
namespace C5N36_SuccessorNode
{
	//1 û�����������Լ���������====���ڵ�
	//2  ��������====����������ͷ
	//3  û�����������Լ����������������ߣ�ֱ���ߵ������������Ľڵ�cur����ӡcur�ĸ��ڵ�
	//4  �߽磺�ߵ�ͷҲû����������������root���Ǿ������һ���ڵ㣬û�к��


}

//37����ǰ��������л�������
//1 valueҪ�н�����־
//2 nullҪ�б�ʾ����������¼
namespace C5N37_1serialByPre
{
	string serialByPre(BiTreeNode *root)
	{
		if (root == nullptr)
			return "#!";
		string valueStr = to_string(root->val);
		string ret = valueStr + "!";
		ret += serialByPre(root->left);
		ret += serialByPre(root->right);
		return ret;
	}
}



//38����ǰ����������л�������
namespace C5N37_2reconstructByPre
{
	bool isNULL(string &str)
	{
		if (str[0] == '#') {
			string help(str.begin() + 2, str.end());
			str = help;
			return true;
		}
		return false;
	}

	int getValChangeStr(string &str) {
		size_t offset = 0;
		int ret = stoi(str, &offset);
		string help(str.begin() + offset + 1, str.end());
		str = help;
		return ret;
	}
	BiTreeNode *process(string &str)
	{
		if (str.empty())
			return nullptr;
		if (isNULL(str)) {
			return nullptr;
		}
		int val = getValChangeStr(str);
		BiTreeNode* root = new BiTreeNode(val);

		root->left = process(str);
		root->right = process(str);

		return root;
	}

	BiTreeNode * reconstructBiTree(string str)
	{
		//��Ϊprocess��ı�ԭstr
		return process(str);
	}

	void test()
	{
		string res = C5N37_1serialByPre::serialByPre(&valueForTest::BiTree::n1);
		cout << res;
		BiTreeNode * reconstruct = C5N37_2reconstructByPre::reconstructBiTree(res);

		BiTreeFunc().printTree(&valueForTest::BiTree::n1);
		BiTreeFunc().printTree(reconstruct);
	}
}

//37�������Ĳ������
//1 rootָ��ָ��ڵ㣬����q
//2 rootָ�����q���ı�
//3 ʹ�õݹ���ʵ��������߼�
namespace C5N37_PrintBiTreeByLevel
{
	void process(queue<BiTreeNode*> &q)
	{
		if (q.empty())
			return;

		BiTreeNode *root = q.front();
		q.pop();
		cout << root->val << "  ";

		if (root->left)
			q.push(root->left);
		if (root->right)
			q.push(root->right);

		process(q);
	}

	void PrintBiTreeByLevel(BiTreeNode *root)
	{
		queue<BiTreeNode*> q;
		q.push(root);
		process(q);
		cout << endl;
	}

	void PrintBiTreeByLevel(BiTreeNode *root, queue<BiTreeNode*> &q)
	{
		//��Ϊ�� ��ӡ 
		//ָ���ƶ����߼�����ͬ��
		if (root != nullptr)
		{
			cout << root->val << " ";
			q.push(root->left);
			q.push(root->right);
		}

		if (q.empty())
			return;

		BiTreeNode *front = q.front();
		q.pop();
		PrintBiTreeByLevel(front, q);
	}


	void test()
	{
		auto n1 = valueForTest::BiTree::n1;
		queue<BiTreeNode *> q;
		valueForTest::BiTree::showdata();
		PrintBiTreeByLevel(&n1, q);

		PrintBiTreeByLevel(&n1);
	}
}

//38�ж��Ƿ���ƽ�������
//˼·��1 ������������ƽ��������� 2 ���������ĸ߶Ȳ�С�ڵ���1
// ʹ���쳣��ʵ�֣���ȥ���Լ���װ�ط���ֵ����
namespace C5N38_JudgeBalanceBiTree
{
	//����1���쳣ʵ��
	class Solution
	{
	public:
		bool isBalance(BiTreeNode *root)
		{
			try {
				int high = getHigh(root);
				cout << "Balance, height:" << high << endl;
			}
			catch (bool) {
				cout << "not Balance" << endl;
				return false;
			}
			return true;
		}

		int getHigh(BiTreeNode *root) {
			if (root == nullptr)
				return 0;
			int lHigh = getHigh(root->left);
			int rHigh = getHigh(root->right);
			if (abs(lHigh - rHigh) > 1)
				throw bool();
			return max({ lHigh, rHigh }) + 1;
		}
	};

	//����2����װ�Լ��ķ���ֵʵ��
	class ReturnValue
	{
	public:
		ReturnValue(bool _isB, int _h)
		{
			this->h = _h;
			this->isB = _isB;
		}
	public:
		bool isB;
		int h;
	};

	class node
	{
	public:
		node(int _val, node* _left, node* _right)
		{
			val = _val;
			left = _left;
			right = _right;
		}
	public:
		int val;
		node *left;
		node *right;
	};

	ReturnValue process(node *root)
	{
		if (root == nullptr)
		{//��������ƽ��
			return ReturnValue(true, 0);
		}

		ReturnValue leftdata = process(root->left);
		if (!leftdata.isB)
		{
			return ReturnValue(false, 0);//��������ƽ��
		}
		ReturnValue rightdata = process(root->right);
		if (!rightdata.isB)
		{
			return ReturnValue(false, 0);//��������ƽ��
		}

		int Ddeep = abs((leftdata.h - rightdata.h));
		if (Ddeep > 1)
		{
			return ReturnValue(false, 0);
		}
		else
		{
			int curh = leftdata.h > rightdata.h ? leftdata.h + 1 : rightdata.h + 1;
			return ReturnValue(true, curh);
		}
	}//process end

	bool JudgeBalanceBiTree(node *root)
	{
		ReturnValue ret = process(root);
		return ret.isB;
	}

	void test()
	{
		//              1
		//         2       null
		//      3     4
		node n4(4, nullptr, nullptr), n3(3, nullptr, nullptr), n2(2, &n3, &n4), n1(1, &n2, nullptr);

		node b4(4, nullptr, nullptr), b3(3, nullptr, nullptr), b2(2, &b3, &b4), b5(5, nullptr, nullptr), b1(1, &b2, &b5);
		bool isB = JudgeBalanceBiTree(&n1);
		if (isB == true)
		{
			cout << "is Banlance" << endl;
		}
		else
		{
			cout << "not Banlance" << endl;
		}

		isB = JudgeBalanceBiTree(&b1);
		if (isB == true)
		{
			cout << "is Banlance" << endl;
		}
		else
		{
			cout << "not Banlance" << endl;
		}
	}
}

//39�ж��Ƿ�������������
//��������������Ľ������������ľ��Ƕ���������
namespace C5N40_JudegBST//binary search tree
{
	void isBiSearchTree(BiTreeNode* root, int last);
	bool isBiSearchTree(BiTreeNode* root);

	bool isBiSearchTree(BiTreeNode* root)
	{
		try {
			isBiSearchTree(root, INT_MIN);
		}
		catch (bool) {
			return false;
		}
		return true;
	}

	void isBiSearchTree(BiTreeNode* root, int last)
	{
		if (root == nullptr)
			return;
		isBiSearchTree(root->left, last);
		if (root->val < last)
			throw bool();
		isBiSearchTree(root->right, root->val);
		return;
	}

}

//40�ж��Ƿ�����ȫ������
//�������
//1 �ڵ����Һ���û���ӣ�����false
//2 ���һ���ڵ㲻���������Ӷ��У���ô�����������Ľڵ㶼Ҫ��Ҷ�ӽڵ�
//3 
namespace JudgeCBT//complete binary tree
{

}



//41����ȫ�������Ľڵ������ʱ�临�Ӷ�log(N)*log(N)
//0 ���rootΪҶ�ӽڵ㣬����1
//1 ����߽磬��������һ�㣬�õ�Height
//2 ������������߽磬���Ƿ񵽴�Height
	//����		�õ��������Ľڵ�������ݹ�������
	//û����	�õ��������Ľڵ�������ݹ�������
// 1<<n  ��2��n�η�
namespace C5N42_CountNodeInCBT
{

}

//45�Ӽ���������õ�����_randompool
namespace RandomPool
{





}

//46bloomfilter��¡������
namespace BloomFilter
{
	class bitmap
	{
	public:
		bitmap(int _size = 32000)
		{
			arr = new unsigned int[_size / 32 + 1]();
			size = _size;
		}

		void put(int index)// example:8
		{
			if (index > size - 1)
			{
				//����
				delete[] arr;
				//arr = 

			}
			int intIndex = index / 32;//ÿ��int������32bit  ����Ϊ0
			int bitIndex = index % 32;//Ϊ8

			arr[intIndex] = (arr[intIndex] | (1 << bitIndex));
			return;
		}

		void print()
		{
			for (int i = 0; i < size; i++)
			{
				int intIndex = i / 32;
				int bitIndex = i % 32;
				if (arr[intIndex] & (1 << bitIndex))
				{
					cout << i << " ";
				}
			}
		}

	private:
		unsigned int *arr;
		int size;
	};

	void test()
	{
		bitmap bm(10);
		bm.put(3);
		bm.put(9);
		bm.print();
	}
}



//50�ֵ���/�Ż�/insert/delete/search/searchPre
namespace C5N50_TrieTree
{

}
//51��һ�����ϵ��ַ���ƴ�ӳ�1���ַ�����Ҫ��õ����ַ������ֵ�����С
namespace C5N51_AppendString
{


}

//52�ֽ���
namespace Haffman
{





}

//53
//������̰��
namespace greedy_RoomAndMeeting
{
	bool EndEarlyFirst(vector<int> v1, vector<int> v2)
	{
		return v1[1] < v2[1];
	}

	class solution
	{
	public:
		void initvTimePair(int(*arr)[2], int N)
		{
			for (int i = 0; i < N; i++)
			{
				vector<int> temp;
				temp.resize(2);
				temp[0] = arr[i][0];
				temp[1] = arr[i][1];
				vTimePair.push_back(temp);
			}
		}

		void func1(int(*arr)[2], int N)//��ȷ�������
		{
			initvTimePair(arr, N);

			sort(vTimePair.begin(), vTimePair.end(), EndEarlyFirst);

			walk();
		}

		void walk()
		{
			vector<vector<int>> tempTimePair = this->vTimePair;
			int curtime = 0;
			count = 0;
			for (auto it = vTimePair.begin(); it != vTimePair.end(); it++)
			{
				if (curtime <= (*it)[0])
				{
					count++;
					curtime = (*it)[1];
					cout << "curtime" << curtime << endl;//***********
				}
			}
			cout << "�ܹ�������" << count << endl;
		}

	public:
		vector<vector<int>> vTimePair;
		int count;
	};
	void test()
	{
		int arr[][2] = { 1,9,2,4,3,6,4,7,8,10 };
		solution().func1(arr, 5);
	}
}




//namespace Graph
//{
//	class Node
//	{
//	public:
//		Node(int value=0,int index =0)
//		{
//			this->index = index;
//			this->value = value;
//			this->in = 0;
//			this->out = 0;
//		}
//
//	public:
//		int value;
//		int index;//��ͼ���ǵڼ��Žڵ�
//		int in;
//		int out;
//		vector<Node *> nexts;//�洢�ڽӽڵ���graph�еı��
//		vector<Edge*> edges;
//	};
//
//	class Edge
//	{
//	public:
//		Edge(int weight, int from, int to)
//		{
//			this->weight = weight;
//			this->from = from;
//			this->to = to;
//		}
//
//	public:
//		int weight;
//		Node from;
//		Node to;
//	};
//
//	class Graph
//	{
//
//	public:
//		unordered_map<int, Node> nodes;
//		unordered_set<Edge> edges;
//
//	public:
//		//1 ͨ�����бߵ���Ϣ����ͼ 
//		//	 weight	   from  	to 
//		//		2	   	1	    2	
//		//		1		3		4
//	 
//		//2	ͨ���ڽӾ��󹹽�ͼ 
//		//��-->��
//		//	   v0       v1       v2       v3
//		//	 v0  1        INT_MAX    2        4
//		//	 v1 INT_MAX   INT_MAX    5        2
//		//	 v2 INT_MAX   INT_MAX    5
//		//	 v3 INT_MAX	  INT_MAX    6        1
//		void BuildBy_AdjacencyMatrix(int **arr, int N)
//		{
//			for (int i = 0; i < N; i++)
//			{
//				Node newnode(0,i);
//				nodes.insert(make_pair(i, newnode));
//				//map����0--N-1�Žڵ�
//			}
//
//			//arr[i]-->arr[j]
//			for (int i = 0; i < N; i++)
//			{
//				for (int j = 0; j < N; j++)
//				{
//					if (arr[i][j] != INT_MAX)
//					{
//						//�б�
//						Edge new_edge(arr[i][j], i, j);
//						Edge *p = &new_edge;
//					//from node
//						auto iti = nodes.find(i);
//						if (iti == nodes.end())
//						{
//							cout << "û���ҵ���" << i << "���ڵ㣬������֮ǰ�����սڵ�ʱʧ��" << endl;
//							return;
//						}
//						(*iti).second.out++;				//���ȼ�1
//						(*iti).second.nexts.push_back(j);//��¼�ڽӽڵ�index
//						(*iti).second.edges.push_back()
//					//to node
//						auto itj = nodes.find(j);
//						if (itj == nodes.end())
//						{
//							cout << "û���ҵ���" << j << "���ڵ㣬������֮ǰ�����սڵ�ʱʧ��" << endl;
//							return;
//						}
//						(*itj).second.in++;				//��ȼ�1
//
//					//edge
//
//						edges.insert(new_edge);
//					}
//
//				}
//			}
//
//		}
//	};
//
//	void test()
//	{
//
//
//	}
//}

namespace IsGivenValueInBiTree
{
	class solution
	{
	public:
		void isIn(int _givenvalue, BiTreeNode* root)
		{
			result = false;
			this->givenvalue = _givenvalue;
			cout << "isIn begin...givenvalue=" << this->givenvalue << endl;
			vector<int> v;
			process(root, v);
			if (result == false)
			{
				cout << "not in" << endl;
				return;
			}
			else
			{
				for (auto it1 = vvi.begin(); it1 != vvi.end(); it1++)
				{
					for (auto it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
					{
						cout << (*it2) << " " << endl;
					}
					cout << endl;
				}
			}
		}

	private:
		void process(BiTreeNode *root, vector<int> &v)
		{
			v.push_back(root->val);
			//	cout << "push " << root->val << " ";
			if (root->left != nullptr)
			{
				process(root->left, v);
			}
			if (root->right != nullptr)
			{
				process(root->right, v);
			}
			if (root->left == nullptr &&root->right == nullptr)
			{
				//��Ҷ�ӽڵ���
				int sum = accumulate(v.begin(), v.end(), 0);

				if (sum == givenvalue)
				{
					cout << "sum=" << sum << endl;
					vvi.push_back(v);
					result = true;
				}
			}
			//	cout << "pop " << v.back() << endl;

			v.pop_back();
			return;
		}

	private:
		int givenvalue;
		vector<vector<int>> vvi;
		bool result;
	};

	void test()
	{
		solution fuc;
		cout << "test:6" << endl;
		fuc.isIn(6, &valueForTest::BiTree::n1);

		cout << "test:3" << endl;
		solution().isIn(3, &valueForTest::BiTree::n1);

		cout << "test:10" << endl;
		solution().isIn(10, &valueForTest::BiTree::n1);
	}
}





//54
//��̬�滮
namespace coin_change
{

}

//55
//��׳�n!
namespace C5N55_factorial
{
	int getFactorial(int n)
	{
		if (n == 1)
		{
			return 1;
		}
		int ret = 0;
		ret = n * getFactorial(n - 1);
		return ret;
	}
}

//56
//��ŵ��
namespace C5N56_hanoi
{
	class solution
	{
	public:
		void func1(int N, string from, string to, string help)//��ȷ�������
		{
			walk(N, from, to, help);
		}

		void walk(int N, string from, string to, string help)
		{
			if (N == 1)
			{
				cout << "Move 1" << from << " to " << to << endl;
			}
			else
			{
				walk(N - 1, from, help, to);							//��n-1��fromŲ��help��
				cout << "Move " << N << " " << from << " to " << to << endl;
				walk(N - 1, help, to, from);							//��n-1��helpŲ��to��
			}
		}

	public:
		int N;
		string from;
		string to;
		string help;
	};

	void test()
	{
		solution().func1(3, "��", "��", "��");
	}
}

//57
//C5N57_��ӡ�ַ��������������� ��ͬλ�õĿ�������
namespace PrintDupAllSubSeq
{

	void process(string::iterator it, string &original_str, string output)
	{
		if (it == original_str.end())
		{
			cout << output << endl;
			return;
		}
		process(it + 1, original_str, output);
		process(it + 1, original_str, output + (*it));

	}

	void func(string::iterator it, string &original_str, string output)
	{
		process(it, original_str, output);
	}

	void test()
	{
		string str = "abc";

		auto it = str.begin();
		string output;
		func(it, str, output);
	}
}

//58
//C5N58_��ӡһ���ַ�����ȫ����
namespace AllArray
{
	class solution
	{
	public:
		void func1(string str)//��ȷ�������
		{
			int N = str.size();
			//��ʼ��map
			map<char, int> pair;
			for (auto it = str.begin(); it != str.end(); it++)
			{
				auto it2 = pair.find((*it));
				if (it2 != pair.end())
				{
					//�ҵ��� ����+1
					pair[(*it)] += 1;
				}
				else
				{//û�ҵ� ����
					pair.insert(make_pair((*it), 1));
				}
			}
			walk(pair, 0, N);
		}

		void walk(map<char, int> pair, int cur, int N)
		{
			if (cur == N)
			{
				for (auto it = vch.begin(); it != vch.end(); it++)
				{
					cout << (*it) << " ";
				}
				cout << endl;
			}
			for (auto it1 = pair.begin(); it1 != pair.end(); it1++)
			{
				if ((*it1).second != 0)
				{
					vch.push_back((*it1).first);	//ʹ���ַ�
					(*it1).second--;				//ʣ�����-1
					walk(pair, cur + 1, N);//�ݹ���һ��
					vch.pop_back();					//���ַ�����ȥ
					(*it1).second++;
				}
			}
		}

	public:
		vector<char> vch;
	};

	void test()
	{
		string str = "abcc";

		solution().func1(str);
	}
}

//59
//ĸţ��Сţ��Сţ3���Ҳ������Сţ
namespace C5N59_babbyCow
{

}

//��ӡ�ַ���������������
namespace PrintAllSubSeq
{
	class solution
	{
	public:
		void func1(string _str)//��ȷ�������
		{
			this->str = _str;
			vector<string> vstr;
			vstr.push_back("");
			cout << "�� Ӧ��1 " << vstr.size() << endl;
			auto it = str.begin();

			walk(it, vstr);

		}
		void walk(string::iterator &it, vector<string> vstr)
		{
			if (it == str.end())
			{
				return;
			}

			int size = vstr.size();
			for (int i = 0; i < size; i++)
			{
				string temp = vstr[i] + (*it);
				cout << temp << endl;
				vstr.push_back(temp);
			}
			vvstr.push_back(vstr);
			walk(++it, vstr);
		}

	public:
		vector<vector<string>>  vvstr;
		string str;
	};
	void test()
	{
		string str = "abc";
		solution().func1(str);
	}
}



//�ھ��������ߣ���С·����
namespace walk_matrix
{
	class solution
	{
	public:
		int  func1(int(*arr)[4], int _row, int _col)//��ȷ�������
		{
			this->col = _col;
			this->row = _row;
			int ret = walk(arr, 0, 0);

			cout << ret << endl;
			return ret;
		}

		int walk(int(*arr)[4], int i, int j)
		{
			int ret = 0;
			if (i == row - 1 && j == col - 1) {
				return arr[i][j];
			}
			else if (i == row - 1) {
				return arr[i][j] + walk(arr, i, j + 1);
			}
			else if (j == col - 1) {
				return arr[i][j] + walk(arr, i + 1, j);
			}
			else {
				int right = walk(arr, i, j + 1);
				int down = walk(arr, i + 1, j);
				return min(right, down) + arr[i][j];
			}
		}

	public:
		int row;
		int col;
	};
	//

	void test()
	{
		int arr[][4] = { 3,2,1,0,7,5,0,1,3,7,6,2 };
		solution().func1(arr, 3, 4);
	}
}

//����һ�����飬ʹ������������ܷ��ۼӵõ�k
namespace isSum
{
	class solution
	{
	public:
		void func1(vector<int> v, int _aim)//��ȷ�������
		{
			this->aim = _aim;
			auto it = v.begin();
			int sum = 0;
			bool ret = walk(v, it, sum);
			if (ret == true) {
				cout << "����" << endl;
				printVector<int>(vresult);
			}
			else {
				cout << "������" << endl;
			}
		}

		bool walk(vector<int> &v, vector<int>::iterator it, int sum)
		{
			if (it == v.end())
			{
				if (sum == aim)
				{
					vresult = vtemp;
					printVector<int>(vresult);//***********
					return true;
				}
				else {
					return false;
				}
			}
			vtemp.push_back((*it));
			bool use = walk(v, it + 1, sum + (*it));
			vtemp.pop_back();
			bool notuse = walk(v, it + 1, sum);
			return use || notuse;
		}

	public:
		int aim;
		vector<int> vtemp;

		vector<int> vresult;
	};

	void test()
	{
		vector<int> v = { 1,2,5,4,8,7,2,1,3,4,1,5 };
		int k = 7;
		solution().func1(v, k);
	}
}


//�ݹ�ʵ�������ַ�������󹫹�������
//��׼�ĵݹ�
namespace MaxSameSubSeq_digui2
{
	class solution
	{
	public:
		void func1(string _str1, string _str2)//��ȷ�������
		{
			str1 = _str1;
			str2 = _str2;
			auto it1 = str1.begin();
			auto it2 = str2.begin();
			int ret = walk(it1, it2);
			cout << "�ܹ��У�" << ret << endl;
		}

		int walk(string::iterator it1, string::iterator it2)
		{
			int ret = 0;
			if (it1 == str1.end() || it2 == str2.end())
			{
				return 0;
			}
			if ((*it1) == (*it2))
			{
				cout << "same character: " << (*it1) << endl;
				ret = 1 + walk(it1 + 1, it2 + 1);
			}
			else {
				int ret1 = walk(it1 + 1, it2);
				int ret2 = walk(it1, it2 + 1);
				ret = max(ret1, ret2);
			}
			return ret;
		}

	public:
		string str1;
		string str2;
		vector<char> vch;
	};

	void test() {
		solution().func1("abcdefg", "gabcefg");
	}
}

//��д��������
namespace calculator
{
	char getSopTop(stack<char> &s) {
		if (s.empty()) {
			return 'n';
		}
		else {
			return s.top();
		}
	}

	//ʹ��optop���㣬�õ������snumջ
	//sop.pop();
	void use_op_push_value(stack<int> &snum, stack<char> &sop, char &optop) {
		int num2 = snum.top();
		snum.pop();
		int num1 = snum.top();
		snum.pop();
		int newnum = 0;
		switch (optop)
		{
		case '*':
			newnum = num1 * num2;
			break;
		case '/':
			newnum = num1 / num2;
			break;
		case '+':
			newnum = num1 + num2;
			break;
		case '-':
			newnum = num1 - num2;
			break;
		}
		sop.pop();
		snum.push(newnum);
	}

	int cal(string::iterator &it, string &str) {
		stack<int> snum;
		stack<char> sop;

		while (it != str.end()) {
			char optop = getSopTop(sop);
			char cur = (*it);

			if (cur > '0' && cur < '9') {
				//������
				int temp = 0;
				string strtemp(it, str.end());
				size_t offset = 0;
				temp = stoi(strtemp, &offset);
				it += offset;
				snum.push(temp);
			}
			else {
				//��op
				if (cur == '(') {
					int ret = cal(++it, str);
					snum.push(ret);

				}
				else if (cur == ')') {
					it++;
					break;
				}
				else {
					//��+ - * /
					if (optop == 'n') {
						//opջ��
						sop.push(cur);
						it++;
					}
					else {
						//opջ����
						if (cur == '+' || cur == '-') {
							if (optop == '+' || optop == '-') {
								use_op_push_value(snum, sop, optop);
								it++;
								//��getOpTopһ�Σ�����1+2*3+4*5+6-->1+6+20+6,Ҳ���Բ�ʹ��
							/*	while ((optop = getSopTop(sop)) != 'n')
								{
									sop.pop();
									int num2 = snum.top();
									snum.pop();
									int num1 = snum.top();
									snum.pop();
									int newnum = 0;
									switch (optop)
									{
									case '+':
										newnum = num1 + num2;
										break;
									case '-':
										newnum = num1 - num2;
										break;
									}
								}*/
								sop.push(cur);
							}//optop + -
							else {
								//optop * /
								use_op_push_value(snum, sop, optop);
								sop.push(cur);
								it++;
							}//optop * /
						}//cur + - 
						else if (cur == '*' || cur == '/')
						{
							if (optop == '+' || optop == '-') {
								sop.push(cur);
								it++;
							}
							else {
								use_op_push_value(snum, sop, optop);
								sop.push(cur);
								it++;
							}//optop * /
						}// cur * / 
					}// ��+ - * /
				}//��op + - * / 
			}//end of ��()+-*/
		}//end of while

		//����β��
		while (!sop.empty()) {
			char optop = getSopTop(sop);
			use_op_push_value(snum, sop, optop);
		}
		return snum.top();
	}//end of cal

	int func(string &str) {
		string::iterator it = str.begin();
		int ret = cal(it, str);
		cout << ret << endl;
		return ret;
	}

	void test() {
		string str = "100*(1+1)-200*2";
		int ret = func(str);
	}
}

//namespace zero_length_array
//{
//	extern "C"
//	{
//		void test() {
//		typedef struct A
//		{
//			int a[0];//��СΪ0�����飬�����Ƕ�̬�����
//		};
//	}
//	}
//}

namespace stl_array
{
	void test()
	{
		//�����㲻��
		array<int, 3> arr;
		cout << "sizeof(arr):" << sizeof(arr) << endl;
		cout << " &arr:" << &arr << endl;

		cout << "1 : " << *(unsigned int*)(&arr) << endl;
		cout << "2: " << *((unsigned int*)(&arr) + 1) << endl;
		cout << "3: " << *((unsigned int*)(&arr) + 2) << endl;
	}
}

namespace typeid_test
{
	class B
	{};
	class A
	{
	public:
		B b;
	};
	void test()
	{
		int a = 0;
		map<int, int> map1;
		cout << typeid(a).name() << endl;
		cout << typeid(map1).name() << endl;
		cout << typeid(map<int, int>::iterator).name() << endl;

		typedef int I;
		I i = 0;
		//	typename char C;//����ʹ��C�������
		//	C c = 'a';
		//	cout << C << endl;

	}
}

//��Ǯ���⣬��1,2,5�������Ļ��ң���Ҫ����7ԪǮ���ж����ֻ���
//�ݹ�ʵ��
namespace Arr_Accumulate_K
{
	int process(vector<int>::iterator it, vector<int> &v, int aim);

	int coins(vector<int> v, int aim)
	{
		auto it = v.begin();

		int ret = process(it, v, aim);
		cout << ret << endl;
		return ret;
	}

	int process(vector<int>::iterator it, vector<int> &v, int aim)
	{
		int ret = 0;
		if (it == v.end())
		{
			if (aim == 0) {
				return (ret = 1);
			}
			else {
				return (ret = 0);
			}
		}
		for (int i1 = 0; i1*(*it) <= aim; ++i1) {
			ret += process(it + 1, v, aim - i1 * (*it));
		}
		return ret;
	}

	void test()
	{
		vector<int> v = { 1,2,5 };
		int aim = 7;
		coins(v, aim);
	}
}


namespace smart_ptr_test
{
	template<typename T>
	class my_ptr
	{
	public:
		T operator*()
		{
			return *p;
		}

	public:
		my_ptr()
		{
			pcount = new int(1);
			p = new T;
		}
		my_ptr(T t)
		{
			pcount = new int(1);
			p = new T(t);

		}
		int PrintCount()
		{
			cout << (*pcount) << endl;
			return (*pcount);
		}

		my_ptr(const my_ptr& p2)
		{
			decreaseCount_autoDelete();
			pcount = p2.pcount;
			(*p2.pcount) += 1;
			p = p2.p;
		}
		~my_ptr()
		{
			decreaseCount_autoDelete();
		}

		my_ptr& operator=(const my_ptr& p2)
		{
			decreaseCount_autoDelete();
			pcount = p2.pcount;
			(*p2.pcount) += 1;
			p = p2.p;
			return *this;
		}

		void decreaseCount_autoDelete()
		{
			if (pcount != nullptr)
			{
				--(*pcount);
				if (*pcount <= 0)
				{
					delete p;
					p = nullptr;
				}
			}
		}

	private:
		T * p;
		int *pcount;
	};

	void test()
	{
		//1 shared_ptr
			//1 ��ʼ��
			//2 count������
			//3 ������ֵ
		shared_ptr<int> sp1 = make_shared<int>(100);
		cout << "sp1.use_count()" << sp1.use_count() << endl;
		shared_ptr<int> sp2(sp1);
		cout << "sp1.use_count()" << sp1.use_count() << endl;
		auto up3 = make_unique<int>(300);
		cout << "*sp1" << *sp1 << endl;

		//unique_ptr up;

		cout << "test my_ptr" << endl;
		my_ptr<int> p;
		p.PrintCount();
		my_ptr<int> p2 = p;
		cout << "my_ptr<int> p2 =p;" << endl;
		p.PrintCount();
		p2.PrintCount();
		cout << "my_ptr<int> p3 =p2 = p;" << endl;
		my_ptr<int> p3;
		p3 = p2 = p;
		p.PrintCount();
		p2.PrintCount();
		p3.PrintCount();
		cout << "*p3: " << *p3 << endl;

		int arr[10];
		cout << "sizeof(arr)" << sizeof(arr) << endl;
	}
}

namespace mergesort
{
	class solution
	{
	public:
		void MergeSort(vector<int> &arr)
		{
			int L = 0;
			int R = arr.size() - 1;
			sortprocess(arr, L, R);
		}
	private:
		void sortprocess(vector<int> &arr, int L, int R)
		{
			if (R <= L) {	//ֻ��һ����ʱ�ͷ���		
				return;
			}
			int mid = L + (R - L) / 2;
			sortprocess(arr, L, mid);		//���������
			sortprocess(arr, mid + 1, R);	//�Ұ�������
			merge(arr, L, mid, R);			//�������ߺϲ�
		}

		void merge(vector<int> &arr, int L, int mid, int R)
		{
			vector<int> temp_arr(R - L + 1);
			int i1 = L;
			int i2 = mid + 1;
			int i = 0;
			while ((i1 <= mid) && (i2 <= R)) {
				temp_arr[i++] = (arr[i1] < arr[i2] ? arr[i1++] : arr[i2++]);

			}
			while (i1 <= mid) {
				temp_arr[i++] = arr[i1++];
			}
			while (i2 <= R) {
				temp_arr[i++] = arr[i2++];
			}
			for (int i = 0; i < R - L + 1; i++) {
				arr[L + i] = temp_arr[i];
			}
		}
	};

	void test()
	{
		vector<int> arr = { 2,4,1,3 };
		int len = arr.size();
		printVector(arr);

		solution().MergeSort(arr);
		printVector(arr);
	}
}

namespace xiaohe
{
	class solution
	{
	public:
		int ans(vector<int> v) {
			int L = 0;
			int R = v.size() - 1;

			return process(v, L, R);
		}
		int process(vector<int> &arr, int L, int R) {
			if (R <= L)
				return 0;
			int mid = (L + R) / 2;
			int sum = process(arr, L, mid) + process(arr, mid + 1, R);	//�ݹ�ֽ�

			int i1 = L, i2 = mid + 1, i = 0;
			vector<int> temp_arr(R - L + 1);
			while ((i1 <= mid) && (i2 <= R)) {
				temp_arr[i++] = (arr[i1] < arr[i2] ?
					(sum += ((R - i2 + 1)*arr[i1]), arr[i1++]) : arr[i2++]);
			}
			while (i1 <= mid) {
				temp_arr[i++] = arr[i1++];
			}
			while (i2 <= R) {
				temp_arr[i++] = arr[i2++];
			}
			for (int i = 0; i < R - L + 1; i++) {
				arr[L + i] = temp_arr[i];
			}
			return sum;
		}

	private:
		vector<int> vret;
	};

	void test()
	{
		vector<int> v = { 1,3,4,2,5 };
		int ret = solution().ans(v);
		cout << ret << endl;
		printVector(v);
	}
}

namespace QuickSort_2
{
	class solution
	{
	public:
		void QuickSort(vector<int> &v)
		{
			int len = v.size();
			int L = 0;
			int R = len - 1;
			quicksort_process(&(v[0]), L, R);
		}

		void quicksort_process(int *arr, int L, int R)
		{
			if ((L < 0) || (L >= R)) {			//С�����±����Ϊ����û��С����
				return;
			}
			vector<int> pos = partition(arr, L, R);//����С�����ʹ��������±�
			quicksort_process(arr, L, pos[0]);
			quicksort_process(arr, pos[1], R);
		}
		vector<int> partition(int *arr, int L, int R)
		{
			int cur = L;
			int less = L;
			int more = R;
			int pv = arr[R];
			while (cur <= more) {
				if (arr[cur] < pv) {
					swap(arr, cur++, less++);
				}
				else if (arr[cur] == pv) {
					cur++;
				}
				else if (arr[cur] > pv) {
					swap(arr, cur, more--);
				}
			}
			vector<int> retV;
			retV.push_back(less - 1);
			retV.push_back(more + 1);
			return retV;
		}
		void swap(int *arr, int a, int b) {
			int temp = arr[a];
			arr[a] = arr[b];
			arr[b] = temp;
		}
	};
	void test()
	{
		vector<int> v = { 3,2,5,4,1 };
		printVector(v);
		solution().QuickSort(v);
		printVector(v);
	}
}

namespace my_priority_queue
{
	//ϵͳĬ�ϵ��Ǵ����
	void test()
	{
		priority_queue<int> q;
		q.push(2);
		q.push(3);
		cout << q.top() << endl;
	}
}

namespace rotate_matrix
{
	class solution
	{
	public:
		void rotate(vector<vector<int>> &arr)
		{
			if (arr.empty()) {
				return;
			}
			if (arr.size() != arr[0].size()) {
				cout << "������������" << endl;
				return;
			}
			int N = arr.size() - 1;
			int a = 0, b = N;
			while (a < b) {
				RotateEdge(arr, a++, b--);
			}
		}
		void RotateEdge(vector<vector<int>> &arr, int a, int b)
		{
			int offset = 0;
			while (a + offset < b) {
				Rotate4Points(arr, a, b, offset++);
			}
		}
		void Rotate4Points(vector<vector<int>> &arr, int a, int b, int offset)
		{
			int temp = arr[a][a + offset];
			arr[a][a + offset] = arr[b - offset][a];
			arr[b - offset][a] = arr[b][b - offset];
			arr[b][b - offset] = arr[a + offset][b];
			arr[a + offset][b] = temp;
		}
	};


	void test()
	{
		vector<vector<int>> arr;
		vector<int> v1 = { 1,2,3 };
		vector<int> v2 = { 4,5,6 };
		vector<int> v3 = { 7,8,9 };
		arr.push_back(v1);
		arr.push_back(v2);
		arr.push_back(v3);

		printVector<int>(arr);

		solution().rotate(arr);

		printVector<int>(arr);
	}
}

namespace FindInOrderedArray
{
	//˼·����һ��������Ͻǿ�ʼ���չ����ƶ�����������˻�û���ҵ�����ô����û��
	class Solution {
	public:
		bool Find(int target, vector<vector<int> > array) {
			if (array.empty() || array[0].empty()) {
				return false;
			}
			int x = 0, y = array[0].size() - 1;
			int ROW = array.size();
			int COL = array[0].size();
			while ((x >= 0 && x < ROW) && (y >= 0 && y < COL)) {
				if (array[x][y] == target) {
					return true;
				}
				else if (array[x][y] < target) {
					++x;
				}
				else {
					--y;
				}
			}
			return false;
		}
	};
}

namespace string_test
{
	//����ͬʱ�����вι��캯�����޲ι��캯��
	//�����вι��캯������ȫ��Ĭ�ϲ�������Ϊ���ڶ����� 
	class Test
	{
	public:
		Test(int a) :a(a)
		{
		}
		Test()
		{
			this->a = 0;
		}
		int a;

	};
	void test()
	{
		string s = "12345678";
		cout << sizeof(s) << endl;
		Test a1;
		Test a2(1);
	}
}

namespace ChouShu
{
	/*��ֻ��������2��3��5��������������Ugly Number����
	����6��8���ǳ�������14���ǣ���Ϊ����������7��
	ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������*/
	//˼·����̬�滮����������ָ�룬��ʾ*2��*3��*5.������������ǰ���Ϳ��Եõ����еĳ���
	//��ΪҪ�õ�����ĳ������飬����Ҫ��ǰ����ʱ��Ƚ�
	class Solution {
	public:
		int GetUglyNumber_Solution(int index) {
			if (index == 1)
				return 1;
			int p2 = 0, p3 = 0, p5 = 0;
			int cur = 0;
			int *arr = new int[index];
			arr[0] = 1;
			while (++cur < index) {
				(arr[p2] * 2) < (arr[p3] * 3) ?
					((arr[p2] * 2) < (arr[p5] * 5) ? (set_num(arr, cur, p2, 2)) : (set_num(arr, cur, p5, 5))) :
					((arr[p3] * 3) < (arr[p5] * 5) ? (set_num(arr, cur, p3, 3)) : (set_num(arr, cur, p5, 5)));
			}
			int ret = arr[index - 1];
			delete[] arr;
			return ret;
		}
	private:
		void set_num(int *&arr, int &cur, int &p, int n)
		{
			int val = arr[p] * n;
			for (int i = 0; i < cur; ++i) {
				if (arr[i] == val) {
					--cur;	//cur���ƶ�
					++p;	//p�ƶ�
					return;
				}
			}
			arr[cur] = arr[p] * n;
			++p;
		}
	};

	void Print(int N)
	{
		cout << Solution().GetUglyNumber_Solution(N) << endl;

	}
	void test()
	{
		int i = 0;
		while (i++ < 10) {
			cout << "��" << i << "�������ǣ� ";
			Print(i);
		}
	}
}

namespace once_char
{
	//��һ��ֻ����һ�ε��ַ�
	/*��һ���ַ���(1<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��*/

	class Solution {
	public:
		int FirstNotRepeatingChar(string str) {
			if (str.empty()) {
				return -1;
			}
			bool already_in[52];
			bool once[52];
			int pos[46] = { 0 };
			for (int i = 0; i < 52; ++i) {
				already_in[i] = false;
			}
			for (int i = 0; i < 52; ++i) {
				once[i] = false;
			}
			for (unsigned int i = 0; i < str.size(); ++i) {
				int cur = str[i] - 'a' >= 0 ? str[i] - 'a' : str[i] - 'A' + 26;
				if (already_in[cur] == false) {
					already_in[cur] = true;
					once[cur] = true;
					pos[cur] = i;
				}
				else {
					once[cur] = false;
				}
			}

			vector<int> help;
			for (int i = 0; i < 52; ++i) {
				if (already_in[i] == true && once[i] == true) {
					help.push_back(pos[i]);
					//cout << (char)(i + 'a') << " or " << (char)(i + 'A') << endl;
				}
			}
			if (!help.empty()) {
				sort(help.begin(), help.end());
				return help[0];
			}
			else {
				return -1;
			}
		}
	};

	void test() {
		cout << Solution().FirstNotRepeatingChar("NXWtnzyoHoBhUJaPauJaAitLWNMlkKwDYbbigdMMaYfkVPhGZcrEwp");
	}
}

namespace nixudui
{
	//�����е������

	class Solution {
	public:
		int InversePairs(vector<int> data) {

			return process(data, 0, data.size() - 1);
		}
	private:
		int process(vector<int> &data, int L, int R)
		{
			if (R <= L) {
				return 0;
			}
			int mid = R - (R - L) / 2;
			return process(data, L, mid - 1) + process(data, mid, R) + merge(data, L, mid - 1, mid, R);


		}
		int merge(vector<int> &data, int L1, int R1, int L2, int R2)
		{
			vector<int> help(R1 - L1 + 1 + R2 - L2 + 1);
			int i1 = L1, i2 = L2, cur = 0;
			int sum = 0;
			while (i1 <= R1 && i2 <= R2) {
				if (data[i2] < data[i1]) {
					sum += R1 - i1 + 1;
					help[cur++] = data[i2++];
				}
				else {
					help[cur++] = data[i1++];
				}
			}
			while (i1 <= R1) {
				help[cur++] = data[i1++];
			}
			while (i2 <= R2) {
				help[cur++] = data[i2++];
			}
			for (int i = L1; i < R2 + 1; ++i) {
				data[i] = help[i - L1];
			}
			return sum;
		}
	};

	void test()
	{
		vector<int> v = { 1,2,3,4,5,6,7,0 };
		cout << Solution().InversePairs(v);
	}
}

namespace gonggongjiedian
{

	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
			val(x), next(NULL) {
		}
	};
	class Solution {
	public:
		ListNode * FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
			//1
			int len1 = GetLen(pHead1);
			int len2 = GetLen(pHead2);
			//
			if (len1*len2 == 0)
				return nullptr;
			//2
			ListNode* Long = nullptr, *Short = nullptr;
			int LenLong = 0, LenShort = 0;
			set_long_short(Long, LenLong, Short, LenShort, pHead1, len1, pHead2, len2);
			//3
			ListNode* cur_long = move_n(Long, LenLong - LenShort);
			//4
			return move_together_when_equal_return(cur_long, Short);
		}
	private:
		int GetLen(ListNode* pHead) {
			int ret = 0;
			while (pHead != nullptr) {
				pHead = pHead->next;
				++ret;
			}
			return ret;
		}
		ListNode* move_n(ListNode* Long, int n) {
			while (n > 0) {
				--n;
				if (Long == nullptr) {
					cout << "move_n ����ĩβ" << endl;
					return nullptr;
				}
				Long = Long->next;
			}
			return Long;
		}
		void set_long_short(ListNode* &Long, int &LenLong, ListNode* &Short, int &LenShort,
			ListNode* pHead1, int len1, ListNode* pHead2, int len2) {
			if (len1 >= len2) {
				Long = pHead1;
				LenLong = len1;
				Short = pHead2;
				LenShort = len2;
			}
			else {
				Long = pHead2;
				LenLong = len2;
				Short = pHead1;
				LenShort = len1;
			}
		}

		ListNode* move_together_when_equal_return(ListNode* Long, ListNode* Short) {
			while (Long != nullptr && Long != Short) {
				Long = Long->next;
				Short = Short->next;
			}
			return Long;
		}
	};
	void test() {
		ListNode l1(1), l2(2);

		l1.next = &l2;
		cout << (Solution().FindFirstCommonNode(&l1, &l2))->val << endl;
	}

}

namespace ctor_dtor_order
{
	class Base1
	{
	public:
		Base1() {
			cout << "Base1 Ctor" << endl;
		}
		~Base1() {
			cout << "Base1 Dtor" << endl;
		}

	};

	class Base2
	{
	public:
		Base2() {
			cout << "Base2 Ctor" << endl;
		}
		~Base2() {
			cout << "Base2 Dtor" << endl;
		}
	};
	class A :public Base1
	{
	public:
		A() {
			cout << "A Ctor" << endl;
		}
		~A() {
			cout << "A Dtor" << endl;
		}
		Base2 b1;
	};

	void test() {
		A a;
	}
}

namespace dizengzixulie
{
	//�����������
	//��̬�滮
	class Solution1
	{
	public:
		int GetIt(vector<int>  &v)
		{
			int ret = process(v, 0, INT_MIN);
			return ret;
		}
		int process(vector<int> &v, unsigned int pos, int max) {
			if (pos >= v.size()) {
				return 0;
			}
			int ret1 = 0, ret2 = 0;
			if (v[pos] > max)		//�ж��������д�ǰ�洫������max����dp��ʱ���Ǳ���Ϊ�����鵱ǰλ����������
				ret1 = 1 + process(v, pos + 1, v[pos]);
			ret2 = process(v, pos + 1, max);
			return ret1 > ret2 ? ret1 : ret2;
		}
	};

	class Solution2
	{
	public:
		int GetIt(vector<int>  &v) {
			if (v.empty()) {
				return 0;
			}
			int *ret = new int[v.size()];
			memset(ret, 0, sizeof(int)*(v.size()));
			for (int i = v.size() - 1; i >= 0; --i) {
				int ret_val = find_max_ifnull_0(v, i, ret);
				ret[i] = ret_val + 1;
			}

			int max = 0;
			for (unsigned int i = 0; i < v.size(); ++i) {
				if (ret[i] > max)
					max = ret[i];
			}

			delete[] ret;
			return max;
		}

	private:
		//�ҵ�����v[i] > v[cur]ǰ���£�arr[i]������
		int find_max_ifnull_0(vector<int>& v, int cur, int *arr) {
			if (cur == v.size() - 1) {
				return 0;//���һ��
			}
			int max = 0;
			for (unsigned int i = cur + 1; i < v.size(); ++i) {
				if (v[i] > v[cur] && arr[i] > max) {
					max = arr[i];
				}
			}
			return max;
		}
	};

	void test()
	{
		srand(unsigned(time));
		for (int i = 0; i < 100; i++) {
			auto v = getRandom::vector_int(0, 20000, 50);
			//PrintVector(v);
			//cout << endl;
			//cout << Solution1().GetIt(v) << endl;
			//cout << Solution2().GetIt(v) << endl;
			if (Solution1().GetIt(v) == Solution2().GetIt(v)) {
				cout << "nice" << endl;
			}
			else
			{
				cout << "ohhhh no!!!!!!!" << endl;
			}
		}
		vector<int> v = { 10,1,20,5,30,4,40,9,50,60 ,8 };
		printVector(v);
		cout << endl;
		cout << Solution1().GetIt(v) << endl;
		cout << Solution2().GetIt(v) << endl;
	}
}

namespace test_argument_duotai
{
	class A
	{
	public:
		int a;
	};
	class B :public A
	{
	public:
		string b;
	};
	void func(A a) {

	}
	void test()
	{
		B b;
		B *pb = &b;

		func(b);
	}

}

//�� ��ָoffer

namespace maxInWindows {
	/*����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
	���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ�
	���ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}�� �������{2,3,4,2,6,2,5,1}�Ļ�������������6���� 
	{[2,3,4],2,6,2,5,1}�� {2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}�� {2,3,4,[2,6,2],5,1}�� {2,3,4,2,[6,2,5],1}��
	{2,3,4,2,6,[2,5,1]}*/
//˼·��˫�����飬ͷ�������ֵ��С�����һ����ӽ�����Ԫ�ض�ɾ��
//��ʼ����ʱ��Ͱ����������
	class Solution {
	public:
		vector<int> maxInWindows(const vector<int>& num, unsigned int size)
		{
			vector<int> ret;
			if (num.empty() || size == 0 || size>num.size()) return ret;
			deque<vector<int>::const_iterator> help;
			init(help, num, size);		//��ʼ��ҲҪ���չ���
			ret.push_back(*help.front());
			//print(help);
			for (auto it = num.begin()+1; it!= num.end() && it != num.end()-size+1; ++it) {
				popWhenEqual(help, it-1);	
				pushAndDelete(help, it + size-1);
				ret.push_back(*help.front());
				//print(help);
			}
			return ret;
		}
	private:
		void init(deque<vector<int>::const_iterator> &help, const vector<int>& num, unsigned int size ) {
			help.push_back(num.begin());
			for (auto it = num.begin() + 1; it != num.end() && it != num.begin() + size ;++it) {
				pushAndDelete(help, it);
			}
		}
		void popWhenEqual(	
			deque<vector<int>::const_iterator> &help,
			vector<int>::const_iterator it) {
			if (help.front() == it) {
				help.pop_front();
			}
		}
		void pushAndDelete(
			deque<vector<int>::const_iterator> &help,
			vector<int>::const_iterator it) {
			while (!help.empty() && (*help.front() < *it)) {
				help.pop_front();
			}
			while (!help.empty() && (*help.back() < *it)) {
				help.pop_back();
			}
			help.push_back(it);
		}

		void print(deque<vector<int>::const_iterator> help) {
			while (!help.empty()) {
				cout << *help.front() << " ";
				help.pop_front();
			}
			cout << endl;
		}
	};


}
namespace GetMedianFromStream {
//˼·��ʹ�����ȼ����У���¼������λ�����������Сֵ��С����λ����������ֵ
//		ÿ�β������ֵ�ʱ���չ��򣬱�֤���Ը��ݶѶ��õ���λ��
	class Solution {
	public:
		void Insert(int num)
		{
			if (minHeap.size() == 0) {
				minHeap.push(num);
				return;
			}
			if (maxHeap.size() == 0) {
				maxHeap.push(num);
				return;
			}
			if (num > maxHeap.top()) {
				//�ʹ�����Ƚ�
				if (minHeap.size() == maxHeap.size()) {
					minHeap.push(num);
				}
				else {
					if (num < minHeap.top()) {
						maxHeap.push(num);
					}
					else {
						maxHeap.push(minHeap.top());
						minHeap.pop();
						minHeap.push(num);
					}
				}
			}
			else {
				if (minHeap.size() == maxHeap.size()) {
					minHeap.push(maxHeap.top());
					maxHeap.pop();
					maxHeap.push(num);
				}
				else {
					maxHeap.push(num);
				}
			}
		}

		double GetMedian()
		{
			if (minHeap.size() == maxHeap.size()) {
				return ((double)minHeap.top() + (double)maxHeap.top()) / 2.0;
			}
			else {
				return minHeap.top();
			}
		}
	private:
		priority_queue<int> maxHeap;
		priority_queue<int, vector<int>, greater<int>> minHeap;
	};
}

namespace KthNode {
	/*����һ�ö��������������ҳ����еĵ�kС�Ľ�㡣
	���磬 ��5��3��7��2��4��6��8��    �У��������ֵ��С˳�����С����ֵΪ4��
	*/
//˼·���������������k����ʱ�����
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
		}
	};

	class Solution {
	public:
		TreeNode * KthNode(TreeNode* pRoot, int k)
		{
			stack<TreeNode*> help;
			stack<TreeNode*> out;
			goLeft(help, pRoot);
			while (!help.empty()) {
				out.push(help.top());
				if (out.size() == k) {
					return out.top();
				}
				auto tmp = help.top();
				help.pop();
				goLeft(help, tmp->right);
			}
			return nullptr;
		}
	private:
		void goLeft(stack<TreeNode*> &help, TreeNode *pRoot) {
			//����ĳ���ڵ�һֱ�����ߣ�·���Ľڵ㶼��ջ
			while (pRoot != nullptr) {
				help.push(pRoot);
				pRoot = pRoot->left;
			}
		}
	};


}

namespace isSymmetrical {
/*�ж϶������ǲ��ǶԳƵ�*/
//˼·�������ڶԳ�λ���ϵĽڵ�һֱ������
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
		}
	};

	class Solution {
	public:
		bool isSymmetrical(TreeNode* pRoot)
		{
			if (pRoot == nullptr)
				return true;
			return process(pRoot->left, pRoot->right);
		}
	private:
		bool process(TreeNode* node1, TreeNode* node2) {
			if (node1 == nullptr &&node2 == nullptr)
				return true;
			else if (node1 == nullptr || node2 == nullptr)
				return false;

			if (node1->val != node2->val)
				return false;
			else
				return process(node1->left, node2->right)&process(node1->right, node2->left);
		}
	};
}
namespace GetNext {
	//1 �Լ��������� ==>�������������

	//1 ����Լ��������� 
	//�Լ����ڵ�
	//2 ����Լ���������
	//�Լ�û��������==>���Լ����ڵ�ֱ�����ڵ���үү�ڵ��������

	struct TreeLinkNode {
		int val;
		struct TreeLinkNode *left;
		struct TreeLinkNode *right;
		struct TreeLinkNode *next;
		TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
		}
	};

	class Solution {
	public:
		TreeLinkNode * GetNext(TreeLinkNode* pNode)
		{
			if (pNode == nullptr) return nullptr;

			if (pNode->right != nullptr) {
				return goleft(pNode->right);
			}
			else {
				while (pNode->next != nullptr && pNode != pNode->next->left) {
					if (pNode->next == nullptr) return nullptr;
					pNode = pNode->next;
				}
				return pNode->next;
			}
		}
	private:
		TreeLinkNode * goleft(TreeLinkNode* pNode) {
			while (pNode->left != nullptr) {
				pNode = pNode->left;
			}
			return pNode;
		}
	};
}
namespace PrintBitreeByLevel {

	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
		}
	};

	class Solution {
	public:
		vector<vector<int> > Print(TreeNode* pRoot) {

			vector<vector<int> > ret;
			if (pRoot == nullptr)
				return ret;
			vector<vector<TreeNode*> > help;

			vector<TreeNode*> tmp2;
			tmp2.push_back(pRoot);
			help.push_back(tmp2);

			auto it = help.begin();

			while (1) {
				vector<TreeNode*> tmp;
				vector<int> tmpInt;
				for (auto it2 = (*it).begin(); it2 != (*it).end(); it2++) {
					tmpInt.push_back((*it2)->val);
					if ((*it2)->left != nullptr) {
						tmp.push_back((*it2)->left);
					}
					if ((*it2)->right != nullptr) {
						tmp.push_back((*it2)->right);
					}
				}
				ret.push_back(tmpInt);
				if (tmp.empty())
					break;
				help.push_back(tmp);
				it = help.end() - 1;///----
			}
			return ret;
		}
	};
}

namespace StrToInt {
	//1 �ж��Ƿ�Ϸ�
	//2 ����stackתΪ��׺���ʽ��vector
	//3 ����ջ�������㣬ջ��Ψһ���
	class Solution {
	public:
		int StrToInt(string str) {
			try {
				return process(str);
			}
			catch (bool) {
				return 0;
			}
		}

		int process(string str) {
			isLegal(str);
			vector<string> out = In2Post(str);
			return getValFromPost(out);
		}

	private:
		//��������ֱ�����
		//�������ź�ջ���Ƚ����ȼ������ȼ����ڻ����ջ����ֱ����ջ
		//							���ȼ�����ջ�����ȵ���ջ��Ԫ�ز���ӡ������ջ
		//����'('��ջ�����ȼ����
		//����')'����������ӡ����ջ��Ԫ�أ�ֱ������'('
		vector<string> In2Post(string str) {
			const char *pc = str.c_str();
			stack<char> op;
			vector<string> post;
			post.push_back("0");

			while (*pc != '\0') {
				int n = isNumber(pc);
				if (n != 0) {
					post.push_back(string(pc, pc + n));
					pc += n;
				}
				else {
					if (*pc == ')') {
						while (op.top() != '(') {
							post.push_back(string() = op.top());
							op.pop();
						}
						op.pop();
						pc++;
					}
					else if (*pc == '(') {
						op.push(*pc);
						pc++;
					}
					else {
						if (op.empty() || getPriority(op.top()) <= getPriority(*pc)) {
							op.push(*pc);
						}
						else {
							post.push_back(string() = op.top());
							op.pop();
							op.push(*pc);
						}
						pc++;
					}
				}
			}
			while (!op.empty()) {
				post.push_back(string() = op.top());
				op.pop();
			}
			//printVector(post);//-------------
			return post;
		}

		int  getValFromPost(vector<string> out) {
			stack<int> help;
			for (auto it = out.begin(); it != out.end(); ++it) {
				if (isNumber((*it).c_str())) {
					help.push(mstoi((*it).c_str()));
				}
				else {
					int second = help.top();
					help.pop();
					int first = help.top();
					help.pop();
					switch (*(*it).c_str())
					{
					case '+':
						help.push(first + second);
						break;
					case '-':
						help.push(first - second);
						break;
					case '*':
						help.push(first * second);
						break;
					case '/':
						help.push(first / second);
						break;
					default:
						break;
					}

				}
			}
			return help.top();
		}

	private:
		int getPriority(char c) {
			switch (c) {
			case '+':
			case '-':
				return 1;
				break;
			case '*':
			case '/':
				return 2;
				break;
			case '(':
				return 0;
				break;
			}
		}

		void isLegal(string str) {
			const char *pc = str.c_str();
			bool isOp = false;
			int leftR = 0;

			while (*pc != '\0') {
				if (!isNumber(pc)) {
					switch (*pc)
					{
					case '-':
					case '+':
					case '*':
					case '/':
						if (isOp == true)
							throw bool();
						isOp = true;
						break;
					case '(':
						leftR++;
						isOp = false;
						break;
					case ')':
						leftR--;
						isOp = false;
						if (leftR < 0)
							throw bool();
						break;
					default:
						throw bool();
					}
					pc++;
				}
				else {
					isOp = false;
					pc++;
				}
			}
			if (leftR > 0) {
				throw bool();
			}
		}

		int isNumber(const char *begin) {
			const char *pc = begin;
			if ('0' <= *pc && *pc <= '9') {
				while ('0' <= *pc && *pc <= '9') {
					pc++;
				}
				return pc - begin;
			}
			else
				return 0;
		}

		int mstoi(const char *pc, int &offset) {
			const char *cur = pc;
			int ret = 0;
			int tmp = 0;
			while (*cur >= '0'&&*cur <= '9') {
				ret *= 10;
				tmp = *cur - '0';
				ret += tmp;
				++cur;
			}
			offset = cur - pc;
			return ret;
		}

		int mstoi(const char *pc) {
			const char *cur = pc;
			int ret = 0;
			int tmp = 0;
			while (*cur >= '0'&&*cur <= '9') {
				ret *= 10;
				tmp = *cur - '0';
				ret += tmp;
				++cur;
			}
			return ret;
		}

		string mto_string(int a) {
			string ret;
			stack<char> help;
			int temp = 0;
			while (a != 0) {
				temp = a % 10;
				a /= 10;
				char tempC = '0' + temp;
				help.push(tempC);
			}
			while (!help.empty()) {
				ret += help.top();
				help.pop();
			}
			return ret;
		}
	};


}

namespace Convert {
	//ʹ�÷ǵݹ��������
	/*����һ�ö��������������ö���������ת����һ�������˫������
	Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��*/
	//˼·�����Ƕ�������ǰ��������ǵ�ʹ��ջ��������������ָ�룬ע�⴦��߽������next = nullptr��ʱ��
	class Solution {
	public:
		BiTreeNode * Convert(BiTreeNode* pRootOfTree) {
			if (pRootOfTree == nullptr)
				return nullptr;

			BiTreeNode *next = nullptr, *cur = nullptr, *last = nullptr;
			stack<BiTreeNode*> sNode;
			goLeft(pRootOfTree, sNode);
			BiTreeNode *retNode = sNode.top();

			while (!sNode.empty()) {
				last = cur;
				cur = sNode.top();
				sNode.pop();
				goLeft(cur->right, sNode);
				if (!sNode.empty()) {
					next = sNode.top();
				}
				else {
					next = nullptr;
				}
				cur->left = last;
				cur->right = next;
			}
			return retNode;
		}
	private:
		void goLeft(BiTreeNode *root, stack<BiTreeNode*> &sNode) {
			while (root != nullptr)
			{
				sNode.push(root);
				root = root->left;
			}
		}
	};


}

namespace LastRemaining_Solution {
	/*��Ŀ����
ÿ����һ��ͯ��,ţ�Ͷ���׼��һЩС����ȥ�����¶�Ժ��С����,����������ˡ�
HF��Ϊţ�͵�����Ԫ��,��ȻҲ׼����һЩС��Ϸ������,�и���Ϸ��������:����,��С������Χ��һ����Ȧ��
Ȼ��,�����ָ��һ����m,�ñ��Ϊ0��С���ѿ�ʼ������ÿ�κ���m-1���Ǹ�С����Ҫ���г��׸�,
Ȼ���������Ʒ�����������ѡ����,���Ҳ��ٻص�Ȧ��,��������һ��С���ѿ�ʼ,����0...m-1����....������ȥ....
ֱ��ʣ�����һ��С����,���Բ��ñ���,�����õ�ţ������ġ�����̽���ϡ���ذ�(��������Ŷ!!^_^)��
������������,�ĸ�С���ѻ�õ������Ʒ�أ�(ע��С���ѵı���Ǵ�0��n-1)*/

/*
1

*/
	class Solution {
	public:
		int LastRemaining_Solution(int n, int m)
		{


		}
	};


}

namespace IsContinuous {
	/*��Ŀ����
LL���������ر��,��Ϊ��ȥ����һ���˿���,���������Ȼ��2������,2��С��(һ����ԭ����54��^_^)...
��������г����5����,�����Լ�������,�����ܲ��ܳ鵽˳��,����鵽�Ļ�,������ȥ��������Ʊ,�ٺ٣���
������A,����3,С��,����,��Ƭ5��,��Oh My God!������˳��.....LL��������,��������,������\С �����Կ����κ�����,
����A����1,JΪ11,QΪ12,KΪ13�������5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ���2��4),��So Lucky!����LL����ȥ��������Ʊ����
����,Ҫ����ʹ�������ģ������Ĺ���,Ȼ���������LL��������Σ�
����������˳�Ӿ����true����������false��Ϊ�˷������,�������Ϊ��С����0*/
//˼·�� 1 ������ 2 ����0����������ֵ 3 С�����ظ�������
	class Solution {
	public:
		bool IsContinuous(vector<int> numbers) {
			if (numbers.size() == 0)
				return false;
			sort(numbers.begin(), numbers.end());
			int joker = 0;
			for (auto it = numbers.begin(); *it == 0; ++it) {
				joker++;
			}
			for (auto it = numbers.begin() + joker; it != numbers.end(); ++it) {
				if (it + 1 == numbers.end())
					break;
				int sub = *(it + 1) - (*it) - 1;
				if (sub == -1)
					return false;// 0 0 1 1���ظ�����
				joker -= sub;
			}
			if (joker < 0)
				return false;
			else
				return true;
		}
	};
}

namespace LeftRotateString {
	//˼·�����Ƶ�λ�����ܻᳬ���ַ����ĳ���
	class Solution {
	public:
		string LeftRotateString(string str, int n) {
			if (str.size() < 2)
				return str;
			n = n % str.size();
			string retStr(str.begin() + n, str.end());
			string tmp(str.begin(), str.begin() + n);
			return retStr + tmp;
		}
	};
}


namespace ReverseSentence {
	//˼·��	1 �ȷ�תÿ������
	//			2 �Ӻ���ǰ��ȡ��������
	class Solution {
	public:
		string ReverseSentence(string str) {
			auto it = str.begin();

			while (it != str.end()) {
				auto it2 = it;
				while ((it2 + 1) != str.end() && *(it2 + 1) != ' ') {
					++it2;
				}
				auto it1 = it;
				it = it2 + 1;
				while ((it2 - it1) >= 0) {
					swap(it1, it2);
					++it1;
					--it2;
				}
				while (it != str.end() && *it == ' ')
					++it;
			}
			string retStr;
			string::reverse_iterator rit = str.rbegin();
			while (rit != str.rend()) {
				retStr += *rit;
				++rit;
			}
			return retStr;
		}
	private:
		void swap(string::iterator it1, string::iterator it2) {
			char tmp = (*it1);
			*it1 = *it2;
			*it2 = tmp;
		}
	};

	void test() {
		cout << Solution().ReverseSentence("you! \n fuck will i");

	}



}
namespace FindNumsAppearOnce
{
	//������ֻ����һ�ε���������
	/*һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�*/
//	�״�㣺ʹ��insert�������ݵ�map��ʱ�����key�Ѿ����ڣ���value���ᱻ�޸ģ�����ʧ�ܡ�
//			ʹ��map[key] = new_value��ʱ�����key�Ѿ����ڣ�value�ᱻˢ��Ϊnew_value		
	class Solution {
	public:
		void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
			unordered_map<int, int> map;
			for (auto &i : data) {
				auto it = map.find(i);
				if (it == map.end())
					map.insert(make_pair(i, 1));
				else
					it->second = 2;
			}
			int flag = 0;
			for (auto &i : data) {
				auto it = map.find(i);
				if ((*it).second == 1) {
					if (flag == 0) {
						*num1 = (*it).first;
						flag = 1;
					}
					else
						*num2 = (*it).first;
				}
			}
		}
	};

}

namespace FindContinuousSequence {
	/*С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,
	�����Ͼ�д������ȷ����100�����������������ڴ�,�����뾿��
	�ж������������������еĺ�Ϊ100(���ٰ���������)��û���,��
	�͵õ���һ������������Ϊ100������:18,19,20,21,22�����ڰ���
	�⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? */
	//˼·��ʹ�üٶ�̬�滮�ķ�������ΪҪ�����������������ģ����Ե��ƹ�ϵ�ܺ���
	// �������ʾ��β�����֣��������ʾ��ʼ�����֣�dp[i][j]��ʾ��i��ʼ����j��β�����еĺ�
	class Solution {
	public:
		vector<vector<int> > FindContinuousSequence(int sum) {
			vector<vector<int> > retV;
			if (sum < 0)
				return retV;

			vector<vector<int>> dp(sum - 1);
			for (auto &v : dp) {
				vector<int> temp(sum - 1);
				v = temp;
			}
			for (int i = 0; i < sum - 1; ++i) {
				for (int j = i; j < sum - 1; ++j) {
					if (i == j)
						dp[i][j] = i + 1;
					else
						dp[i][j] = dp[i][j - 1] + j + 1;
				}
			}
			for (int i = 0; i < sum - 1; ++i) {
				for (int j = i; j < sum - 1; ++j) {
					if (dp[i][j] == sum) {
						vector<int> v;
						for (int cur = i + 1; cur <= j + 1; ++cur) {
							v.push_back(cur);
						}
						retV.push_back(v);
					}
				}
			}
			return retV;
		}
	};
}

//��֮����˳���ӡ������
namespace ZigZagPrintBiTreeByLevel
{
	//
	class Solution {
	public:
		vector<vector<int> > Print(BiTreeNode* pRoot) {
			if (pRoot == nullptr)
				return vector<vector<int> >();
			vector<vector<int> > retV;
			queue<BiTreeNode* > q;
			int level = 1;
			stack<BiTreeNode *> s;
			vector<int> v;
			q.push(pRoot);
			//1 ��ӡq�����нڵ㣬��ӡ�����ջ��ֱ��qΪ��
			//2 ��vectorѹ��retV
			//3 ����ջ������Ԫ�أ�����levelѡ�����һ�������null����ջ
			while (!(q.empty() && s.empty())) {
				while (!q.empty()) {
					v.push_back(q.front()->val);
					s.push(q.front());
					q.pop();
				}
				retV.push_back(v);
				vector<int>().swap(v);

				while (!s.empty()) {
					if (level % 2 == 1) {
						if (s.top()->right)
							q.push(s.top()->right);
						if (s.top()->left)
							q.push(s.top()->left);
						s.pop();
					}
					else {
						if (s.top()->left)
							q.push(s.top()->left);
						if (s.top()->right)
							q.push(s.top()->right);
						s.pop();
					}
				}
				++level;
			}
			return retV;
		}

	private:
		vector<vector<int>> retV;
	};

	void test()
	{
		printVector(Solution().Print(&valueForTest::BiTree::n1));
	}
}

//쳲���������
namespace C6FibonacciSequence
{
	class Solution {
	public:
		int Fibonacci(int n) {
			if (n < 3)
				return 1;

			vector<int> v(n);
			v[0] = 1;
			v[1] = 1;
			for (int i = 2; i < n; ++i)
				v[i] = v[i - 1] + v[i - 2];
			return v[n - 1];
		}
	};
}

//������ʽƥ��
namespace C6Regex
{
	/*��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��
	ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ���
	�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ��
	���磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��*/
	/*
	˼·��
	ʹ�õݹ�ǰ������������������ʱ�򷵻�false
	��str��patternͬʱ����ĩβ��ʱ�򣬷���true
	��һ������'*'
	��ǰƥ�䣬str��patternͬʱ��1��
	��ǰ��ƥ�䣬����false
	��һ����'*'
	str���ߣ�pattern��2����ʾ*0
	str��1��pattern��0����ʾ�Ѿ�ƥ��*1
	*/
	class Solution {
	public:
		bool match(char* str, char* pattern)
		{
			if (*str == '\0' && *pattern == '\0')
				return true;

			if (*(pattern + 1) == '*') {
				if (*pattern == '.' || *pattern == *str)
					if (*str == '\0')
						return match(str, pattern + 2);
					else
						return match(str + 1, pattern) | match(str, pattern + 2);
				else
					return match(str, pattern + 2);
			}
			else {
				if (*pattern == '.' || *pattern == *str)
				{
					if (*str == '\0')
						return false;
					else
						return match(str + 1, pattern + 1);
				}
				else
					return false;
			}

		}
	};
	//�ĳɶ�̬�滮
	class Solution2 {
	public:
		bool match(const char* str, const char* pattern)
		{
			int ROW = strlen(str) + 1, COL = strlen(pattern) + 2;
			vector<vector<bool>> vv(ROW);
			for (int i = 0; i < ROW; ++i) {
				vector<bool> v(COL);
				vv[i] = v;
			}

			vv[ROW - 1][COL - 2] = true;

			for (int col = COL - 3; col >= 0; --col) {
				if (pattern[col] == '*')
					continue;
				if (pattern[col + 1] == '*') {
					if (pattern[col] == '.')
						vv[ROW - 1][col] = vv[ROW - 1][col + 2];
					else
						vv[ROW - 1][col] = false;
				}
				else {
					vv[ROW - 1][col] = false;
				}
			}
			cout << "set last ROW" << endl;//***********
			printVector(vv);

			for (int row = 0; row < ROW; ++row)
				vv[row][COL - 1] = (pattern[COL - 3] == '*');

			cout << "set last COL" << endl;//***********
			printVector(vv);

			for (int row = ROW - 2; row >= 0; --row)
				for (int col = COL - 2; col >= 0; --col) {
					//	cout << "row:" << row << "col:" << col << "  " << vv[ROW - 1][COL - 2] << endl;
					if (pattern[col + 1] == '*') {
						if (pattern[col] == '.' || pattern[col] == str[row])
							vv[row][col] = vv[row][col + 2] | vv[row + 1][col];
						else
							vv[row][col] = vv[row][col + 2];
					}
					else {
						if (pattern[col] == '.' || pattern[col] == str[row])
							vv[row][col] = vv[row + 1][col + 1];
						else
							vv[row][col] = false;
					}
				}
			printVector(vv);
			return vv[0][0];
		}
	};
	void test()
	{
		const char *str = "";
		const char* pattern = "c*";
		cout << Solution2().match(str, pattern);
	}

}


//��
//�﷨����ľ���ʹ��

//1
//������������/�Ƚ���
//�Ƚ������Զ���sort�Ĺ���
namespace Comparator
{
	//1 ����������<����� -->�������ȼ�����
	class TestClass
	{
	public:
		TestClass(int _index, int _value)
		{
			this->index = _index;
			this->value = _value;
		}
		bool operator<(const TestClass &b)
		{
			return this->index < b.index;
		}

	public:
		int index;
		char value;
	};

	//2 ����bool���͵ĺ���,aС����true
	bool CompareFunc(const TestClass &a, const TestClass &b)
	{
		return a.index > b.index;
	}

	//3 ����()�������������������
	class ComparatorTestClass
	{
	public:
		bool operator()(const TestClass &a, const TestClass &b)
		{
			return a.index < b.index;
		}
	};

	void printVector(vector<TestClass> &v)
	{
		for (auto it = v.begin(); it != v.end(); it++)
		{
			cout << "index: " << (*it).index << "value: " << (*it).value << endl;
		}
	}

	void test()
	{
		TestClass A(1, 'A'), B(2, 'B'), C(3, 'C');

		vector<TestClass> v;
		v.push_back(A);
		v.push_back(C);
		v.push_back(B);

		printVector(v);

		cout << "operator<" << endl;
		sort(v.begin(), v.end());
		printVector(v);

		cout << "CompareFunc()" << endl;
		sort(v.begin(), v.end(), CompareFunc);
		printVector(v);

		cout << "ComparatorTestClass" << endl;
		sort(v.begin(), v.end(), ComparatorTestClass());
		printVector(v);
	}
}

//2
//��������ת���ڶ�̬�е�ʹ��
/*
�ܽ᣺
1 ����ָ������ת
	static����������ͨ������ʹ��������Ͳ���������ʱҲ��������ΪNULL��
	dynamic������ͨ��������ʱ���ݶ���ᱨ��ΪNULL��

2 ����ָ������ת
	���ϼ̳й�ϵ�����ɹ�
3 ����ת
	dynamic����ʱ����static���벻ͨ��
*/
namespace C7N2_Cast
{
	//class base
	class base
	{
	public:
		virtual void vFunc()
		{
			cout << "base vFunc" << endl;
			cout << str << endl;
		}
		void print()
		{
			cout << str << endl;
		}
		base()
		{
			str = "base";
		}
	private:
		string str;
	};
	//class derive1 :public base
	class derive1 :public base
	{
	public:
		virtual void vFunc()
		{
			cout << "derive1 vFunc" << endl;
			cout << str << endl;
		}
		void print()
		{
			cout << str << endl;
		}
		derive1()
		{
			str = "derive1";
		}
	private:
		string str;
	};
	//class derive2 :public base
	class derive2 :public base
	{
	public:
		virtual void vFunc()
		{
			cout << "derive2 vFunc" << endl;
			cout << str << endl;
		}
		void print()
		{
			cout << str << endl;
		}
		derive2()
		{
			str = "derive2";
		}
	private:
		string str;
	};

	void test()
	{
		base b1, *pbb, *pbd;
		derive1 d1, *pdd, *pdb;
		pbb = &b1;
		pbd = &d1;
		pdd = &d1;
		//pdb = &b1; //error:����ָ�벻��ָ�������

//dynamic_cast
//1.1 ����ָ�� ����ת
	//�������-->�ɹ�
		if (dynamic_cast<derive1 *>(pbd) == nullptr) {
			cout << "dynamic_cast<derive1 *>(pbd)ʱʧ��" << endl;
		}
		//���󲻷���-->ʧ��
		if (dynamic_cast<derive2 *>(pbd) == nullptr) {
			cout << "dynamic_cast<derive2 *>(pbd)ʱʧ��" << endl;	//ʧ��
		}
		//1.2 ����ָ������ת
				//���ϼ̳й�ϵ-->�ɹ�
		if (dynamic_cast<base *>(pdd) == nullptr) {
			cout << "dynamic_cast<base *>(pdd)ʱʧ��" << endl;
		}
		//1.3 ����ת
			//������̳й�ϵ-->ʧ��
		if (dynamic_cast<derive2 *>(pdd) == nullptr) {
			cout << "dynamic_cast<derive2 *>(pdd)ʱʧ��" << endl;	//ʧ��
		}

		//static_case
		//2.1 ����ָ��  ����ת
				//�������-->�ɹ�
		if (static_cast<derive1 *>(pbd) == nullptr) {
			cout << "static_cast<derive1 *>(pbd)ʱʧ��" << endl;
		}
		//���󲻷���-->������
		if (static_cast<derive2 *>(pbd) == nullptr) {
			cout << "static_cast<derive2 *>(pbd)ʱʧ��" << endl;
		}
		//2.2 ����ָ�� ����ת
				//���ϼ̳й�ϵ-->�ɹ�
		if (static_cast<base *>(pdd) == nullptr) {
			cout << "static_cast<base *>(pdd)ʱʧ��" << endl;
		}
		//�����ϼ̳й�ϵ-->���벻ͨ��
//		if (static_cast<derive2 *>(pdd) == nullptr) {
//			cout << "static_cast<derive2 *>(pdd)ʱʧ��" << endl;	//û�����ͼ��
//		}
//2.3 ����ת
		//���붼��ͨ��

	}
}


//��ɢ��Ŀ
//�������ַ�������������ַ���
namespace Max_Dup_SubStr
{
	class Solution	//�ݹ�ʵ��
	{
	public:
		int getMaxSubStr(string &str1, string &str2) const {
			string::reverse_iterator it1 = str1.rbegin();
			string::reverse_iterator it2 = str2.rbegin();
			auto ret = getMaxSubStr(str1, str2, it1, it2);
			return ret.second;
		}
	private:
		pair<bool, int> getMaxSubStr(string &str1, string &str2, string::reverse_iterator it1, string::reverse_iterator it2) const {
			if (it1 == str1.rend() || it2 == str2.rend()) {
				return make_pair(true, 0);
			}
			pair<bool, int> ret0(false, 0), ret1(false, 0), ret2(false, 0);
			if (*it1 == *it2) {
				ret0 = getMaxSubStr(str1, str2, it1 + 1, it2 + 1);
				if (ret0.first)
					ret0.second++;
				else {
					ret0.first = true;
					ret0.second = 1;
				}
			}

			ret1.second = getMaxSubStr(str1, str2, it1 + 1, it2).second;
			ret2.second = getMaxSubStr(str1, str2, it1, it2 + 1).second;
			auto ret = ret1.second > ret2.second ? ret1 : ret2;

			if (ret <= ret0)
				return ret0;
			else
				return ret;
		}
	};

	class Solution_dp
	{



	};

	void comp(string s)
	{
		cout << s << endl;
		cout << Solution().getMaxSubStr(s, s) << endl;

	}
	void comp(string s1, string s2)
	{
		cout << s1 << endl;
		cout << s2 << endl;
		cout << Solution().getMaxSubStr(s1, s2) << endl;

	}
	void test()
	{
		string s1 = "abcdefg", s2 = "abcfgrabcd", s3 = "fgabcfga";
		comp(s1, s2), comp(s2, s3), comp(s3, s1);

	}
}

namespace MaxSubIncreaseSeq
{
	//������������������
	class Solution_recursion
	{
	public:
		int MaxSubIncreaseSeq(vector<int> v) {
			if (v.empty())
				return 0;
			int len = v.size();
			int *arr = &v[0];
			return MaxSubIncreaseSeq(arr, len);
		}

		int MaxSubIncreaseSeq(int *arr, int len) {
			return MaxSubIncreaseSeq(0, INT_MIN, arr, len);
		}

		int MaxSubIncreaseSeq(int i, int max, int *arr, int len) {//������Ϊ����
			if (i >= len)
				return 0;
			int ret0 = MaxSubIncreaseSeq(i + 1, max, arr, len);
			int ret1;
			if (max > arr[i])
				return ret0;
			else {
				ret1 = 1 + MaxSubIncreaseSeq(i + 1, arr[i], arr, len);
				if (ret1 > ret0)
					return ret1;
				else
					return ret0;
			}
		}
	};

	class Solution_dp0
	{
	public:
		int MaxSubIncreaseSeq(vector<int> v) {
			if (v.empty())
				return 0;
			int len = v.size();
			int *arr = &v[0];
			return MaxSubIncreaseSeq(arr, len);
		}

		int MaxSubIncreaseSeq(int *arr, int len) {
			vector<int> v(len + 1);
			vector<vector<int>> dp;
			for (int i = 0; i < len + 1; ++i)
				dp.push_back(v);
			for (int j = len - 1; j >= 0; --j)
				for (int i = j; i >= 0; --i) {
					int _max = i > 0 ? arr[i - 1] : INT_MIN;
					int val = arr[j];
					if (_max > val) {
						dp[i][j] = dp[i][j + 1];
					}
					else {
						dp[i][j] = max({ dp[i][j + 1], 1 + dp[j + 1][j + 1] });
					}
				}
			return dp[0][0];
		}
	};

	void test() {
		time(NULL);
		for (int i = 1000; i > 0; i--) {
			vector<int> v = getRandom::vector_int(0, 30000, 3);
			//PrintVector(v);

			if (Solution_recursion().MaxSubIncreaseSeq(v) == Solution_dp0().MaxSubIncreaseSeq(v))
				//	cout << "nice" << endl;
				;
			else
				cout << "oh~no!" << endl;

			if (Solution_recursion().MaxSubIncreaseSeq(v) == dizengzixulie::Solution1().GetIt(v))
				//	cout << "nice" << endl;
				;
			else {
				cout << "oh~no!" << endl;
				printVector(v);
				cout << Solution_recursion().MaxSubIncreaseSeq(v) << " " << dizengzixulie::Solution1().GetIt(v) << endl;

			}
		}
	}
}

namespace SelfMaxSubDupSeq
{
	//��һ���ַ�������ظ�������
	class Solution
	{
	public:
		int getSelfMaxSubDupSeq(string str) {
			int ret = 0;
			if (str.empty())
				return 0;
			for (auto it1 = str.begin(); it1 != str.end() - 1; ++it1) {
				int dupnum = 0;
				auto cur1 = it1;
				for (auto it2 = it1 + 1; it2 != str.end(); it2++) {
					if (*it2 == *cur1) {
						dupnum++;
						cur1++;
					}
					else {
						break;
					}
				}
				ret = dupnum > ret ? dupnum : ret;

			}
			return ret;
		}
	};
	void test()
	{

		cout << Solution().getSelfMaxSubDupSeq("abfgnabf") << endl;
	}

}

namespace test_dsq
{
	void test() {
		vector<int> v = getRandom::vector_int(10, 0, 100);
		printVector(v);

		auto vv = getRandom::vector_vector_int(10, 10, 0, 100);
		printVector(vv);

		auto vv2 = getDefault::vector_vector_int(10, 10);
		printVector(vv2);

		string str1 = getRandom::string(100);
		cout << str1 << endl;

		string str2 = getRandom::string(100, 'a', 'd');
		cout << str2 << endl;

		string str3 = getRandom::string(100, 'A', 'Z');
		cout << str3 << endl;


	}
}
// ���������
namespace countTreeDeep {
	
	class TreeNode
	{
	public:
		TreeNode(int _val, TreeNode* _left = nullptr, TreeNode* _right = nullptr):val(_val), left(_left),right(_right){}
	public:
		int val;
		TreeNode *left;
		TreeNode *right;
	};
	//1 �ݹ�ʵ��
	//	1 �Ƚ�����������������ȣ�ͨ������ֵ��ã�������+1����Ϊ������ȣ�����Ϊ����ֵ����
	//  2 ����������Ϊ�գ������Ϊ1,��������0
	class Solution {
	public:
		int countDeep(TreeNode* root) const
		{
			if (root == nullptr) return 0;
			return 1+max(countDeep(root->left), countDeep(root->right));
		}
	};
	//2 �ǵݹ�ʵ��
}

//STL����
namespace STLTest {
	void string_replace() {
		string str = "ln1 ln2 ln3 ...";
		cout << str << endl;
		int index = str.find("ln", 0);
		while (index != str.npos) {
			str.replace(index, 2, "YYYYY");
			index = str.find("ln", index+sizeof("ln")/sizeof(char) - 1);

		}
		cout << str << endl;

		str.erase(0, 3);
		cout << str << endl;
		str.erase();//û�в�������ɾ�����У���clear()һ����
		cout << str << endl;

		return;
	}
}

int main()
{
	STLTest::string_replace();

	system("pause");
	return 0;
}


//�쳣
namespace ExceptionTest
{
	void ThrowException(int a, char c)
	{
		cout << "ThrowException ִ��" << endl;
		if (a == 1)
		{
			throw a;
		}
		else if (c == 'a')
		{
			throw c;
		}
	}

	void test()
	{
		int a;
		char c;
		cout << "1 a" << endl;
		cin >> a >> c;
		try
		{
			ThrowException(a, c);
		}
		catch (int)
		{
			cout << "a == 1" << endl;
		}
		catch (char)
		{
			cout << "a!=1, c = 'a'" << endl;
		}
		ThrowException(a, c);
	}
}

//���Եõ�������
//���� �˯
/*
���룺
10 5
6481 6127 4477 5436 7356 3137 1076 7182 8147 835
1      0    1    0    1    1    0    0    0   1
����һ���������ڣ����ڳ���Ϊk�������������ǰΪ1��+����+���ں�Ϊ1�����е�data[i]֮�͵����ֵ
*/
class Sleep2 {
public:

	void input() {
		cin >> n;
		cin >> k;
		for (int i = 0; i < n; ++i) {
			int tmp;
			cin >> tmp;
			data.push_back(tmp);
		}

		for (int i = 0; i < n; ++i) {
			int tmp;
			cin >> tmp;
			sleep.push_back(tmp);
		}

	}
	void main() {
		input();
		if (k >= n) {
			cout << accumulate(data.begin(), data.end(), 0) << endl;
			return;
		}

		before = -1;
		end = k;
		for (int i = before + 1; i < k; ++i) {
			slidWindow.push_back(data[i]);
		}
		slidSum = accumulate(slidWindow.begin(), slidWindow.end(), 0);

		preSum = 0;
		resetPostSumAndPostEnd();
		int sum = preSum + slidSum + postSum;
		retQ.push(sum);
		cout << preSum << " " << slidSum << " " << postSum << " " << preSum + slidSum + postSum << endl;
		while (postEnd < n) {
			before++;
			//1 ����preSum
			if (sleep[before] == 0) {
				preSum = 0;
			}
			else {
				preSum += data[before];
			}
			//2 ���û�������
			slidSum -= slidWindow.front();
			slidWindow.pop_front();
			slidSum += data[end];
			slidWindow.push_back(data[end]);
			end++;
			//3 ����postQueue
			if (end > postEnd) {
				resetPostSumAndPostEnd();
			}
			else {
				if (!postQueue.empty()) {
					postSum -= postQueue.front();
					postQueue.pop_front();
				}
				else {
					postSum = 0;
				}
			}

			int tmp = preSum + slidSum + postSum;
			retQ.push(tmp);
			cout << preSum << " " << slidSum << " " << postSum << " " << preSum + slidSum + postSum << endl;
		}
		cout << retQ.top() << endl;
		return;
	}

	void resetPostSumAndPostEnd() {
		//����end��sleep������postsum������postend
		int cur = end;
		postSum = 0;
		while (cur<n&&sleep[cur] == 1) {
			postSum += data[cur];
			cur++;
		}
		postEnd = cur;
	}
private:
	int preSum;
	int postSum;
	int slidSum;
	int before;
	int end;
	int postEnd;
	deque<int> slidWindow;
	deque<int>postQueue;
	vector<int> data;
	vector<int> sleep;
	int n;
	int k;
	priority_queue<int> retQ;
};
