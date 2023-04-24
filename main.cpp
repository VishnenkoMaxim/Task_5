#include <iostream>
#include<map>
#include <memory>
#include <utility>

using namespace std;

#include "version.h"
#include "Primitives.h"

class Document{
private:
    map<int, Element> objects_map;

public:
    Document() = default;

    int CreateElement(const Element &_element){
        UNUSED(_element);
        return 0;
    }

    int DeleteElement(const int id){
        UNUSED(id);
        return 0;
    }

    int Export(const string & path) const {
        UNUSED(path);
        return 0;
    }

    int Import(const string & path) {
        UNUSED(path);
        return 0;
    }

    void Print(){
        //
    }

    ~Document(){
        objects_map.clear();
    };
};

class DocumentView{
public:
    void ShowDocument(shared_ptr<Document> doc){
        //show document
        doc->Print();
    }

    ~DocumentView(){}
};

class DocumentController{
private:
    shared_ptr<DocumentView>    view;
    shared_ptr<Document>        doc;
public:
    explicit DocumentController(shared_ptr<DocumentView> _view){
        view = _view;
    }

    void CreateDocument(){
        doc.reset();
        doc = make_shared<Document> ();
    };

    int ImportDocument(const string &path_src){
        doc.reset();
        return doc->Import(path_src);
    };

    int ExportDocument(const string &path_dst){
        return doc->Export(path_dst);
    }

    int CreateElement(const Element &_obj){
        return doc->CreateElement(_obj);
    }

    void DeleteElement(const int id){
        doc->DeleteElement(id);
    }

    void UpdateView(){
        view->ShowDocument(doc);
    }
};

int main() {
    auto view = make_shared<DocumentView>();
    DocumentController controller(view);

    controller.CreateDocument();
    controller.UpdateView();

    controller.ImportDocument("/cfg/file.ext");
    int id_1 = controller.CreateElement(Element(Circle{1,1,10.2}));
    int id_2 = controller.CreateElement(Element(Rectangle{10,10,5,5}));
    controller.UpdateView();

    controller.DeleteElement(id_1);
    controller.UpdateView();
    controller.DeleteElement(id_2);
    controller.ExportDocument("/test/file.ext");

    return EXIT_FAILURE;
}
