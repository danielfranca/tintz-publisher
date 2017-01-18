//
// Created by Daniel Franca on 1/6/17.
//

#ifndef TINTZPUBLISHER_CBZPUBLISHER_H
#define TINTZPUBLISHER_CBZPUBLISHER_H

#include "AbstractPublisherBackend.h"
#include <zipper/unzipper.h>
#include "ComicBook.h"

namespace tintz {
    class CBZPublisher : public AbstractPublisherBackend {
    public:
        CBZPublisher(std::string fileName) : AbstractPublisherBackend(fileName) {};

        ComicBook publish() override;
    };
}

#endif //TINTZPUBLISHER_CBZPUBLISHER_H
