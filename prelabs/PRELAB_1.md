# Lab 1 - Cross-checker - Prep Worksheet
### Background Summary

If you were presented with the problem of comparing two code implementations to make sure they accomplish the same task, how would you decide whether two implementations are similar? Different coders have different style, so direct text comparison won't work, so you could try something like testing all the inputs and outputs to see if they are the same, but what if the output is not easily measurable as a number (like in the case of our blinking LEDs)? We would need some way of tracking the important information without getting bogged down in stylistic or functionality-independent choices.

A simple method of doing this (and the way we are going to implement) involves tracking the memory reads/writes

### Exercises:

1) What is a checksum? What information can be "checksummed"?

2) For this course we will use the default unix cksum command. What is the cksum of "checksumtest.txt?"
