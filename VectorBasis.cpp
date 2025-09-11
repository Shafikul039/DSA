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
// O(n * d)

// For a set of independent vectors, we can change any of these vectors by adding to it any linear combination of all of them,
// and the vectors will still stay independent. What's more fascinating is that, the set of vectors in the space representable by 
// some linear combination of this independent set stays exactly the same after the change.

// Notice that, in case of Zd2
//  vector space, the coefficients in the linear combination of vectors must also lie in Z2.
//  Which means that, an element vector can either stay or not stay in a linear combination, there's no in-between.

// The basis is actually the smallest sized set such that all other vectors in the vector space are representable by a linear combination of just the element vectors of that set.

// The basis vectors are independent.

// For any set with smaller number of independent vectors than the basis, not all of the vectors in the space will be representable.

// And there cannot possibly be larger number of independent vectors than basis in a set. If d  is the size of the basis of a vector space, then the moment you have d
//  independent vectors in a set, it becomes a basis. You cannot add another vector into it, since that new vector is actually representable using the basis.

// For a d−dimensional vector space, it's basis can have at most d vector elements.
