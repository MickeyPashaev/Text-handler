# Text Processing Program

**Course Work – Option 4.6**

## Description

This console program reads text from `stdin`, performs one selected operation, prints the result to `stdout`, and terminates.
At startup, the program must print:
`Course work for option <V>, created by <Name> <Surname>.`
After printing this line, the program waits for a command number.

---
## Commands
- `0` – print text after mandatory preprocessing
- `1` – count word occurrences
- `2` – reverse characters in every word
- `3` – remove sentences containing a comma
- `4` – sort sentences
- `5` – print help

For commands `0–4`, text input follows the command.  
Text ends with two consecutive newline characters (`\n\n`).  
For command `5`, no text is required.

---

## Text Rules

- Sentences are separated by a dot (`.`).
- Each sentence is printed on a separate line.
- Words consist of Latin letters, digits, and `-`.
- All other characters are treated as separators.
- Duplicate sentences are removed (case-insensitive comparison).

---
## Operations
### 1 — Word Counting
Counts occurrences of each word (case-insensitive).  
Output format:
`word : count`
Words are printed in lowercase and in order of first appearance.

---
### 2 — Reverse Words
Reverses characters in each word while preserving separators and sentence structure.

---
### 3 — Remove Sentences with Comma
Deletes all sentences containing `,`.

---
### 4 — Sort Sentences
Sorts sentences in descending order by the value of the 5th character:
- If the 5th character is a separator, the next non-separator is used.
- If a sentence has fewer than 5 characters, its value is `-1`.
- Stable sorting is required.
- Standard library sorting functions must be used.

---
## Error Handling
If an operation cannot be performed:
`Error: <reason>`
The program then terminates.

---
## Build
If a `Makefile` is used, the executable must be named:
`cw`

Example:
`make ./cw`

