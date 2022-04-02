#include <stdio.h>
#include <stdint.h>



struct InterleavedBits_t {
  uint32_t WS_num;
  uint32_t nibbles[6];
  uint16_t scaler;
  uint16_t mic;
};



int fileSize;




int main( int argc, char *argv[] )
{
  FILE *fp;
  struct InterleavedBits_t packed;
  int i, j, k;

  if( argc > 2 )
    {
      printf("Too many arguments supplied.\n");
      return 1;
    }
  if (argc != 2)
    {
      printf("One argument expected.\n");
      return 1;
    }

  fp = fopen(argv[1], "r");

  for (i=0; i<1; i++)
    {
      fread(&packed, sizeof(packed), 1, fp);
      printf("WS_num=%06d, mic=%02d ", packed.WS_num, packed.mic);
      for (j=0; j < 6; j++)
	{
	  for (k=32; k > 0;)
	    {
	      k -= 4;
	      printf(" %x", (packed.nibbles[j]>>k)&0xf);
	    }
	}
      printf("\n");
    }
  
  
  
  return 0;

}
