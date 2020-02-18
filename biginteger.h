#pragma once
#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;



class BigInteger {
private:
    bool sign;
    vector <char> value;

public:
    // конструкторы //
    BigInteger(const string& str);
    BigInteger(const BigInteger& another);
    BigInteger(int _value);
    BigInteger() {}

    explicit operator bool() const;
    string toString() const;
    BigInteger abs() const;

    // арифметические операторы //
    friend const BigInteger operator+(const BigInteger& first, const BigInteger& second);
    friend const BigInteger operator-(const BigInteger& first, const BigInteger& second);
    friend const BigInteger operator*(const BigInteger& first, const BigInteger& second);
    friend const BigInteger operator/(const BigInteger& first, const BigInteger& second);
    friend const BigInteger operator%(const BigInteger& first, const BigInteger& second);

    // составные арифметические операторы //
    BigInteger& operator+=(const BigInteger& another);
    BigInteger& operator-=(const BigInteger& another);
    BigInteger& operator*=(const BigInteger& another);
    BigInteger& operator/=(const BigInteger& another);
    BigInteger& operator%=(const BigInteger& another);

    // операторы сравнения //
    friend bool operator==(const BigInteger& first, const BigInteger& second);
    friend bool operator!=(const BigInteger& first, const BigInteger& second);
    friend bool operator<=(const BigInteger& first, const BigInteger& second);
    friend bool operator>=(const BigInteger& first, const BigInteger& second);
    friend bool operator<(const BigInteger& first, const BigInteger& second);
    friend bool operator>(const BigInteger& first, const BigInteger& second);

    // унарные операторы //
    const BigInteger operator++(int);
    const BigInteger operator--(int);
    BigInteger& operator++();
    BigInteger& operator--();

    const BigInteger operator-() const; // унарный минус
    const BigInteger operator+() const; // унарный плюс

    // операторы для работы с потоками //
    friend std::ostream& operator<<(std::ostream& output, const BigInteger& bigInt);
    friend std::istream& operator>>(std::istream& input, BigInteger& bigInt);
};