#ifndef BASECLASSFORINHERITANCE_HPP
#define BASECLASSFORINHERITANCE_HPP

#include <iostream>
#include <string>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

class BaseClassForInheritance
{
public:
    BaseClassForInheritance() {}

    void init()
    {
        m_stringData = "Data from base class";
        m_intData = 112358;
        m_floatData = 2.7;
    }

    virtual void print() const
    {
        std::cout << "Data from base class:\n{";
        std::cout << m_intData << std::endl;
        std::cout << m_floatData << std::endl;
        std::cout << m_stringData << std::endl;
        std::cout << "}" << std::endl;
    }

private:
    friend class boost::serialization::access;

    template<class Archive>
        friend void serialize(Archive & ar, BaseClassForInheritance& obj, const unsigned int version);

    std::string m_stringData;
    int m_intData;
    float m_floatData;
};

#endif // BASECLASSFORINHERITANCE_HPP
