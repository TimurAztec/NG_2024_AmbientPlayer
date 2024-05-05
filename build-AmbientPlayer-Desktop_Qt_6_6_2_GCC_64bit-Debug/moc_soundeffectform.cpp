/****************************************************************************
** Meta object code from reading C++ file 'soundeffectform.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AmbientPlayer/soundeffectform.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'soundeffectform.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSoundEffectFormENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSoundEffectFormENDCLASS = QtMocHelpers::stringData(
    "SoundEffectForm",
    "removeWidget",
    "",
    "SoundEffectData*",
    "data",
    "playPause",
    "updateVolume",
    "volume",
    "checkRepeat",
    "state",
    "updateInterval",
    "interval",
    "remove",
    "fade"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSoundEffectFormENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[16];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[5];
    char stringdata5[10];
    char stringdata6[13];
    char stringdata7[7];
    char stringdata8[12];
    char stringdata9[6];
    char stringdata10[15];
    char stringdata11[9];
    char stringdata12[7];
    char stringdata13[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSoundEffectFormENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSoundEffectFormENDCLASS_t qt_meta_stringdata_CLASSSoundEffectFormENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "SoundEffectForm"
        QT_MOC_LITERAL(16, 12),  // "removeWidget"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 16),  // "SoundEffectData*"
        QT_MOC_LITERAL(47, 4),  // "data"
        QT_MOC_LITERAL(52, 9),  // "playPause"
        QT_MOC_LITERAL(62, 12),  // "updateVolume"
        QT_MOC_LITERAL(75, 6),  // "volume"
        QT_MOC_LITERAL(82, 11),  // "checkRepeat"
        QT_MOC_LITERAL(94, 5),  // "state"
        QT_MOC_LITERAL(100, 14),  // "updateInterval"
        QT_MOC_LITERAL(115, 8),  // "interval"
        QT_MOC_LITERAL(124, 6),  // "remove"
        QT_MOC_LITERAL(131, 4)   // "fade"
    },
    "SoundEffectForm",
    "removeWidget",
    "",
    "SoundEffectData*",
    "data",
    "playPause",
    "updateVolume",
    "volume",
    "checkRepeat",
    "state",
    "updateInterval",
    "interval",
    "remove",
    "fade"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSoundEffectFormENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   59,    2, 0x08,    3 /* Private */,
       6,    1,   60,    2, 0x08,    4 /* Private */,
       8,    1,   63,    2, 0x08,    6 /* Private */,
      10,    1,   66,    2, 0x08,    8 /* Private */,
      12,    0,   69,    2, 0x08,   10 /* Private */,
      13,    0,   70,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject SoundEffectForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSSoundEffectFormENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSoundEffectFormENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSoundEffectFormENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SoundEffectForm, std::true_type>,
        // method 'removeWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SoundEffectData *, std::false_type>,
        // method 'playPause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateVolume'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'checkRepeat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'updateInterval'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'remove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'fade'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SoundEffectForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SoundEffectForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->removeWidget((*reinterpret_cast< std::add_pointer_t<SoundEffectData*>>(_a[1]))); break;
        case 1: _t->playPause(); break;
        case 2: _t->updateVolume((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 3: _t->checkRepeat((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->updateInterval((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 5: _t->remove(); break;
        case 6: _t->fade(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SoundEffectForm::*)(SoundEffectData * );
            if (_t _q_method = &SoundEffectForm::removeWidget; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *SoundEffectForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SoundEffectForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSoundEffectFormENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SoundEffectForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void SoundEffectForm::removeWidget(SoundEffectData * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
