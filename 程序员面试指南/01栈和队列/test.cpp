// 1. 设置一个最小的栈
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
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
//	// 这里直接
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
//				// 那么此时这里就不是有效的元素
//				all.pop();
//			}
//
//		}
//		// 这里是为了遍历我们这些不能被删除的
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
//	std::queue<Pet> all; // 保存的所有的元素
//	std::queue<Pet> dog; // 只保存了dog
//	std::queue<Pet> cat; // 保存cat
//};
//

// 改写一下
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
//		// 这里注意构造一个时间戳
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
//	// 这里直接
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
//		count = 0; // 这个就随便了
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

// 这个排序的是对的,性能不佳
//void quick_sort(std::vector<int>& v, int left, int right)
//{
//
//	//递归出口
//	if (left >= right)
//		return;
//
//	// 1. 选右左key,left先走.right后面走
//	// 1.1 left找比key大, right找比key小,然后交换
//	// 1.2 当碰到一起的时候,直接和key交换
//	// 单糖递归
//	int keyi = right;
//	int key = v[right];
//	int l = left;
//	int r = right;
//	while (left < right)
//	{
//		// 走left
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
//		//递归出口
//		if (left >= right)
//			return left;
//		int keyi = right;
//		int key = v[right];
//		while (left < right)
//		{
//			// 走left
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
//			// 只要超过一个元素,我们也要进行排序
//			s.push(left);
//			s.push(proi - 1);
//		}
//		if (right - proi > 1)
//		{
//			s.push(proi + 1);
//			s.push(right);
//		}
//		// 注意,我们压入的时候值是左右
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
//				// 只要超过一个元素,我们也要进行排序
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
//	// 到这里,我们的help就是从栈底到栈顶的元素逐渐减少
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

// 这里的n是盘子数
//void dfs(std::vector<int>& a, std::vector<int>& b, std::vector<int>& c, int n)
//{
//	if (1 == n)
//	{
//		c.push_back(a.back());
//		a.pop_back();
//		return;
//	}
//	dfs(a, c, b, n - 1); // 将n-1个盘子移动到b出
//	c.push_back(a.back());
//	a.pop_back();
//	dfs(b, a, c, n - 1); // 将n-1个盘子移动到b出
//}

//void dfs(std::vector<int>& a, std::vector<int>& b, std::vector<int>& c, int n)
//{
//	dfs()
//}
//宏的# 和 ## 这里得 需要看一下

//#define PRINT(a) printf("%c\n"#a, a)
//int main()
//{
//	PRINT(97);
//	return 0;
//}