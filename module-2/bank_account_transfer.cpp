/*
🧪 Final Exercise: Bank Account Transfer (Deadlock-Free)
🧠 Problem Statement:
You have two bank accounts, each protected by a mutex.

Multiple threads transfer money from one to the other.

You must ensure:

No race conditions

No deadlocks

Balance integrity maintained
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

using namespace std;

class Account
{

public:
    int balance;
    mutex mtx;

    Account(int initial_balance) : balance(initial_balance) {}

    void deposit(int amount)
    {
        balance += amount;
    }

    void withdraw(int amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient funds for withdrawal.\n";
        }
    }

    int get_balance()
    {
        return balance;
    }
};

void transfer(Account &sender, Account &receiver, int amount)
{
    lock(sender.mtx, receiver.mtx);
    lock_guard<mutex> lock1(sender.mtx, adopt_lock);
    lock_guard<mutex> lock2(receiver.mtx, adopt_lock);
    if (sender.get_balance() >= amount)
    {
        sender.withdraw(amount);
        receiver.deposit(amount);
        cout << "Transferred ₹" << amount << " from Account A to B\n";
    }
    else
    {
        cout << "Transfer failed: Insufficient funds in sender account.\n";
    }
}

int main()
{
    Account A(1000);
    Account B(1000);

    vector<thread> threads;
    for (int i = 0; i < 10; i++)
    {
        threads.emplace_back(transfer, ref(A), ref(B), 500);
        threads.emplace_back(transfer, ref(B), ref(A), 10);
    }

    for (auto &th : threads)
    {
        th.join();
    }

    cout << "Final Balance of Account A: ₹" << A.get_balance() << "\n";
    cout << "Final Balance of Account B: ₹" << B.get_balance() << "\n";
}
