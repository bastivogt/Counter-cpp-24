#include <iostream>

#include "Counter2.h"

namespace sevo {
    Counter2::Counter2(const int start, const int end, const int step) {
        this->reset(start, end, step);
    }

    void Counter2::reset(const int start, const int end, const int step) {
        this->_start = start;
        this->_end = end;
        this->_step = step;
        this->_count = this->_start;
    }

    void Counter2::run() {
        this->_count = this->_start;
        this->_emit_event(CounterEventType::STARTED);
        for(; this->_count < this->_end; this->_count += this->_step) {
            this->_emit_event(CounterEventType::CHANGED);
        }
        this->_emit_event(CounterEventType::FINISHED);
    }

    int Counter2::get_count() {
        return this->_count;
    }


    void Counter2::set_counter_event_handler(void (*handler)(Counter2 sender, CounterEventType type)) {
        this->_counter_event_handler = handler;
    }

    void Counter2::remove_counter_event_handler() {
        this->_counter_event_handler = nullptr;
    }

    void Counter2::_emit_event(sevo::CounterEventType type) {
        if(this->_counter_event_handler != nullptr) this->_counter_event_handler(*this, type);
    }

}



