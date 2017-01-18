//
// Created by Daniel Franca on 1/16/17.
//

#ifndef TINTZPUBLISHER_COMICBOOK_H
#define TINTZPUBLISHER_COMICBOOK_H

#include <string>
#include "Image.h"

namespace tintz {
    class ComicBook {
    private:
        std::string fileName;
        unsigned int totalPageNumber;
        std::vector<Image> images;

    public:
        ComicBook(std::string fileName) {
            this->fileName = fileName;
        }

        void setTotalPageNumber(unsigned int totalPageNumber) {
            this->totalPageNumber = totalPageNumber;
        }

        std::string getFileName() {
            return this->fileName;
        }

        unsigned int getTotalPageNumber() {
            return this->totalPageNumber;
        }

        void addPage(std::string fileName, std::vector<unsigned char>& binaryData, unsigned int pageNumber) {
            images.emplace_back(fileName, pageNumber, binaryData);
        }
    };
}


#endif //TINTZPUBLISHER_COMICBOOK_H
