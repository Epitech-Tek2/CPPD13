/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-clement.muth
** File description:
** ToyStory
*/

#include "ToyStory.hpp"
#include <cstring>

static bool checkProcess(size_t &idx, size_t &i, std::string &sentence, Toy& toy1, Toy& toy2,
    speak func1, speak func2, std::ifstream &file)
{
    idx = sentence.find("picture:");
    if (!idx) {
        if (!(i % 2)) {
            if (!toy1.setAscii(sentence.substr(8))) return (false);
            cOut(toy1.getAscii());
        } else {
            if (!toy2.setAscii(sentence.substr(8))) return (false);
            cOut(toy2.getAscii());
        }
        getline(file, sentence);
    }
    if (!(i % 2)) {
        if (!(toy1.*func1)(sentence)) return (false);
    } else
        if (!(toy2.*func2)(sentence)) return (false);
    i++;
    return (true);
}

static bool process(std::string const& filename, Toy& toy1, Toy& toy2, speak func1, speak func2)
{
    static std::ifstream file(filename.data());
    static char buffer[0x400];
    static std::string sentence;
    static size_t idx = 0;
    static size_t i = 0;

    if (file.eof()) return (true);
    memset(buffer, 0, 0x400);
    file.getline(buffer, 0x400);
    sentence = buffer;
    if (!checkProcess(idx, i, sentence, toy1, toy2, func1, func2, file)) return (false);
    return (process(filename, toy1, toy2, func1, func2));
}

void ToyStory::tellMeAStory(std::string const& filename, Toy& toy1, speak func1, Toy& toy2, speak func2) noexcept
{
    std::ifstream file(filename.data());

    if (!file.is_open()) {
        cOut("Bad Story");
        return;
    }
    cOut(toy1.getAscii());
    cOut(toy2.getAscii());
    process(filename, toy1, toy2, func1, func2);
}