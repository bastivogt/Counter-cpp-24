#include <iostream>

#include "classes/Counter.h"
#include "classes/Counter2.h"

int main(int argc, char **argv) {

    std::cout << "Counter" << std::endl;

    sevo::Counter c = sevo::Counter();

    c.set_counter_started_handler([](sevo::Counter sender) -> void {
        std::cout << "COUNTER_STARTED count: " << sender.get_count() << std::endl;
    });

    c.set_counter_changed_handler([](sevo::Counter sender) -> void {
        std::cout << "COUNTER_CHANGED count: " << sender.get_count() << std::endl;
    });

    c.set_counter_finished_handler([](sevo::Counter sender) -> void {
        std::cout << "COUNTER_FINISHED count: " << sender.get_count() << std::endl;
    });

    c.run();

    std::cout << std::endl << "Counter2" << std::endl;

    sevo::Counter2 c2 = sevo::Counter2(1, 20, 2);

    c2.set_counter_event_handler([](sevo::Counter2 sender, sevo::CounterEventType type) -> void {
        if(type == sevo::CounterEventType::STARTED) {
            std::cout << "COUNTER_STARTED count: " << sender.get_count() << std::endl;
        }else if(type == sevo::CounterEventType::CHANGED) {
            std::cout << "COUNTER_CHANGED count: " << sender.get_count() << std::endl;
        }else if(type == sevo::CounterEventType::FINISHED) {
            std::cout << "COUNTER_FINISHED count: " << sender.get_count() << std::endl;
        }else {
            std::cout << "None" << std::endl;
        }
    });

    //c2.remove_counter_event_handler();

    c2.run();

    return 0;
}
