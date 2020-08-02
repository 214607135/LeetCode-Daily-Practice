// Question: Reverse bits of a given 32 bits unsigned integer.

typedef unsigned int uint32_t;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t cur = 0, power = 31;
		while (n != 0) {
			cur += (n & 1) << power--;
			n = n >> 1;
		}
		return cur;
	}
};