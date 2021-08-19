# cmon

Monitor for any changes in your C file and automatically recompile and execute it. Be inspired by [nodemon](https://github.com/remy/nodemon)


## Why

Made your C-Learning-Life happy.

**before**

```sh
gcc demo.c -o demo # compile
./demo             # execute
111                # show result
                   # change the demo.c
gcc demo.c -o demo # compile
./demo             # execute
222                # show result
                   # change the demo.c
gcc demo.c -o demo # compile
./demo             # execute
333                # show result
  
...  
```

**now**

```sh
cmon demo.c        # compile and execute it
111 
                   # change the demo.c
222                # show result
                   # change the demo.c
333                # show result
```

## Install

1. download executable file: [For Windows](https://github.com/tsq/cmon/releases/download/v1.0.0/cmon.exe), [For macOS and Linux](https://github.com/tsq/cmon/releases/download/v1.0.0/cmon)

2. copy the download file to any directory which is already exists in the **PATH** 

## Note

1. The GCC should be available on your machine.
2. This tool just support GCC compiler no other compilers like clang.
