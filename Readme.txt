*******************************************************
*  Name      :  Melanie Woe        
*  Student ID:  105557790              
*  Class     :  CSC 2421           
*  HW#       :  9               
*  Due Date  :  Apr. 25, 2016
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program is a simple spelling checker, where it will read the file,
and insert the words into a hash table. The filechecker.back will 
contain a number of words. Read the document, and separated it into a 
sequence of words converted to lowercase. And then using a hash table, 
it will print out a list of words that appear to be misspelled.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program. It contains a program utilizing the class my_string. 
   It takes input file of data.txt. The program then takes the column 
   that the user enter and then format that input text into a vector. 
   And also print the output to the screen.

Name:  HashTable.h
   Implements various functions which demonstrates the use of hash
   table.  


*******************************************************
*  Circumstances of programs
*******************************************************

   The program was developed and tested on Xcode. 

*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [WoeHW9]

   Now you should see a directory named homework with the files:
        main.cpp
	HashTable.h
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [WoeHW9] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[HashTable]

4. Delete the obj files, executables, and core dump by
   %./make clean
