# Quick Start Guide (WIP!, TODO)
This section describes how to run the sample application for those who want to try it out.
See [DevelopApp.md](DevelopApp.md) for a detailed description of each task.

## Obtaining the source code
```bash
git clone https://github.com/spike-rt/spike-rt.git
cd spike-rt
````

## Build the development environment
Build the development environment according to [Env.md](Env.md).

## Build
### Configure (first time only)
```bash
mkdir -p build/obj-primehub_kernel
cd build/obj-primehub_kernel
... /... /asp3/configure.rb -T primehub_gcc -f -m ... /... /common/kernel.mk
cd ... /...
````bash

````bash
mkdir -p build/obj-primehub_led
cd build/obj-primehub_led
... /... /asp3/configure.rb -T primehub_gcc -L ... /obj-primehub_kernel -a ... /... /samples/ -A app -m ... /... /... /common/app.mk
```

### build
```bash
(cd ... /obj-primehub_kernel && make libpybricks.a && make libkernel.a) && rm -rf asp asp.bin && make && make asp.bin
```

## assemble
## write
````bash
PYTHON3=... /... /tools/python/bin/python3 sudo ... /... /scripts/deploy-dfu.sh asp.bin     
```


Translated with DeepL.com (free version)