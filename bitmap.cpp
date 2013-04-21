#include "bitmap.h"
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

BitMap::BitMap(int lhs)
{
    assert(lhs > 0);
    init(lhs);
}

void BitMap::SetBitMap(unsigned int lhs)
{
    if(bitCounts != 0 || bitMap != NULL || charNums != 0)
    {
	delete[] bitMap;
	init(lhs);
    }
}

BitMap::BitMap(const BitMap& lhs)
{
    this->bitCounts = lhs.bitCounts;
    this->charNums = lhs.charNums;
    this->bitMap = new unsigned char[this->charNums]();
    
    assert(this->bitMap != NULL);

    memcpy(this->bitMap,lhs.bitMap,sizeof(unsigned char) * this->charNums);
}

BitMap& BitMap::operator =(const BitMap& lhs)
{
    unsigned char* orig = this->bitMap;

    this->bitCounts = lhs.bitCounts;
    this->charNums = lhs.charNums;
    this->bitMap = new unsigned char[this->charNums]();
    
    memcpy(this->bitMap,lhs.bitMap,sizeof(unsigned char) * this->charNums);

    delete[] orig;
    return *this;
}

bool BitMap::IsExistBit(unsigned int lhs) const
{
    assert(lhs <= this->bitCounts);

    int tmp = sizeof(unsigned char) * 8;
    int divisor = lhs / tmp;
    int reminder = lhs % tmp;

    if(reminder == 0)
    {
	if(divisor == 0)
	{
	    unsigned char c = this->bitMap[0];

	    if(c & 0x01)
	    {
		return true;
	    }
	    else
	    {
		return false;
	    }
	}
	else
	{
	    unsigned char c = this->bitMap[divisor - 1];

	    if((c >> 7) & 0x01)
	    {
	        return true;
	    }
	    else
	    {
	        return false;
	    }
	}
    }
    else
    {
	unsigned char c = this->bitMap[divisor];

	if((c >> (reminder - 1)) & 0x01)	
	{
	    return true;
	}
	else
	{
	    return false;
	}
    }
}

void BitMap::SetBit(unsigned int lhs)
{
    assert(lhs <= this->bitCounts);
    int tmp = sizeof(unsigned char) * 8;
    int divisor = lhs / tmp;
    int reminder = lhs % tmp;

    if(reminder == 0)
    {
	if(divisor == 0)
	{
	    this->bitMap[0] |= 0x01; 
	}
	else
	{
	    this->bitMap[divisor - 1] |= 0x80;
	}
    }
    else
    {
	this->bitMap[divisor] |= (0x01 << (reminder - 1));
    }
}

BitMap::~BitMap()
{
    delete[] this->bitMap;
    bitCounts = charNums = 0;
}

void BitMap::init(unsigned int lhs)
{
    this->bitCounts = lhs;
    bool isZero = bitCounts % charOfbitNums;

    if(isZero)
    {
	charNums = (bitCounts / charOfbitNums) + 1;	
	bitMap = new unsigned char[charNums]();

	assert(bitMap != NULL);
    }
    else
    {
	charNums = bitCounts / charOfbitNums;
	bitMap = new unsigned char[charNums]();

	assert(bitMap != NULL);
    }
}

void BitMap::ClearBitMap()
{
    memset(this->bitMap,0,sizeof(unsigned char) * charNums);
}
