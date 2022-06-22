# tdmTools
Specification for samples in file from Beaglebone.
Might actually be "mirrored" in each unsigned int 32.
Big endian mixed with little endian is a bit hard.
See the code in nibbles2pcm.c.

See the ICS-52000 spec to understand how the PCM-24 values from the mics is read.

The 64 mics are daisy chained in four separate loops, i.e. 16 mics per chain.
"A sign" is the nibble with the signs of e.g. the mics with index 0 for all four loops.
"B sign" is the nibble with the signs, in the same exaple, for the mics with index 1.
"A22s" is the most significant bits for the four mics.
"A00s" is the least significant bits.


```text
 0                   1                   2                   3
 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|             Sequence Number for sampling occurance            |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
| A sign|  A22s |  A21s |  A20s |  A19s |  A18s |  A17s |  A16s |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|  A15s |  A14s |  A13s |  A12s |  A11s |  A10s |  A09s |  A08s |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|  A07s |  A06s |  A05s |  A04s |  A03s |  A02s |  A01s |  A00s |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
| B sign|  B22s |  B21s |  B20s |  B19s |  B18s |  B17s |  B16s |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|  B15s |  B14s |  B13s |  B12s |  B11s |  B10s |  B09s |  B08s |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|  B07s |  B06s |  B05s |  B04s |  B03s |  B02s |  B01s |  B00s |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|        fs=25e6/512/(x+1) Hz   |      B's mic index in loop    |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
```
