#include <iostream>
#include <thread>

using namespace std;

int main()
{
    thread t([]()
             { cout << "Hello from lambda thread!\n"; });
    t.join();
    std::cout << "Main thread done.\n";
}

/*
Syntax	Meaning
[x]	Capture x by value
[&x]	Capture x by reference
[=]	Capture all used variables by value
[&]	Capture all used variables by reference
[=, &x]	Capture all by value, but x by reference
[&, x]	Capture all by reference, but x by value
*/