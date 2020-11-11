#include <iostream>
#include <string>
#include <algorithm>


using namespace std;


class longHex {

private:

    typedef short data_t;

    static const size_t SIZE = 2048;
    data_t* intlong;
    size_t length = 1;

    static int getint(char c)
    {
        if (isdigit(c)) {
            return c - '0';
        }
        else {
            return toupper(c) - 'A' + 10;
        }
    }

    void shift(size_t _shift, bool dir)
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

    longHex submod(const longHex& b, bool dir) const
    {
        if (b.intlong[0] == 0 && b.length <= 1) {
            throw "zero divide submod";
        }
        longHex shifter(b);
        longHex res;
        longHex ost = longHex(*this);
        for (int j = ost.length - b.length; j >= 0; j--) {
            shifter = b;
            shifter.shift(j, 1);
            data_t count = 0;
            bool triger = true;
            while (triger) {
                try {
                    ost = ost - shifter;
                    count++;
                }
                catch (...) {
                    triger = false;
                }
            }
            res.intlong[j] = count;
        }
        res.length = res.getsize(length);
        ost.length = ost.getsize(length);
        if (dir) {
            return res;
        }
        else {
            return ost;
        }
    }

    size_t getsize(size_t s) const
    {
        for (s = min(s, SIZE - 1); s != 0 && intlong[s] == 0; s--);
        return s + 1;
    }
    bool overflow() const
    {
        return intlong[SIZE - 1] / 16 != 0;
    }

    bool getbit(int n) const 
    {
        return intlong[n / 4] & (1 << (n % 4));
    }
        

public:

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
        for (int i = 0; i < min(_str.size(), SIZE); i++) {
            intlong[i] = getint(_str[i]);
        }
        length = getsize(_str.size());
    };

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
        string snum;
        for (int i = length - 1; i >= 0; i--) {
            snum += "0123456789ABCDEF"[intlong[i]];
        }
        return snum;
    }

    longHex& operator = (const longHex& _longHex) {
        length = _longHex.length;
        for (int i = 0; i < SIZE; ++i) {
            intlong[i] = _longHex.intlong[i];
        }
        return *this;
    }

    longHex operator + (const longHex& b) const
    {
        longHex res;
        size_t temp = max(length, b.length);
        res.intlong[0] = intlong[0] + b.intlong[0];
        for (int i = 1; i < min(temp + 1, SIZE); i++) {
            res.intlong[i] = intlong[i] + b.intlong[i] + res.intlong[i - 1] / 16;
            res.intlong[i - 1] %= 16;
        }
        if (res.overflow()) {
            throw "overflow";
        }
        res.length = res.getsize(temp);
        return res;
    }

    longHex operator - (const longHex& b) const
    {
        longHex res;
        size_t temp = max(length, b.length);
        data_t carry = 0;
        for (int i = 0; i < temp; i++) {
            res.intlong[i] = intlong[i] - b.intlong[i] - carry;
            if (res.intlong[i] < 0) {
                carry = 1;
                res.intlong[i] += 16;
            }
            else {
                carry = 0;
            }
        }
        if (carry) {
            throw "negative result";
        }
        res.length = res.getsize(temp);
        return res;
    }

    longHex operator * (const longHex& b) const
    {
        longHex res;
        data_t carry = 0;
        if (length + b.length - 1 > SIZE) {
            throw "overflow";
        }
        for (int i = 0; i < b.length + 1; i++) {
            for (int j = 0; j < min(length + 1, SIZE - i); j++) {
                res.intlong[i + j] += intlong[j] * b.intlong[i] + carry;
                carry = res.intlong[i + j] / 16;
                res.intlong[i + j] %= 16;
            }
        }
        if (res.overflow()) {
            throw "overflow";
        }
        else {
            res.intlong[b.length + length - 1] += carry;
        }
        res.length = res.getsize(length + b.length);
        return res;
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

    static longHex pow(const longHex& a, const longHex& b, const longHex& m)
    {
        longHex res = longHex("1");
        for (int i = b.length * 4; i >= 0; --i) {
                if (b.getbit(i) == 1) {
                    res = ((res * res % m) * a) % m;
                }
                else {
                    res = res * res % m;
                }
        }
        res.length = res.getsize(m.length+1);
        return res;
    }

    void print() const
    {
        cout << string(*this) << '\n';
    }
};