#!/bin/bash

OUTFILE="formatter"

CXX="g++"
CXX_FLAGS="-g -std=c++11 -Wall -pedantic"
CXX_OUT="-o $OUTFILE"
SRC="main.cpp NumberFormatter.cpp"

"$CXX" $CXX_FLAGS $CXX_OUT $SRC

"./$OUTFILE" <&0
