#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{

	//printf("hello");
	/*printf("%d\n", sizeof(long double));
	printf("%d\n", sizeof(double));*/
	// ע��,���ֳ������޷�Ѱַ��,Ҳ�ǲ��ܱ����ı��.��ʹ���Ǵ洢���ڴ���

	// ������ 
	// �˽��� 0 
	// ʮ���� ������ͨ��
	// ʮ������ 0x 

	// ��������һ������, \ddd	\xdd
	// һ�����,��������Ĭ������int����,�����long�Ļ�,�����ں������l����L
	// �����Ƽ�Lд��,����������Ϊ����1
	//long int x = 100L;
	// ���Ƶ����ǿ��Ա��ΪΪ�޷��ŵ�
	//unsigned int y = 10u; 

	//���ڸ���������,����������������ֵķ�ʽ
	// ʮ���� �� ��ѧ������
	// ����ʮ���ƶ���,��������Ĭ�ϵ���double, Ҳ����С��Ĭ����˫���ȵ�
	// �����Ҫ�ǽ���Ϊ������, ��ô�������һ��f������F

	// ���ڿ�ѧ��������,
	// xxexx
	/*double x = 1e3;
	double y = 1e-3;

	printf("%lf\n", x);
	printf("%lf\n", y);*/
	auto ch = L'x';
	cout << typeid(ch)<< endl;

	return 0;
}