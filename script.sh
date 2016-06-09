#!/bin/bash

./sender&
./reader
killall -9 sender
ipcrm -Q 8888 #insert your key here
