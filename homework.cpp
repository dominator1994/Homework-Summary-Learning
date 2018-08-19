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

//一
//常用数据结构
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

//二
//常用函数

//******打印vector
template<class T>
void printVector(vector<T> v)
{
	for (T i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}

//******打印vector
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

//******交换同一类型的两个地址中的内容
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

//******二叉树相关函数
class BiTreeFunc {
public:
	//直观打印二叉树
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
	//二叉树中序遍历

	//二叉树中序遍历

	//二叉树后序遍历

	//二叉树后序遍历
public:
	//1 先序遍历
	/*
	后打印的先入栈
	取出节点就打印，然后压入右孩子，再压左孩子
	根，左，右
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
	//2 中序遍历
	/*
	左，根，右
	root一直走到最左边，才开始打印，如果右边有节点，那么从右边开始又要走到最左边

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
	//3 后序遍历
	/*
	左，右，中
	思路1：
	使用两个栈，一个存放遍历的顺序，另一个用来辅助root实现变化
	data栈一直等到所有数据都入栈才开始打印
	所以数据要按照中，右，左的顺序全部压入data栈
	但是“中”被压在“右”的下面，无法获得，所以再来一个help栈，用来获得“中”，继续让“中”->left GoRight
	思路2：
	按照中，右，左的顺序将节点入栈，全部入栈之后再打印
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

//*****字符串分割
//以pattern为分隔符将str分割开，放在vector<string>中
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
	//方便截取最后一段数据！！
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

//******检测四点能否组成正方形
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
//判断 正方形 图形
class IsSquare {
public:
	bool isSquare(vector<POINT> p)
	{
		if (p.size() != 4) {
			cout << "isSquare需要四个点的输入" << endl;
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

//三
//常用测试数据
namespace getRandom
{
	vector<int> vector_int(int size, int low, int high) {//左闭右闭
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
		//1 二叉树
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


//四 基础算法 
//很重要，一定要熟记思路和关键点

//1
//二分查找，返回第一个大于等于target的数的索引
namespace C4N1_binary_search
{
	int binary_search(int *a, int len, int target)
	{
		//0 边界情况：数组为空
		if (a == nullptr || len == 0)
		{
			cout << "数组为空" << endl;
			return -1;
		}
		//1 使用下界中位数
		int low = 0, high = len - 1, median = 0;

		while (low <= high)//2 只要维护的数据区间内还有数据
		{
			median = high - (high - low) / 2;
			//cout << "median" << median << endl;
			if (a[median] < target)//3 a[low]保存第一个大于等于target的数的索引
			{
				low = median + 1;
				//只有在中间值小于目标值的时候low才会移动--所以它保存的是第一个大于等于target的值
			}
			else//a[median] >= target
			{
				high = median - 1;//4 a[high]保存第一个小于target的数的索引
			}
		}

		if (a[low] == target)
		{
			cout << "找到了，索引为：" << low << endl;
		}
		else
		{
			cout << "没找到，第一个大于" << target << "的数的索引是：" << low << endl;
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
//快速排序
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
		//随机产生partition数值
		int pos = left + rand() % (right - left + 1);
		int pv = a[pos];
		//荷兰国旗
		while (cur <= large)
		{
			if (a[cur] < pv)
			{
				//小于区域互换，小于区域右移
				swap(a, small, cur);
				++small;
				++cur;
			}
			else if (a[cur] > pv)
			{
				//大于区域互换，大于区域左移
				swap(a, large, cur);
				large--;
			}
			else
			{
				//相等的话区域大小不变
				++cur;
			}
		}//while end
		return make_pair(small, large);
	}

	void quick_sort(int *a, int left, int right)
	{
		//1 判断递归是否终止
		if (left >= right){
			return;
		}
		//2 做分割，返回的small和large分别是小于区大于区的下一个数
		auto ret = partition(a, left, right);
		//3 继续快排
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

//五
//左神算法课
//18数组实现栈
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
				cout << "栈为空，pop失败" << endl;
				return;
			}
			--index;
		}

		void push(int newval) {
			if (index == capacity) {
				cout << "栈已满，push失败" << endl;
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

//18数组实现队列
namespace C5N18_2_array_queue
{
	class ArrayQueue
	{
	public:
		//1 初始化
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
			//1 是否满
			if (size == capacity)
			{
				cout << "队列已满, push失败" << endl;
				return;
			}
			//2 未满
			arr[end--] = newval;
			//是否回到头部
			end = end < 0 ? (capacity - 1) : end;
			++size;
		}

		//3 pop
		void pop()
		{
			//1 是否空
			if (size == 0)
			{
				cout << "队列已空, pop失败" << endl;
				return;
			}
			//2 未空
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
		//数据
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

//19getmin()栈
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

//20队列实现栈
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
				cout << "栈为空，pop失败" << endl;
				return;
			}
			while ((*cur).size() != 1)
			{
				//移动
				(*empty).push((*cur).front());
				(*cur).pop();
			}
			//丢弃最后一个
			(*cur).pop();
		}

		//3 front
		int front()
		{
			setp();
			while ((*cur).size() != 1)
			{
				//移动
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
			//1 2皆空 使用q1
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

//21栈实现队列
namespace C5N21_stack_queue
{
	class stack_queue
	{
		//数据不在这边就在那边
		//1 push的时候一定要在push栈中
		//2 front和pop的时候一定要在pop栈中

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
				cout << "stack已空" << endl;
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
				cout << "stack没有元素" << endl;
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

//22猫狗队列
namespace C5N22_CatDogQueue
{



}

//23转圈打印矩阵
//三个函数：
	//1 从A点到B点打印一条线
	//2 从A点到B点打印一个矩形
	//3 从A点到B点打印多个矩形，直到A与B错开，全部打印完
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
				cout << "只能打印直线" << endl;
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

//反转链表
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
		//先写测试用例的重要性
		SingleList l3(3, nullptr), l2(2, &l3), l1(1, &l2), head(0, &l1);
		SingleList * phead = &head;
		Psinglelist(*phead);

		cout << "反转后：";
		reverseSList(&phead);
		Psinglelist(*phead);
	}
}

//29判断链表是否有环，返回环入口的地址
namespace C5N29_ListHasLoop
{
	//fast和slow两个指针
	//fast一次走两步，slow一次走1步
	//fast到null，则无环
	//fast==slow则有环
		//头节点和相遇点开始一起走，每次一步，相遇的地方就是环的入口

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

//33判断两个链表是否相交
namespace C5N33_TwoListIntersect
{
	//1 判断是否有环，并返回环的入口节点地址


	//2-1 没环，找到len1，len2，长的先走len1-len2，然后一起走

	//2-2 一个有环一个没环
		//肯定不相交

	//2-3两个有环
		//1 loop1一直走，直到回到loop1也没遇到loop2-->不相交

		//2 loop1 == loop2 -->退化为2-1

		//3 loop1!=loop2-->相交
}

//34非递归遍历二叉树
namespace C5N34_BiTree_print_no_digui
{
	//思路：根据打印顺序，思考指针root如何移动，栈来帮助root实现移动

	//1 先序遍历
	/*
	后打印的先入栈
	取出节点就打印，然后压入右孩子，再压左孩子
	根，左，右
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

	//2 中序遍历
	/*
	左，根，右
	root一直走到最左边，才开始打印，如果右边有节点，那么从右边开始又要走到最左边

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

	//3 后序遍历
	/*
	左，右，中
	思路1：
	使用两个栈，一个存放遍历的顺序，另一个用来辅助root实现变化
	data栈一直等到所有数据都入栈才开始打印
	所以数据要按照中，右，左的顺序全部压入data栈
	但是“中”被压在“右”的下面，无法获得，所以再来一个help栈，用来获得“中”，继续让“中”->left GoRight
	思路2：
	按照中，右，左的顺序将节点入栈，全部入栈之后再打印
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
		cout << "先序遍历" << endl;
		PreOrderPrint(&a);
		cout << "中序遍历" << endl;
		InOrderPrint(&a);
		cout << "后序遍历" << endl;
		PostOrderPrint(&a);
	}
}

//36在含有parent指针的二叉树中，打印某个节点的后继
//后继：中序遍历顺序中的下一个节点
namespace C5N36_SuccessorNode
{
	//1 没有右子树，自己是左子树====父节点
	//2  有右子树====右子树的左尽头
	//3  没有右子树，自己是右子树，往上走，直到走到了是左子树的节点cur，打印cur的父节点
	//4  边界：走到头也没有遇到是左子树的root，那就是最后一个节点，没有后继


}

//37按照前序遍历序列化二叉树
//1 value要有结束标志
//2 null要有表示方法，并记录
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



//38按照前序遍历反序列化二叉树
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
		//因为process会改变原str
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

//37二叉树的层序遍历
//1 root指针指向节点，队列q
//2 root指针根据q来改变
//3 使用递归来实现整体的逻辑
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
		//不为空 打印 
		//指针移动的逻辑是相同的
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

//38判断是否是平衡二叉树
//思路：1 两个子树都是平衡二叉树。 2 左右子树的高度差小于等于1
// 使用异常来实现，免去了自己封装地返回值类型
namespace C5N38_JudgeBalanceBiTree
{
	//方法1：异常实现
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

	//方法2：封装自己的返回值实现
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
		{//空树左右平衡
			return ReturnValue(true, 0);
		}

		ReturnValue leftdata = process(root->left);
		if (!leftdata.isB)
		{
			return ReturnValue(false, 0);//左子树不平衡
		}
		ReturnValue rightdata = process(root->right);
		if (!rightdata.isB)
		{
			return ReturnValue(false, 0);//左子树不平衡
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

//39判断是否是搜索二叉树
//二叉树中序遍历的结果是依次升序的就是二叉搜索树
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

//40判断是否是完全二叉树
//按层遍历
//1 节点有右孩子没左孩子，返回false
//2 如果一个节点不是两个孩子都有，那么按层遍历后面的节点都要是叶子节点
//3 
namespace JudgeCBT//complete binary tree
{

}



//41求完全二叉树的节点个数，时间复杂度log(N)*log(N)
//0 如果root为叶子节点，返回1
//1 找左边界，看到了哪一层，得到Height
//2 找右子树的左边界，看是否到达Height
	//到达		得到左子树的节点个数，递归右子树
	//没到达	得到右子树的节点个数，递归左子树
// 1<<n  是2的n次方
namespace C5N42_CountNodeInCBT
{

}

//45从集合中随机得到对象_randompool
namespace RandomPool
{





}

//46bloomfilter布隆过滤器
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
				//扩容
				delete[] arr;
				//arr = 

			}
			int intIndex = index / 32;//每个int可以有32bit  索引为0
			int bitIndex = index % 32;//为8

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



//50字典树/优化/insert/delete/search/searchPre
namespace C5N50_TrieTree
{

}
//51把一个集合的字符串拼接成1个字符串，要求得到的字符串的字典序最小
namespace C5N51_AppendString
{


}

//52分金条
namespace Haffman
{





}

//53
//会议室贪心
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

		void func1(int(*arr)[2], int N)//正确传入参数
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
			cout << "总共能做：" << count << endl;
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
//		int index;//在图中是第几号节点
//		int in;
//		int out;
//		vector<Node *> nexts;//存储邻接节点在graph中的编号
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
//		//1 通过所有边的信息构建图 
//		//	 weight	   from  	to 
//		//		2	   	1	    2	
//		//		1		3		4
//	 
//		//2	通过邻接矩阵构建图 
//		//列-->行
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
//				//map中有0--N-1号节点
//			}
//
//			//arr[i]-->arr[j]
//			for (int i = 0; i < N; i++)
//			{
//				for (int j = 0; j < N; j++)
//				{
//					if (arr[i][j] != INT_MAX)
//					{
//						//有边
//						Edge new_edge(arr[i][j], i, j);
//						Edge *p = &new_edge;
//					//from node
//						auto iti = nodes.find(i);
//						if (iti == nodes.end())
//						{
//							cout << "没有找到第" << i << "个节点，可能是之前创建空节点时失败" << endl;
//							return;
//						}
//						(*iti).second.out++;				//出度加1
//						(*iti).second.nexts.push_back(j);//记录邻接节点index
//						(*iti).second.edges.push_back()
//					//to node
//						auto itj = nodes.find(j);
//						if (itj == nodes.end())
//						{
//							cout << "没有找到第" << j << "个节点，可能是之前创建空节点时失败" << endl;
//							return;
//						}
//						(*itj).second.in++;				//入度加1
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
				//到叶子节点了
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
//动态规划
namespace coin_change
{

}

//55
//求阶乘n!
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
//汉诺塔
namespace C5N56_hanoi
{
	class solution
	{
	public:
		void func1(int N, string from, string to, string help)//正确传入参数
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
				walk(N - 1, from, help, to);							//把n-1从from挪到help上
				cout << "Move " << N << " " << from << " to " << to << endl;
				walk(N - 1, help, to, from);							//把n-1从help挪到to上
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
		solution().func1(3, "左", "中", "右");
	}
}

//57
//C5N57_打印字符串的所有子序列 不同位置的看做两个
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
//C5N58_打印一个字符串的全排列
namespace AllArray
{
	class solution
	{
	public:
		void func1(string str)//正确传入参数
		{
			int N = str.size();
			//初始化map
			map<char, int> pair;
			for (auto it = str.begin(); it != str.end(); it++)
			{
				auto it2 = pair.find((*it));
				if (it2 != pair.end())
				{
					//找到了 数量+1
					pair[(*it)] += 1;
				}
				else
				{//没找到 插入
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
					vch.push_back((*it1).first);	//使用字符
					(*it1).second--;				//剩余个数-1
					walk(pair, cur + 1, N);//递归下一次
					vch.pop_back();					//把字符还回去
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
//母牛生小牛，小牛3年后也可以生小牛
namespace C5N59_babbyCow
{

}

//打印字符串的所有子序列
namespace PrintAllSubSeq
{
	class solution
	{
	public:
		void func1(string _str)//正确传入参数
		{
			this->str = _str;
			vector<string> vstr;
			vstr.push_back("");
			cout << "空 应该1 " << vstr.size() << endl;
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



//在矩阵中行走，最小路径和
namespace walk_matrix
{
	class solution
	{
	public:
		int  func1(int(*arr)[4], int _row, int _col)//正确传入参数
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

//给定一个数组，使用里面的数字能否累加得到k
namespace isSum
{
	class solution
	{
	public:
		void func1(vector<int> v, int _aim)//正确传入参数
		{
			this->aim = _aim;
			auto it = v.begin();
			int sum = 0;
			bool ret = walk(v, it, sum);
			if (ret == true) {
				cout << "可以" << endl;
				printVector<int>(vresult);
			}
			else {
				cout << "不可以" << endl;
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


//递归实现两个字符串的最大公共子序列
//标准的递归
namespace MaxSameSubSeq_digui2
{
	class solution
	{
	public:
		void func1(string _str1, string _str2)//正确传入参数
		{
			str1 = _str1;
			str2 = _str2;
			auto it1 = str1.begin();
			auto it2 = str2.begin();
			int ret = walk(it1, it2);
			cout << "总共有：" << ret << endl;
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

//手写四则运算
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

	//使用optop运算，得到结果入snum栈
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
				//是数字
				int temp = 0;
				string strtemp(it, str.end());
				size_t offset = 0;
				temp = stoi(strtemp, &offset);
				it += offset;
				snum.push(temp);
			}
			else {
				//是op
				if (cur == '(') {
					int ret = cal(++it, str);
					snum.push(ret);

				}
				else if (cur == ')') {
					it++;
					break;
				}
				else {
					//是+ - * /
					if (optop == 'n') {
						//op栈空
						sop.push(cur);
						it++;
					}
					else {
						//op栈不空
						if (cur == '+' || cur == '-') {
							if (optop == '+' || optop == '-') {
								use_op_push_value(snum, sop, optop);
								it++;
								//再getOpTop一次，看看1+2*3+4*5+6-->1+6+20+6,也可以不使用
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
					}// 是+ - * /
				}//是op + - * / 
			}//end of 是()+-*/
		}//end of while

		//到结尾了
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
//			int a[0];//大小为0的数组，长度是动态分配的
//		};
//	}
//	}
//}

namespace stl_array
{
	void test()
	{
		//根本搞不懂
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
		//	typename char C;//不能使用C定义变量
		//	C c = 'a';
		//	cout << C << endl;

	}
}

//换钱问题，有1,2,5三种面额的货币，需要换出7元钱，有多少种换法
//递归实现
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
			//1 初始化
			//2 count计数器
			//3 做返回值
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
			if (R <= L) {	//只有一个数时就返回		
				return;
			}
			int mid = L + (R - L) / 2;
			sortprocess(arr, L, mid);		//左半边排序好
			sortprocess(arr, mid + 1, R);	//右半边排序好
			merge(arr, L, mid, R);			//左右两边合并
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
			int sum = process(arr, L, mid) + process(arr, mid + 1, R);	//递归分解

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
			if ((L < 0) || (L >= R)) {			//小于区下标可能为负，没有小于区
				return;
			}
			vector<int> pos = partition(arr, L, R);//返回小于区和大于区的下标
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
	//系统默认的是大根堆
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
				cout << "矩阵不是正方形" << endl;
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
	//思路：让一个点从右上角开始按照规则移动，如果出界了还没有找到，那么就是没有
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
	//可以同时存在有参构造函数和无参构造函数
	//但是有参构造函数不能全有默认参数，因为存在二义性 
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
	/*把只包含因子2、3和5的数称作丑数（Ugly Number）。
	例如6、8都是丑数，但14不是，因为它包含因子7。
	习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。*/
	//思路：动态规划，设置三个指针，表示*2，*3，*5.沿着数组依次前进就可以得到所有的丑数
	//因为要得到有序的丑数数组，所以要在前进的时候比较
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
					--cur;	//cur不移动
					++p;	//p移动
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
			cout << "第" << i << "个丑数是： ";
			Print(i);
		}
	}
}

namespace once_char
{
	//第一个只出现一次的字符
	/*在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置*/

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
	//数组中的逆序对

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
					cout << "move_n 到达末尾" << endl;
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
	//最长递增子序列
	//动态规划
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
			if (v[pos] > max)		//判断条件中有从前面传进来的max，在dp的时候，是表现为从数组当前位置向后遍历！
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
		//找到满足v[i] > v[cur]前提下，arr[i]中最大的
		int find_max_ifnull_0(vector<int>& v, int cur, int *arr) {
			if (cur == v.size() - 1) {
				return 0;//最后一个
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

//六 剑指offer

namespace maxInWindows {
	/*给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
	例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
	他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
	{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}，
	{2,3,4,2,6,[2,5,1]}*/
//思路：双端数组，头保存最大值，小于最后一个添加进来的元素都删除
//初始化的时候就按照这个规则
	class Solution {
	public:
		vector<int> maxInWindows(const vector<int>& num, unsigned int size)
		{
			vector<int> ret;
			if (num.empty() || size == 0 || size>num.size()) return ret;
			deque<vector<int>::const_iterator> help;
			init(help, num, size);		//初始化也要按照规则
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
//思路：使用优先级队列，记录大于中位数的数组的最小值和小于中位数数组的最大值
//		每次插入数字的时候按照规则，保证可以根据堆顶得到中位数
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
				//和大数组比较
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
	/*给定一棵二叉搜索树，请找出其中的第k小的结点。
	例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
	*/
//思路：中序遍历，到第k个的时候输出
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
			//沿着某个节点一直向左走，路过的节点都入栈
			while (pRoot != nullptr) {
				help.push(pRoot);
				pRoot = pRoot->left;
			}
		}
	};


}

namespace isSymmetrical {
/*判断二叉树是不是对称的*/
//思路：两个在对称位置上的节点一直向下走
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
	//1 自己有右子树 ==>右子树的最左边

	//1 如果自己是左子树 
	//自己父节点
	//2 如果自己是右子树
	//自己没有右子树==>找自己父节点直到父节点是爷爷节点的左子树

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
	//1 判断是否合法
	//2 利用stack转为后缀表达式，vector
	//3 利用栈进行运算，栈中唯一结果
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
		//遇到数字直接输出
		//遇到符号和栈顶比较优先级，优先级高于或等于栈顶，直接入栈
		//							优先级低于栈顶，先弹出栈顶元素并打印，再入栈
		//遇到'('入栈，优先级最低
		//遇到')'，弹出并打印所有栈中元素，直到遇到'('
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
	//使用非递归先序遍历
	/*输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
	要求不能创建任何新的结点，只能调整树中结点指针的指向。*/
	//思路：就是二叉树的前序遍历，记得使用栈辅助。定义三个指针，注意处理边界情况，next = nullptr的时候
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
	/*题目描述
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。
然后,他随机指定一个数m,让编号为0的小朋友开始报数。每次喊到m-1的那个小朋友要出列唱首歌,
然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....这样下去....
直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)*/

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
	/*题目描述
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,
并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。
现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何，
如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0*/
//思路： 1 先排序 2 看看0够不够填充差值 3 小心有重复的数字
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
					return false;// 0 0 1 1有重复数字
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
	//思路：左移的位数可能会超过字符串的长度
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
	//思路：	1 先翻转每个单词
	//			2 从后向前读取整个句子
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
	//数组中只出现一次的两个数字
	/*一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。*/
//	易错点：使用insert插入数据到map的时候，如果key已经存在，则value不会被修改，插入失败。
//			使用map[key] = new_value的时候，如果key已经存在，value会被刷新为new_value		
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
	/*小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,
	他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟
	有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他
	就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问
	题交给你,你能不能也很快的找出所有和为S的连续正数序列? */
	//思路：使用假动态规划的方法，因为要求正数序列是连续的，所以递推关系很好找
	// 行坐标表示结尾的数字，纵坐标表示开始的数字，dp[i][j]表示以i开始，以j结尾的序列的和
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

//按之字形顺序打印二叉树
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
			//1 打印q中所有节点，打印完就入栈，直到q为空
			//2 把vector压入retV
			//3 弹出栈中所有元素，根据level选择，先右还是先左，null不入栈
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

//斐波那契数列
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

//正则表达式匹配
namespace C6Regex
{
	/*请实现一个函数用来匹配包括'.'和'*'的正则表达式。
	模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。
	在本题中，匹配是指字符串的所有字符匹配整个模式。
	例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配*/
	/*
	思路：
	使用递归前进，当不满足条件的时候返回false
	当str和pattern同时到达末尾的时候，返回true
	下一个不是'*'
	当前匹配，str和pattern同时走1步
	当前不匹配，返回false
	下一个是'*'
	str不走，pattern走2，表示*0
	str走1，pattern走0，表示已经匹配*1
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
	//改成动态规划
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


//七
//语法，库的具体使用

//1
//匿名函数对象/比较器
//比较器：自定义sort的规则
namespace Comparator
{
	//1 在类内重载<运算符 -->用于优先级队列
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

	//2 返回bool类型的函数,a小返回true
	bool CompareFunc(const TestClass &a, const TestClass &b)
	{
		return a.index > b.index;
	}

	//3 重载()运算符的类做函数对象
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
//两种类型转换在多态中的使用
/*
总结：
1 上行指针向下转
	static不报错，编译通过，即使对象和类型不符合运行时也不报错（不为NULL）
	dynamic，编译通过，运行时根据对象会报错（为NULL）

2 子类指针向上转
	符合继承关系，都成功
3 胡乱转
	dynamic运行时报错，static编译不通过
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
		//pdb = &b1; //error:子类指针不能指向父类对象

//dynamic_cast
//1.1 上行指针 向下转
	//对象符合-->成功
		if (dynamic_cast<derive1 *>(pbd) == nullptr) {
			cout << "dynamic_cast<derive1 *>(pbd)时失败" << endl;
		}
		//对象不符合-->失败
		if (dynamic_cast<derive2 *>(pbd) == nullptr) {
			cout << "dynamic_cast<derive2 *>(pbd)时失败" << endl;	//失败
		}
		//1.2 子类指针向上转
				//符合继承关系-->成功
		if (dynamic_cast<base *>(pdd) == nullptr) {
			cout << "dynamic_cast<base *>(pdd)时失败" << endl;
		}
		//1.3 胡乱转
			//不满足继承关系-->失败
		if (dynamic_cast<derive2 *>(pdd) == nullptr) {
			cout << "dynamic_cast<derive2 *>(pdd)时失败" << endl;	//失败
		}

		//static_case
		//2.1 上行指针  向下转
				//对象符合-->成功
		if (static_cast<derive1 *>(pbd) == nullptr) {
			cout << "static_cast<derive1 *>(pbd)时失败" << endl;
		}
		//对象不符合-->不报错
		if (static_cast<derive2 *>(pbd) == nullptr) {
			cout << "static_cast<derive2 *>(pbd)时失败" << endl;
		}
		//2.2 子类指针 向上转
				//符合继承关系-->成功
		if (static_cast<base *>(pdd) == nullptr) {
			cout << "static_cast<base *>(pdd)时失败" << endl;
		}
		//不符合继承关系-->编译不通过
//		if (static_cast<derive2 *>(pdd) == nullptr) {
//			cout << "static_cast<derive2 *>(pdd)时失败" << endl;	//没有类型检查
//		}
//2.3 胡乱转
		//编译都不通过

	}
}


//零散题目
//求两个字符串的最长公共子字符串
namespace Max_Dup_SubStr
{
	class Solution	//递归实现
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
	//求数组的最长递增子序列
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

		int MaxSubIncreaseSeq(int i, int max, int *arr, int len) {//后两个为常量
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
	//求一个字符串的最长重复子序列
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
// 求树的深度
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
	//1 递归实现
	//	1 比较左子树右子树的深度（通过返回值获得），最大的+1，即为树的深度，并作为返回值返回
	//  2 左右子树均为空，则深度为1,空树返回0
	class Solution {
	public:
		int countDeep(TreeNode* root) const
		{
			if (root == nullptr) return 0;
			return 1+max(countDeep(root->left), countDeep(root->right));
		}
	};
	//2 非递归实现
}

//STL测试
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
		str.erase();//没有参数就是删除所有，和clear()一样。
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


//异常
namespace ExceptionTest
{
	void ThrowException(int a, char c)
	{
		cout << "ThrowException 执行" << endl;
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

//考试得到的轮子
//网易 瞌睡
/*
输入：
10 5
6481 6127 4477 5436 7356 3137 1076 7182 8147 835
1      0    1    0    1    1    0    0    0   1
做了一个滑动窗口，窗口长度为k，可以求出窗口前为1的+窗口+窗口后为1的所有的data[i]之和的最大值
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
			//1 设置preSum
			if (sleep[before] == 0) {
				preSum = 0;
			}
			else {
				preSum += data[before];
			}
			//2 设置滑动窗口
			slidSum -= slidWindow.front();
			slidWindow.pop_front();
			slidSum += data[end];
			slidWindow.push_back(data[end]);
			end++;
			//3 设置postQueue
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
		//根据end和sleep来计算postsum和设置postend
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
