//
// Created by oupson on 06/12/22.
//

#include <MessageBuffer.hpp>

MessageBuffer::MessageBuffer() = default;

void MessageBuffer::add_char(char c) {
    for (int i = 0; i < 13; i++) {
        this->buffer[i] = this->buffer[i + 1];
    }
    this->buffer[13] = c;
}

bool MessageBuffer::detect() const {
    for (int i = 0; i < 14 - 1; i++) {
        for (int j = i + 1; j < 14; j++) {
            if (this->buffer[i] == 0 || this->buffer[i] == this->buffer[j] ) {
                return false;
            }
        }
    }

    return true;
}