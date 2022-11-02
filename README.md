# Philosophers

The aim of this project is to become acquainted with threads, processes and semaphores.

## Overview

Here are the rules:
* One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table.
* The philosophers alternatively eat, think, or sleep. While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.
* There are also chopsticks on the table. There are as many chopsticks as philosophers.
* Because serving and eating spaghetti with only one chopstick is very inconvenient, a
philosopher takes their right and their left chopsticks to eat, one in each hand.
* When a philosopher has finished eating, they put their chopsticks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.
* Every philosopher needs to eat and should never starve.
* Philosophers don’t speak with each other.
* Philosophers don’t know if another philosopher is about to die.
* No need to say that philosophers should avoid dying!

## Usage

Clone the repository and go to one of the three directories. In the first one, the problem is solved using threads, whilst the
second uses semaphores and the third processes. Then execute the following, changind the arguments as you like:
```shell
make
./a.out <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> <number_of_times_each_philosopher_must_eat>
```

The last argument is optional.

## Status

Finished :white_check_mark:
