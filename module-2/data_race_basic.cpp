#include <iostream>
#include <thread>

using namespace std;

int counter = 0;
void increment()
{
    for (int i = 0; i < 100000; ++i)
    {
        ++counter; // Increment the shared counter
    }
    cout << "Thread finished incrementing.\n";
}

int main()
{
    thread t1(increment);
    thread t2(increment);
    t1.join();
    t2.join();
    cout << "Final counter value: " << counter << "\n";
    std::cout << "Main thread done.\n";
}

/*
❓ Why Does This Happen?
Because counter++ is not atomic. It's three separate steps:

Read the value of counter into a CPU register

Add 1 to that value

Write the result back into memory

If two threads read at the same time, they both get the same value, increment it, and overwrite each other’s work.
*/