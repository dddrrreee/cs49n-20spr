# Lab 1 - Cross-checker - Prep Worksheet
### Background Summary

If you were presented with the problem of comparing two code implementations to make sure they accomplish the same task, how would you decide whether two implementations are similar? Different coders have different style, so direct text comparison won't work, so you could try something like testing all the inputs and outputs to see if they are the same, but what if the output is not easily measurable as a number (like in the case of our blinking LEDs)? We would need some way of tracking the important information without getting bogged down in stylistic or functionality-independent choices.

A simple method of doing this (and the way we are going to implement) involves tracking the memory reads/writes to keep track of what GPIO functions were called and how. We will end up with a "table" of the memory puts/gets, which each of you can then compare to each other's in order to show you have code with the same function.

### Lab Skills:

  1. You will create a mock version of put32 and get32 for cross-checking purposes.

  2. Modify a Makefile?

  3. You will learn one method of establishing code equivalence.

### Exercises:

This lab only has a few exercises, but it is important that you understand them. We also recommend going over the lab README for context.

1) What is a checksum? What information can be "checksummed"?

2) For this course we will use the default unix cksum command. What is the cksum of "checksumtest.txt?"
