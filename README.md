# TREATMENT MANAGEMENT

Treatment Management System
The Treatment Management System is a simple, terminal-based application developed in C for managing patient treatment records efficiently. The system provides fundamental functionalities including adding new treatment details, searching for treatments by ID or patient name, updating existing treatment records, and deleting entries when necessary. All treatment information is stored persistently in a binary .dat file, ensuring that data remains available across multiple sessions. Designed for ease of use, the program offers a menu-driven interface suitable for beginners and small-scale healthcare setups. The project demonstrates basic concepts of file handling, data structures, and control flow in C, providing a practical solution for managing treatment data in a lightweight and accessible format.

Features of the Program
- Add new treatment records with details (patient ID, diagnosis, prescribed medicines, dosage, duration, doctor’s notes, etc.)
- View all stored treatment records in a clean, organized list
- Search for treatments by treatment ID or patient name
- Update existing treatment information (e.g., change medication or dosage)
- Delete treatment records from the database
- Persistent data storage using a .dat file
- Fully terminal-based (CLI) interface
- Beginner-friendly, easy-to-understand C program structure
- Automatically creates the data file if it doesn’t exist
- Basic error handling for invalid input and missing files

Technical Requirements
1. System Requirements
- Operating System: Windows / Linux / macOS
- Terminal/command-line environment
- Minimum RAM: 4 MB
- Minimal disk space for the .dat file
2. Software Requirements
- C Compiler: GCC / MinGW / Clang / MSVC
- Any text editor or IDE (VS Code, Code::Blocks, Dev-C++, Vim, etc.)
- Optional: Make tool if using a Makefile
3. Programming Requirements
- Language: C
- Supported C Standards: C89 / C99 / C11
- Standard libraries required:
- <stdio.h>
- <stdlib.h>
- <string.h>
4. File Handling Requirements
- Read/write access to the working directory
- Treatment records stored in a binary .dat file
- Program creates the data file automatically if missing
5. Compilation Requirements
- Code should compile without errors
- Recommended flag: -Wall to show warnings

Functional Requirements
1. User Interface
- Operates entirely through the terminal
- Clearly displays all menu options
- Accepts and validates user inputs
2. Treatment Record Operations
- Add Treatment: Enter and save new treatment information
- Search Treatment: Find records by treatment ID or patient name
- View Treatments: Display all stored records
- Update Treatment: Modify existing treatment details
- Delete Treatment: Remove a record from the database
3. Data Management
- Stores all information in a persistent .dat file
- Ensures data remains available across multiple sessions
- Handles missing or new data files smoothly
4. Program Flow
- Uses a menu-driven loop until user selects Exit
- Provides confirmation and error messages
- Smooth navigation between different options

  5. screenshots
     <img width="498" height="476" alt="Screenshot 2025-11-24 212000" src="https://github.com/user-attachments/assets/f9d8371e-e207-43cc-8b54-a799991e933f" />
<img width="737" height="411" alt="Screenshot 2025-11-24 212017" src="https://github.com/user-attachments/assets/bbffe817-d941-4ab8-a41a-1bc82d0b1475" />
<img width="473" height="269" alt="Screenshot 2025-11-24 212032" src="https://github.com/user-attachments/assets/17ed624a-90a0-4914-ad39-d47239ecd8ae" />
<img width="476" height="285" alt="Screenshot 2025-11-24 212047" src="https://github.com/user-attachments/assets/babb63bd-0edc-413c-b6dc-cb547a9b8188" />
<img width="423" height="449" alt="Screenshot 2025-11-24 212111" src="https://github.com/user-attachments/assets/a4fc8ec2-e09d-4762-a6f3-9c9fbc73cd45" />




How to Run the Program
- Compile the Program
Open your terminal inside the project directory and run:
gcc treatment_management.c -o treatment_management
- Run the Executable
- On Linux/macOS:
./treatment_management
- On Windows:
treatment_management.exe
- Data File
- The program automatically creates treatments.dat if it doesn't already exist
- All treatment records are saved and retrieved from this file



👉 This mirrors the Patient Management System model but focuses on treatment records instead of patient demographics.
Would you like me to also draft the C program skeleton code (with structures, menu, and file handling) for this Treatment Management System so you can directly compile and run it?
