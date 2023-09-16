#include <iostream>
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
    future<void> f(async(std::launch::async, print_ch, '-', 10));
    print_ch('+', 10);

}

// Output example: +-+--++--+-+-+-+-+-+                                                                                                
