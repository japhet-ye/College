/*
 * Homework problems on bit manipulation
 */
#include <stdio.h>
#include <stdlib.h>


void displayBits(unsigned int b);
int countBits(unsigned int b);
unsigned int pairwiseSwap(unsigned int b);

const unsigned int varzero = 0;

void main()
{

unsigned int n = 23;
printf("Bits in the number %d:\n",n);
displayBits(n);

/* Test countBits */
printf("Number of bits in %d = %d\n\n", n, countBits(n));

/* Swap even and odd bits */
n = 0x8234abcd;
printf("Bits in %x:\n", n);
displayBits(n);
printf("\n");
printf("Pair-wise swap: \n");
displayBits(pairwiseSwap(n));
printf("\n");


}

/*
 * Swaps odd and even bits in an unsigned int, e.g.,
 * bits 0 and 1 are swapped, bits 2 and 3 are swapped, etc
 * For example: Suppose 
 *
 *        b = 1000 0001 0010 0011 1010 1011 1100 1101
 * 
 *  Then the function returns
 *             
 *            0100 0010 0001 0011 0101 0111 1100 1110
 *  
 *  Obviously the function doesn't work.  Rewrite it so
 *  it works correctly and using only BarelyC instructions
 *  given in the homework.
 *
 *  Hint:  Use shift and bit-wise logic operations
 */
unsigned int pairwiseSwap(unsigned int b)
{

unsigned int var1;
unsigned int var2;
unsigned int var3;
unsigned int var4;
unsigned int var5;
unsigned int var6;

var5 = varzero + varzero;
var6 = varzero + varzero;
var1 = varzero + 1;
var2 = b + varzero;
loop: if(var6 > 16) goto end;
var3 = var1 & var2;
var3 = var3 << 1;
var5 = var5 | var3;

var1 = var1 << 1;
var4 = var1 & var2;
var4 = var4 >> 1;
var5 = var5 | var4;

var1 = var1 << 1;
var6 = var6 + 1;
goto loop;
end:
return var5; 
}




/* 
 * Counts the number of bits in b
 * For example, if b = 23 then its bits are 00....10111,
 * and so the function should return the value 4.
 * Obviously, the function doesn't work.
 * Fix the function so it works but use only BarelyC
 * instructions as stated in the homework.
 */
int countBits(unsigned int b)
{
// this works
//int ans = 0;
//while(b != 0){
//	if(b & 1 != 0) ans++;
//	b = b >> 1;
//}

//return ans;

unsigned int var1 = b + 0;
unsigned int var2 = varzero + 0;

loop: if(var1 == 0) goto endloop;
	if(var1 & 1 == 1)var2 = var2 + 1;
	goto shift;
shift: var1 = var1 >> 1;
	goto loop;
 endloop:

 return var2;
}

/* Displays the bits in b */
void displayBits(unsigned int b)
{
unsigned int bits = b;

for (int i=1; i<=32; i++) {
   if ((bits >> 31) & 1 == 1) {
      printf("1");
   }
   else {
      printf("0");
   }
   if (i%8 == 0) { 
      printf(" ");
   }
   bits = bits << 1;
}
printf("\n");
}

