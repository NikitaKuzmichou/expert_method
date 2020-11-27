cmake_minimum_required (VERSION 3.17)

add_library (MathematicLib
             STATIC
                MathVector.cpp
                MathVectorSize.cpp
                MathVectorService.cpp
                Matrix.cpp
                MatrixSize.cpp
                MatrixService.cpp)