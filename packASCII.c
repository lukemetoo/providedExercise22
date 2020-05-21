/*
 * PROVIDED FILE - DO NOT MODIFY!
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "packASCII.h"

static void pack(FILE *in, FILE *out)
{
   int byte;
   unsigned int bits = 0, bitCount = 0;

   while(EOF != (byte = getc(in))) {
      if (byte > ASCII_MAX) {
         fprintf(stderr, "ERROR: Input file is not a text file\n");
         exit(EXIT_FAILURE);
      }

      /* TODO: You must write packByte - see packASCII.h for details. */
      packByte(byte, &bits, &bitCount);
   
      /* Make sure there are enough bits to make a byte */
      if (bitCount < CHAR_BIT)
         continue;

      /* TODO: You must write getMSBByte - see packASCII.h for details. */
      if (EOF == putc(getMSBByte(&bits, &bitCount), out)) {
         fprintf(stderr, "ERROR: Writing to output file\n");
         exit(EXIT_FAILURE);
      }
   }

   if (ferror(in)) {
      fprintf(stderr, "ERROR: Reading input file\n");
      exit(EXIT_FAILURE);
   }

   /* TODO: You must write makeMSBByteFromLeftOverBits - see packASCII.h. */
   if (bitCount > 0)
      if (EOF == putc(makeMSBByteFromLeftOverBits(&bits, &bitCount), out)) {
         fprintf(stderr, "ERROR: Writing to output file\n");
         exit(EXIT_FAILURE);
      }
}

static void checkArgs(int argc, char *argv[], FILE **in, FILE **out)
{
   if (argc != 3) {
      fprintf(stderr, "Usage: packText textFileToPack packedTextFile\n");
      exit(EXIT_FAILURE);
   }

   *in = fopen(argv[1], "r");

   if (*in == NULL) {
      perror(argv[1]);
      exit(EXIT_FAILURE);
   }

   *out = fopen(argv[2], "w");

   if (*out == NULL) {
      perror(argv[2]);
      exit(EXIT_FAILURE);
   }
}

int main(int argc, char *argv[])
{
   FILE *in, *out;
   
   checkArgs(argc, argv, &in, &out);

   /* See the pack function to see the calls to the functions you must write */
   pack(in, out);

   fclose(in);
   fclose(out);
   return 0;
}
