//
// Created by Daniel Franca on 1/6/17.
//

#ifndef TINTZPUBLISHER_PUBLISHERFACTORY_H
#define TINTZPUBLISHER_PUBLISHERFACTORY_H

#include "AbstractPublisherBackend.h"
#include "CBZPublisher.h"

#include <memory>

class PublisherFactory {
public:
    static std::shared_ptr<AbstractPublisherBackend> make(std::string fileName) {
        return std::make_shared<CBZPublisher>(fileName);
    }
};

#endif //TINTZPUBLISHER_PUBLISHERFACTORY_H
