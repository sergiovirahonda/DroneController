#ifndef DRONE_COMMAND_H
#define DRONE_COMMAND_H

class DroneCommand {
    private:
        int pitch, roll, yaw, throttle;
        unsigned long timestamp;

    public:
        DroneCommand(
            int pitch,
            int roll,
            int yaw,
            int throttle,
            unsigned long timestamp
        );
        int getPitch();
        int getRoll();
        int getYaw();
        int getThrottle();
        unsigned long getTimestamp();
        // Setters
        void setPitch(int pitch);
        void setRoll(int roll);
        void setYaw(int yaw);
        void setThrottle(int throttle);
        void setTimestamp(unsigned long timestamp);
        void reset();
};

#endif