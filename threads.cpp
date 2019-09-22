// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
 
void foo() 
{
    printf("FOO \n");  
}

void bar(int x)
{
    printf("BAR: %d \n", x);
}

int main() 
{
  std::thread first (foo);     // spawn new thread that calls foo()
  std::thread second (bar,0);  // spawn new thread that calls bar(0)

  //std::cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  //first.join();                // pauses until first finishes
  //second.join();               // pauses until second finishes

  //std::cout << "foo and bar completed.\n";

  return 0;
}