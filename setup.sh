sudo modprobe vcan
sudo ip link add dev vcan0 type vcan
sudo ip link set vcan0 up
candump -tz vcan0
cansend vcan0 "123#00FFAA5501020304"
