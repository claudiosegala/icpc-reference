y  =  (x & (1 << i)) // Get the i-th bit
x |=  (1 << i)       // Set the i-th bit
x &= ~(1 << i)       // Clear the i-th bit
