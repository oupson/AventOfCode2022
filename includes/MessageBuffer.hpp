//
// Created by oupson on 06/12/22.
//

#ifndef ADVENTOFCODE2022_MESSAGEBUFFER_HPP
#define ADVENTOFCODE2022_MESSAGEBUFFER_HPP


class MessageBuffer {
public:
    MessageBuffer();

    void add_char(char c);

    [[nodiscard]] bool detect() const;

private:
    char buffer[14] = {0};
};


#endif //ADVENTOFCODE2022_MESSAGEBUFFER_HPP
