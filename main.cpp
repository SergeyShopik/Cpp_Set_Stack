#include"Set.h"

int main()
{
	Set s("God"), s2("go");

	std::cout << (s - s2) << std::endl;

	Stack st;
	st.push(5);
	st.print();
	return 0;
}