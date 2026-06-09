#include <iostream>
#include <thread>
#include <vector>

int counter = 0;

void increment_task(){
    for ( int i = 0; i < 100'000; ++i ) {
        counter++; // Not an atomic operation
    }
}

int main()
{
    std::jthread t1(increment_task);
    std::jthread t2(increment_task);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << '\n';
    return 0;
}
