// 1. 设置一个最小的栈
#include <stack>

class min_stack
{
public:
	min_stack() {}
	~min_stack(){}
public:
	void pop()
	{
		if (_s.empty())
			return ;
		if (_s.top() == _min_s.top())
		{
			_min_s.top();
		}
		_s.top();
	}
	void push(const int& val)
	{
		_s.push(val);
		if(!_min_s.empty() && val <= _min_s.top())
			_min_s.push(val);
	}
	int getMin()
	{
		if (_min_s.empty())
			return -1;
		return _min_s.top();
	}

private:
	std::stack<int> _s;
	std::stack<int> _min_s;
};
