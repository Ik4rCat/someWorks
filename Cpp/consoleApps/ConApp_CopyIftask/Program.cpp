#include <iostream>

template <typename T, typename Pred>
T* CopyIf(const T* srcBegin, const T* srcEnd, T* dstBegin, Pred pred)
{
    while (srcBegin != srcEnd)
    {
        if (pred(*srcBegin))
        {
            *dstBegin = *srcBegin;
            ++dstBegin;
        }
        ++srcBegin;
    }
    return dstBegin;
}

class NoSequence
{
    char last;
    bool isFirst;
public:
    NoSequence() : last(0), isFirst(true) {}

    bool operator()(char c)
    {
        if (isFirst)
        {
            isFirst = false;
            last = c;
            return true;
        }

        if (c == last)
            return false;

        last = c;
        return true;
    }
};

class SumLimit
{
    int count;
    int limit;
public:
    explicit SumLimit(int limit_) : count(0), limit(limit_) {}

    bool operator()(int)
    {
        if (count >= limit)
            return false;

        ++count;
        return true;
    }
};

int main()
{
    const char srcChars[] = "aaabbbcdd";
    char dstChars[20];

    NoSequence ns;
    char* endChars = CopyIf(srcChars, srcChars + 9, dstChars, ns);
    *endChars = '\0';

    std::cout << "NoSequence result: " << dstChars << std::endl;

    int srcNums[] = {1, 2, 3, 4, 5, 6};
    int dstNums[10];

    SumLimit sl(3);
    int* endNums = CopyIf(srcNums, srcNums + 6, dstNums, sl);

    std::cout << "SumLimit result: ";
    for (int* p = dstNums; p != endNums; ++p)
    {
        std::cout << *p << ' ';
    }
    std::cout << std::endl;

    return 0;
}