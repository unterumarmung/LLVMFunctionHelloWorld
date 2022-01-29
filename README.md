# LLVM out-of-source hello world

This repository contains a simple example of LLVM pass that written out of source of LLVM

## Build

1. Install dependencies

```
sudo apt install llvm-dev
```

2. Build the pass

```
mkdir build && cd build && cmake .. && make && cd ..
```

3. Run 
    * Example 
        ```
        cd example/simple && ./run.sh
        ```
    * Your own file
        ```
        clang -Xclang -load -Xclang <path to lib>/libHelloWorld.so <your file>
        ```