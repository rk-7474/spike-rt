mkdir -p build/obj-primehub_motor
cd build/obj-primehub_motor
../../asp3/configure.rb -T primehub_gcc -L ../obj-primehub_kernel -a ../../sample/motor/ -A motor -m ../../common/app.mk
make -j4& make asp.bin
cd -
