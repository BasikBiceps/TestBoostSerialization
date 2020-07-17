#ifndef SERIALIZATIONHELPER_HPP
#define SERIALIZATIONHELPER_HPP

#include <boost/serialization/list.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/set.hpp>
#include <boost/serialization/map.hpp>

#include <ClassForSerialization.hpp>
#include <CustomDataType.hpp>
#include <BaseClassForInheritance.hpp>

    template<class Archive>
        void serialize(Archive & ar, ClassForSerialization& obj, const unsigned int version)
        {
            ar & boost::serialization::base_object<BaseClassForInheritance>(obj);

            if (version == 1)
            {
                ar & obj.m_dataFromOtherVersion;
            }

            ar & obj.m_charData;
            ar & obj.m_uCharData;
            ar & obj.m_intData;
            ar & obj.m_shIntData;
            ar & obj.m_lIntData;
            ar & obj.m_uIntData;
            ar & obj.m_uLongIntData;
            ar & obj.m_floatData;
            ar & obj.m_doubleData;
            ar & obj.m_boolData;
            ar & obj.m_stringData;
            ar & obj.m_longTopic;
            ar & obj.m_intVectorData;
            ar & obj.m_intStringMapData;
            ar & obj.m_stringListData;
            ar & obj.m_stringSetData;
            ar & obj.m_customDataVector;
            ar & obj.m_customDataList;
        }

    template<class Archive>
        void serialize(Archive & ar, CustomDataType& obj, const unsigned int version)
        {
            ar & obj.m_charData;
            ar & obj.m_intData;
            ar & obj.m_doubleData;
            ar & obj.m_stringData;
            ar & obj.m_stringVectorData;
            ar & obj.m_intListData;
        }

    template<class Archive>
        void serialize(Archive & ar, BaseClassForInheritance& obj, const unsigned int version)
        {
            ar & obj.m_intData;
            ar & obj.m_floatData;
            ar & obj.m_stringData;
        }


#endif // SERIALIZATIONHELPER_HPP
