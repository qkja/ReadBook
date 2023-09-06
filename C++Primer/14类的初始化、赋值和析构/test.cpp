class Data {
public:
	int ival;
	char* ptr;
};

int main()
{
	Data local1 = { 0, 0 };
	Data local2 = { 1024, (char*)"Anna Livia Plurabelle" };
	return 0;
}