/****************************************************************************
** Meta object code from reading C++ file 'LrcEditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.15)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "LrcEditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LrcEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.15. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LrcEditor_t {
    QByteArrayData data[20];
    char stringdata0[237];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LrcEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LrcEditor_t qt_meta_stringdata_LrcEditor = {
    {
QT_MOC_LITERAL(0, 0, 9), // "LrcEditor"
QT_MOC_LITERAL(1, 10, 13), // "openAudioFile"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 15), // "togglePlayPause"
QT_MOC_LITERAL(4, 41, 21), // "insertTimestampedText"
QT_MOC_LITERAL(5, 63, 16), // "updateTimerLabel"
QT_MOC_LITERAL(6, 80, 8), // "position"
QT_MOC_LITERAL(7, 89, 15), // "saveLyrictoFile"
QT_MOC_LITERAL(8, 105, 12), // "updateSlider"
QT_MOC_LITERAL(9, 118, 14), // "updateDuration"
QT_MOC_LITERAL(10, 133, 8), // "duration"
QT_MOC_LITERAL(11, 142, 4), // "seek"
QT_MOC_LITERAL(12, 147, 10), // "closeEvent"
QT_MOC_LITERAL(13, 158, 12), // "QCloseEvent*"
QT_MOC_LITERAL(14, 171, 5), // "event"
QT_MOC_LITERAL(15, 177, 15), // "removeAudioFile"
QT_MOC_LITERAL(16, 193, 11), // "loadLrcfile"
QT_MOC_LITERAL(17, 205, 19), // "applicaImpostazioni"
QT_MOC_LITERAL(18, 225, 6), // "colore"
QT_MOC_LITERAL(19, 232, 4) // "font"

    },
    "LrcEditor\0openAudioFile\0\0togglePlayPause\0"
    "insertTimestampedText\0updateTimerLabel\0"
    "position\0saveLyrictoFile\0updateSlider\0"
    "updateDuration\0duration\0seek\0closeEvent\0"
    "QCloseEvent*\0event\0removeAudioFile\0"
    "loadLrcfile\0applicaImpostazioni\0colore\0"
    "font"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LrcEditor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    1,   77,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    1,   81,    2, 0x08 /* Private */,
       9,    1,   84,    2, 0x08 /* Private */,
      11,    0,   87,    2, 0x08 /* Private */,
      12,    1,   88,    2, 0x08 /* Private */,
      15,    0,   91,    2, 0x08 /* Private */,
      16,    0,   92,    2, 0x08 /* Private */,
      17,    2,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::ULongLong,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::ULongLong,    6,
    QMetaType::Void, QMetaType::ULongLong,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor, QMetaType::QFont,   18,   19,

       0        // eod
};

void LrcEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LrcEditor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->openAudioFile(); break;
        case 1: _t->togglePlayPause(); break;
        case 2: _t->insertTimestampedText(); break;
        case 3: _t->updateTimerLabel((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 4: _t->saveLyrictoFile(); break;
        case 5: _t->updateSlider((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 6: _t->updateDuration((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 7: _t->seek(); break;
        case 8: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 9: _t->removeAudioFile(); break;
        case 10: _t->loadLrcfile(); break;
        case 11: _t->applicaImpostazioni((*reinterpret_cast< const QColor(*)>(_a[1])),(*reinterpret_cast< const QFont(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LrcEditor::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_LrcEditor.data,
    qt_meta_data_LrcEditor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LrcEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LrcEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LrcEditor.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LrcEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
