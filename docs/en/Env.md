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
docker run --rm -it \ \}
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
+docker run --rm -it -v C:\Users\user1\repo\spike-rt:/home/user1/repo/spike-rt -w /home/user1/repo/spike-r

Translated with DeepL.com (free version)