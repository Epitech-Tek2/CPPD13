/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-clement.muth
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture() noexcept :
    data{""} {}

Picture::Picture(std::string const& filename) noexcept
{
    getPictureFromFile(filename);
}

bool Picture::getPictureFromFile(std::string const& filename) noexcept
{
    std::ifstream _file(filename.data());
    std::stringstream _buffer;

    if (!_file.is_open()) {
        std::cout << "setAscii" << ": " << "bad new illustration" << std::endl;
        return (false);
    }
    _buffer << _file.rdbuf();
    data = _buffer.str();
    _file.close();
    return (true);
}

Picture& Picture::operator=(Picture const& picture) noexcept
{
    data = picture.data;
    return (*this);
}