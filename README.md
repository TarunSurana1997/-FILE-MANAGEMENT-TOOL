#  FILE MANAGEMENT TOOL

*COMPANY*: CODTECH IT SOLUTIONS

*NAME*: TARUN SURANA

*INTERN ID*: CT12KDX

*DOMAIN*: C++ PROGRAMMING

*DURATION*: 8 WEEEKS

*MENTOR*: NEELA SANTOSH

*DESCRIPTON OF THE TASK*

This C++ program is a simple file handling utility that allows users to perform basic file operations such as writing to a new file, reading from an existing file, and appending content to an existing file.
The program is designed with a user-friendly interface, utilizing ANSI escape codes to add colors and styles to the terminal output, making it visually appealing and easier to navigate.

Key Components of the Code:
1. ANSI Escape Codes:
    The program uses ANSI escape codes to format the terminal output. These codes are stored in string constants like RESET, BOLD, RED, GREEN, etc.

    They are used to change the text color, background color, and text style (e.g., bold) in the terminal.

    For example, RED changes the text color to red, and BOLD makes the text bold.

2. Main Function:

    The main() function is the entry point of the program. It displays a menu to the user and processes their choice.

    The menu options include writing to a file, reading from a file, appending to a file, and exiting the program.

    The program runs in a loop until the user chooses to exit.

3. Menu Display:

    The displayMenu() function prints the main menu with options for the user to choose from.

    The menu is styled with colors and borders to make it visually distinct.



4. File Operations:
   
  a. Writing to a File: The handleWrite() function allows the user to create a new file and write content to it.
    The user is prompted to enter a filename and then input content line by line. The input ends when the user types "END" on a new line.
    The content is then saved to the specified file.

b. Reading from a File: The handleRead() function lets the user read the contents of an existing file.
   The user provides the filename, and the program reads and displays the file's content line by line.

c. Appending to a File: The handleAppend() function allows the user to add content to an existing file without overwriting its current content.
    Similar to the write operation, the user inputs content line by line, ending with "END".

5. User Interaction:
   
The program uses cin and getline() to interact with the user.

It also includes error handling to manage cases where files cannot be opened or created.

For example, if a file cannot be opened, an error message is displayed in red.

6. Screen Clearing:
   
The clearScreen() function uses ANSI escape codes to clear the terminal screen, providing a clean slate for new output.

This is used before displaying the menu or any file content to avoid clutter.

7. Header and Styling:

The printHeader() function displays a styled header with the program's name, "FILE HANDLER," at the top of the screen.

This adds to the program's aesthetic appeal and provides a clear indication of the program's purpose.

Workflow:
1. The program starts by displaying a colorful header and menu.

2. The user selects an option (write, read, append, or exit).

3. Depending on the choice, the program performs the corresponding file operation.

4. After each operation, the program pauses and waits for the user to press Enter before returning to the main menu.

5. The loop continues until the user chooses to exit.

Error Handling:

The program checks if files can be opened or created successfully.

If not, it displays an error message and returns to the main menu.

Conclusion:

This program is a practical example of how to create a simple, interactive command-line tool in C++.

It demonstrates file handling, user input, and terminal formatting using ANSI escape codes.

The use of colors and styles enhances the user experience, making the program more engaging and easier to use.

#OUTPUT
