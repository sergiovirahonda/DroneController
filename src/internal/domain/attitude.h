#ifndef ATTITUDE_H
#define ATTITUDE_H

struct Attitude {
    private:
        int pitch;
        int roll;

    public:
        Attitude(int pitch, int roll);
        int getPitch();
        int getRoll();
        void setPitch(int pitch);
        void setRoll(int roll);
};

#endif