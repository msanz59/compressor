# Compressor

Compressor is a C++ tool for compressing and decompressing files using two classic algorithms: **RLC (Run-Length Coding)** and **Huffman**. Its goal is to make text file size reduction simple and efficient.

## What is RLC?

**RLC (Run-Length Coding)** is a lossless compression algorithm that replaces consecutive sequences of the same data with a single instance of that data and a repetition counter. It is especially effective for files with many repeated characters.

## What is Huffman?

**Huffman** is a lossless compression algorithm based on the frequency of symbols. It assigns shorter codes to more frequent symbols and longer codes to less frequent ones, achieving efficient compression.

## Usage

When you run the program, you will see a menu with the following options:

1. Compress with RLC
2. Decompress with RLC
3. Compress with Huffman
4. Decompress with Huffman  
   q. Exit

**Important:**  
When the program asks for a file name, **do not specify the file extension**. For example, if your file is `test.txt`, just enter `test` when prompted.

It is recommended to use files with the `.txt` extension for correct operation.

### Example

If you have a file named `document.txt` and want to compress it with Huffman:

1. Select option 3.
2. Enter `document` when asked for the file name.

The program will automatically generate compressed and decompressed files with derived names.

## Requirements

- CMake 3.31 or higher
- C++ compiler compatible with C++20

## Build

```sh
cmake -B build
cmake --build build