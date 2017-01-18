//
// Created by Daniel Franca on 1/13/17.
//
#include "../include/CBZPublisher.h"

#include <iostream>
#include <regex>

tintz::ComicBook tintz::CBZPublisher::publish() {

    zipper::Unzipper unzipper(this->fileName);

    std::regex extensionExpression("\\.(jpg|png)$");
    std::regex pageExpression("([\\d]+)\\.(jpg|png)$");
    std::smatch baseMatch;
    ComicBook cb(this->fileName);
    unsigned int totalPages = 0;

    for (auto entry: unzipper.entries()) {
        if (std::regex_search(entry.name, extensionExpression)) {
            unsigned int pageNumber = 0;
            if (std::regex_search(entry.name, baseMatch, pageExpression)) {
                if (baseMatch.size() >= 2) {
                    std::ssub_match subMatch = baseMatch[1];
                    pageNumber = std::stoi(subMatch.str());
                    totalPages = std::max(totalPages, pageNumber);
                }
            }

            //Extract file and store its content
            std::vector<unsigned char> unzipped_entry;
            try {
                unzipper.extractEntryToMemory(entry.name, unzipped_entry);
            } catch(std::runtime_error e) {
                std::cout << e.what() << std::endl;
                continue;
            }

            cb.addPage(entry.name, unzipped_entry, pageNumber);
        }
    }


    cb.setTotalPageNumber(totalPages);

    unzipper.close();

    return cb;
}
