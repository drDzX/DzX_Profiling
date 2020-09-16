#include "Source/DzX_Profiler.h"


#define PROFILING 1
#if PROFILING
	#define PROFILING_SCOPE(name) Timer timer##__LINE__(name)
	#define PROFILING_FUNCTION() PROFILING_SCOPE(__FUNCTION__)
#else
	#define PROFILING_SCOPE(name)
#endif



void Func1()
{
	PROFILING_FUNCTION();
	for (int i = 0; i < 1000; i++)
	{
		std::cout << "Func1 i : " << i << std::endl;
	}
}
void Func2()
{
	PROFILING_FUNCTION();
	for (int i = 0; i < 1000; i++)
	{
		std::cout << "Func2 i : " << sqrt(i) << std::endl;
	}
}
void Benchmark()
{
	PROFILING_FUNCTION();
	Func1();
	Func2();
}
int main()
{
	Instrumentor::Get().BeginSession("Profile");
		Benchmark();
	Instrumentor::Get().EndSession();

	std::cin.get();

}