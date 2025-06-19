#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

int counter = 0;
mutex mtx;

// void increment()
// {
//     for (int i = 0; i < 10000; i++)
//     {
//         unique_lock<mutex> lock(mtx);
// unique_lock allows for more flexibility than lock_guard
// e.g. it can be unlocked and locked again
// does not lock the mutex immediately, but when it goes out of scope
// it will automatically unlock the mutex
//  here it behaves like a lock_guard
//         counter++;
//     }
// }

void flexible_worker(int id)
{
    unique_lock<mutex> lock(mtx, defer_lock); // doesnot lock automatically
    cout << "Thread " << id << " waiting. \n";
    this_thread::sleep_for(chrono::milliseconds(100)); // Simulate some work
    lock.lock();
    cout << "Thread " << id << " got the lock.\n";
    lock.unlock(); // Explicitly unlock the mutex
    cout << "Thread " << id << " released the lock.\n";
}

int main()
{

    // thread t1(increment);
    // thread t2(increment);
    // thread t3(increment);
    // t1.join();
    // t2.join();
    // t3.join();

    thread t4(flexible_worker, 1);
    thread t5(flexible_worker, 2);
    t4.join();
    t5.join();

    // cout << "Final counter value: " << counter << "\n";
}

// 🔑 General Rule of Locking
// "You lock anything that can be accessed or modified concurrently by more than one thread."

// This includes :
// Shared variables(like counter)
// Shared output streams(cout)
// Shared containers(vector, map)
// Shared files, databases, sockets, etc.