#!/bin/bash

if [ -f .gitmodules ] && [ -s .gitmodules ]; then
    echo "Configuring Submodules..."
    rm -rf ./Vendor
    mkdir ./Vendor
    cd Vendor
    git submodule update --init --recursive
else
    echo "No submodules found. Adding."
    if [ ! -d "./Vendor" ]; then
        echo "Creating Folder and adding Submodules."
        mkdir ./Vendor
    fi
    cd Vendor
    git submodule add https://github.com/google/googletest.git
    git submodule update --init --recursive
fi