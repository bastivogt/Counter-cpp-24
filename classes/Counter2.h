
#pragma once


namespace sevo {

    enum class CounterEventType {
        STARTED,
        CHANGED,
        FINISHED
    };

    class Counter2 {
        private:
            int _start {1};
            int _end {10};
            int _step {1};
            int _count {0};

            void (*_counter_event_handler)(Counter2 sender, CounterEventType type) = nullptr;

            void _emit_event(CounterEventType type);

        public:
            Counter2(const int start = 1, const int end = 10, const int step = 1);
            void reset(const int start = 1, const int end = 10, const int step = 1);
            void run();
            int get_count();

            void set_counter_event_handler(void (*handler)(Counter2 sender, CounterEventType type));
            void remove_counter_event_handler();

    };
}

