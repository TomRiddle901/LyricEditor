#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QColor>
#include <QFont>
#include <QPushButton>
#include <QLabel>
#include <QRect>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

class SettingsDialog : public QDialog{
    Q_OBJECT

    public:
        explicit SettingsDialog(Qwidget *parent = nullptr);
        ~SettingsDialog();

        QColor getTheme() const;
        QFont getFont() const;
        QColor getBackgroundPwColor() const;

    private slots:
        void chooseColor();
        coid chooseFont();

    private:
        QPushButton *btnChooseColor;
        QPushButton *btnChooseFont;
        QPushButton *btnChoosePwColor;

        QLabel *lblFont;

        QColor selectedColor;
        QColor backgroundPwColor;

        QFont selectedFont;

    signals:
        void impostazioniCambiate(const QColor &colore, const QFont &font);
};

#endif // SETTINGSDIALOG_H