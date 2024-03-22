# Tests
This section describes how to run tests on SPIKE-RT itself.

## Test implementation
[test/](... /... /test) is where the tests are implemented. The test framework Unity is used to realize the tests.  
See [external/Unity/README.md](https://github.com/ThrowTheSwitch/Unity/tree/0b899aec14d3a9abb2bf260ac355f0f28630a6a3) for more information about Unity.

## Building the test
You can build the test in the same way as an application.
You can build it by referring to [DevelopApp.md](DevelopApp.md), or by using the script [scripts/build-test.sh](... /...). /... /scripts/build-test.sh) to simplify the build process.
```bash
. /scripts/build-test.sh
```

## Connect PUP devices
[test/test_config.h](... /... //test/test_config.h) to connect the PUP device.  
However, it is possible to confirm the operation by seeing `a` on the LED matrix display without connecting the PUP device.

## Writing
Refer to [DevelopApp.md#Writing](DevelopApp.md#Writing). However, replace `obj-primehub_app` with `obj-primehub_test`.

## Serial communication
Test results can be checked by serial communication via USART at Port F.
Connect as follows.
```bash
sudo minicom -D /dev/ttyACM0 -b 115200
````

## Reboot the Hub & verify operation
Reboot the Hub, wait 10 seconds, and if you see the following on the serial output, the test was successful
```bash
.....

-----------------------
7 Tests 0 Failures 0 Ignored 
```
