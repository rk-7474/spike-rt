mkdir -p build/obj-primehub_kernel
cd build/obj-primehub_kernel
../../asp3/configure.rb -T primehub_gcc -f -m ../../common/kernel.mk
make libpybricks.a && make libkernel.a &&
cd -

mkdir -p build/obj-primehub_main
cd build/obj-primehub_main
../../asp3/configure.rb -T primehub_gcc -L ../obj-primehub_kernel -a ../../programs/main/ -A motor -m ../../common/app.mk
make -j4& make asp.bin
cd -
