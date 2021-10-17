/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-clement.muth
** File description:
** ToyStory
*/

#pragma once

#include "Toy.hpp"

#define cOut(message) std::cout << message << std::endl
typedef bool (Toy::*speak)(std::string const message);


class ToyStory
{
    public:
        ToyStory() = default;
        ~ToyStory() = default;

        static void tellMeAStory(std::string const& filename, Toy& toy1, speak func1, Toy& toy2, speak func2) noexcept;
};
