#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx1;
mutex mtx2;

void thread1_func()
{
    lock(mtx1, mtx2);
    lock_guard<mutex> lock1(mtx1, adopt_lock);
    this_thread::sleep_for(chrono::milliseconds(100));
    lock_guard<mutex> lock2(mtx2, adopt_lock);
    cout << "Thread 1 acquired both locks.\n";
}

void thread2_func()
{
    lock(mtx1, mtx2);
    lock_guard<mutex> lock1(mtx1, adopt_lock);
    this_thread::sleep_for(chrono::milliseconds(100));
    lock_guard<mutex> lock2(mtx2, adopt_lock);
    cout << "Thread 2 acquired both locks.\n";
}

int main()
{
    thread t1(thread1_func);
    thread t2(thread2_func);

    t1.join();
    t2.join();
}
