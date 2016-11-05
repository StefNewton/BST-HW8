# BST-HW8

*******************************************************
*  Name      :  Stefani Moore        
*  Student ID:  106789878  
*  Class     :  CSCI 2421           
*  HW#       :  8                
*  Due Date  :  Oct. 29, 2016
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

Implement a binary search tree.  Specifically, you will 
implement a printPreorder, printInorder, printPostorder, 
and findNode member functions.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that tests
   the function implementation of the BSTree and Node
   classes. 

Name:  BSTree.h
   Contains the definition for the BSTree class.  

Name: BSTree.cpp
   Defines and implements the BSTree class.  
 
Name:  Node.h
   Contains the definition for the Node class.  
 
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on Microsoft Visual
   Studios Community 2015.  It was compiled, run, and tested 
   on the csegrid.ucdenver.pvt.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [MooreHW8]

   Now you should see a directory named homework with the files:
        main.cpp
        Node.h
        BSTree.cpp
	BSTree.h
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [MooreHW8] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[tree]

4. Delete the obj files, executables, and core dump by
   %./make clean
