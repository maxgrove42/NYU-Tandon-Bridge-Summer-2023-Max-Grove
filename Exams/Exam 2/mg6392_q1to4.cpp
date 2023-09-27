//
//  main.cpp
//  mg6392_q1to4
//
//  Created by Max Grove on 9/22/23.
//  Exam 2: Questions 1 to 4
/*
    1. We will prove the sum from i = 0 to n of 3^n is equal to 1/2 * (3 ^ (n+1) - 1 ) for any non-positive integer using mathematical induction.
 
    Under the base case, n = 0, the sum from i = 0 to 0 of 3^n is equal to 3 ^ 0 = 1.
        Additionally, 1/2 * (3 ^ (0+1) - 1 ) = 1/2 * (3 - 1) = 1/2 * 2 = 1
        Thus the base case holds.
    We assume the sum from i = 0 to k of 3^k is equal to 1/2 * (3 ^ (k+1) - 1 ) for any non-positive integer
    We will now prove the sum from i = 0 to k+1 of 3^k = 1/2 * (3 ^ ((k+1)+1) - 1 )
        = 1/2 * (3 ^ (k + 2) - 1)
        = 1/2 * (3^2 * 3^k - 1)
        = 9/2 * 3^k - 1/2
 
    The sum from i = 0 to k+1 of 3^k
    = 3^(k+1) + The sum from i = 0 to k of 3^k (definition of summation)
    = 3^(k+1) + 1/2 * (3 ^ (k+1) - 1 ) (hypothesis)
    = 3*3^k + 1/2*(3*3^k - 1)
    = 3*3^k + 3/2 * 3^k - 1/2
    = 9/2*3^k - 1/2
    This completes our proof and shows the sum from i = 0 to n of 3^n is equal to 1/2 * (3 ^ (n+1) - 1 ) for any non-positive integer using mathematical induction.
 
    2a. We must choose all the orderings of 5 students where one is Hal plus all the orderings of 5 students where 1 is Ida and subtract all the orderings of 5 students where Hal and Ida are in the picture.
        = C(9,4) * 5 + C(9,4) * 5 - 5*4*C(8,3)
        We first choose all the orderings of 4 students plus where Hal stands in the photo.
        We add all the orderings of 4 students plus where Ida stands in the photo.
        We subtract out all the orderings of 3 students plus where Ida and Hal stand in the photo.
 
    2b. P(8,3). Since order does not matter in a subset, we are doing a permutation. Since two of the digits are already selected, we only have 8 digits to permutate through. We permutate the remaining 3 digits into the subset of 5 that includes 3 and 4
 
    3a. Given the first students is a freshman, we have 9 freshman left, 12 sophomores, and 8 juniors. The chance of selecting a freshman from this group is 9/(9+12+8)
        = 9/29
 
    3b. For there to be more 0s than 1s, we could have (5 0's and 3 1's) or (6 0's and 2 1's) or (7 0's and 1 1's) or (8 0's and 0 1's)
 
        Count of (5 0's and 3 1's) = C(8,5)
        Count of (6 0's and 2 1's) = C(8,6)
        Count of (7 0's and 1 1's) = C(8,7)
        Count of (8 0's and 0 1's) = C(8,8)
 
        Total possible bit strings of length 8 = 2^8
 
        P(more 0s than 1s) = ( C(8,5) + C(8,6) + C(8,7) + C(8,8) ) / (2^8)
 
    4. Function 1 run time = n*log base 5 (n) + n*n + constants
        O(n) = n^2
 
        Function 2 run time = log base 5 (n) * log base 5 (n)
        O(n) = ( log(n) ) ^ 2
 
 */

