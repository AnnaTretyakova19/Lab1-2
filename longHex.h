#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;


class longHex {

private:

    typedef unsigned long long data_t;

    static const int SIZE = 4096;
    data_t* intlong;

    static int getint(char c)
    {
        if (isdigit(c)) {
            return c - '0';
        }
        else {
            return toupper(c) - 'A' + 10;
        }
    }
    int getsize(int s) const
    {
        for (s = min(s, SIZE - 1); s != 0 && intlong[s] == 0ULL; --s);
        return s + 1;
    }
    void global_shift(int _shift, bool dir)
    {
        if (_shift == 0) {
            return;
        }
        if (dir) {
            if (length + _shift > SIZE) {
                throw "overflow";
            }
            for (int i = int(length) - 1 + int(_shift); i >= int(_shift); --i) {
                intlong[i] = intlong[i - _shift];
                intlong[i - _shift] = 0;
            }
            length = getsize(length + _shift + 1);
        }
        else {
            for (int i = 0; i < min(length, SIZE - _shift); i++) {
                intlong[i] = intlong[i + _shift];
                intlong[i + _shift] = 0;
            }
            length = getsize(length);
        }
    }

    void local_shift(int len) {
        if (len == 0) {
            return;
        }
        if (len > 0) {
            
            for (int i = min(length, SIZE - 1); i > 0; --i) {
                intlong[i] = ((intlong[i] << len) | (intlong[i - 1] >> (32 - len))) & UINT_MAX;
            }
            intlong[0] = (intlong[0] << len) & UINT_MAX;
        }
        else {
            len = -len;
            for (int i = 0; i < min(length, SIZE - 1); ++i) {
                intlong[i] = ((intlong[i] >> len) | (intlong[i + 1] << (32 - len))) & UINT_MAX;
            }
            intlong[min(length, SIZE - 1)] = (intlong[min(length, SIZE - 1)] >> len) & UINT_MAX;
        }
        length = getsize(length + 1);
    }

    longHex submod(const longHex& b, bool dir) const
    {
        if (b.isnull()) {
            throw "null divide";
        }
        longHex x(*this), y(b), res;
        int p = x.highbit() - y.highbit();
        y.shift(p);
        if (x < y) {
            y.shift(-1);
            --p;
        }
        while (p >= 0) {
            x -= y;
            res.setbit(p, 1);
            int t = y.highbit() - x.highbit();
            p -= t;
            y.shift(-t);
            if (x < y) {
                y.shift(-1);
                --p;
            }
        }
        res.length = res.getsize(SIZE);
        if (dir) {
            return res;
        }
        else {
            return x;
        }
    }

    void release_carry(int s) {
        for (int i = 0; i < min(length, SIZE - 1); ++i) {
            intlong[i + 1] += intlong[i] > UINT_MAX;
            intlong[i] &= UINT_MAX;
        }
        length = getsize(s);
        if (overflow()) {
            throw "overflow";
        }
    }
    
    bool isnull() const {
        return length == 1 && intlong[0] == 0;
    }
    bool overflow() const
    {
        return intlong[SIZE - 1] >> 32ULL != 0;
    }

   

public:
    int length = 1;
    bool getbit(int n) const
    {
        return (intlong[n / 32] >> (n % 32ULL)) & 1ULL;
    }
    void setbit(int n, bool v) {
        if (v) {
            intlong[n / 32] |= (data_t)v << ((data_t)n % 32ULL);
        }
        else {
            intlong[n / 32] &= ~((data_t)v << ((data_t)n % 32ULL));
        }
    }
   
    static data_t f(data_t x) {
        return x ? 1 + f(x >> 1) : 0;
    }

    int highbit() const {
        return (length - 1) * 32 + f(intlong[length - 1]) - 1;
    }
    void shift(int _shift) {
        int tmp = _shift < 0 ? -1 : 1;
        local_shift(tmp * (abs(_shift) % 32));
        global_shift(abs(_shift) / 32, _shift > 0);
    }

    longHex()
    {
        intlong = new data_t[SIZE];
        for (int i = 0; i < SIZE; i++) {
            intlong[i] = 0;
        }
    };

    longHex(string _str) : longHex()
    {
        reverse(_str.begin(), _str.end());
        for (int i = 0; i < min((int)_str.size(), SIZE * 8); i++) {
            setbit(i * 4, getint(_str[i]) & 1);
            setbit(i * 4 + 1, getint(_str[i]) & 2);
            setbit(i * 4 + 2, getint(_str[i]) & 4);
            setbit(i * 4 + 3, getint(_str[i]) & 8);
        }
        length = getsize(_str.size());
    }

    longHex(const longHex& _longHex) {
        intlong = new data_t[SIZE];
        length = _longHex.length;
        for (int i = 0; i < SIZE; ++i) {
            intlong[i] = _longHex.intlong[i];
        }
    }

    ~longHex() {
        delete[] intlong;
    }

    operator string() const
    {
        if (isnull()) {
            return "0";
        }
        string snum;
        for (int i = length - 1; i >= 0; i--) {
            for (int j = 8; j > 0; --j) {
                snum += "0123456789ABCDEF"[(intlong[i] >> ((j - 1) * 4)) & 15];
            }
        }
        snum.erase(0, snum.find_first_not_of('0'));
        return snum;
    }

    longHex& operator = (const longHex& _longHex) {
        length = _longHex.length;
        for (int i = 0; i < SIZE; ++i) {
            intlong[i] = _longHex.intlong[i];
        }
        return *this;
    }

    longHex& operator += (const longHex& b) {
        int temp = max(length, b.length);
        for (int i = 0; i < temp; ++i) {
            intlong[i] += b.intlong[i];
        }
        release_carry(temp + 1);
        return *this;
    }
    longHex operator + (const longHex& b) const
    {
        return longHex(*this) += b;
    }
    longHex& operator -= (const longHex& b) {
        if (*this < b) {
            throw "negate";
        }
        longHex _b = b;
        int temp = max(length, _b.length);
        for (int i = 0; i < temp; ++i) {
            if (intlong[i] < _b.intlong[i]) {
                intlong[i] += UINT_MAX + 1ULL;
                ++_b.intlong[i + 1];
            }
            intlong[i] -= _b.intlong[i];
        }
        release_carry(temp + 1);
        return *this;
    }
    longHex operator - (const longHex& b) const
    {
        return longHex(*this) -= b;
    }
    longHex& operator *= (const longHex& b) {
        longHex temp = *this;
        *this = longHex();
        for (int i = 0; i <= b.highbit(); ++i) {
            if (b.getbit(i)) {
                *this += temp;
            }
            temp += temp;
        }
        /*longHex res;
        for (int i = 0; i < length; ++i) {
            longHex temp = b;
            for (int j = 0; j < temp.length; ++j) {
                assert(ULLONG_MAX / intlong[i] >= temp.intlong[j]);
                temp.intlong[j] *= intlong[i];
            }
            temp.global_shift(i, true);
            res += temp;
        }
        *this = res;*/
        return *this;
    }

    longHex operator * (const longHex& b) const
    {
        return longHex(*this) *= b;
    }

    bool operator > (const longHex& b) const
    {
        if (length > b.length) { 
            return true; 
        };
        for (int i = SIZE - 1; i >= 0; --i) {
            if (intlong[i] != b.intlong[i]) {
                return intlong[i] > b.intlong[i];
            }
        }
        return false;
    }
    bool operator == (const longHex& b) const {
        return !(b > *this) && !(*this > b);
    }
    bool operator < (const longHex& b) const {
        return !(*this > b) && !(*this == b);
    }
    longHex operator / (const longHex& b) const
    {
        return submod(b, 1);
    }

    longHex operator % (const longHex& b) const
    {
        return submod(b, 0);
    }

    static longHex pow(const longHex& a, const longHex& b)
    {
        static const longHex one = longHex("1"), two = longHex("2");
        if (b.intlong[0] == 0 && b.length <= 1) {
            return one;
        }
        longHex res = pow(a, b / two);
        if (b.intlong[0] % 2 == 0) {
            return res * res;
        }
        else {
            return res * res * a;
        }
    }

    static longHex gcd(const longHex& a, const longHex& b)
    {

        return (b.intlong[0] == 0 && b.length <= 1) ? a : gcd(b, a % b);
    }

    static longHex lcm(const longHex& a, const longHex& b)
    {
        return a / gcd(a, b) * b;
    }

   /* static longHex pow(const longHex& a, const longHex& b, const longHex& m)
    {
        static const longHex one = longHex("1"), two = longHex("2");
        if (b.intlong[0] == 0 && b.length <= 1) {
            return one;
        }
        longHex res = pow(a, b / two);
        if (b.intlong[0] % 2 == 0) {
            return (res * res) % m;
        }
        else {
            return (((res * res) % m) * a) % m;
        }
    }*/
    static longHex pow(const longHex& a, const longHex& b, const longHex& m)
    {
        longHex res = longHex("1");
        for (int i = b.length * 32; i >= 0; --i) {
            if (b.getbit(i) == 1) {
                res = ((res * res % m) * a) % m;
            }
            else {
                res = res * res % m;
            }
        }
        res.length = res.getsize(m.length + 1);
        return res;
    }

    void print() const
    {
        cout << string(*this) << '\n';
    }

    friend ostream& operator << (ostream& os, const longHex& n) {
        return os << string(n);
    }

};