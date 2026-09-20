#include <stdio.h>
extern "C"{ //Stops CPP from obfuscating the func name in the .so
    void dosmth(void _NERR) //NERR makes it so that the godot compilr doesnt crash if it doesn't have any params{
        printf("i did smth\n");
    }
}
