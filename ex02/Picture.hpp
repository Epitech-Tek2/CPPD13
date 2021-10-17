/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-clement.muth
** File description:
** Picture
*/

#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Picture {
    public:
        /////////////////////////////////////////////////////////////////////////////
        ///
        /// Constructor
        ///
        /////////////////////////////////////////////////////////////////////////////
        Picture() noexcept;
        Picture(std::string const& filename) noexcept;
        virtual ~Picture() = default;

        /////////////////////////////////////////////////////////////////////////////
        ///
        /// Getter
        ///
        /////////////////////////////////////////////////////////////////////////////
        bool getPictureFromFile(const std::string& filename) noexcept;

        Picture& operator=(Picture const& picture) noexcept;

        std::string data;
};