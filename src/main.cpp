//
// Created by Daniel Franca on 1/5/17.
//
#include <getopt.h>

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {

    //Parameters
    //-f filename
    //-h
    int c;
    std::string filename;
    static struct option long_options[] = {
            {"help", no_argument, nullptr, 'h'},
            {"file", required_argument, nullptr, 'f'},
            {0, 0, 0, 0}};

    const char usage_str[] =
            ("Usage: tintzPublisher [options] -f <filename>\n"
                    "\n"
                    "General Options:\n"
                    "  -h, --help           Show help\n"
                    "  -f, --filename=FILENAME   The file to publish\n");

    int option_index = 0;

    while ((c = getopt_long(argc, argv, "hf:", long_options, &option_index)) != -1) {
        switch (c) {
            case 'f':
                filename = optarg;
                std::cout << "File: " << filename;
                break;
            case 'h':
                std::cout << usage_str;
                return 0;

        }
    }

    if (filename.empty()) {
        std::cerr << usage_str;
    }

    return 0;
}