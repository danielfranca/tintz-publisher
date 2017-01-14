//
// Created by Daniel Franca on 1/6/17.
//

#ifndef TINTZPUBLISHER_IMAGE_H
#define TINTZPUBLISHER_IMAGE_H

#include <string>
#include <vector>

// Is it good to use header-only in C++ ?
// How move big ammount of data on the constructor?

namespace tintz {

    class Image {

        private:
            std::string fileName;
            std::vector<unsigned char> binaryData;

        public:

            Image(std::string fileName, std::vector<unsigned char>&& binaryData) {
                this->fileName = fileName;
                this->binaryData = binaryData;
            }

            bool save();

    };

}

#endif //TINTZPUBLISHER_IMAGE_H
