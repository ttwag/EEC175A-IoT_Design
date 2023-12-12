# Compression
Compression reduces the size of a file to 
* Save **space** when storing it
* Save **time** and **energy** when transmitting it

## Classification
* **Entropy Coding** (statistical)
    * Representing frequently occurring paterns with few bits and rarely occurring patterns with many bits.
    * lossless
    * EX: Run-Length Encoding (RLE), Huffman Encoding.
* **Source Coding**
    * Usually lossy; reduces bits by removing unnecessary or less important information.
* **Hybrid Coding**
    * Combines entropy with source encoding

## RLE
EX: 11000 = 5 bits

We could represent this data by 

1(2) 0(3)

or with 2 bits system to show the count

1(10) 0(11) = 6 bits

Sometimes this method could use less bit in the count version. However, it's not the case in this example.

## Huffman Coding
**Variable length** length encoding of symbols.
Efficient when symbol probabilities vary widely.

* Principle
    * Use fewer bits to represent frequent symbols.
    * Use more bits to represent infrequent symbols.
* Properties
    * Prefix Code: no code is a prefix of another code.
    * **No need for end of code marker**
    * Non-deterministic: multiple Huffman coding is possible for same input.