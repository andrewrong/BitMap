#include "bitmap.h"
#include <iostream>
#include <cassert>

using namespace std;

BitMap::BitMap():bitCounts(8),charNums(1)
{
    bitMap = new unsigned char[charNums]();
    assert(bitMap != NULL);
}

BitMap::BitMap(int lhs)
{
    assert(lhs >= 0);

    bitCounts = lhs;
    int charOfbitNums = sizeof(unsigned char) * 8;
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
BitMap::BitMap(const BitMap& lhs)
{
    this->bitCounts = lhs.bitCounts;
    this->charNums = lhs.charNums;
    this->bitMap = new unsigned char[this->charNums]();
    
    assert(this->bitMap != NULL);

    memcpy(this->bitMap,lhs->bitMap,sizeof(unsigned char) * this->charNums);
}

BitMap& BitMap::operator =(const BitMap& lhs)
{
    unsigned char* orig = this->bitMap;

    this->bitCounts = lhs.bitCounts;
    this->charNums = lhs.charNums;
    this->bitMap = new unsigned char[this->charNums]();
    
    memcpy(this->bitMap,lhs->bitMap,sizeof(unsigned char) * this->charNums);

    delete[] orig;
    return *this;
}

//向右移动就表示往低端移位

BitMap BitMap::operator >>(unsigned int shift)
{
    if(shift > this->bitCounts)
    {
	cout << "你移动的位数超过了你本来有的bit数目" << endl;	
	memset(this->bitMap,0,sizeof(unsigned char) * this->charNums);

	return *this;
    }


}
