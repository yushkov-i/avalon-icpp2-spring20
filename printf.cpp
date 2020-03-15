#include <cstdio>
#include <limits>

int main()
{
	unsigned int maxValue 
		= std::numeric_limits<unsigned int>::max();
	int median = 45;

	unsigned long long max 
		= std::numeric_limits<unsigned long long>::max();

	printf("max value = %d\nmediana = %d\nmax long long = %llu\n",
		maxValue, median, max);

	printf("max float = %e\n", std::numeric_limits<float>::max());	
	printf("max float = %e\n", std::numeric_limits<double>::max());
}