/****************************************************************************
** Meta object code from reading C++ file 'resultswindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../resultswindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'resultswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_resultswindow_t {
    QByteArrayData data[12];
    char stringdata[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_resultswindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_resultswindow_t qt_meta_stringdata_resultswindow = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 26),
QT_MOC_LITERAL(2, 41, 0),
QT_MOC_LITERAL(3, 42, 18),
QT_MOC_LITERAL(4, 61, 12),
QT_MOC_LITERAL(5, 74, 19),
QT_MOC_LITERAL(6, 94, 16),
QT_MOC_LITERAL(7, 111, 14),
QT_MOC_LITERAL(8, 126, 19),
QT_MOC_LITERAL(9, 146, 26),
QT_MOC_LITERAL(10, 173, 8),
QT_MOC_LITERAL(11, 182, 12)
    },
    "resultswindow\0receive_results_for_Public\0"
    "\0const QListWidget*\0nextTeamList\0"
    "const QTableWidget*\0RCSTrankingtable\0"
    "RCrankingtable\0AUTONOMrankingtable\0"
    "receive_comment_for_Public\0mComment\0"
    "swapTimeTick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_resultswindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   29,    2, 0x0a /* Public */,
       9,    1,   38,    2, 0x0a /* Public */,
      11,    0,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,

       0        // eod
};

void resultswindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        resultswindow *_t = static_cast<resultswindow *>(_o);
        switch (_id) {
        case 0: _t->receive_results_for_Public((*reinterpret_cast< const QListWidget*(*)>(_a[1])),(*reinterpret_cast< const QTableWidget*(*)>(_a[2])),(*reinterpret_cast< const QTableWidget*(*)>(_a[3])),(*reinterpret_cast< const QTableWidget*(*)>(_a[4]))); break;
        case 1: _t->receive_comment_for_Public((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->swapTimeTick(); break;
        default: ;
        }
    }
}

const QMetaObject resultswindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_resultswindow.data,
      qt_meta_data_resultswindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *resultswindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *resultswindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_resultswindow.stringdata))
        return static_cast<void*>(const_cast< resultswindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int resultswindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
