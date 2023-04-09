#include <iostream>
#include "version.h"
#include "Primitives.h"
#include "Document.h"

using namespace std;

namespace Actions{
    shared_ptr<Document> CreateNewDocument() {
        return shared_ptr<Document> (new Document);
    };

    shared_ptr<Document> Import(const string &path_src){
        UNUSED(path_src);
        return nullptr;
    };

    int Export(const shared_ptr<Document> &doc, const string &path_dst) {
        return doc->Export(path_dst);
    }

    int CreateElement(shared_ptr<Document> &doc, const Element &element){
        return doc->CreateElement(element); // id
    }

    int DeleteElement(shared_ptr<Document> &doc, const int id){
        doc->DeleteElement(id);
        return 0;
    }
}
using namespace Actions;

namespace UserActions{
    shared_ptr<Document> OnCreateDocument(){
        return CreateNewDocument();
    };

    shared_ptr<Document> OnImportDocument(const string &path_src){
        return Import(path_src);
    };

    int OnExportDocument(const shared_ptr<Document> &doc, const string &path_dst){
        return Export(doc, path_dst);
    }

    int OnCreateElement(shared_ptr<Document> &doc, const Element &_obj){
        return CreateElement(doc, _obj);
    }

    void OnDeleteElement(shared_ptr<Document> &doc, const int id){
        DeleteElement(doc, id);
    }
}
using namespace UserActions;

int main() {

    auto doc_1 = OnCreateDocument();
    auto doc_2 = OnImportDocument("/tmp/file.cfg");
    OnExportDocument(doc_2, "/tmp/file_2.cfg");

    int id_1 = OnCreateElement(doc_2, Element(Circle{1,1,10.2}));
    int id_2 = OnCreateElement(doc_2, Element(Rectangle{10,10,5,5}));

    OnDeleteElement(doc_2, id_1);
    OnDeleteElement(doc_2, id_2);

    return EXIT_FAILURE;
}
