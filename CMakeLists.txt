project(CLion)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wall -Wextra -Werror")

add_executable(aufgabe1Exe Aufgabe1/Aufgabe1.cpp)
add_executable(aufgabe2Exe Aufgabe2/Aufgabe2.cpp)
add_executable(aufgabe3Exe Aufgabe3/Date.cpp Aufgabe3/Aufgabe3.cpp Aufgabe3/Person.cpp Aufgabe3/Person.h)
add_executable(aufgabe4Exe Aufgabe4/Aufgabe4.cpp Aufgabe4/Date.cpp Aufgabe4/Date.h Aufgabe4/Person.cpp Aufgabe3/Person.h)
add_executable(aufgabe5Exe Aufgabe5/Aufgabe5.cpp Aufgabe5/Aufgabe5.h Aufgabe5/Date.cpp Aufgabe5/Date.h Aufgabe5/Person.cpp Aufgabe5/Person.h Aufgabe5/Friends.cpp Aufgabe5/Friends.h)
add_executable(aufgabe6Exe Aufgabe6/Aufgabe6.cpp Aufgabe6/Aufgabe6.h Aufgabe6/Date.cpp Aufgabe6/Date.h Aufgabe6/Person.cpp Aufgabe6/Person.h Aufgabe6/Friends.cpp Aufgabe6/Friends.h)
add_executable(aufgabe7Exe Aufgabe7/Aufgabe7.cpp Aufgabe7/Aufgabe7.h Aufgabe7/Vector.cpp Aufgabe7/Date.cpp Aufgabe7/Date.h Aufgabe7/Person.cpp Aufgabe7/Person.h Aufgabe7/Friends.cpp Aufgabe7/Friends.h)
add_executable(aufgabe8Exe Aufgabe8/Aufgabe8.cpp Aufgabe8/Aufgabe8.h Aufgabe8/Date.cpp Aufgabe8/Date.h Aufgabe8/ArrayList.cpp Aufgabe8/ArrayList.h Aufgabe8/Person.cpp Aufgabe8/Person.h)
add_executable(aufgabe9Exe Aufgabe9/Aufgabe9.cpp Aufgabe9/Aufgabe9.h)
add_executable(aufgabe10Exe Aufgabe10/main.cpp)
add_executable(aufgabe11Exe Aufgabe11/main.cpp)