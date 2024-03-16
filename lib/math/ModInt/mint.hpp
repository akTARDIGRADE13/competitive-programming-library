#pragma once

#include <cassert>
#include <iostream>

namespace akTARDIGRADE13 {

template <int mod> struct mint {
    long long x;

    mint(long long x = 0) : x(normalize(x)) {
        static_assert(mod > 0, "modulus must be positive");
        static_assert(mod < (1 << 30), "modulus must be small than 2*30");
    }

    mint &operator++() {
        if(++x == mod)
            x = 0;
        return *this;
    }

    mint operator++(int) {
        mint result(*this);
        ++(*this);
        return result;
    }

    mint &operator--() {
        if(--x < 0)
            x += mod;
        return *this;
    }

    mint operator--(int) {
        mint result(*this);
        --(*this);
        return result;
    }

    mint &operator+=(const mint &a) {
        if((x += a.x) >= mod)
            x -= mod;
        return *this;
    }

    mint &operator-=(const mint &a) {
        if((x += mod - a.x) >= mod)
            x -= mod;
        return *this;
    }

    mint &operator*=(const mint &a) {
        x = (x * a.x) % mod;
        return *this;
    }

    mint &operator/=(const mint &a) { return *this *= a.inv(); }

    mint operator-() const { return mint(-x); }
    mint operator+(const mint &a) const { return mint(*this) += a; }
    mint operator-(const mint &a) const { return mint(*this) -= a; }
    mint operator*(const mint &a) const { return mint(*this) *= a; }
    mint operator/(const mint &a) const { return mint(*this) /= a; }

    bool operator==(const mint &a) const { return x == a.x; }
    bool operator!=(const mint &a) const { return x != a.x; }

    mint pow(long long t) const {
        assert(t >= 0);
        mint res(1), a(*this);
        while(t > 0) {
            if(t & 1)
                res *= a;
            a *= a;
            t >>= 1;
        }
        return res;
    }

    mint inv() const { return pow(mod - 2); }

    static long long normalize(long long n) {
        n %= mod;
        if(n < 0)
            n += mod;
        return n;
    }

    friend std::istream &operator>>(std::istream &is, mint &m) {
        is >> m.x;
        m.x = normalize(m.x);
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const mint &m) {
        os << m.x;
        return os;
    }
};

template <int id> struct d_mint {
    using mint = d_mint;
    static int mod;
    long long x;

    d_mint(long long x = 0) : x(normalize(x)) {}

    static void set_mod(int m) {
        assert(m > 0 && "modulus must be positive");
        assert(m < (1 << 30) && "modulus must be smaller than 2^30");
        mod = m;
    }

    mint &operator++() {
        if(++x == mod)
            x = 0;
        return *this;
    }

    mint operator++(int) {
        mint result(*this);
        ++(*this);
        return result;
    }

    mint &operator--() {
        if(--x < 0)
            x += mod;
        return *this;
    }

    mint operator--(int) {
        mint result(*this);
        --(*this);
        return result;
    }

    mint &operator+=(const mint &a) {
        if((x += a.x) >= mod)
            x -= mod;
        return *this;
    }

    mint &operator-=(const mint &a) {
        if((x += mod - a.x) >= mod)
            x -= mod;
        return *this;
    }

    mint &operator*=(const mint &a) {
        x = (x * a.x) % mod;
        return *this;
    }

    mint &operator/=(const mint &a) { return *this *= a.inv(); }

    mint operator-() const { return mint(-x); }
    mint operator+(const mint &a) const { return mint(*this) += a; }
    mint operator-(const mint &a) const { return mint(*this) -= a; }
    mint operator*(const mint &a) const { return mint(*this) *= a; }
    mint operator/(const mint &a) const { return mint(*this) /= a; }

    bool operator==(const mint &a) const { return x == a.x; }
    bool operator!=(const mint &a) const { return x != a.x; }

    mint pow(long long t) const {
        assert(t >= 0);
        mint res(1), a(*this);
        while(t > 0) {
            if(t & 1)
                res *= a;
            a *= a;
            t >>= 1;
        }
        return res;
    }

    mint inv() const { return pow(mod - 2); }

    static long long normalize(long long n) {
        n %= mod;
        if(n < 0)
            n += mod;
        return n;
    }

    friend std::istream &operator>>(std::istream &is, mint &m) {
        is >> m.x;
        m.x = normalize(m.x);
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const mint &m) {
        os << m.x;
        return os;
    }
};

template <int id> int d_mint<id>::mod;

}