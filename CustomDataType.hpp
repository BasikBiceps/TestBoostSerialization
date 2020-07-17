#ifndef CUSTOMDATATYPE_HPP
#define CUSTOMDATATYPE_HPP

#include <stl_print.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

class CustomDataType
{
public:
    CustomDataType() {}

    void init()
    {
        m_charData = 'k';
        m_intData = 1337;
        m_doubleData = 3.14;
        m_stringData = "String from custom data.";
        m_stringVectorData = {"String", "from", "custom", "data", "vector"};
        m_intListData = {1,1,2,3,5,8,13,21};
    }

    friend std::ostream& operator<< (std::ostream &out, const CustomDataType &data);

private:
    friend class boost::serialization::access;

    template<class Archive>
        friend void serialize(Archive & ar, CustomDataType& obj, const unsigned int version);

    char m_charData;
    int m_intData;
    double m_doubleData;
    std::string m_stringData;
    std::vector<std::string> m_stringVectorData;
    std::list<int> m_intListData;
};

std::ostream& operator << (std::ostream &os, const CustomDataType &obj)
{
    os << "Print custom data type object:\n{" << std::endl;

    os << obj.m_charData << std::endl;
    os << obj.m_intData << std::endl;
    os << obj.m_doubleData << std::endl;
    os << obj.m_stringData << std::endl;
    os << obj.m_stringVectorData << std::endl;
    os << obj.m_intListData << std::endl;

    os << "}" << std::endl;

    return os;
}

#endif // CUSTOMDATATYPE_HPP
