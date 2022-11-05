## Question 03:

### The Collatz Conjecture algorithm is an interesting algorithm in mathematics which states that, when the algorithm is continually applied, any positive integer will eventually reach 1. The algorithm is,

```
𝑛= {𝑛/2, 	𝑖𝑓 𝑛 𝑖𝑠 𝑒𝑣𝑒𝑛
3×𝑛+1, 		𝑖𝑓 𝑛 𝑖𝑠 𝑜𝑑𝑑
```
### Few examples of the application of the algorithm are given below,
-	When n = 35, the sequence is 35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1.
-	When n=16, the sequence is 16, 8, 4, 2, 1
-	When n=6, the sequence is 6, 10, 5, 16, 8, 4, 2, 1

### Based on this Collatz Conjecture algorithm, follow the steps given below to write a C program and generate the number sequence for a given initial number.
### a)	Take the initial number from the user keyboard and perform necessary error checking to ensure that it is a positive integer.
### b)	Create a child process to generate the number sequence.
### c)	Due to the different memory copies of parent and child, the resulted sequence should be returned from the child to the parent process.

Hint: You may use an unnamed pipe, so that the child can write the generated number sequence to the pipe.
Note: Write the numbers one by one and stop writing when the number equals to 1.

### d)	Parent should wait for the child to complete and then read the written number sequence from the pipe. Finally, parent must print both the number sequence and the “End of Execution” message to the screen.
Note: Read the numbers one by one and stop reading when the number is 1.

### e)	Display necessary messages including error validations related to pipe and child creations to the screen.
Hint: Read the initial number from the keyboard and create the pipe before creating the child process.
