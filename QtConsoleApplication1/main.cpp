//#include <QtCore/QCoreApplication>
#include "Filter.h"


int main(int argc, char* argv[])
{
    //setlocale(LC_ALL, "Russian");

    std::string s;
    QImage img;

    for (int i = 0; i < argc; i++)
    {
        if (!strcmp(argv[i], "-p") && (i + 1 < argc))
            s = argv[i + 1];
    }

    img.load(QString(s.c_str()));
    img.save("Images/Source.png");

    InvertFilter invert;
    invert.process(img).save("Images/Invert.png");
}
