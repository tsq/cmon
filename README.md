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

#### On macOS or Linux

**by curl**

```sh
curl -o xxx.sh
```

**by wget**

```sh
```

**by source code**

```sh
```

#### On Windows

```

```

## TODO

You can skip the file name if there is only one c file on current directory.

```
cmon app.c
y [cmon] 2.0.6
y [cmon] watching file: 
11
g [cmon] starting `recompile and reexecute`
22
```

```

```