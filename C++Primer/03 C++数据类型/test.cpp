#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{

	//printf("hello");
	/*printf("%d\n", sizeof(long double));
	printf("%d\n", sizeof(double));*/
	// 注意,文字常量是无法寻址的,也是不能被给改变的.即使他是存储在内存中

	// 二进制 
	// 八进制 0 
	// 十进制 就是普通的
	// 十六进制 0x 

	// 这里引入一个问题, \ddd	\xdd
	// 一般而言,我们数据默认是是int类型,如果是long的话,可以在后面添加l或者L
	// 这里推荐L写法,这样不会认为是是1
	//long int x = 100L;
	// 类似的我们可以标记为为无符号的
	//unsigned int y = 10u; 

	//对于浮点数而言,我们这里就两个表现的方式
	// 十进制 和 科学计数法
	// 对于十进制而言,我们这里默认的是double, 也就是小数默认是双精度的
	// 如果想要是解释为单精度, 那么后面添加一个f或者是F

	// 对于科学计数法发,
	// xxexx
	/*double x = 1e3;
	double y = 1e-3;

	printf("%lf\n", x);
	printf("%lf\n", y);*/
	auto ch = L'x';
	cout << typeid(ch)<< endl;

	return 0;
}