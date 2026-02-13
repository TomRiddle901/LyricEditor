#include "LrcEditor.h"
#include "settingsDialog.h"
#include <QTIme>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QSlider>
#include <QCloseEvent>
#include <QStyle>
#include <QAction>
#include <QMenuBar>
#include <QMainWindow>
#include <QRegularExpression>
#include <QregularExpressionMatch>

LrcEditor::LrcEditor(QWidget *parent) : QWidget(parent){
    // Inizializzazione
    player = new QMediaPlayer(this);
    openButton = new QPushButton("Apri audio");
    playPauseButton = new QPushButton(this);
    insetTextButton = new QPushButton("Inserisci testo");
    saveButton = new QPushButton("Salva Lyric");
    positionSlider = new QSlider(Qt::Horizontal, this);
    removeAudioButton = new QPushButton("X", this);
    loadLrcButton = new QPushButton("Carica lyric già esistente *.lrc", this);
    settingsDialog = nnew SettingsDialog(this);
    settingsButton = new QPushButton("Impostazioni", this);

    removeAudioButton->setFixedSize(24, 24);
    removeAudioButton->setToolTip("Rimuovi audio");
    removeAudioButton->hide();

    playPauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    playPauseButton->setFixedSize(32, 32);

    positionSlider->setRange(0, 0);

    lyricsEditor = new QTextEdit(this);
    lyricsEditor->setPlaceholderText("Qui apparirà la strofa sincronizzata con il tempo");
    lyricsEditor->setReadOnly(false);

    nowPlaying = new QLabel("Nessun file audio selezionato!", this);
    timerLabel = new QLabel("00:00 / 00:00", this);
    timerLabel->setAlignment(Qt::AlignCenter);

    // Layout
    auto *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(openButton);
    buttonsLayout->addWidget(loadLrcButton);
    buttonsLayout->addWidget(insertTextButton);
    buttonsLayout->addWidget(saveButton);
    buttonsLayout->addWidget(settingsButton);

    auto *sliderLayout = new QHBoxLayout;
    sliderLayout->addWidget(playPauseButton);
    sliderLayout->addWidget(positionSlider);

    auto *nowPlayinglayout = new QHBoxLayout;
    nowPlayinglayout->addWidget(nowPlaying);
    nowPlayinglayout->addWidget(removeAudioButton);
    nowPlayinglayout->addStretch();

    auto *layout = new QVBoxLayout(this);
    layout->addLayout(buttonsLayout);
    layout->addWidget(timerLabel);
    layout->addLayout(nowPlayinglayout);
    layout->addLayout(sliderLayout);
    layout->addWidget(lyricsEditor);

    // Connessioni
    connect(openButton, &QPushButton::clicked, this, &LrcEditor::openAudioFile);
    connect(playPauseButton, &QPushButton::clicked, this, &LrcEditor::togglePlayPause);
    connect(insertTextButton, &QPushButton::clicked, this, &LrcEditor::insertTimestampedText);
    connect(player, &QMediaPlayer::positionChanged, this, &LrcEditor::updateTimerLabel);
    connect(saveButton, &QPushButton::clicked, this, &LrcEditor::saveLyrictoFile);
    connect(player, &QMediaPlayer::positionChanged, this, &LrcEditor::updateSlider);
    connect(player, &QMediaPlayer::durationChanged, this, &LrcEditor::updateDuration);
    connect(positionSlider, &QSlider::sliderPressed, [this](){ isSliderPressed = true;});
    connect(positionSlider, &QSlider::sliderReleased, this, &LrcEditor::seek);
    connect(removeAudioButton, &QPushButton::clicked, this, &LrcEditor::removeAudioFile);
    connect(loadLrcButton, &QPushButton::clicked, this, &LrcEditor::loadLrcfile);
    connect(settingsButton, &QPushButton::clicked, settingsDialog, &QDialog::exec);
    connect(settingsDialog, &SettingsDialog::impostazioniCambiate, this, &LrcEditor::applicaImpostazioni);

    setWindowTitle("Lyric Editor Beta - Untitled");
    setMinimumSize(1280, 720);
}