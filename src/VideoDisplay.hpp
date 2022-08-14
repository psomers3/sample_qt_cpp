#ifndef VIDEODISPLAY_HPP
#define VIDEODISPLAY_HPP

#include <QtWidgets>
#include <QtCore>
#include <QtMultimedia>
#include <QtMultimediaWidgets>



class VideoPlayer : public QWidget
{
    Q_OBJECT
private:
    QPointer<QMediaPlayer> _media_player;
    QPointer<QVideoWidget> _video_player;
    QPointer<QImageCapture> _frame_grabber;
    QString _video_name;
    QString _video_path;


public:
    explicit VideoPlayer(QWidget *parent = nullptr);
    ~VideoPlayer(){};

    int duration();
    void set_video(QString video_file);

public slots:
    void grab_frame();
    void play();
    void pause();
    void pause_and_grab();
    void toggle_play_pause();
    void set_position(int new_position);
protected slots:
    void keyPressEvent(QKeyEvent *event) override;

signals:
    void media_state_changed(QMediaPlayer::PlaybackState state);
    void playback_position_changed(int position);
    void video_duration_changed(int duration);
    void frame_grabbed(QImage img, int position);
};

#endif