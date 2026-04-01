# transaction-reconciliation-system
C++ system to reconcile payment transactions with bank settlements and detect discrepancies like missing entries, duplicates, delays, and rounding errors.
Project: Transaction Reconciliation System
Author: Adinath Patil
Role: AI Native Engineer Assessment – Onelab Ventures

----------------------------------------
📌 Description:
This project reconciles transactions from a payments platform with bank settlements and identifies discrepancies such as:
- Missing settlements
- Late settlements
- Duplicate transactions
- Invalid refunds
- Rounding mismatches

----------------------------------------
⚙️ Requirements:
- C++ compiler (g++ recommended)
- Supports C++17 or above

----------------------------------------
▶️ How to Compile:
g++ main.cpp -o app

----------------------------------------
▶️ How to Run:
./app

----------------------------------------
📊 Output:
The program prints an analysis report showing:
- Missing settlements
- Late settlements
- Duplicate transactions
- Invalid refunds
- Rounding difference summary

----------------------------------------
📁 Files Included:
- main.cpp   → C++ source code
- README.txt → Instructions to run the project

----------------------------------------
⚠️ Notes:
- Data is generated inside the program (no external files required)
- Dates are in DD-MM format
- Matching is based on transaction ID
