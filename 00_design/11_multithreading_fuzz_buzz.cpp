/* https://leetcode.com/problems/fizz-buzz-multithreaded/

Write a program that outputs the string representation of numbers from 1 to n, however:

If the number is divisible by 3, output "fizz".
If the number is divisible by 5, output "buzz".
If the number is divisible by both 3 and 5, output "fizzbuzz".
For example, for n = 15, we output: 1, 2, fizz, 4, buzz, fizz, 7, 8, fizz, buzz, 11, fizz, 13, 14, fizzbuzz.

Suppose you are given the following code:

class FizzBuzz {
  public FizzBuzz(int n) { ... }               // constructor
  public void fizz(printFizz) { ... }          // only output "fizz"
  public void buzz(printBuzz) { ... }          // only output "buzz"
  public void fizzbuzz(printFizzBuzz) { ... }  // only output "fizzbuzz"
  public void number(printNumber) { ... }      // only output the numbers
}
Implement a multithreaded version of FizzBuzz with four threads. The same instance of FizzBuzz will be passed to four different threads:

Thread A will call fizz() to check for divisibility of 3 and outputs fizz.
Thread B will call buzz() to check for divisibility of 5 and outputs buzz.
Thread C will call fizzbuzz() to check for divisibility of 3 and 5 and outputs fizzbuzz.
Thread D will call number() which should only output the numbers.
*/


class FizzBuzz {
private:
    int n;
    int i;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        unique_lock<mutex> lock(m);
        this->n = n;
        i = 1;
        lock.unlock();
        cv.notify_all();
    }
    
    void run(function<bool(int)> test, function<void(int)> print) {
        while (i <= n) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{ return i > n || test(i); });
            if (i > n) break;
            print(i++);
            lock.unlock();
            cv.notify_all();
        }
    }

    void fizz(function<void()> printFizz) {
        run([](int i){ return i % 3 == 0 && i % 5 != 0; },
            [&](int i){ printFizz(); });
    }

    void buzz(function<void()> printBuzz) {
        run([](int i){ return i % 3 != 0 && i % 5 == 0; },
            [&](int i){ printBuzz(); });
    }

	void fizzbuzz(function<void()> printFizzBuzz) {
        run([](int i){ return i % 3 == 0 && i % 5 == 0; },
            [&](int i){ printFizzBuzz(); });
    }

    void number(function<void(int)> printNumber) {
        run([](int i){ return i % 3 != 0 && i % 5 != 0; }, printNumber);
    }
};
