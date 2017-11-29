#include "color.hpp"

using namespace std;

Color::Color(uint8_t r, uint8_t g, uint8_t b):
    mR(r), mG(g), mB(b)
{}


Color& Color::operator*= (double k)
{
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
    stream << color.mR << " " << color.mG << " " << color.mB;
    return stream;
}
