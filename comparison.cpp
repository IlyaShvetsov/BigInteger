#include "biginteger.h"



bool operator==(const BigInteger& first, const BigInteger& second) {
    if (first.sign != second.sign || first.value.size() != second.value.size()) {
        return false;
    }
    for (int i = 0; i < static_cast<int>(first.value.size()); ++i) {
        if (first.value[i] != second.value[i]) {
            return false;
        }
    }
    return true;
}



bool operator!=(const BigInteger& first, const BigInteger& second) {
    return !(first == second);
}



bool operator<=(const BigInteger& first, const BigInteger& second) {
    if (first.sign && !second.sign) {
        return false;
    }
    if (!first.sign && second.sign) {
        return true;
    }
    if (first.value.size() > second.value.size()) {
        return !first.sign;
    }
    if (first.value.size() < second.value.size()) {
        return first.sign;
    }
    for (int i = 0; i < static_cast<int>(first.value.size()); ++i) {
        if (first.value[i] > second.value[i]) {
            return false;
        }
        if (first.value[i] < second.value[i]) {
            return true;
        }
    }
    return true;
}



bool operator>=(const BigInteger& first, const BigInteger& second) {
    return second <= first;
}



bool operator<(const BigInteger& first, const BigInteger& second) {
    return !(first >= second);
}



bool operator>(const BigInteger& first, const BigInteger& second) {
    return !(first <= second);
}
