#include <iostream>

#include "Counter.h"

namespace sevo {
    Counter::Counter(const int start, const int end, const int step) {
        this->reset(start, end, step);
    }

    void Counter::reset(const int start, const int end, const int step) {
        this->_start = start;
        this->_end = end;
        this->_step = step;
        this->_count = this->_start;
    }

    void Counter::run() {
        this->_count = this->_start;
        this->_emit_counter_started_handler();
        for(; this->_count < this->_end; this->_count += this->_step) {
            this->_emit_counter_changed_handler();
        }
        this->_emit_counter_finished_handler();
    }

    int Counter::get_count() {
        return this->_count;
    }



    // Started
    void Counter::set_counter_started_handler(void (*handler)(Counter sender)) {
        this->_counter_started_handler = handler;
    }

    void Counter::remove_counter_started_handler() {
        this->_counter_started_handler = nullptr;
    }

    void Counter::_emit_counter_started_handler() {
        if(this->_counter_started_handler != nullptr) this->_counter_started_handler(*this);
    }


    // changed
    void Counter::set_counter_changed_handler(void (*handler)(Counter sender)) {
        this->_counter_changed_handler = handler;
    }

    void Counter::remove_counter_changed_handler() {
        this->_counter_changed_handler = nullptr;
    }

    void Counter::_emit_counter_changed_handler() {
        if(this->_counter_changed_handler != nullptr) this->_counter_changed_handler(*this);
    }


    // finished
    void Counter::set_counter_finished_handler(void (*handler)(Counter sender)) {
        this->_counter_finished_handler = handler;
    }

    void Counter::remove_counter_finished_handler() {
        this->_counter_finished_handler = nullptr;
    }

    void Counter::_emit_counter_finished_handler() {
        if(this->_counter_finished_handler != nullptr) this->_counter_finished_handler(*this);
    }
}


