#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx;

void try_to_work(int id)
{
    const int max_attempts = 3;
    for (int attempts = 0; attempts < max_attempts; attempts++)
    {
        if (mtx.try_lock())
        {
            cout << "Thread " << id << " has acquired the lock on attempt " << attempts + 1 << ". \n";
            this_thread::sleep_for(chrono::milliseconds(100));
            mtx.unlock();
            return;
        }
        else
        {
            cout << "Thread " << id << " could not acquire the lock on attempt " << attempts + 1 << ". \n";
            if (attempts == max_attempts - 1)
            {
                cout << "Thread " << id << " giving up after " << max_attempts << " attempts.\n";
            }
            else
            {
                this_thread::sleep_for(chrono::milliseconds(50)); // Wait before retrying
            }
        }
    }
    // if(mtx.try_lock())
    // {
    //     cout << "Thread " << id << " has acquired the lock. \n";
    //     this_thread::sleep_for(chrono::milliseconds(100));
    //     mtx.unlock();
    //     cout << "Thread " << id << " has released the lock. \n";
    // }
    // else
    // {
    //     cout << "Thread " << id << " could not acquire the lock. \n";
    // }
}

int main()
{
    vector<thread> threads;
    for (int i = 0; i < 3; i++)
    {
        threads.emplace_back(try_to_work, i);
    }

    for (auto &th : threads)
    {
        th.join();
    }
}