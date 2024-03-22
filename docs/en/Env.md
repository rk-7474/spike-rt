# Building a development environment
- This section assumes that the environment is built on WSL2 (Windows), Mac, and Ubuntu (Linux).
- We will show you how to build only on an application container (e.g. Docker).
- For Linux, Ubuntu is assumed.
- For Mac, Docker Desktop for Mac is assumed.
- Docker Desktop for Windows is also reported to work.

Each work:
| Work contents | Execution method
| :--- | :--- | Coding | Any editor (e.g., Docker Desktop for Windows)
| Coding | Any editor (host) | [build](build)(build)(build)(build)(build)(build)(build)(build)
| [build](#build environment) | compiler (container) |
| [write](#build write environment) | python3 (host) |
| [serial communication](#serial communication)(optional) | minicom etc. (host) |
| [Bluetooth serial communication](#Bluetooth serial communication)(optional) | Google Chrome etc. (host) |


## Build environment
### Pull container image
Pull a `slim` or `rich` version of the container.
We assume that you will choose the `rich` version unless you have a communication line or capacity reasons.
```bash
docker pull ghcr.io/spike-rt/spike-rt:rich
```

### Starting and attaching containers
When building, mount the source code in a container, and launch and attach the container.

#### Linux or WSL2(Windows)
Execute the following.
The second option line mounts the source code and specifies it as a work directory.
The third option solves the file permission problem.
```bash
docker run --rm -it \
  -v $(pwd):$(pwd) -w $(pwd) \
  -u "$(id -u $USER):$(id -g $USER)" -v /etc/passwd:/etc/passwd:ro -v /etc/group:/etc/group:ro \
  ghcr.io/spike-rt/spike-rt:rich /bin/bash
```

#### For Mac
On Docker Desktop for Mac, run the following.
This command does not seem to cause file permission problems.
```bash
docker run --rm -it -v $(pwd):$(pwd) -w $(pwd) ghcr.io/spike-rt/spike-rt:rich /bin/bash
```

#### * On Windows (non-WSL2, using Docker Desktop for Windows directly)
Since the path notations on the host and container sides are different, specify the full path for each.
Here, the user name is user1, and spike-rt is git cloned to C:\Users\users\users\repo

```winbatch
+docker run --rm -it -v C:\Users\user1\repo\spike-rt:/home/user1/repo/spike-rt -w /home/user1/repo/spike-rt ghcr.io/spike-rt/spike-rt:rich  /bin/bash
```

## Set up writing environment
Assuming that writing to Prime Hub is done on the host side.  
PyUSB(Python3) is used for writing.

### Preparations for PyUSB installation
Preparations are required for WSL2(Windows) and Mac.

#### For WSL2(Windows)
Follow [Connecting USB Devices | Microsoft Docs](https://docs.microsoft.com/ja-jp/windows/wsl/connect-usb) to enable USB devices to be connected from WSL2 via USB/IP. 

Attach the Prime Hub USB to WSL2 as follows.
```powershell
usbipd wsl attach --busid <busid>
```

If you do not see any USB devices in `usbipd wsl list`(PowerShell) or `lsusb`(WSL2), check if the `3240/tcp` port is blocked by the firewall on Windows side.
 
#### For Mac
Install the dependent libraries of PyUSB
Run 
```bash
brew install libusb
```

### Installing PyUSB
Install the required package PyUSB ([PyPI](https://pypi.org/project/pyusb/), [GitHub](https://github.com/pyusb/pyusb)) with the following command.  
To avoid polluting the host python environment, install under the venv environment. In this example, the installation is performed in `./tools/python/`. 
```bash
python3 -m venv ./tools/python
./tools/python/bin/pip install pyusb
```

## Serial communication
Serial communication via USB or USART (Port F) is described.
For Bluetooth, see [Bluetooth serial communication](#Bluetooth serial communication).

It is assumed that `minicom` is used for serial communication with Hub.  
Install `minicom` as follows.

In case of WSL2(Windows) or Ubuntu(Linux)
```bash
sudo apt install minicom
```

On Mac
```bash sudo apt install minicom
brew install minicom
```

## Bluetooth serial communication
SPIKE-RT reuses Pybricks device drivers.
Currently, only Bluetooth connection via Pybricks' [Web IDE](https://beta.pybricks.com/) is supported.

Pybricks' [Web IDE](https://beta.pybricks.com/) does not support Firefox or other browsers.
Use Google Chrome or Chromium browser.
