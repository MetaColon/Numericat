![C/C++ CI](https://github.com/MetaColon/Numericat/workflows/C/C++%20CI/badge.svg?branch=Develop)

# Numericat
Numerical solution of the Schrödinger equation for arbitrary potentials and visualisation of the results.

This project will consist of three parts:
* Parsing of an arbitrary one dimensional potential function (C)
* Numerically solving the time dependent Schrödinger equation by using the Crank-Nicolson method (C)
* Visualising the results (Java)

Currently functional:
* Basic parsing of functions

Supported platforms:
* Linux
* MacOS
* Eventually Windows (not actively tested, some changes might have to be made to the Makefile)

## Use
Prerequisities:
* Make
* Some sort of C compiler (e.g. `gcc`)
* A Java 8 or higher JDK (e.g. OpenJDK 8)
Install:
* Install using `make` (not yet fully supported)
