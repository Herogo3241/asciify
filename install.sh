#!/bin/bash

mkdir build/
cd build/
cmake ../ && make clean && make -j$(nproc) && sudo make install
cd ..

if [ -z "$XDG_CONFIG_HOME" ]
then
    CONFIG_DIR=$HOME/.config/asciify
else
    CONFIG_DIR=$XDG_CONFIG_HOME/asciify
fi
