# Snake-game-in-c

# Snake Game

A simple console-based Snake game implemented in C.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [How to Play](#how-to-play)
- [Requirements](#requirements)
- [Build and Run](#build-and-run)
- [Controls](#controls)
- [Game Rules](#game-rules)
- [Acknowledgments](#acknowledgments)

## Introduction

This Snake game is a console-based application written in C. The game provides a classic Snake experience where the player controls a snake, guiding it to eat apples and grow longer while avoiding collisions with itself and the game borders.

## Features

- Simple and intuitive gameplay.
- Dynamic board with a growing snake.
- Randomly generated apples for the snake to consume.
- Win condition for reaching a certain snake length.
- Lose condition for collisions with the snake's own body or the game borders.

## How to Play

1. Clone or download the repository.
2. Build the project using a C compiler.
3. Run the executable to start the game.

## Requirements

- C compiler (e.g., GCC)
- Windows operating system

## Build and Run

To build and run the Snake game, follow these steps:

```bash
gcc SnakeGame.c snake.c -o SnakeGame
./SnakeGame
```

Note: Ensure that you have a C compiler installed on your system.

## Controls

- **1:** Move the snake up
- **2:** Move the snake down
- **3:** Move the snake left
- **4:** Move the snake right

## Game Rules

1. The snake starts with a length of 1.
2. Control the snake to eat apples ('@') on the board.
3. The snake grows longer with each apple consumed.
4. Avoid collisions with the snake's own body and the game borders.
5. Win the game by reaching a specified snake length.
6. Lose the game if the snake collides with itself or the borders.

## Acknowledgments

- The game was created as a simple project for learning C programming.
- Inspired by classic Snake games.

Feel free to customize and expand upon this readme as needed. Enjoy playing the Snake game!
