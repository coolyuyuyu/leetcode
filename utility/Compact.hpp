
void encode(size_t val, string& out) {
    do {
        unsigned char v = static_cast<unsigned char>(val) & MASK;
        if (MASK < val) {
            v |= CARRY;
        }
        out += v;
    } while (val >>= SHIFT);
}



void decode(string::const_iterator& itr, size_t& val) {
    val = 0;

    int shiftCnt = 0;
    size_t c;
    do { 
        c = *itr++;
        val |= (c & MASK) << shiftCnt;
        shiftCnt += SHIFT;
    } while (c & CARRY);
}