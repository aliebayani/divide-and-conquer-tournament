# divide-and-conquer-tournament
Algorithm Design university course exercise implementing tournament scheduling with a divide-and-conquer approach for 2^n teams. (2020)

# Tournament Scheduler

This is a simple C++ program that simulates a tournament scheduler using a divide-and-conquer approach. It schedules matches between teams in a round-robin format.

## Description

This project implements a tournament scheduling algorithm using the divide-and-conquer approach for a tournament involving 2^n teams. According to this method, matches are scheduled first for 2 teams, then for 4 teams, then for 8 teams, and so on, until all teams have played against each other.

## Usage

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/aliebayani/divide-and-conquer-tournament.git
    ```

2. Compile the program using a C++ compiler. For example, using g++:

    ```bash
    g++ main.cpp -o tournament
    ```

3. Run the executable:

    ```bash
    ./tournament
    ```

4. Follow the prompts to enter the names of the teams participating in the tournament.

5. The program will schedule and simulate matches between teams, printing the matches to the console.

## Requirements

- C++ compiler (e.g., g++)
- Git (optional, for cloning the repository)

© 2022 Ali Bayani
