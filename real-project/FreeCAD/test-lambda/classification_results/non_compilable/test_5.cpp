#include <bits/stdc++.h>

namespace App {
class DocumentObject;
}

namespace Gui {
class ViewProvider;
class ViewProviderDocumentObject : public ViewProvider {
public:
    int getTreeRank() const;
};

class Application {
public:
    static Application* Instance;
    ViewProvider* getViewProvider(App::DocumentObject*);
};
} // namespace Gui

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(App::DocumentObject* a, App::DocumentObject* b) {
    Gui::ViewProviderDocumentObject* vpA = dynamic_cast<Gui::ViewProviderDocumentObject*>(Gui::Application::Instance->getViewProvider(a));
    Gui::ViewProviderDocumentObject* vpB = dynamic_cast<Gui::ViewProviderDocumentObject*>(Gui::Application::Instance->getViewProvider(b));
    if (vpA && vpB) {
        return vpA->getTreeRank() < vpB->getTreeRank();
    }
    return false;
}

void test1(App::DocumentObject* a, App::DocumentObject* b, App::DocumentObject* c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
        ConsistencyChecker();
}

void test2(App::DocumentObject* a, App::DocumentObject* b, App::DocumentObject* c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
        TransiveChecker();
}

void test3_1(App::DocumentObject* a, App::DocumentObject* b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(App::DocumentObject* a) {
    NewTest();
    if (lambda0(a, a)) 
        ReflexivityChecker();
}