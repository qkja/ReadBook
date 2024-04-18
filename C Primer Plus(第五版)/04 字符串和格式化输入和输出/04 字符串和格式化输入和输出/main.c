//#include <stdio.h>
//#define STR "\"qqqq\""
//int main()
//{
//	//printf("%2.2e %2.2f\n", 1201.0, 1201.0);
//	printf("%s", STR);
//	return 0;
//}
#include <stdio.h>

//#define BOOK "War and Peace"
//int main()
//{
//	float cost = 12.99;
//	float percent = 80.0;
//	printf("This copy of \"%s\" sells for $%.2f.\nThat is %.0f%% of list",
//		BOOK, cost, percent);
//	return 0;
//}

//int main()
//{
//	printf("%4X\n", 0x8a);
//	return 0;
//}
void test1()
{
	char* surname[10] = { 0 };
	char* name[10] = { 0 };
	scanf("%s", surname);
	scanf("%s", name);
	printf("%s, %s", name, surname);
}
void test2()
{
	char* name[10] = { 0 };
	scanf("%s", name);
	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
}
int main()
{
	//test1();
	test2();
	return 0;
}