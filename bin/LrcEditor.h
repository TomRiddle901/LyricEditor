#ifndef LRCEDITOR_H
#define LRCEDITOR_H

#include "settingsDialog.h"
#include <QWidget>
#include <QMediaPlayer>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QFileDialog>
#include <QMediaPlaylist>
#include <QLabel>
#include <QInputDialog>
#include <QMessageBox>
#include <QSlider>
#include <QCloseEvent>
#include <QStyle>
#include <QAction>
#include <QMenuBar>
#include <QMainWindow>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

class LrcEditor : public QWidget{
    Q_OBJECT

    public:
        explicit LrcEditor(QWidget *parent = nullptr);

    private slots:
        void openAudioFile();
        void togglePlayPause();
        void insertTimestampedText();
        void updateTimerLabel(quint64 position);
        void saveLyrictoFile();
        void updateSlider(quint64 position);
        void updateDuration(quint64 duration);
        void seek();
        void closeEvent(QCloseEvent *event) override;
        void removeAudioFile();
        void loadLrcfile();
        void applicaImpostazioni(const QColor &colore, const QFont &font);

    private:
        QMediaPlayer *player;
        QPushButton *openButton;
        QPushButton *playPauseButton;
        QPushButton *insertTextButton;
        QPushButton *saveButton;
        QPushButton *removeAudioButton;
        QPushButton *loadLrcButton;
        QPushButton *settingsButton;

        QTextEdit *lyricsEditor;
        
        QLabel *nowPlaying;
        QLabel *timerLabel;
        
        QSlider *positionSlider;

        QString loadedLrcPath;

        SettingsDialog *settingsDialog;
        
        bool isSliderPressed = false;
        bool lrcLoaded = false;
};

#endif // LRCEDITOR_H