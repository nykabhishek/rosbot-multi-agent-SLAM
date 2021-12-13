# Multi-agent SLAM using ROSBots
A ROS package for multi agent SLAM using ROSBots by Husarion

![ROSBot2](rosbots.jpeg)

## Overview ##
This package contains launch files and nodes needed for collaborative SLAM by multiple agents in an unknown environment using ROSBots by Husarion.

## Dependencies ##
Environment
- `Ubuntu 18.04`
- `ROS Melodic`

ROS packages:
- `husarion_ros`
- `rosbot_description`
- `rosbot_ekf`
- `multirobot_map_merge`
- `gmapping`
- `explore_lite`
- `rplidar ros`

## Setup ##
A single central computer will act as a central hub (ROS master) and all the ROSBots will communicate with it by connecting to a common LAN network. This can also be acieved by [Husarnet](https://husarnet.com/) (a Peer-to-Peer VPN client) which uses Internet as the communication medium instead of the LAN network. Steps on setting up the communication network can be found [here](https://husarion.com/tutorials/ros-tutorials/5-running-ros-on-multiple-machines).

## Launching the autonomous mapping system
The central hub is used to SSH into each of the ROSbots to launch the required nodes.

Run the following commands on each ROSBots:
On ROSBot 1:
```
    roslaunch multi_rosbot_SLAM robo1_explore.launch 
```

Run Rviz on the central hub:
```
    rviz rviz/rosbot.rviz
```

To Save a completed merged map:
```
    rosrun map_server map_saver map:=/merged_map -f <output_filename>
```

# References:
- [Husarion tutorials](https://husarion.com/tutorials/)
- [Multi Robot SLAM](https://answers.ros.org/question/41433/multiple-robots-simulation-and-navigation/)
- [Multiple ROSBot Simulation](https://github.com/adamkrawczyk/multiple_rosbots_simulation)




