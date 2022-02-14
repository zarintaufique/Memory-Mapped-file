# Memory-Mapped-file
Write C/C++ code for a program that takes as command line argument a file name.
Your program will make a memory map of the file and change the case of English alphabets.
Make two threads for this purpose. The first thread will change the case from the first half of the
map and the second thread will change the case from the second half of the map. Assume that
there are 100 bytes in the file. (Hint: Create a single map. Pass the map pointer to first thread as
parameter. For the second thread, add 50 to the map pointer and pass it to the second thread as
parameter, i.e., map+50.

Sample Data for File:
v1gU6OTg7MifG7zmQWp04ZEGRi!q1uFs%9RzZWc^!@#QL7jBMNKUQVEAIsKZia40M3Tq^&amp;eGEMEkkSagf
U&amp;7mU3PbQ*zsiJm23Hq
