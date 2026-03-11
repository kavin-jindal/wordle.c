# wordle.c
A terminal-based Wordle clone written in C.

## How to Play

- Guess the hidden 5-letter word in **6 attempts**
- Only **uppercase** letters are accepted
- After each guess, letters are colored to give feedback according to the original Wordle game:
  - 🟩 **Green** — correct letter, correct position
  - 🟨 **Yellow** — correct letter, wrong position
  - ⬜ **Gray** — letter not in the word

## Setup

**Prerequisites:** GCC and a `words.txt` wordlist in the same directory (one word per line).
```bash
gcc wordle.c -o wordle
./wordle
```

## Note
I built the project while learning C, and it took me nearly 5-6 hours to complete. Coding this game was a good logic-building exercise and gave me more knowledge of C programming than any tutorial possibly could. Not to ignore the hours of scrolling through StackOverflow and documentation, considering I kept the use of AI down to the very minimum and only used Claude for debugging and troubleshooting in times of dire need.






