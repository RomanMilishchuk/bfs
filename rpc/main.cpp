#include <iostream>
#include "rpc.h"

int main() {
    Rpc rpc("0x00c469eee8b9bc1a331070be0e5814a0bc6f902e", "0x3fDCC710BA867541a2031c25bed49fdA04C2D1b7");
    uint8_t data[1024] = {0xFF, 0xFF};
    if(!rpc.create_file("/test.txt")) {
        std::cout << "Couldn't create file" << std::endl;
    }
    if(!rpc.write_file("/test.txt", data, 2)) {
        std::cout << "Couldn't write to a file" << std::endl;
    }
    size_t num = rpc.read_file("/test.txt", data, 1024, 0);
    std::cout << "0x";
    for (int i = 0; i < num; i++) {
        std::cout << std::hex << (unsigned int) data[i];
    }
    return 0;
}