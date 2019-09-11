web_video_server [![Build Status](https://api.travis-ci.org/RobotWebTools/web_video_server.png)](https://travis-ci.org/RobotWebTools/web_video_server)
================

#### HTTP Streaming of ROS Image Topics in Multiple Formats
This node combines the capabilities of [ros_web_video](https://github.com/RobotWebTools/ros_web_video) and [mjpeg_server](https://github.com/RobotWebTools/mjpeg_server) into a single node.

For full documentation, see [the ROS wiki](http://ros.org/wiki/web_video_server).

[Doxygen](http://docs.ros.org/indigo/api/web_video_server/html/) files can be found on the ROS wiki.

This project is released as part of the [Robot Web Tools](http://robotwebtools.org/) effort.

### Dependencies for using NVENC in FFmpeg (for desktop pc)

> You can also use [this installation script](https://github.com/corenel/env-setup/blob/master/packages/install_ffmpeg.sh).

1. Clone the FFmpeg git repository https://git.ffmpeg.org/ffmpeg.git 
2. Download and install a compatible driver (418.30 or newer for NVIDIA Video Codec SDK 9.0.18) from the NVIDIA [web site](https://www.nvidia.com/drivers) 
3. Download and install the [CUDA toolkit](https://developer.nvidia.com/cuda-toolkit) 
4. Clone the `nv-codec-headers` [repository](https://github.com/FFmpeg/nv-codec-headers)  and install using this repository as header-only: `sudo make install`
5. Configure FFmpeg using the following command (use correct CUDA library path):

```
/configure --enable-cuda --enable-cuvid --enable-nvenc --enable-nonfree --enable-libnpp --enable-gpl --enable-libx264 --enbale-libx265 --extra-cflags=-I/usr/local/cuda/include  --extra-ldflags=-L/usr/local/cuda/lib64
```

6. Build with multiple processes to increase build speed and suppress excessive output: `make -j -s`
7. Install built FFmpeg: `sudo make install`

### Increase encoder sessions for NVIDIA GPUs

Use [this repo](https://github.com/keylase/nvidia-patch) to patch NVIDIA driver.

### License
web_video_server is released with a BSD license. For full terms and conditions, see the [LICENSE](LICENSE) file.

### Authors
See the [AUTHORS](AUTHORS.md) file for a full list of contributors.
