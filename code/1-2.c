#include <stdio.h>
#include <string.h>

struct IPv4{
    unsigned int version;
    unsigned int ih1;
    unsigned long long tt1;
    unsigned long long protocol;
    unsigned char data[1024];
};

int main(){
    struct IPv4 s;
    s.version = 0;
    s.ih1 = 0;
    s.tt1 = 256;
    s.protocol = 0;
    sprintf(s.data, "hello world");

    printf("version: %u, size: %zu\n", s.version, sizeof(s.version));
    printf("ih1: %u, size: %zu\n", s.ih1, sizeof(s.ih1));
    printf("tt1: %u, size: %zu\n", s.tt1, sizeof(s.tt1));
    printf("protocol: %u, size: %zu\n", s.protocol, sizeof(s.protocol));
    printf("data: %u, size: %zu\n", s.data, sizeof(s.data));
}
