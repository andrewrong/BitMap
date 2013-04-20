#ifndef BITMAP_H
#define BITMAP_H

class BitMap
{
    public:
	BitMap();
	BitMap(int lhs);
	BitMap(const BitMap& lhs);
	BitMap& operator =(const BitMap& lhs);
	
	BitMap operator >>(int shift);
    private:
	unsigned int bitCounts;
	unsigned char* bitMap;
	unsigned int charNums;
};
#endif
