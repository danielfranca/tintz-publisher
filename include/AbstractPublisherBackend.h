//
// Created by Daniel Franca on 1/6/17.
//

#ifndef TINTZPUBLISHER_ABSTRACTPUBLISHERBACKEND_H
#define TINTZPUBLISHER_ABSTRACTPUBLISHERBACKEND_H

#include <vector>

#include "image.h"

class AbstractPublisherBackend {
    public:
        AbstractPublisherBackend(std::string fileName) {
            this->fileName = fileName;
        }
        virtual std::vector<tintz::Image> toSortedImagesList()=0;

    protected:
        std::string fileName;
};

#endif //TINTZPUBLISHER_ABSTRACTPUBLISHERBACKEND_H
