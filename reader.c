#include <stdio.h> 
#include <time.h>
#include <unistd.h>
#include <string.h>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>
#include <assert.h>

//CAN socket
int s;

int main (int argc, char *argv[]){

    //open can socket 
    /* int s; */
    if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
        perror("Socket");
        return 1;
    }

    //index CAN interface
    struct ifreq ifr;
    strcpy(ifr.ifr_name, "vcan0");
    ioctl(s, SIOCGIFINDEX, &ifr);

    //bind CAN interface
    struct sockaddr_can addr;
    memset(&addr, 0, sizeof(addr));
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Bind");
        return 1;
    }

    //main logic
    struct can_frame frame;
    int nbytes;

    nbytes = read(s, &frame, sizeof(struct can_frame));

    if (nbytes < 0) {
            perror("can raw socket read");
            return 1;
    }

    if (nbytes < sizeof(frame)) {
            fprintf(stderr, "read: incomplete CAN frame\n");
    }

    //parse frame
    for (int i = 0; i < frame.can_dlc; i++){
        printf("Temperature channel %d: %d\n", i + 1, frame.data[i]);
    }

    return 0;
}

