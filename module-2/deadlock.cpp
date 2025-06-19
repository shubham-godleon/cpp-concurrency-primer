#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx1;
mutex mtx2;

void thread1_func()
{
    lock_guard<mutex> lock1(mtx1);
    this_thread::sleep_for(chrono::milliseconds(100));
    lock_guard<mutex> lock2(mtx2);
    cout << "Thread 1 acquired both locks.\n";
}

void thread2_func()
{
    lock_guard<mutex> lock2(mtx2);
    this_thread::sleep_for(chrono::milliseconds(100));
    lock_guard<mutex> lock1(mtx1);
    cout << "Thread 2 acquired both locks.\n";
}

int main()
{
    thread t1(thread1_func);
    thread t2(thread2_func);

    t1.join();
    t2.join();
}

// Always acquire locks in the same order in all threads.