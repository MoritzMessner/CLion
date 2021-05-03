project(CLion)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wall -Wextra -Werror")

add_executable(aufgabe1 Aufgabe1/main.cpp Aufgabe5/Aufgabe5.cpp Aufgabe5/Aufgabe5.h)
add_executable(aufgabe1Exe Aufgabe1/Aufgabe1.cpp)
add_executable(aufgabe2Exe Aufgabe2/Aufgabe2.cpp)
add_executable(aufgabe3Exe Aufgabe3/Date.cpp Aufgabe3/Aufgabe3.cpp Aufgabe3/Person.cpp Aufgabe3/Person.h)
add_executable(aufgabe4Exe Aufgabe4/Aufgabe4.cpp Aufgabe4/Date.cpp Aufgabe4/Date.h Aufgabe4/Person.cpp Aufgabe3/Person.h)
add_executable(aufgabe5Exe Aufgabe5/Aufgabe5.cpp Aufgabe5/Aufgabe5.h Aufgabe5/Date.cpp Aufgabe5/Date.h Aufgabe5/Person.cpp Aufgabe5/Person.h Aufgabe5/Friends.cpp Aufgabe5/Friends.h)
add_executable(05 05/main.cpp 05/Date.cpp 05/Date.h 05/Person.cpp 05/Person.h 05/Friends.cpp 05/Friends.h)
add_executable(aufgabe6Exe Aufgabe6/Aufgabe6.cpp Aufgabe6/Aufgabe6.h Aufgabe6/Date.cpp Aufgabe6/Date.h Aufgabe6/Person.cpp Aufgabe6/Person.h Aufgabe6/Friends.cpp Aufgabe6/Friends.h)