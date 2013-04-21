#ifndef BITMAP_H
#define BITMAP_H

class BitMap
{
    public:
	BitMap():bitCounts(0),bitMap(0),charNums(0){}
	BitMap(int lhs);
	BitMap(const BitMap& lhs);
	BitMap& operator =(const BitMap& lhs);
	bool IsExistBit(unsigned int lhs) const;	
	void SetBit(unsigned int lhs);
	void SetBitMap(unsigned int lhs);
	void ClearBitMap();
	~BitMap();

    private:
	void init(unsigned int lhs);
	unsigned int bitCounts;
	unsigned char* bitMap;
	unsigned int charNums;
	static const unsigned int charOfbitNums = sizeof(unsigned char) * 8;
};
#endif
