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
    /*
    char size[80];
    std::ifstream ifs("KernelM.txt");
    ifs.getline(size, 3, '\n');
    int sizei = std::atoi(size);
    Kernel MatKernel(sizei);
    std::unique_ptr<float[]> tmp = std::make_unique<float[]>(sizei * sizei);

    for (int i = 0; i < sizei * sizei; i++)
    {
        ifs.getline(size, 1, '\n');
        tmp[i] = std::atoi(size);
    }

    MatKernel.SetKernel(tmp.get(), sizei / 2);
    */
    
    InvertFilter invert;
    invert.process(img).save("Images/Invert.png");

    BlurFilter blur;
    blur.process(img).save("Images/Blur.png");

    GaussianFilter gauss;
    gauss.process(img).save("Images/Gauss.png");

    GrayScaleFilter gray;
    gray.process(img).save("Images/Gray.png");

    Sepia sep;
    sep.process(img).save("Images/Sep.png");

    BrightUp bright;
    bright.process(img).save("Images/Bright.png");
    
    SharpnessUp sharpness;
    sharpness.process(img).save("Images/SharpnessUp.png");
    
    GreyWorldFilter gworld;
    gworld.process(img).save("Images/GreyWorld.png");
    
    Transfer trasf;
    trasf.process(img).save("Images/Transfer.png");
    
    Glass glass;
    glass.process(img).save("Images/Glass.png");
    
    Sharpness sharp;
    sharp.process(img).save("Images/Sharpness.png");
    
    MotionBlur motblur;
    motblur.process(img).save("Images/MotionBlur.png");
    
    Dilation dil;
    dil.process(img).save("Images/Dilation.png");
    
    Erosion eros;
    eros.process(img).save("Images/Erosion.png");
    
    Opening op;
    op.process(img).save("Images/Opening.png");
    
    Closing cl;
    cl.process(img).save("Images/Closing.png");
    
    LinealStretching lin(img);
    lin.process(img).save("Images/LinealStretching.png");
    
    Grad grad;
    grad.process(img).save("Images/Gradient.png");
    
    Median med;
    med.process(img).save("Images/Median.png");
    
    SobelFilterX sobelx;
    sobelx.process(img).save("Images/SobelX.png");

    SobelFilterY sobelY;
    sobelY.process(img).save("Images/SobelY.png");
    
    return 0;
}
