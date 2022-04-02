#include <stdio.h>
#include <stdint.h>

struct InterleavedBits_t {
  uint32_t WS_num;
  uint32_t nibbles[6];
  uint16_t scaler;
  uint16_t mic;
};

struct SampleRound_t
{
  struct InterleavedBits_t samples[8];
};
//struct PCMs {
  
int fileSize;

int main( int argc, char *argv[] )
{
  FILE *fp;
  struct SampleRound_t sampleRound;
  int i, j, k, l;

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
  if (NULL == fp)
    {
      printf("Could not open file \"%s\"\n", argv[1]);
      return 1;
    }

  fseek(fp, 0L, SEEK_END);
  fileSize = ftell(fp);
  rewind(fp);
  
  printf("Size: 0x%x\t0x%x\n", fileSize, (unsigned int)(fileSize/sizeof(struct SampleRound_t)));
  
  for (i=0; i<2; i++)
    {
      fread(&sampleRound, sizeof(sampleRound), 1, fp);
      struct InterleavedBits_t* interleavedBits_p = &sampleRound.samples[0];
      uint32_t WS_num = interleavedBits_p->WS_num;
      printf("WS_num=%d\n", WS_num);
      
      for (l=0; l<8; l++)
	{
	  int WS_numIter;
	  interleavedBits_p = &sampleRound.samples[l];
	  WS_numIter = interleavedBits_p->WS_num;
	  if (WS_num != WS_numIter)
	    {
	      printf("Format error: Change of WS_num at %d\n", WS_num);
	      return 1;
	    }
	  
	  printf("mic=%02d ",
		 interleavedBits_p->mic);
	  for (j=0; j < 3; j++)
	    {
	      for (k=28; k >= 0; k -= 4)
		{
		  printf(" %x", (interleavedBits_p->nibbles[j]>>k)&0xf);
		}
	      printf(" |");
	    }
	  printf("|||");
	  for (j=3; j < 6; j++)
	    {
	      for (k=28; k >= 0; k -= 4)
		{
		  printf(" %x", (interleavedBits_p->nibbles[j]>>k)&0xf);
		}
	      printf(" |");
	    }
	  printf("\n");
	}
    }
  
  return 0;

}
