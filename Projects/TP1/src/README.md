# Dependencies and compilation

This project is built using several files. In order to compile and link them all, we used a Makefile. 

## Compiling
To compile and link the project, one should execute on the command line:

`$ make`

## Execution
After the compilation, just type and execute: 

`$ ./a.out vans_file_number orders_file_number`

where `vans_file_number` and `orders_file_number` are both numbers to assemble the files names to be accessed. This numbers should not exceed 3 or be less than 1, otherwise the program will produce an exception. 
Also, running the program without exacly 3 arguments will display the following message:

`Usage: ./a.out vans_file_number orders_file_number`

## Cleaning executables
To clean the executables out of the folder, simply run: 

`$ make clean`