#ifndef STL_PRINT_HPP
#define STL_PRINT_HPP

#include <iostream>

#include <map>
#include <vector>
#include <list>
#include <set>

template<typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
    os << "Print vector: " << std::endl;

    for (const auto& i : v)
    {
        os << i << ' ';
    }
    os << std::endl;

    return os;
}

template<typename T>
std::ostream& operator << (std::ostream& os, const std::set<T>& v)
{
    os << "Print set: " << std::endl;

    for (const auto& i : v)
    {
        os << i << ' ';
    }
    os << std::endl;

    return os;
}

template<typename T>
std::ostream& operator << (std::ostream& os, const std::list<T>& v)
{
    os << "Print list: " << std::endl;

    for (const auto& i : v)
    {
        os << i << ' ';
    }
    os << std::endl;

    return os;
}

template<typename T, typename K>
std::ostream& operator << (std::ostream& os, const std::pair<T, K>& v)
{
    os << '(' << v.first << ", " << v.second << ") ";

    return os;
}

template<typename T, typename K>
std::ostream& operator << (std::ostream& os, const std::map<T, K>& v)
{
    os << "Print map: " << std::endl;

    for (const auto& i : v)
    {
        os << i << ' ';
    }
    os << std::endl;

    return os;
}

#endif // STL_PRINT_HPP
