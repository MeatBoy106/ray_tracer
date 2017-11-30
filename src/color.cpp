#include <algorithm>
#include <iostream>
#include "color.hpp"

using namespace std;

extern double const epsilon;

Color::Color(uint32_t r, uint32_t g, uint32_t b):
    mR(r), mG(g), mB(b)
{}


Color& Color::operator*= (double k)
{
    //Negative k causes underflow so k < 0 is declared equivalent to k == 0
    k = max(0., k);

    mR *= k;
    mG *= k;
    mB *= k;

    return *this;
}


Color& Color::operator*= (const Color& that)
{
    mR *= that.mR;
    mG *= that.mG;
    mB *= that.mB;

    return *this;
}


Color& Color::operator+= (const Color& that)
{
    mR += that.mR;
    mG += that.mG;
    mB += that.mB;

    return *this;
}


Color operator* (const Color& c, double k)
{
    Color res(c);
    return res *= k;
}


Color operator* (const Color& c1, const Color& c2)
{
    Color res(c1);
    return res *= c2;
}


Color operator+ (const Color& c1, const Color& c2)
{
    Color res(c1);
    return res += c2;
}


ostream& operator <<(ostream& stream, const Color& color)
{
    auto c = Color(color);
    c.bound();
    stream << (uint32_t)c.mR << " " << (uint32_t)c.mG << " " << (uint32_t)c.mB;
    return stream;
}

void Color::bound() {
    uint32_t max{255};
    mR = min(mR, max);
    mG = min(mG, max);
    mB = min(mB, max);
}
