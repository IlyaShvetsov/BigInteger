#include <vector>
#include <string>
#include "biginteger.h"
using std::vector;
using std::string;



BigInteger::BigInteger(const string& str) {
    if (str[0] == '-') {
        sign = false;
    } else {
        sign = true;
        value.push_back(str[0]-'0');
    }
    for (int i = 1; i < static_cast<int>(str.size()); ++i) {
        value.push_back(str[i]-'0');
    }
}



BigInteger::BigInteger(const BigInteger& another) {
    value = another.value;
    sign = another.sign;
}



BigInteger::BigInteger(int _value) {
    sign = true;
    if (_value < 0) {
        sign = false;
        _value = -_value;
    }
    long long temp = _value;
    int count = 0;
    for (; temp; ++count, temp /= 10);
    value.resize(count);
    for (int i = count - 1; i >= 0; --i, _value /= 10) {
        value[i] = _value % 10;
    }
}



BigInteger::operator bool() const {
    return !value.empty();
}



string BigInteger::toString() const {
    string str;
    if (!*this) {
        str = '0';
        return str;
    }
    if (!sign) {
        str += '-';
    }
    for (int i = 0; i < static_cast<int>(value.size()); ++i) {
        str += (value[i] + '0');
    }
    return str;
}



BigInteger BigInteger::abs() const {
    return (sign ? *this : -*this);
}



std::ostream& operator<<(std::ostream& output, const BigInteger& bigInt) {
    output << bigInt.toString();
    return output;
}



std::istream& operator>>(std::istream& input, BigInteger& bigInt) {
    string str;
    input >> str;
    bigInt = BigInteger(str);
    return input;
}
