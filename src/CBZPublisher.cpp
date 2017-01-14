//
// Created by Daniel Franca on 1/13/17.
//
#include "../include/CBZPublisher.h"

#include <iostream>

std::vector<tintz::Image> CBZPublisher::toSortedImagesList() {

    zipper::Unzipper unzipper(this->fileName);
    for (auto entry: unzipper.entries()) {
        std::cout << entry.name;
    }

    std::vector<tintz::Image> result;

    return result;
}
