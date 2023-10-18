// 1. ����һ����С��ջ
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

//class min_stack
//{
//public:
//	min_stack() {}
//	~min_stack(){}
//public:
//	void pop()
//	{
//		if (_s.empty())
//			return ;
//		if (_s.top() == _min_s.top())
//		{
//			_min_s.top();
//		}
//		_s.top();
//	}
//	void push(const int& val)
//	{
//		_s.push(val);
//		if(!_min_s.empty() && val <= _min_s.top())
//			_min_s.push(val);
//	}
//	int getMin()
//	{
//		if (_min_s.empty())
//			return -1;
//		return _min_s.top();
//	}
//
//private:
//	std::stack<int> _s;
//	std::stack<int> _min_s;
//};


//class Pet {
//public:
//	Pet(const std::string& type) :_type(type) {}
//public:
//	std::string getPetType() const
//	{
//		return _type;
//	}
//private:
//	std::string _type;
//};
//
//
//class Dog : public Pet
//{
//public:
//	Dog() :Pet("dog") {}
//private:
//};
//
//class Cat : public Pet
//{
//public:
//	Cat() : Pet("cat") {}
//private:
//};


//int main()
//{
//	std::cout << Dog().getPetType() << std::endl;
//	std::cout << Cat().getPetType() << std::endl;
//	return 0;
//}
//class cat_and_dog_queue {
//public:
//	cat_and_dog_queue() = default;
//	void add(const Pet& pet)
//	{
//		all.push(pet);
//		if (pet.getPetType() == "Dog") dog.push(pet);
//		else                           cat.push(pet);
//	}
//	// ����ֱ��
//	void pollAll() {
//		while (!isEmpty())
//		{
//			if (!dog.empty() && all.front().getPetType() == dog.front().getPetType())
//			{
//				all.pop();
//				dog.pop();
//			}
//			else if (!cat.empty() && all.front().getPetType() == cat.front().getPetType())
//			{
//				all.pop();
//				cat.pop();
//			}
//			else
//			{
//				// ��ô��ʱ����Ͳ�����Ч��Ԫ��
//				all.pop();
//			}
//
//		}
//		// ������Ϊ�˱���������Щ���ܱ�ɾ����
//		while (!all.empty())
//		{
//			all.pop();
//		}
//		
//	}
//	void pollDog() {
//		while (dog.empty())
//		{
//			dog.pop();
//		}
//	}
//	void pollCat(){
//		while (!cat.empty())
//		{
//			cat.pop();
//		}
//	}
//	bool isEmpty() {
//		return isDogEmpty() && isCatEmpty();
//	}
//	bool isDogEmpty() {
//		return dog.empty();
//	}
//	bool isCatEmpty(){
//		return cat.empty();
//	}
//private:
//	std::queue<Pet> all; // ��������е�Ԫ��
//	std::queue<Pet> dog; // ֻ������dog
//	std::queue<Pet> cat; // ����cat
//};
//

// ��дһ��
//class PetEnterQueue {
//public:
//	PetEnterQueue(const Pet& pet, long count) :_pet(pet), _count(count) {}
//public:
//	Pet GetPet()
//	{
//		return _pet;
//	}
//	long GetCount()
//	{
//		return _count;
//	}
//	std::string GetType()
//	{
//		return _pet.getPetType();
//	}
//private:
//	Pet _pet;
//	long _count;
//};
//
//class cat_and_dog_queue {
//public:
//	cat_and_dog_queue() = default;
//	void add(const Pet& pet)
//	{
//		// ����ע�⹹��һ��ʱ���
//		if (pet.getPetType() == "Dog")
//		{
//			dog.push(PetEnterQueue(pet, count++));
//		}
//		else
//		{
//			cat.push(PetEnterQueue(pet, count++));
//		}
//	}
//
//	// ����ֱ��
//	void pollAll() {
//		while (!cat.empty() && !dog.empty())
//		{
//			if (cat.front().GetCount() < dog.front().GetCount()) {
//				cat.pop();
//			}
//			else
//			{
//				dog.pop();
//			}
//		}
//		while (!cat.empty())
//		{
//			cat.pop();
//		}while (!dog.empty())
//		{
//			dog.pop();
//		}
//		count = 0; // ����������
//	}
//	void pollDog() {
//		while (!dog.empty())
//		{
//			dog.pop();
//		}
//	}
//	void pollCat() {
//		while (!cat.empty())
//		{
//			cat.pop();
//		}
//	}
//	bool isEmpty() {
//		return cat.empty() && dog.empty();
//	}
//	bool isDogEmpty() {
//		return dog.empty();
//	}
//	bool isCatEmpty() {
//		return cat.empty();
//	}
//private:
//	std::queue<PetEnterQueue> dog;
//	std::queue<PetEnterQueue> cat;
//	long count = 0;
//};

// ���������ǶԵ�,���ܲ���
//void quick_sort(std::vector<int>& v, int left, int right)
//{
//
//	//�ݹ����
//	if (left >= right)
//		return;
//
//	// 1. ѡ����key,left����.right������
//	// 1.1 left�ұ�key��, right�ұ�keyС,Ȼ�󽻻�
//	// 1.2 ������һ���ʱ��,ֱ�Ӻ�key����
//	// ���ǵݹ�
//	int keyi = right;
//	int key = v[right];
//	int l = left;
//	int r = right;
//	while (left < right)
//	{
//		// ��left
//		while (left < right && v[left] <= key)
//		{
//			++left;
//		}
//		while (left < right && v[right] >= key)
//		{
//			--right;
//		}
//
//		std::swap(v[left], v[right]);
//	}
//	std::swap(v[left], v[keyi]);
//	quick_sort(v, l, left - 1);
//	quick_sort(v, left+1, r);
//}
//class Solution {
//public:
//	int _quick_sort(std::vector<int>& v, int left, int right)
//	{
//
//		//�ݹ����
//		if (left >= right)
//			return left;
//		int keyi = right;
//		int key = v[right];
//		while (left < right)
//		{
//			// ��left
//			while (left < right && v[left] <= key)
//			{
//				++left;
//			}
//			while (left < right && v[right] >= key)
//			{
//				--right;
//			}
//			std::swap(v[left], v[right]);
//		}
//		std::swap(v[left], v[keyi]);
//		return left;
//	}
//
//
//	void quick_sort(std::vector<int>& v, int left, int right)
//	{
//		std::stack<int> s;
//		int proi = _quick_sort(v, left, right);
//
//		if (proi - left > 1)
//		{
//			// ֻҪ����һ��Ԫ��,����ҲҪ��������
//			s.push(left);
//			s.push(proi - 1);
//		}
//		if (right - proi > 1)
//		{
//			s.push(proi + 1);
//			s.push(right);
//		}
//		// ע��,����ѹ���ʱ��ֵ������
//		while (!s.empty())
//		{
//			right = s.top();
//			s.pop();
//			left = s.top();
//			s.pop();
//
//			proi = _quick_sort(v, left, right);
//			if (proi - left > 1)
//			{
//				// ֻҪ����һ��Ԫ��,����ҲҪ��������
//				s.push(left);
//				s.push(proi - 1);
//			}
//			if (right - proi > 1)
//			{
//				s.push(proi + 1);
//				s.push(right);
//			}
//
//		}
//	}
//
//	std::vector<int> sortArray(std::vector<int>& nums) {
//		quick_sort(nums, 0, nums.size() - 1);
//		return nums;
//	}
//};

//std::stack<int> stack_sort(std::stack<int>& s)
//{
//	std::stack<int> help;
//	while (!s.empty())
//	{
//		auto cur = s.top();
//		s.pop();
//		while (!help.empty() &&  help.top() > cur)
//		{
//			s.push(help.top());
//			help.pop();
//		}
//		help.push(cur);
//	}
//	while (!help.empty())
//	{
//		s.push(help.top());
//		help.pop();
//	}
//	// ������,���ǵ�help���Ǵ�ջ�׵�ջ����Ԫ���𽥼���
//	return help;
//}
//
//int main()
//{
//	std::stack<int> s;
//	int arr[] = { 1,2,3,4,5,-1 };
//	for (auto e : arr)
//	{
//		s.push(e);
//	}
//	//s = stack_sort(s);
//    stack_sort(s);
//	while (!s.empty())
//	{
//		std::cout << s.top() << std::endl;
//		s.pop();
//	}
//
//	return 0;
//}

// �����n��������
//void dfs(std::vector<int>& a, std::vector<int>& b, std::vector<int>& c, int n)
//{
//	if (1 == n)
//	{
//		c.push_back(a.back());
//		a.pop_back();
//		return;
//	}
//	dfs(a, c, b, n - 1); // ��n-1�������ƶ���b��
//	c.push_back(a.back());
//	a.pop_back();
//	dfs(b, a, c, n - 1); // ��n-1�������ƶ���b��
//}

//void dfs(std::vector<int>& a, std::vector<int>& b, std::vector<int>& c, int n)
//{
//	dfs()
//}
//���# �� ## ����� ��Ҫ��һ��

//#define PRINT(a) printf("%c\n"#a, a)
//int main()
//{
//	PRINT(97);
//	return 0;
//}


//
//void adjust_down(std::vector<int>& v, int root, int size)
//{
//	int parent = root;
//	int child = 2 * parent + 1;// ����
//
//	while (child < size)
//	{
//		// Ѱ�����Һ��ӽϴ�ֵ
//		if (child + 1 < size && v[child + 1] > v[child])
//		{
//			child++;
//		}
//		if (v[parent] < v[child])
//		{
//			std::swap(v[parent], v[child]);
//		}
//		else
//		{
//			break;
//		}
//		parent = child;
//		child = 2 * parent + 1;
//	}
//}
//
//void build_a_large_root_heap(std::vector<int>& v)
//{
//	for (int parent = (v.size() - 1 - 1) / 2; parent >= 0; --parent)
//	{
//		adjust_down(v, parent, v.size());
//	}
//}
//
//void heap_sort(std::vector<int>& v)
//{
//	build_a_large_root_heap(v); // ����
//	for (int i = v.size() - 1; i > 0; i--)
//	{
//		// 1. ��λ��
//		std::swap(v[0], v[i]);
//		// 2. ���µ���, ע��,������Ҫ��������Ĵ�С
//		adjust_down(v, 0, i);
//	}
//}
//
//int main()
//{
//	std::vector<int> v = { 4, 2, 7, 8, 5, 1, 0, 6 };
//	heap_sort(v);
//	for (int i = 0; i < v.size(); i++)
//	{
//		printf("%d ", v[i]);
//	}
//	return 0;
//}

//struct Node
//{
//	int _val;
//	struct Node* _left;
//	struct Node* _right;
//	Node()
//	{
//		_val = 0;
//		_left = nullptr;
//		_right = nullptr;
//	}
//};
//
//int main()
//{
//	std::vector<int> v;
//	Node* pRoot = new Node[v.size()];
//	for (int i = 0; i < v.size(); i++)
//	{
//		(pRoot + i)->_val = v[i];
//	}
//	std::stack<Node*> s;
//	std::unordered_map<Node*, Node*> l_big_map;
//	std::unordered_map<Node*, Node*> r_big_map;
//	// �������ı�val���
//	for (int i = 0; i < v.size(); i++)
//	{
//		Node* node = pRoot + i;
//		while (!s.empty() && s.top()->_val < node->_val)
//		{
//			pop_stack_set_map(s, l_big_map);
//		}
//		s.push(node);
//	}
//	// ������
//	while (!s.empty())
//	{
//		pop_stack_set_map(s, l_big_map);
//	}
//
//	for (int i = v.size() - 1; i >= 0; --i)
//	{
//		Node* node = pRoot + i;
//		while (!s.empty() && s.top()->_val < node->_val)
//		{
//			pop_stack_set_map(s, r_big_map);
//		}
//		s.push(node);
//	}
//
//	while (!s.empty())
//	{
//		pop_stack_set_map(s, r_big_map);
//	}
//
//	Node* root = nullptr;
//	for (int i = 0; i < v.size(); ++i)
//	{
//		Node* node = pRoot + i;
//		Node* left = l_big_map[node];// node һ����
//		Node* right = r_big_map[node];// node һ����
//		if (left == nullptr && right == nullptr)
//		{
//			root = node;
//		}
//		else if (left == nullptr)
//		{
//			// ���û�б�val���,�Ҳ���
//			if (right->_left == nullptr)
//				right->_left = node;
//			else
//				right->_right = node;
//		}
//		else if (right == nullptr)
//		{
//			if (left->_left == nullptr)
//				left->_left = node;
//			else
//				left->_right = node;
//		}
//		else
//		{
//			Node* parent = left->_val < right->_val ? left : right;
//
//			if (parent->_left == nullptr)
//				parent->_left = node;
//			else
//				parent->_right = node;
//		}
//
//	}
//
//	delete[] pRoot;
//	return 0;
//}
//
//void pop_stack_set_map(std::stack<Node*>& s, std::unordered_map<Node*, Node*>& m)
//{
//	Node* node = s.top();
//	s.pop();
//	if (s.empty())
//	{
//		m[node] = nullptr;
//	}
//	else
//	{
//		m[node] = s.top();
//	}
//}
//struct A
//{
//	~A()
//	{
//		std::cout << "1" << std::endl;
//	}
//};
//A* func()
//{
//
//	return new A[3];
//}
//int main()
//{
//	A* p = func();
//	delete[] p;
//	return 0;
//}

//class Solution {
//public:
//	int maxArea(vector<int>& height) {
//		int n = height.size();
//		int ret = 0;
//		// ���� for ö�ٳ����п��ܳ��ֵ����
//		for (int i = 0; i < n; i++) {
//			for (int j = i + 1; j < n; j++) {
//				// �����ݻ����ҳ�������һ��
//				ret = max(ret, min(height[i], height[j]) * (j - i));
//			}
//		}
//		return ret;
//	}
//};
//int max_rec_from_bottom(const std::vector<int>& height)
//{
//	int left = 0, right = height.size() - 1, ret = 0;
//	while (left < right)
//	{
//		int v = std::min(height[left], height[right]) * (right - left);
//		ret = std::max(ret, v);
//		// �ƶ�ָ��
//		if (height[left] < height[right]) left++;
//		else right--;
//	}
//	return ret;
//}
//int max_rec_size(const std::vector<std::vector<int>>& v)
//{
//	if (v.empty())
//		return 0;
//	int maxLen = 0;
//	std::vector<int> ret(v.back().size(), 0);
//	for (int i = 0; i < v.size(); i++)
//	{
//		for (int j = 0; j < v[i].size(); j++)
//		{
//			ret[j] = v[i][j] == 0 ? 0 : ret[j] + 1;
//		}
//		maxLen = std::max(maxLen, max_rec_from_bottom(ret));
//	}
//	return maxLen;
//}
//
//int main()
//{
//	std::vector<std::vector<int>> v = { {1,0,1,1}, {1,1,1,1}, {1,1,1,0}};
//	std::cout << max_rec_size(v) << std::endl;
//	return 0;
//}

