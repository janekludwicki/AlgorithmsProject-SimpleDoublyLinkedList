## Double-Linked List Management Program in C++

### Overview
This project implements a double-linked list management program in C++. The program supports various operations such as adding elements before or after a specified node, removing elements, navigating through the list, and printing elements. The main feature of this project is its interactive command-line interface, which allows users to manipulate and navigate through the double-linked list using a series of commands.

### Key Features
1. **Double-Linked List Structure**:
   - Each node in the list (`ListElement`) contains a value, a pointer to the next node, and a pointer to the previous node.
   - The list is managed using head and tail pointers to keep track of the beginning and end of the list.

2. **Dynamic Memory Management**:
   - New nodes are dynamically allocated and properly linked to maintain the double-linked structure.
   - Nodes are safely removed and memory is deallocated to prevent memory leaks.

3. **Command-Line Interface**:
   - The program uses a set of commands to interact with the list. Commands are entered in the console and processed in real-time.
   - Supported commands include:
     - `i y B|E|n`: Initialize tab[y] to point to the head, tail, or nth element.
     - `+ n`: Move the nth tab to the next element.
     - `- n`: Move the nth tab to the previous element.
     - `. B|E|n y`: Add a new element with value `y` before the head, tail, or nth element.
     - `A B|E|n y`: Add a new element with value `y` after the head, tail, or nth element.
     - `R B|E|n`: Remove the head, tail, or nth element.
     - `P A|n`: Print the entire list or the value of the nth element.
