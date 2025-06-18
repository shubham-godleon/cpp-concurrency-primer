#include <iostream>
#include <thread>
#include <vector>
using namespace std;

/*
🧪 Mini Project: Parallel Greetings
🎯 Objective:
Create a program that launches N threads, each using a lambda function, to simulate a “greeting bot” system — every thread prints a personalized greeting message based on an index.

💼 Requirements:
Use a lambda function to define each thread’s task.

The task should be:

Simulate greeting: "Hello from bot #i!"

Wait for a short duration (use std::this_thread::sleep_for)

Launch at least 10 threads.

Collect all threads in a std::vector<std::thread>.

Join all threads before the main function ends.

Do not use mutexes or shared state yet. Keep it clean and isolated.

🧩 Sample Output (unordered due to threading):
csharp
Copy
Edit
Hello from bot #3!
Hello from bot #7!
Hello from bot #1!
Hello from bot #0!
...
Main thread: All bots greeted.
You’ll notice the output isn’t in any particular order — which is expected and totally okay for this project.

🔧 Tips:
Make sure to capture the loop index i by value, not by reference, to avoid bugs.

Simulate work with:

cpp
Copy
Edit
std::this_thread::sleep_for(std::chrono::milliseconds(100));
Wrap your lambda inline directly inside emplace_back().
*/

int main()
{
    vector<thread> threads;
    for (int i = 0; i < 10; ++i)
    {
        threads.emplace_back([i]()
                             { cout << "Hello from bot #" << i << "\n"; });
        this_thread::sleep_for(chrono::milliseconds(100)); // makes the main thread sleep for 100 milliseconds every iteration
    }

    for (auto &th : threads)
    {
        th.join(); // wait for all threads to finish
    }
    std::cout << "Main thread done.\n";
}
