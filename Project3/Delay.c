#include <regx51.h>
#include <intrins.h>

void Delay(unsigned int _ms)
{
    unsigned char i, j;

    while (_ms--)
    {
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j);
        } while (--i);
    }
}