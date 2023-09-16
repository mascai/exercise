#include <cstdint>
#include <iostream>
#include <type_traits>
#include <future>
#include <thread>
#include <chrono>


using namespace std;


void print_ch(char ch, int n) {
    for (int i = 0; i < n; ++i) {
        cout << ch;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main() {
    future<void> f1(async(print_ch, '-', 5));
    future<void> f2(async(print_ch, '+', 5));

    // if any of tasks is completed
    if (f1.wait_for(chrono::seconds(0)) != future_status::deferred ||
        f2.wait_for(chrono::seconds(0)) != future_status::deferred) {

        while (f1.wait_for(chrono::seconds(0)) != future_status::ready ||
               f2.wait_for(chrono::seconds(0)) != future_status::ready) {
        
            this_thread::yield();
        }
    }
}
