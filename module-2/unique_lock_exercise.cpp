#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

int counter = 0;
mutex mtx;

void delayed_lock(int id)
{
    unique_lock<mutex> lock(mtx, defer_lock);
    cout << "Thread " << id << " waiting. \n";
    this_thread::sleep_for(chrono::milliseconds(50 * id));
    lock.lock();
    cout << "Thread " << id << " got the lock.\n";
    lock.unlock(); // Explicitly unlock the mutex
    cout << "Thread " << id << " released the lock.\n";
}

int main()
{
    thread t1(delayed_lock, 1);
    thread t2(delayed_lock, 2);
    thread t3(delayed_lock, 3);
    t1.join();
    t2.join();
    t3.join();
}