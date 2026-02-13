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

void LrcEditor::openAudioFile(){
    QString filePath = QFileDialog::getOpenFileName(this, "Scegli file audio", "", "Audio files (*.mp3 *.wav *.ogg);;Tutti i file (*.*)");

    if (!filePath.isEmpty()){
        player->setMedia(QUrl::fromLocalFile(filePath));
        nowPlaying->setText("In Riproduzione: " + QFileInfo(filePath).fileName());
        removeAudioButton->show();
        playPauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        setWindowTitle("Lyric Editor Beta - " + QFileInfo(filePath).fileName());
    }
}

void LrcEditor::togglePlayPause(){
    if (player->mediaStatus() == QMediaPlayer::NoMedia){
        QMessageBox::warning(this, "Nessun file audio selezionato, selezionane uno cliccando 'Apri Audio' prima di riprodurre");
        return;
    }

    if (player-state() == QMediaPlayer::PlayingState){
        player->pause();
        playPauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    } else {
        player->play();
        playPauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    }
}

void LrcEditor::insertTimestampedText(){
    bool allowInsert = true;

    if (player->mediaStatus() == QMediaPlayer::NoMedia){
        QMessageBox msgBox(this);
        msgBox.setWindowtitle("Errore");
        msgBox.setText("Nessun file audio caricato. Vuoi inserire solo il testo?");
        QPushButton *insertOnlyTextBtn = msgBox.addButton("OK", QMessageBox::AcceptRole);
        msg.Box.addButton("NO", QMessageBox::RejectRole);
        msgBox.exec();

        if (msgBox.clickedButton() != insertOnlyTextBtn){
            allowInsert = false;
        }
    }

    if (!allowInsert){
        return;
    }

    if (player->state() == QMediaPlayer::PlayingState){
        player->pause();
        playPauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }

    // Prendi timestamp
    quint64 ms = player->position();
    QTIme time(0, 0);
    time = time.addMSecs(ms);
    QString timestamp = QString("[%1]").arg(time.toString("mm:ss.zzz").left(8));
    
    // Richiedi testo
    bool ok;
    Qstring line = QInputDialog::getText(this, "Inserisci il testo", "Testo da sincronizzare:", QLineEdit::Normal, "", &ok);

    if (ok && !line.isEmpty()){
        lyricsEditor->append(timestamp + " " + line);
    }
}

void LrcEditor::updateTimerLabel(qint64 position){
    qint64 duration = player->duration();

    QTime currentTime((position / 3600000)%60, (position / 60000)%60, (position/1000)%60);
    QTime totaltime((duration / 3600000)%60, (duration / 60000)%60, (duration/1000)%60);
    QString timeText = currentTime.toString("mm:ss") + " / " + totalTime.toString("mm:ss");
    timerLabel->setText(timeText);
}

void LrcEditor::saveLyrictoFile(){
    if (lyricsEditor->toPlainText().trimmed().isEmpty()){
        QMessageBox::warning(this, "Errore", "Non è possibile salvare il file vuoto, inserisci almeno una strofa");
        return;
    }

    QString filePath = QFileDialog::getSaveFileName(this, "Salva lrc", "", "File LRC (*.lrc);;Tutti i file (*.*)");

    if (filePath.isEmpty()){
        return;
    }

    // Aggiungi l'estensione .lrc solo se non è presente
    if (!filePath.endsWith(".lrc", Qt::CaseInsensitive)){
        filePath += ".lrc";
    }

    QFile file(filePath);

    if (file.open(QIODevide::WriteOnly | QIODevice::Text)){
        QTextStram out(&file);
        out << lyricsEditor->toPlainText();
        file.close();
        QMessageBox::information(this, "Salvataggio completato", "File salvato con successo in:\n" + filePath);
    } else{
        QMessageBox::critical(this, "Errore", "A causa di un errore sconosciuto non è stato possibile salvare il file");
    }
}

void LrcEditor::updateSlider(quint64 position){
    if (!isSliderPressed){
        positionSlider->setValue(static_cast<int>(position));
    }
    QTime currentTime(0, 0, 0);
    currentTime = currentTime.addMSecs(position);
    QTime totalTime(0, 0, 0);
    totalTime = totalTime.addMSecs(player->duration());
    timerLabel->setText(currentTime.toString("mm:ss") + " / " + totalTime.toString("mm:ss"));
}

void LrcEditor::updateDuration(qint64 duration){
    positionSlider->setRange(0, static_cast<int>(duration));
}

void LrcEditor::seek(){
    isSliderPressed = false;
    player->setPosition(positionSlider->value());
}