// App Name
// Version 0.1.0 Beta

#include <QApplication>
#include "LrcEditor.h"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    LrcEditor editor;
    editor.showMaximized();
    return app.exec();
}