# ATM Simulation Project

## Description
Console-based ATM mimicking real banking with OOP in C: constructors, enums, file I/O. [file:1]

## Features
- Account creation with initial balance
- Menu: Check Balance, Deposit, Withdraw, Exit (via enum)
- Persistent transaction logging

## Requirements
- C Compiler: GCC/MinGW/Clang
- Editor: VS Code/Code::Blocks
- 2GB RAM minimum [file:1]

## Build & Run
1. `gcc atm_simulation.c -o atm_sim`
2. `./atm_sim`
3. Check `transactions.txt` for logs

## Architecture
- `Account` struct + constructor
- Enum-driven menu
- File handling for persistence [file:1]
