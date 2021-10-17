/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-clement.muth
** File description:
** Woody
*/

#pragma once

#include "Toy.hpp"

class Woody : public Toy
{
    public:
        Woody(std::string const& name, std::string const& filename = "woody.txt") noexcept;
        Woody(Woody const& woody) noexcept;
        virtual ~Woody() = default;

    protected:
    private:
};