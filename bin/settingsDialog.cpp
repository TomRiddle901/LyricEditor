#include "settingsDialog.h"
#include <QVBoxLayout>
#include <QColorDialog>
#include <QFontDialog>
#include <QRect>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

SettingsDialog::SettingsDialog(QWidget *parent) : QDialog(parent), selectedColor(Qt::black),
backgroundPwColor(Qt::black), selectedFont(QFont("Ubuntu", 12)){
    btnChooseColor = new QPushButton("Scegli colore tema", this);
    btnChooseFont = new QPushButton("Scegli Font", this);
    lblFont = new QLabel("Font corrente: " + selectedFont.toString(), this);

    QVboxLayout *settingsLayout = new QVBoxLayout(this);
    settingLayout->addWidget(btnChooseColor);
    settingLayout->addWidget(btnChooseFont);
    settingLayout->addWidget(lblFont);

    connect(btnChooseColor, &QPushButton::clicked, this, &SettingsDialog::chooseColor);
    connect(btnChooseFont, &QPushButton::clicked, this, &SettingsDialog::chooseFont);

    setWindowTitle("Lyric Editor Beta - Impostazioni");
    setMinimumSize(600, 100);
}