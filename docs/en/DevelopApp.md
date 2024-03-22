# How to develop an application
Describe the sequence of steps in application development.

## Obtain source code
Clone the source code as follows.
```bash
git clone git@github.com:spike-rt/spike-rt.git
cd spike-rt
git submodule update --init . /external/.
```
Hereinafter, unless otherwise noted, the top directory is the `spike-rt` directory.
The application source code directory is located in `spike-rt/$appdir`.


## Setting up the development environment
Build the development environment according to [Env.md](Env.md).

## Build
Generate target binaries on the container.
Since the Makefile templates used are different, configure and build the kernel and the application separately.

### Start the container.
```bash
docker run --rm -it -v $(pwd):$(pwd) -w $(pwd) spike-rt-builder /bin/bash
```

### config (first time only)
Before building, a Makefile for building is generated from a template. This is necessary only for the first time.
It is assumed that the kernel and application are built separately.

Generating the Makefile for the kernel
```bash
mkdir -p build/obj-primehub_kernel
cd build/obj-primehub_kernel
... /... /asp3/configure.rb -T primehub_gcc -f -m ... /... /common/kernel.mk
cd ... /...
````

Generate Makefile for the application.
```bash
mkdir -p build/obj-primehub_$appname
cd build/obj-primehub_$appname
... /... /asp3/configure.rb -T primehub_gcc -L ... /obj-primehub_kernel -a ... /... /$appdir/ -A $appname -m ... /... /common/app.mk
cd ... /...
```

### Build
On the host, run the following to move the current directory to the build directory of the app.
````bash
cd build/obj-primehub_$appname
```
The following will cause
```bash
(cd ... /obj-primehub_kernel && make libpybricks.a && make libkernel.a) && rm -rf asp asp.bin && make && make asp.bin
````
This command is also good for re-building and re-linking.

### Example
Example of building ``sample/motor``, a sample motor application.

```bash
docker run --rm -it -v $(pwd):$(pwd) -w $(pwd) spike-rt-builder /bin/bash

mkdir -p build/obj-primehub_kernel
cd build/obj-primehub_kernel
... /... /asp3/configu

Translated with DeepL.com (free version)