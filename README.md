# Inverted Search

## Overview
The Inverted Search project is a command-line application developed in C that implements an **inverted index** to enable efficient searching of words across multiple files. Instead of scanning each file during every search, the program preprocesses data and creates a mapping of words to their respective file locations.

This project demonstrates core concepts of data structures, file handling, and efficient search techniques used in real-world search engines.

## Features
- Create an inverted index from multiple text files  
- Store words along with their file references  
- Search for a word and display all files containing it  
- Display frequency of occurrence of words  
- Efficient retrieval using preprocessed data  
- Handles multiple files dynamically  

## Technologies Used
- Programming Language: C  
- Concepts:  
  - Data Structures (Linked Lists / Hashing)  
  - File Handling  
  - Dynamic Memory Allocation  
  - String Processing  
  - Modular Programming  

## Project Structure
Inverted-Search/  
│── main.c  
│── create_database.c  
│── search.c  
│── display.c  
│── update.c  
│── common.h  
│── Makefile (optional)  
│── input_files/  

## How to Run
Compile the program:
gcc main.c create_database.c search.c display.c update.c -o inverted_search  

Run the program:
./inverted_search file1.txt file2.txt file3.txt  

## Sample Functionality
The program reads multiple input files, builds an inverted index, and allows users to search for specific words. Upon searching, it displays the list of files where the word is present along with the number of occurrences.

## Learning Outcomes
- Understanding of inverted indexing technique  
- Practical use of linked lists and hashing  
- Efficient search implementation  
- Experience with file parsing and data organization  

## Future Enhancements
- Case-insensitive and optimized search  
- Support for large-scale datasets  
- GUI-based interface  
- Persistent storage of index data  
- Performance optimization using advanced data structures  

## Author
Nagaveni Belavadi  

## License
This project is intended for educational and learning purposes.
