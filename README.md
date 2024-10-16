# CLI Arithmetic Parser Using C++
This Github Repository contains all relevant artifacts to Group 22's EECS348 term project: a Command Line Interface (CLI) arithmetic parser.

## Overview
The CLI Arithmetic Parser is a simple yet powerful tool that evaluates mathematical expressions inputted by the user. It supports the following operations:

  - Addition (+)
  - Subtraction (-)
  - Multiplication (*)
  - Division (/)
  - Floor Division (//)
  - Modulus (%)

The parser handles operator precedence and properly evaluates expressions with parentheses.
## Features

  - Supports Multiple Operations: Evaluate expressions with addition, subtraction, multiplication, and division.
  - Parentheses Handling: Correctly evaluates expressions with nested parentheses.
  - User-Friendly CLI: Easy to use via the command line.

## Installation
To get started with the CLI Arithmetic Parser:

  __1. Clone the Repository:__
```
git clone https://github.com/jannadungao/EECS-348-Group-22
cd EECS-348-Group-22
```
  __2. Build the Project:__ Ensure you have the gcc/g++ compiler installed on your computer.
```
g++ -o arithmetic_parser main.cpp
```

## Usage
```
./arithmetic_parser
```

## Example
```
Enter an expression: (3 + 4) * 2
Result: 14
```
