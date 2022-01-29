ROOT=../../
PASS_PATH=${ROOT}build/HelloWorld/libHelloWorld.so
clang -Xclang -load -Xclang ${PASS_PATH} example.cpp
