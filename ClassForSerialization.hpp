#ifndef CLASSFORSERIALIZATION_HPP
#define CLASSFORSERIALIZATION_HPP

#include <CustomDataType.hpp>
#include <BaseClassForInheritance.hpp>

class ClassForSerialization : public BaseClassForInheritance
{
public:
    ClassForSerialization() {}

    void init()
    {
        BaseClassForInheritance::init();
        m_charData = 'y';
        m_uCharData = 255;
        m_intData = -1000001;
        m_shIntData = 31547;
        m_lIntData = 289257478;
        m_uIntData = 4001001000;
        m_uLongIntData = 4000000000;
        m_floatData = 1.35;
        m_doubleData = -0.89;
        m_dataFromOtherVersion = "This is data from 1 version";
        m_boolData = true;
        m_stringData = "Hello, world!";
        m_longTopic = "Breaking out discussion questions like the ones below, questions about everyday things,"
                      "works well because these types of questions really get the brain thinking, relate directly"
                      "to the students on a familiar level and can even incite some fascinating discussions between "
                      "students, all while you sit back and listen!";

        m_intVectorData = {-5, 1, 7, 158, 9};
        m_intStringMapData = {{0, "Test1"},{1, "Test2"},{2, "Test3"}};
        m_stringListData = {"Test1", "Test2", "Test3"};
        m_stringSetData = {"Test1", "Test2", "Test3"};

        m_customDataVector = {CustomDataType(), CustomDataType(), CustomDataType()};
        m_customDataList = {CustomDataType(), CustomDataType(), CustomDataType()};

        for (auto& el : m_customDataVector)
        {
            el.init();
        }

        for (auto& el : m_customDataList)
        {
            el.init();
        }
    }

    void print() const override
    {
        BaseClassForInheritance::print();
        std::cout << m_charData << std::endl;
        std::cout << m_uCharData << std::endl;
        std::cout << m_intData << std::endl;
        std::cout << m_shIntData << std::endl;
        std::cout << m_lIntData<< std::endl;
        std::cout << m_uIntData << std::endl;
        std::cout << m_uLongIntData << std::endl;
        std::cout << m_floatData << std::endl;
        std::cout << m_doubleData << std::endl;
        std::cout << m_boolData << std::endl;
        std::cout << m_stringData << std::endl;
        std::cout << m_longTopic << std::endl;
        std::cout << m_intVectorData << std::endl;
        std::cout << m_stringListData << std::endl;
        std::cout << m_stringSetData << std::endl;
        std::cout << m_intStringMapData << std::endl;
        std::cout << m_intVectorData << std::endl;
        std::cout << m_customDataVector << std::endl;
        std::cout << m_customDataList << std::endl;
        std::cout << m_dataFromOtherVersion << std::endl;
    }

private:
    friend class boost::serialization::access;

    template<class Archive>
        friend void serialize(Archive & ar, ClassForSerialization& obj, const unsigned int version);

    char m_charData;
    unsigned char m_uCharData;
    int m_intData;
    short int m_shIntData;
    long int m_lIntData;
    unsigned int m_uIntData;
    unsigned long int m_uLongIntData;
    float m_floatData;
    double m_doubleData;
    bool m_boolData;
    std::string m_dataFromOtherVersion;
    std::string m_longTopic;
    std::string m_stringData;
    std::vector<int> m_intVectorData;
    std::map<int, std::string> m_intStringMapData;
    std::list<std::string> m_stringListData;
    std::set<std::string> m_stringSetData;
    std::vector<CustomDataType> m_customDataVector;
    std::list<CustomDataType> m_customDataList;
};

BOOST_CLASS_VERSION(ClassForSerialization, 1)

#endif // CLASSFORSERIALIZATION_HPP
