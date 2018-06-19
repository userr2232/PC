/*
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << R"&%$(string with \backslash)&%$";
	return 0;
}
*/
/*
#include <iostream>
int main()
{
  std::cout << "Hello, World\n";
  std::cin.ignore();
  return 0;
}
*/
#include <iostream>
#include <thread>
#include <chrono>

void threadFunc()
{
	int i = 0;
	while (i < 10)
	{
		std::cout<< i++ << std::endl;
        //std::cout<< i++ << '\n';
		// Sleep this thread for 2000 MilliSeconds
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	}
}

int main()
{
	std::thread th(&threadFunc);
	th.join();
	return 0;
}
