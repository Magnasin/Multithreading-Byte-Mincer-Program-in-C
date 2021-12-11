# Multithreading-Byte-Mincer-Program-in-C
The program takes one or more files as input and creates another file (or standard output) which contains the content of all the input files but mix them in a non-deterministic 
fashion. For example, if one input file contains "12345..." and the other input file contains "abcdef...", the output of the program may look like "12a3bcd45ef...", or 
"a1b23cde4f5...", or any other combinations. That is, the output maintains the sequence of bytes from each input file; the output may change the way how the input sequences are 
mixed at each run.  

The command-line for your program should be as follows:
./bytemincer LIST_OF_INPUT_FILES -o OUTPUT_FILE

There must be at least one input file. There can be more than one input files as separate arguments in the command line. 
If -o is specified, the output shall be written to the given output file. Otherwise, the output will be the standard output. 
Note that the "-o OUTPUT_FILE" is a command-line option; that is, it can appear before or after or even in the middle of the input files list. 

Implementation
You should use getopt function to process the command-line options.
In the implementation, you should create a separate thread to handle each input file, which reads the input file, one byte at a time, and insert the byte into the ring buffer. 
You should create another thread to generate the output , which removes a byte, one at a time, from the ring buffer and writes it to the output file. 
(Of course, the output file could be the standard output).
