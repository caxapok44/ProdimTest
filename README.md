# ProdimTest

ProdimTest is a C++ application that fits a circle to a set of 2D points using the Modified Least Squares method. This project demonstrates the use of CMake for building a C++ project and organizing the code into modular components.

## Features

- Circle fitting using the Modified Least Squares method
- Modular code structure with classes and headers
- Easy build system using CMake

## Prerequisites

Make sure you have the following installed on your system:

- **Git**: For cloning the repository.
- **CMake**: Version 3.10 or later.
- **A C++ compiler**: Compatible with C++17 (e.g., g++, clang++).

## Getting Started

### Clone the Repository

To get a copy of the project, clone the repository using Git:

```bash
git clone https://github.com/caxapok44/ProdimTest.git
cd ProdimTest
```

### Build the Project
After cloning the repository, follow these steps to build the project:

Create a build directory:

```bash
mkdir build
cd build
```
Run CMake to generate the build files:

```bash
cmake ..
```
Compile the project using make:

```bash
make
```
Run the Application
After building the project, you can run the application from the build directory:

```bash
./ProdimTest
```
Make sure the points.txt file is in the correct location, as the application reads the 2D points from this file to fit the circle.

## Customize points.txt
The application uses a file named points.txt in the project directory. You can modify this file to input your own 2D points. Each line in points.txt should contain two floating-point numbers separated by a space, representing the x and y coordinates of a point.

### Example points.txt
```plaintext
1.000    0.000
0.707    0.707
0.000    1.000
-0.707   0.707
-1.000   0.000
-0.707  -0.707
0.000   -1.000
0.707   -0.707
```