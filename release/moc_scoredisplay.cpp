/****************************************************************************
** Meta object code from reading C++ file 'scoredisplay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtProjects/Qscoreboard/scoredisplay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scoredisplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScoreDisplay_t {
    QByteArrayData data[9];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScoreDisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScoreDisplay_t qt_meta_stringdata_ScoreDisplay = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ScoreDisplay"
QT_MOC_LITERAL(1, 13, 13), // "updateDisplay"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "home"
QT_MOC_LITERAL(4, 33, 4), // "away"
QT_MOC_LITERAL(5, 38, 10), // "shot_clock"
QT_MOC_LITERAL(6, 49, 6), // "period"
QT_MOC_LITERAL(7, 56, 4), // "time"
QT_MOC_LITERAL(8, 61, 6) // "random"

    },
    "ScoreDisplay\0updateDisplay\0\0home\0away\0"
    "shot_clock\0period\0time\0random"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScoreDisplay[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    5,   24,    2, 0x0a /* Public */,
       8,    0,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QTime,    3,    4,    5,    6,    7,
    QMetaType::Void,

       0        // eod
};

void ScoreDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScoreDisplay *_t = static_cast<ScoreDisplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateDisplay((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QTime(*)>(_a[5]))); break;
        case 1: _t->random(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ScoreDisplay::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ScoreDisplay.data,
    qt_meta_data_ScoreDisplay,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ScoreDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScoreDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScoreDisplay.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ScoreDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
