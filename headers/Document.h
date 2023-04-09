//
// Created by vishn on 08.04.2023.
//

#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <memory>
#include<map>
#include <string>

using namespace std;

#include "Primitives.h"

class Document{
private:
    map<int, Element> objects_map;

public:
    Document() = default;

    int CreateElement(const Element &_element){
        UNUSED(_element);
        return 0;
    };

    int DeleteElement(const int id){
        UNUSED(id);
        return 0;
    };

    int Export(const string & path) const {
        UNUSED(path);
        return 0;
    };

    ~Document(){
        objects_map.clear();
    };
};

#endif //DOCUMENT_H
