int basis[d]; // basis[i] stores a vector (mask) whose i-th bit is the most significant 1-bit (i.e., f(mask) == i)
int sz;       // Number of independent vectors in the basis

void insertVector(int mask) {
    for (int i = 0; i < d; i++) {
        if ((mask & (1 << i)) == 0) continue; // Bit i is not set in mask, skip

        if (!basis[i]) {     // If there's no existing basis vector with i-th bit set
            basis[i] = mask; // Set this mask as the basis vector for bit i
            ++sz;            // Increase size of the basis
            return;
        }

        mask ^= basis[i]; // Eliminate the i-th bit using XOR with existing basis
    }
}
