/*
 * PROVIDED FILE - DO NOT MODIFY!
 */
#ifndef PACKASCII_H
#define PACKASCII_H

#define ASCII_MAX 127

/* Packs the seven least significant bits (LSB) of byte into bits and updates
 * bitCount. Any existing data in bits is NOT overwritten but, rather, it is
 * shifted to the left to make room for the new bits.
 *
 * For Example:
 *
 * Imagine bits contains 0x00000041 (65 decimal/ASCII 'A') and bitCount is 7.
 * And, imagine byte is 0x42 (66 decimal/ASCII 'B'). The function would modify
 * bits so that it has 0x0020c2 and a bitCount of 14.
 */
void packByte(unsigned char byte, unsigned *bits, unsigned *bitCount);

/* Returns the eight most significant bits (MSB) in bits, clears (zeros) them
 * out in bits, and reduces bitCount by eight.
 *
 * NOTE: This function should not be called if bitCount is less than 8.
 */
unsigned char getMSBByte(unsigned *bits, unsigned *bitCount);

/* Makes and returns a byte with the least significant bits (LSB) in shifted
 * to the left to make them the most significant bits (MSB) and sets any now
 * unused LSB bits to zero. Both bits and bitCount are set to zero.
 */
unsigned char makeMSBByteFromLeftOverBits(unsigned *bits, unsigned *bitCount);

#endif
