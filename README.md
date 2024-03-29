# cmon

A command line tool to monitor for any changes in your C file and **automatically** recompile and execute it based on **gcc**. Be inspired by [nodemon](https://github.com/remy/nodemon).

See how it works: https://cmon.clang.cool

## Usage

```sh
cmon demo.c
```

## Install

#### On Windows

1. Click [here](https://github.com/tsq/cmon/releases/download/v1.0.1/cmon-setup.exe) to download `cmon-setup.exe`.
2. Double click the `cmon-setup.exe` and finish the installation.
3. Restart your PC
4. Open `Command Prompt` and test the installation:

```cmd
cmon -v
```

**Tip**: the installation directory is `C:\Program Files (x86)\cmon`.

#### On Linux
1. Run this command to download `cmon`: 

```sh
sudo curl -L "https://github.com/tsq/cmon/releases/download/v1.0.1/cmon" -o /usr/local/bin/cmon
```

2. Apply executable permissions to the binary:

```sh
sudo chmod +x /usr/local/bin/cmon
```

3. Test the installation:

```sh
cmon -v
```
#### On macOS

1. Run this command to download `cmon`: 

```sh
sudo curl -L "https://github.com/tsq/cmon/releases/download/v1.0.1/macos_cmon" -o /usr/local/bin/cmon
```

2. Apply executable permissions to the binary:

```sh
sudo chmod +x /usr/local/bin/cmon
```

3. Test the installation:

```sh
cmon -v
```

**Tip:** when you run the `cmon` command at first time, you maybe see an error dialog, the message is like this:

```
“cmon” cannot be opened because the developer cannot be verified.
```

to fix this problem, your should:

1. go to `System Preferences` > `Security & Privacy`.
2. click the `Click the lock to make changes` on the bottom then input your password or using Touch ID
3. click `Allow Anyway` right of the warning message `"cmon was blocked from use because it is not from an identified developer."`

## Why

This tool will made your **C-Learning-Life** happy.

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
## Pay attention

1. The `gcc` need to be available on your machine.
2. This tool just support `gcc` compiler no other compilers like clang.
3. It just supports compiling a single c file.
4. It doesn't support passing command-line arguments
