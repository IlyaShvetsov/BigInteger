#include <iostream>
#include <vector>
#include "biginteger.h"
using std::vector;
using std::string;



const BigInteger operator+(const BigInteger& first, const BigInteger& second)
{
    if (first.value.size() < second.value.size())
        return second + first;

    if (first.sign && !second.sign)
        return first - (-second);
    if (!first.sign && second.sign)
        return second - (-first);

    BigInteger ans;
    size_t maxSize = first.value.size(), minSize = second.value.size();
    ans.value.resize(maxSize);
    char temp = 0;
    for (int i = static_cast<int>(maxSize - 1); i >= static_cast<int>(maxSize - minSize); --i)
    {
        char sum = first.value[i] + second.value[i + minSize - maxSize] + temp;
        ans.value[i] = sum % 10;
        temp = sum / 10;
    }
    for (int i = static_cast<int>(maxSize - minSize - 1); i >= 0; --i)
    {
        ans.value[i] = temp + first.value[i];
        temp = 0;
    }
    if (temp)
    {
        ans.value.push_back(ans.value[ans.value.size()-1]);
        for (int i = maxSize - 2; i >= 0; --i)
            ans.value[i + 1] = ans.value[i];
        ans.value[0] = temp;
    }

    ans.sign = first.sign;

    return ans;
}



const BigInteger operator-(const BigInteger& first, const BigInteger& second)
{
    if (first.sign && !second.sign)
        return first + (-second);
    if (!first.sign && second.sign)
        return first + (-second);

    if (((first < second) && first.sign) || ((first > second) && !first.sign))
        return -(second - first);

    BigInteger ans;
    char temp = 0;
    for (int i = static_cast<int>(first.value.size() - 1); i >= static_cast<int>(first.value.size() - second.value.size()); --i)
    {
        if (temp == -1)
            temp = 0;
        if (temp != 0)
            temp = -1;
        if (first.value[i] + temp < second.value[i - first.value.size() + second.value.size()])
            temp += 10;
        ans.value.push_back(first.value[i] - second.value[i - first.value.size() + second.value.size()] + temp);
    }

    for (int i = static_cast<int>(first.value.size() - second.value.size() - 1); i >= 0; --i)
    {
        if (temp == -1)
            temp = 0;
        if (temp != 0)
            temp = -1;
        if (first.value[i] + temp < 0)
            temp += 10;
        ans.value.push_back(first.value[i] + temp);
    }

    int j = 1;
    for( ; j <= static_cast<int>(ans.value.size()); ++j)
        if (ans.value[ans.value.size() - j] != 0)
            break;

    ans.value.resize(ans.value.size() - j + 1);
    // reverse //
    for (int i = 0; i < static_cast<int>(ans.value.size()/2); ++i)
    {
        char temp = ans.value[i];
        ans.value[i] = ans.value[ans.value.size() - 1 - i];
        ans.value[ans.value.size() - 1 - i] = temp;
    }
    ans.sign = first > second;

    return ans;
}



const BigInteger operator*(const BigInteger& first, const BigInteger& second)
{
    if (!first || !second)
        return 0;

    if (second.value.size() > first.value.size())
        return second*first;

    BigInteger ans;
    ans.sign = (first.sign == second.sign);
    ans.value.resize(first.value.size());

    for (int j = 0; j < static_cast<int>(second.value.size()); ++j)
    {
        char temp = 0;
        for (int i = static_cast<int>(first.value.size() - 1); i >= 0; --i)
        {
            char prod = first.value[i] * second.value[second.value.size() -1 - j] + temp + ans.value[first.value.size() - 1 - i + j];
            ans.value[first.value.size() - 1 - i + j] = prod%10;
            temp = prod / 10;
        }
        ans.value.push_back(temp);
    }
    if (ans.value[ans.value.size() - 1] == 0)
        ans.value.resize(ans.value.size() - 1);
    // reverse
    for (int i = 0; i < static_cast<int>(ans.value.size()/2); ++i)
    {
        char temp = ans.value[i];
        ans.value[i] = ans.value[ans.value.size() - 1 - i];
        ans.value[ans.value.size() - 1 - i] = temp;
    }

    return ans;
}



const BigInteger operator/(const BigInteger& first, const BigInteger& _second)
{
    if (first.abs() < _second.abs())
        return 0;

    BigInteger ans;
    ans.sign = (first.sign == _second.sign);

    BigInteger second = _second.abs();

    BigInteger temp;
    temp.sign = true;
    for (int i = 0; i < static_cast<int>(second.value.size()); ++i)
        temp.value.push_back(first.value[i]);
    int k = second.value.size();
    if (temp < second)
    {
        temp.value.push_back(first.value[k]);
        k++;
    }
    for (int i = k; i <= static_cast<int>(first.value.size()); ++i)
    {
        char j;
        for (j = 1; j < 10; ++j)
            if (temp < second*j)
                break;
        j--;
        temp -= second*j;
        ans.value.push_back(j);
        if (i != static_cast<int>(first.value.size()))
            temp.value.push_back(first.value[i]);
    }

    return ans;
}


const BigInteger operator%(const BigInteger& first, const BigInteger& second)
{
    BigInteger temp(first);
    temp /= second;
    temp *= second;
    return (first - temp);
}