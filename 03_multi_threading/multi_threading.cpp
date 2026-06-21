import std;

using namespace std;

static int donuts_on_plate = 0;
static atomic donuts_eaten = 0;
static std::vector<int> waiting_queue;

mutex mtx;
condition_variable donut_call;

void customer(int id, const int eating_time)
{
    while (donuts_eaten < 10)
    {
        unique_lock lock(mtx);
        waiting_queue.push_back(id);
        donut_call.wait(lock, [id]() { return (donuts_on_plate != 0 && waiting_queue.front() == id) || donuts_eaten >= 10; });

        // If we woke up because the simulation finished, just clean up and exit!
        if (donuts_eaten >= 10) {
            // Remove our ID from the queue before leaving
            if (const auto it = ranges::find(waiting_queue, id); it != waiting_queue.end())
                waiting_queue.erase(it);
            break;
        }

        // Otherwise, eat the donut normally...
        ++donuts_eaten;
        --donuts_on_plate;
        println("Customer {} found a donut. Eating...", id);
        waiting_queue.erase(waiting_queue.begin());

        lock.unlock();
        this_thread::sleep_for(chrono::milliseconds(eating_time));
        println("Customer {}: Ate a donut! Donuts remaining: {}", id, donuts_on_plate);
        println("Donuts Eaten: {}", donuts_eaten.load());
    }
    donut_call.notify_all(); // Wake up everybody so they can check the loop condition and exit!
}

void chef()
{
    while (donuts_eaten < 10)
    {
        this_thread::sleep_for(1s);

        lock_guard lock(mtx);
        donuts_on_plate++;
        println("Chef: Baked a donut!");
        println("Donuts on Plate: {}", donuts_on_plate);

        donut_call.notify_all();
    }

}

int main()
{
    jthread t1_customer (customer, 1, 2000);
    jthread t2_customer (customer, 2, 3000);
    jthread t_chef (chef);

    return 0;
}
