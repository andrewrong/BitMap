#include "bitmap.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    BitMap bm(12);

    {
	bm.SetBit(1);
	bm.SetBit(3);
	bm.SetBit(5);
	bm.SetBit(6);
	bm.SetBit(8);
	bm.SetBit(12);
    
	for(int i = 1; i <= 12; i++)
	{
	    if(bm.IsExistBit(i))
	    {
		cout << "success" << endl;
	    }
	    else
	    {
		cout << "fail" << endl;
	    }
	}
    }
}
