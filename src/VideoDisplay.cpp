#include "VideoDisplay.hpp"
#include <QtWidgets>
#include <QtCore>


VideoPlayer::VideoPlayer(QWidget *parent)
    : QWidget(parent)
{
    _media_player = new QMediaPlayer(this);
    _video_player = new QVideoWidget();
    _frame_grabber = new QImageCapture();
    _video_name = "";
    _video_path = "";

    setLayout(new QVBoxLayout());
    layout()->addWidget(_video_player);
    _media_player->setVideoOutput(_video_player->videoSink());
    resize(700, 500);

    connect(_media_player, &QMediaPlayer::playbackStateChanged, this, &VideoPlayer::acceptDrops);
    connect(_media_player, &QMediaPlayer::positionChanged, this, &VideoPlayer::playback_position_changed);
    connect(_media_player, &QMediaPlayer::durationChanged, this, &VideoPlayer::video_duration_changed);
}


int VideoPlayer::duration(){
    return _media_player->duration();
}

void VideoPlayer::set_video(QString video_file){
    _media_player->stop();
    _media_player->setSource(QUrl::fromLocalFile(video_file));
    // todo: set video name and path here
}

void VideoPlayer::grab_frame(){
    QVideoSink *vid_out = (QVideoSink*)_media_player->videoOutput();
    QVideoFrame frame = vid_out->videoFrame();
    emit frame_grabbed(frame.toImage(), _media_player->position());
}

void VideoPlayer::play(){
    _media_player->play();
}

void VideoPlayer::pause(){
    _media_player->pause();
}

void VideoPlayer::pause_and_grab(){
    _media_player->pause();
    grab_frame();
}

void VideoPlayer::toggle_play_pause(){
    if (_media_player->playbackState() == QMediaPlayer::PlaybackState::PlayingState)
        pause();
    else
        play();
}

void VideoPlayer::set_position(int new_position){
    _media_player->setPosition(new_position);
}

void VideoPlayer::keyPressEvent(QKeyEvent *event){
    switch (event->key())
    {
    case Qt::Key_Space:
        toggle_play_pause();
        break;
    case Qt::Key_Return:
        pause_and_grab();
        break;
    default:
        break;
    }
}