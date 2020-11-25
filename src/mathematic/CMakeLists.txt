cmake_minimum_required (VERSION 3.17)

add_library (MathematicLib
             STATIC
                MathVector.cpp
                Matrix.cpp 
                MathVectorSize.cpp
                MatrixSize.cpp "MatrixService.cpp")