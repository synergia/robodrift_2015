/****************************************************************************
** Meta object code from reading C++ file 'racewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "racewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'racewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_racewindow_t {
    QByteArrayData data[18];
    char stringdata[263];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_racewindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_racewindow_t qt_meta_stringdata_racewindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 20),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 6),
QT_MOC_LITERAL(4, 40, 22),
QT_MOC_LITERAL(5, 63, 8),
QT_MOC_LITERAL(6, 72, 21),
QT_MOC_LITERAL(7, 94, 4),
QT_MOC_LITERAL(8, 99, 5),
QT_MOC_LITERAL(9, 105, 8),
QT_MOC_LITERAL(10, 114, 11),
QT_MOC_LITERAL(11, 126, 12),
QT_MOC_LITERAL(12, 139, 16),
QT_MOC_LITERAL(13, 156, 23),
QT_MOC_LITERAL(14, 180, 14),
QT_MOC_LITERAL(15, 195, 21),
QT_MOC_LITERAL(16, 217, 22),
QT_MOC_LITERAL(17, 240, 22)
    },
    "racewindow\0send_results_of_race\0\0"
    "result\0receive_final_position\0position\0"
    "receiveRaceWindowData\0team\0mTeam\0"
    "nextTeam\0mSensorTick\0raceTimeTick\0"
    "race_time_format\0on_sensorButton_clicked\0"
    "race_has_began\0race_has_been_stopped\0"
    "load_last_best_results\0save_last_best_results"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_racewindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   67,    2, 0x08 /* Private */,
       6,    3,   70,    2, 0x08 /* Private */,
      11,    0,   77,    2, 0x08 /* Private */,
      12,    1,   78,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,
      14,    0,   82,    2, 0x08 /* Private */,
      15,    0,   83,    2, 0x08 /* Private */,
      16,    0,   84,    2, 0x08 /* Private */,
      17,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QString, QMetaType::Int,    8,    9,   10,
    QMetaType::Void,
    QMetaType::QString, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void racewindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        racewindow *_t = static_cast<racewindow *>(_o);
        switch (_id) {
        case 0: _t->send_results_of_race((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->receive_final_position((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->receiveRaceWindowData((*reinterpret_cast< const team(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 3: _t->raceTimeTick(); break;
        case 4: { QString _r = _t->race_time_format((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: _t->on_sensorButton_clicked(); break;
        case 6: _t->race_has_began(); break;
        case 7: _t->race_has_been_stopped(); break;
        case 8: _t->load_last_best_results(); break;
        case 9: _t->save_last_best_results(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (racewindow::*_t)(const int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&racewindow::send_results_of_race)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject racewindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_racewindow.data,
      qt_meta_data_racewindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *racewindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *racewindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_racewindow.stringdata))
        return static_cast<void*>(const_cast< racewindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int racewindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void racewindow::send_results_of_race(const int & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
