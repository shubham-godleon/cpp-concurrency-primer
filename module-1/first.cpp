#include <iostream>
#include <thread>

using namespace std;

void say_hello() {
    std::cout << "Hello from thread!\n";
}

int main() {
    std::thread t(say_hello); // spawn thread
    t.join();                 // wait for thread to finish
    std::cout << "Main thread done.\n";
}
