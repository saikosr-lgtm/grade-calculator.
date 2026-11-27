# Coding rules for Grade Calculator (C++)

## Rule 1. Variable names use camelCase
The first word is lowercase, every next word starts with a capital letter.
Example: `double classTotal = 0;` (not `class_total` or `ClassTotal`)

## Rule 2. Indentation is 4 spaces
Every block inside `{ }` is moved 4 spaces to the right.
Example:

    for (int i = 1; i <= 5; i++) {
        cin >> score;
    }

## Rule 3. Names must be meaningful
A name explains what the variable stores. No single letters except loop counters.
Example: `int studentCount = 0;` (not `int x = 0;`)

## Rule 4. Comments explain each main step
Put a short comment above each important part of the program.
Example: `// Calculate the average of 5 scores`

## Rule 5. One statement per line, maximum 100 characters per line
Example:

    sum = sum + score;
    count++;

(not `sum = sum + score; count++;` on one line)
