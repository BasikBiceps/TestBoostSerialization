#include <sstream>

#include <ClassForSerialization.hpp>
#include <SerializationHelper.hpp>

int main()
{
    ClassForSerialization obj;
    obj.init();
    std::stringstream ss;

    {
        boost::archive::text_oarchive oa(ss);
        oa << obj;
    }

    ClassForSerialization deserializedObj;
    {
        boost::archive::text_iarchive ia(ss);
        ia >> deserializedObj;
    }

    deserializedObj.print();

    return 0;
}
