//main.cxx
#include <iostream>
#include "B.hxx"
void main()
{
	b<int> bi = b<int>(5);
	b<float> bf = b<float>(float(5.1));

	bi.add(9.99);
	bf.add(9.99);

	std::cout << bi.get() << std::endl;
	std::cout << bf.get() << std::endl;
}