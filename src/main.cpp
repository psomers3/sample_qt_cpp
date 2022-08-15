#include <QtWidgets/QtWidgets>
#include <QtWidgets>
#include <QtCore>
#include "VideoDisplay.hpp"



int main(int argc, char *argv[])
{
    // Creates an instance of QApplication
    QApplication a(argc, argv);
    auto vid = new VideoPlayer;
    auto img = new QLabel;

    QObject::connect(vid, &VideoPlayer::frame_grabbed, [&img](QImage image, int t){
        img->setPixmap(QPixmap::fromImage(image.scaled(800, 600, Qt::AspectRatioMode::KeepAspectRatio)));
        img->show();
    });
    QString file = QFileDialog::getOpenFileName();
    vid->set_video(file);
    vid->show();
    vid->play();
    
    return a.exec();
}