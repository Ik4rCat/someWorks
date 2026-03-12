#include <cstddef>
#include <iostream>
#include <cstring>
#include <string>
#define _CRT_SECURE_NO_WARNINGS_
using namespace std;

class SimpleStr
{
private:
    char* str;
    size_t len;

public:
    SimpleStr(const char*str)
    {
        this->len = strlen(str);
        str = new char[len+1];
    }
    SimpleStr():str(),len(){};
    ~SimpleStr() {delete[] str; }
    SimpleStr& operator=(const SimpleStr& other)
    {
        if(this == &other)
        {
            return *this;
        }
        return *this;
    }

    void copy(const char* src, size_t len)
    {
        str = new char[len + 1];
        strcpy(str, src);
        this->len = len;
    }
    size_t length() const { return len; }
    const char* GetString() const { return str; }

    void pc(const char* src1, const char* src2, size_t len1, size_t len2)
    {
        const char* strr = new char[len1 + 1 + len2];
    //    strr = copy(src1, len1);
    //    strr = copy(src2,len2);
    }

};

int main()
{
    std::cout << "hello world!\n";
    int arr[10]{23,434,54,56,565,65,65,76,656};


}