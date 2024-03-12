# Dependencies
## Git Submodules
This repository uses both [libbpf](https://github.com/libbpf/libbpf/) [libxdp](https://github.com/xdp-project/xdp-tools/) as git-submodules
```
git submodule update --init
```
## Install Packages
### Packages on Fedora
```
$ sudo dnf install clang llvm
$ sudo dnf install elfutils-libelf-devel libpcap-devel perf glibc-devel.i686 m4 pkg-config
```
Fedora by default sets a limit on the amount of locked memory the kernel will allow, which can interfere with loading BPF maps. Use this command to raise the limit:
```
# ulimit -l 1024
```
## Build Submodules
Before compiling libxdp, you need to install libbpf on your system. See more on [libbpf's](https://github.com/libbpf/libbpf) readme.
Assume you are in your workspace and already added libbpf as a submodule:
```
$ cd libbpf/src/
$ make
```
Then go back to root, you can build xdp-tools:
```
$ cd xdp-tools/
$ ./configure
$ make
```
# Loading XDP Program
Compile the kernel space file:
```
$ make
```
Add the executable of xdp-loader to your path:
```
$ cd xdp-tools/xdp-loader/
$ sudo cp xdp-loader /usr/local/bin
```
Now you can load xdp programs using xdp-loader, for example:
```
$ sudo xdp-loader load -m skb lo xdp_redir_kern.o 
```
After loading your xdp program into the kernel, you can remove the object file:
```
$ make clean
```