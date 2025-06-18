#include <iostream>
#include <thread>
#include <vector>
using namespace std;

void print_id(int id)
{
    cout << "Thread " << id << " is complete.\n";
}

int main()
{
    vector<thread> threads;
    for (int i = 0; i < 5; ++i)
    {
        threads.emplace_back(print_id, i); // spawn threads
    }

    for (auto &th : threads)
    {
        th.join(); // wait for all threads to finish
    }
    std::cout << "Main thread done.\n";
}
