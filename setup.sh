sudo modprobe vcan
sudo ip link add dev vcan0 type vcan
echo "Interface Created"
sudo ip link set vcan0 up
echo "Interface vcan0 Up"
