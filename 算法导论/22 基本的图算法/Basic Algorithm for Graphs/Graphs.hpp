#pragma once
#include <unordered_map>
#include <iostream>
#include <vector>


// ����һ�� ��Ȩ�ر�
namespace matrix
{
	using namespace std;

	// �����ٽ־���
	// V ��ʾ���Ƕ���
	// W ��ʾ���Ǳ�
	// MAX_W ��ʾ���� ������ǵ�û���������������,��ô��ʱ���Ǿ͸����ֵ
	// Direction : ��ʾ�Ƕ�������ͼ, false ��ʾ�������
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
	// �����ٽֱ�
}