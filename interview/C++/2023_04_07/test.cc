// 引用和指针的区别
// 1. 指针是一个变量,而引用是别名
// 2. 指针的大小是4字节或者8字节,引用的大小由被引用的对象确定
// 3. 指针存在多级指针,可以为空,可以指向另一个地址,引用只能被初始化一次,不能为空
// 4. 指针拿到数据通过解引用,引用可以直接使用

// 什么时候传引用,什么时候传指针
// 1. 首先如果我们要修改数据,那么传引用和传指针都可以
// 2. 其次如果我们要是传引用,要先确保我们的实参对象一定要存在
// 3. 在类中的拷贝构造,我们参数推荐或者规定传递引用

// 引用的分类
// C++11 前我们谈的引用就是左值引用
// C++11 后我们谈的引用还是左值引用,但是这里增加了一个右值引用

// 那么既让存在了右值引用,请问他和左值有什么区别,有有什么意义
// 1. 先来区分左值和右值,可以取地址的叫左值,不能的叫做右值
// 2. 而对右值取别名就是右值引用
// 3. 这就可以说区别了 左值引用只能引用左值,右值的只能引用右值,但是const修饰的左值可以引用右值

// 4. 继续说意义 右值引用的出现是为了解决我们 返回函数内部局部变量的问题,我们知道
