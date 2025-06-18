# cpp-concurrency-primer
C++ Concurrency Primer
🗂️ Course Outline
📦 Module 0: Prerequisites & Environment Setup
✅ Install modern C++ compiler (GCC ≥ 10 / Clang ≥ 11 / MSVC)

✅ Use an IDE like CLion, VSCode, or Visual Studio

✅ Enable C++20 with -std=c++20

✅ Use sanitizer flags: -fsanitize=thread,address,undefined for debugging

📘 Module 1: Fundamentals of Concurrency
📌 1.1 Concurrency vs. Parallelism
Definitions, examples, OS-level differences

Amdahl’s Law

📌 1.2 Threads (std::thread)
Creating and joining threads

Detaching, joining, lifecycle

Parameter passing (by value, ref, move)

Thread safety intro

🧪 Exercises

Print Hello World from 3 threads

Thread that prints sum of passed vector

Pitfall: Detached thread exiting early

🔐 Module 2: Synchronization Basics
📌 2.1 Race Conditions
Definition and real examples

Data races vs logical races

📌 2.2 Mutexes
std::mutex, std::lock_guard, std::unique_lock

Try-locking, recursive mutexes

std::scoped_lock (C++17), variadic locking (C++20)

📌 2.3 Deadlocks & Prevention
Nested locks, lock ordering

std::lock() with multiple mutexes

🧪 Projects

Thread-safe counter

Thread-safe bank account transfers

Deadlock simulation + fix

⚙️ Module 3: Atomics and Memory Ordering
📌 3.1 std::atomic<T>
Lock-free updates

fetch_add, compare_exchange_weak/strong

📌 3.2 Memory Ordering Deep Dive
memory_order_relaxed, acquire/release, seq_cst

Fences

📌 3.3 Use Cases
Spinlocks

Atomic flags for one-time init

🧪 Projects

Implement lock-free counter

Compare mutex vs atomic on performance

📨 Module 4: Thread Coordination
📌 4.1 Condition Variables
std::condition_variable

Wait/predicate/spurious wake-ups

📌 4.2 std::notify_all_at_thread_exit (C++20)
📌 4.3 Readers-Writers Problem
Starvation-safe solution

🧪 Projects

Producer-Consumer Queue

Readers-Writers implementation

📦 Module 5: Tasks and Futures
📌 5.1 std::future and std::promise
Communication between threads

Blocking, exception passing

📌 5.2 std::packaged_task
Callable wrappers for delayed execution

📌 5.3 std::async
Launch policy: async, deferred

📌 5.4 std::when_all, when_any (C++23 preview)
🧪 Projects

Future-based web scraper

Task chaining with promise/future

🧵 Module 6: Thread Pools and Task Scheduling
📌 6.1 Build a Thread Pool
Worker threads + task queue + stop flag

📌 6.2 Priority Queues
Using std::priority_queue for task prioritization

📌 6.3 Work Stealing (Theory only unless using external lib)
🧪 Project

General-purpose reusable thread pool

Add throttling (limit X concurrent tasks)

🛠️ Module 7: Advanced Synchronization Tools
📌 7.1 std::shared_mutex / std::shared_lock (C++17)
Read-heavy workloads

📌 7.2 std::barrier and std::latch (C++20)
Modern tools for task group synchronization

📌 7.3 std::semaphore (C++20)
Classic bounded resource control

🧪 Projects

Parallel Matrix Multiplication with barrier

Resource pool with semaphore

💾 Module 8: Parallel STL in C++20
📌 8.1 Execution Policies
std::execution::seq, par, par_unseq

📌 8.2 Parallel Algorithms
std::for_each, std::reduce, std::sort, etc.

📌 8.3 Caveats and Data Race Prevention
🧪 Projects

Parallel word frequency counter

Parallel merge sort using par_unseq

🧠 Module 9: Memory Model & Performance
📌 9.1 C++ Memory Model
Happens-before, visibility guarantees

📌 9.2 False Sharing, Padding, Alignment
alignas, cache line size

📌 9.3 Thread Sanitizers & Profilers
TSAN, perf, valgrind, VTune

🏗️ Module 10: Concurrency Patterns
Producer-Consumer

Readers-Writers

Reactor Model

Fork/Join

Double-Checked Locking

Compare-and-Swap Retry Loops

Token Bucket Rate Limiter

🧪 Final Project

Build a mini job scheduler (like cron)

Or thread-safe LRU Cache with expiration
