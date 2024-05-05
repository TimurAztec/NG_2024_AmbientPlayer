/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AmbientPlayer/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "playPause",
    "",
    "checkPause",
    "setAmbient",
    "updateVolume",
    "volume",
    "addSoundEffect",
    "SoundEffectData*",
    "data",
    "removeSoundEffect",
    "playSoundEffect",
    "updateSoundEffectList",
    "fade"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[11];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[11];
    char stringdata5[13];
    char stringdata6[7];
    char stringdata7[15];
    char stringdata8[17];
    char stringdata9[5];
    char stringdata10[18];
    char stringdata11[16];
    char stringdata12[22];
    char stringdata13[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 9),  // "playPause"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 10),  // "checkPause"
        QT_MOC_LITERAL(33, 10),  // "setAmbient"
        QT_MOC_LITERAL(44, 12),  // "updateVolume"
        QT_MOC_LITERAL(57, 6),  // "volume"
        QT_MOC_LITERAL(64, 14),  // "addSoundEffect"
        QT_MOC_LITERAL(79, 16),  // "SoundEffectData*"
        QT_MOC_LITERAL(96, 4),  // "data"
        QT_MOC_LITERAL(101, 17),  // "removeSoundEffect"
        QT_MOC_LITERAL(119, 15),  // "playSoundEffect"
        QT_MOC_LITERAL(135, 21),  // "updateSoundEffectList"
        QT_MOC_LITERAL(157, 4)   // "fade"
    },
    "MainWindow",
    "playPause",
    "",
    "checkPause",
    "setAmbient",
    "updateVolume",
    "volume",
    "addSoundEffect",
    "SoundEffectData*",
    "data",
    "removeSoundEffect",
    "playSoundEffect",
    "updateSoundEffectList",
    "fade"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    1,   71,    2, 0x08,    4 /* Private */,
       7,    1,   74,    2, 0x08,    6 /* Private */,
      10,    1,   77,    2, 0x08,    8 /* Private */,
      11,    0,   80,    2, 0x08,   10 /* Private */,
      12,    0,   81,    2, 0x08,   11 /* Private */,
      13,    0,   82,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'playPause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'checkPause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setAmbient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateVolume'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'addSoundEffect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SoundEffectData *, std::false_type>,
        // method 'removeSoundEffect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SoundEffectData *, std::false_type>,
        // method 'playSoundEffect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateSoundEffectList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'fade'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->playPause(); break;
        case 1: _t->checkPause(); break;
        case 2: _t->setAmbient(); break;
        case 3: _t->updateVolume((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 4: _t->addSoundEffect((*reinterpret_cast< std::add_pointer_t<SoundEffectData*>>(_a[1]))); break;
        case 5: _t->removeSoundEffect((*reinterpret_cast< std::add_pointer_t<SoundEffectData*>>(_a[1]))); break;
        case 6: _t->playSoundEffect(); break;
        case 7: _t->updateSoundEffectList(); break;
        case 8: _t->fade(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
