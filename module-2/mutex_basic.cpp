#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;
mutex mtx;

void increment()
{
    mtx.lock();
    for (int i = 0; i < 10000; i++)
    {
        counter++;
    }
    mtx.unlock();
}

int main()
{
    thread t1(increment);
    thread t2(increment);
    t1.join();
    t2.join();
    cout << "Final counter value: " << counter << "\n";
}