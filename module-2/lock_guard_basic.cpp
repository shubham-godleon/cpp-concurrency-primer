#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

int counter = 0;
mutex mtx;

void increment()
{
    for (int i = 0; i < 10000; i++)
    {
        lock_guard<mutex> lock(mtx);
        counter++;
        // unlocks automatically when going out of scope
        // lock_guard is a RAII wrapper for mutex
        // so no need to explicitly unlock
    }
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    thread t1(increment);
    thread t2(increment);
    thread t3(increment);
    t1.join();
    t2.join();
    t3.join();

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration<double>(end - start);

    cout << "Time taken: " << duration.count() << "\n";
    cout << "Final counter value: " << counter << "\n";
}