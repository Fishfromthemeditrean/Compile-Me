cmake_minimum_required(VERSION 3.22.1)

# Name your project
project(MyAndroidLibrary)

# Specify your C++ source files here (replace main.cpp with your actual file names)
add_library(native-lib SHARED 
    test.cpp
)

# Optional: Link native Android logging libraries if you need them
find_library(log-lib log)
target_link_libraries(native-lib ${log-lib})
