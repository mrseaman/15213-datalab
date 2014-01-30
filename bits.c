/* 
 * CS:APP Data Lab 
 * 
 * Name: Zechen Zhang
 * AndrewID: zechenz
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
  int i = 0x55;
  int j = i | (i << 8);
  return j | (j << 16);
}

/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {

  return !(x ^ y);
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
    int nn = n << 3;
    int mm = m << 3;
    int a = 0xFF << nn;
    int b = 0xFF << mm;
    int byteA = a & x;
    int byteB = b & x;
    int newByteB = byteA >> nn << mm & b;
    int newByteA = byteB >> mm << nn & a;
    return (x & (~(a | b))) | newByteA | newByteB;
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x18765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
	int a, x2, x3, negN;
        negN = ~ n + 1;
	a = ~ (~ 0 << (32 + negN));
	x2 = x >> n;
	x3 = x << (32 + negN);
  return (x2 & a) | x3;
}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  return (((~x + 1) | x) >> 31) + 1 ;
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  return ~(1 << 31);
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
     
    return (x >> 31) | (!(!x));
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  int xx = x >> 1;
  int yy = y >> 1;
  int diff = yy + (~ xx + 1);
  return ((diff >> 31) & 1) | (( !(xx ^ yy)) & (x & 1) & (!(y & 1)));
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
    int mostNeg, xSign, ySign, checkY;
    y = (~ y) + 1;
    mostNeg = 1 << 31;
    xSign = (x >> 31) & 1;
    ySign = (y >> 31) & 1;
    checkY = !(y ^ mostNeg);
    
    return (xSign & checkY) | (checkY ^ (xSign ^ ySign)) | ((!((x + y) >> 31) & 1) ^ xSign);
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum possible value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {
   int ini, xInit, yInit, negOne, ifOverflow, sum, xyInit;
   negOne = ~ 0;
   sum = x + y;
   ini = 1 << 31; // ini = 0x80000000
   xInit = x & ini;
   yInit = y & ini;
   xyInit = sum & ini;
   ifOverflow = !!((xyInit ^ xInit) & (xyInit ^ yInit)); // (ifOverflow == 1) --> Overflow; (ifOverflow == 0) --> !Overflow 

   return ((ifOverflow + negOne) & sum) | ((~(ifOverflow + negOne)) & (ini + ((~(!!xyInit)) + 1)));
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  //int sign = (x >> 31) & 1;
  int signMask = x >> 31;
  int negOne = ~ 0;
  int counter = 0; // counter to count how many bits used
  int temp;
  x  = (x & ~signMask) | ((~x)  & signMask);
  
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  // this block rounds x up to closest 2^w - 1
  
  temp = x >> 16;
  counter += (temp << 4) & 16;
  x = temp | ((temp + negOne) & x);

  temp = x >> 8;
  counter += (temp << 3) & 8;
  x = temp | ((temp + negOne) & x);

  temp = x >> 4;
  counter += (temp << 2) & 4;
  x = temp | ((temp + negOne) & x);

  temp = x >> 2;
  counter += (temp << 1) & 2;
  x = temp | ((temp + negOne) & x);

  temp = x >> 1;
  counter += temp & 1;
  x = temp | ((temp + negOne) & x);

  counter += x;
  return counter + 1;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  int exp = uf & 0x7F800000;
  int sign = uf & 0x80000000;
  int frac = uf & 0x007FFFFF; 
  if (exp == 0x7F800000) return uf; // NaN or Inifity
  if ((!exp) || (exp == 0x00800000)) {
     frac = frac | exp;
     frac = (uf & 0x00FFFFFF) >> 1;
     frac += ((uf & 3) >> 1) & (uf & 1);
     return sign | frac;
     }
  return sign | ((exp - 1) & 0x7F800000) | frac;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  int exp = (uf & 0x7F800000) >> 23;
  int sign = uf & 0x80000000;
  int frac = uf & 0x007FFFFF;
  int realExp;
  realExp = exp - 127; // deduce bias from exp

  if (realExp < 0) return 0;
  if (realExp > 30) return 0x80000000u;
  frac = frac | 0x800000;
  if (realExp < 23) frac = frac >> (23 - realExp);
  else frac = frac << (realExp - 23);
  if (sign) return (~frac) + 1;
  return frac;
}
