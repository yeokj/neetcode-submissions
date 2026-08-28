class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t results = 0;

        for (int i = 0; i < 32; ++i) {
            results <<= 1;
            uint32_t temp = n & 1;
            results |= temp;
            n >>= 1;
        }

        return results;
    }
};
