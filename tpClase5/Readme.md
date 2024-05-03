# Practical Work: Files and Semaphores

## Guidelines

### Exercise 1
An airline has two systems, one for CARGO and the other for RESERVATIONS:

a) CARGO. The cargo system allows loading flights with the following data:
FLIGHT (1000 to 1010)
DESTINATION (Cities)
NAME (Passenger's name)
Loading finishes with flight = 0, and a batch is generated in a file called batch.dat. This file should be created - if it does not exist - and data should be added to it if it exists (using semaphores).
It is possible to load any number of batches.

b) RESERVATIONS. The reservation system processes the reservations loaded in the batches. Each time a new batch is found, it processes it, updating the total reservations received on the screen:
(in all batches)
FLIGHT DESTINATION PASSENGERS
1001 BARAJAS 5
1002 CARACAS 2
Once batch.dat is processed, rename it as batch.999.dat (where 999 is a sequential sequence of batches received 000, 001, 002, etc.).

Important
• The solution must be developed in 2 processes communicated through 1 batch file (batch.dat) and using semaphores.
• The CARGO system is independent and can load batches as long as it can access the batch.dat file; otherwise, indicate that access is being awaited.
• The RESERVATIONS system checks for a new batch every 300 ms.

Notes:
• The program must be PROPERLY INDENTED.
• Use DEFINE for constants.
• Flight loading can be generated randomly.
