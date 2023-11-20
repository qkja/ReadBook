#pragma once
#include <unordered_map>
#include <iostream>
#include <vector>


// 这是一个 非权重表
namespace matrix
{
	using namespace std;

	// 这是临街矩阵
	// V 表示的是顶点
	// W 表示的是边
	// MAX_W 表示的是 如果我们的没有两个顶点的相连,那么此时我们就给这个值
	// Direction : 表示是都是有向图, false 表示是无向的
	template<class V, class W, W MAX_W, bool Direction = false>
	class Graphs
	{
	public:
	private:
		unordered_map<V, size_t> _hashMap; 

	};

}
namespace link
{
	// 这是临街表
}