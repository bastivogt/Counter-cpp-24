#pragma once


namespace sevo {
    class Counter {
        private:
            int _start {1};
            int _end {10};
            int _step {1};
            int _count {0};

            void (*_counter_started_handler)(Counter sender) = nullptr;
            void (*_counter_changed_handler)(Counter sender) = nullptr;
            void (*_counter_finished_handler)(Counter sender) = nullptr;

            void _emit_counter_started_handler();
            void _emit_counter_changed_handler();
            void _emit_counter_finished_handler();

        public:
            Counter(const int start = 1, const int end = 10, const int step = 1);
            void reset(const int start = 1, const int end = 10, const int step = 1);
            void run();
            int get_count();

            void set_counter_started_handler(void (*handler)(Counter sender));
            void remove_counter_started_handler();


            void set_counter_changed_handler(void (*handler)(Counter sender));
            void remove_counter_changed_handler();


            void set_counter_finished_handler(void (*handler)(Counter sender));
            void remove_counter_finished_handler();

    };
}

