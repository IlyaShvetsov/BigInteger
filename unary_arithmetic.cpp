#include "biginteger.h"



const BigInteger BigInteger::operator-() const // унарный минус
{
    BigInteger temp(*this);
    temp.sign = !temp.sign;
    return temp;
}



const BigInteger BigInteger::operator+() const // унарный плюс
{
    return *this;
}



BigInteger& BigInteger::operator+=(const BigInteger& another)
{
    *this = *this + another;
    return *this;
}



BigInteger& BigInteger::operator-=(const BigInteger& another)
{
    *this = *this - another;
    return *this;
}



BigInteger& BigInteger::operator*=(const BigInteger& another)
{
    *this = *this * another;
    return *this;
}



BigInteger& BigInteger::operator/=(const BigInteger& another)
{
    *this = *this / another;
    return *this;
}



BigInteger& BigInteger::operator%=(const BigInteger& another)
{
    *this = *this % another;
    return *this;
}



const BigInteger BigInteger::operator++(int)
{
    BigInteger temp = *this;
    *this = *this + (BigInteger)1;
    return temp;
}



const BigInteger BigInteger::operator--(int)
{
    BigInteger temp = *this;
    *this = *this - (BigInteger)1;
    return temp;
}



BigInteger& BigInteger::operator++()
{
    *this = *this + (BigInteger)1;
    return *this;
}



BigInteger& BigInteger::operator--()
{
    *this = *this - (BigInteger)1;
    return *this;
}