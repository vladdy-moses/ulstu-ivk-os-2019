#!/bin/bash

g++ send_2.c -o send_2.out
g++ receive_2.c -o receive_2.out

./send_2.out
ipcs -q
./receive_2.out
