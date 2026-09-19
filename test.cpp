#include <stdio.h>

class dowrap {
public:
    void dosmth() {
        printf("i did smth\n");
    }
};
extern "C" {
    void dowrap_entry() {
        dowrap instance;
        instance.dosmth();
    }
}
