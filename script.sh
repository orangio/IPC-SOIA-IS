#!/bin/bash
ipcs
./sender&
./reader
killall -9 sender
ipcs
ipcrm -Q 8888 #insert your key here
