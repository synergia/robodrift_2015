/****************************************************************************
** Meta object code from reading C++ file 'racewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../racewindow.h"
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
    QByteArrayData data[26];
    char stringdata[414];
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
QT_MOC_LITERAL(3, 33, 4),
QT_MOC_LITERAL(4, 38, 5),
QT_MOC_LITERAL(5, 44, 6),
QT_MOC_LITERAL(6, 51, 34),
QT_MOC_LITERAL(7, 86, 10),
QT_MOC_LITERAL(8, 97, 22),
QT_MOC_LITERAL(9, 120, 8),
QT_MOC_LITERAL(10, 129, 21),
QT_MOC_LITERAL(11, 151, 8),
QT_MOC_LITERAL(12, 160, 12),
QT_MOC_LITERAL(13, 173, 10),
QT_MOC_LITERAL(14, 184, 12),
QT_MOC_LITERAL(15, 197, 16),
QT_MOC_LITERAL(16, 214, 23),
QT_MOC_LITERAL(17, 238, 14),
QT_MOC_LITERAL(18, 253, 21),
QT_MOC_LITERAL(19, 275, 11),
QT_MOC_LITERAL(20, 287, 22),
QT_MOC_LITERAL(21, 310, 22),
QT_MOC_LITERAL(22, 333, 21),
QT_MOC_LITERAL(23, 355, 19),
QT_MOC_LITERAL(24, 375, 16),
QT_MOC_LITERAL(25, 392, 21)
    },
    "racewindow\0send_results_of_race\0\0team\0"
    "mTeam\0result\0connect_with_master_return_Message\0"
    "PortStatus\0receive_final_position\0"
    "position\0receiveRaceWindowData\0nextTeam\0"
    "rSensorCount\0rLapsCount\0raceTimeTick\0"
    "race_time_format\0on_sensorButton_clicked\0"
    "race_has_began\0race_has_been_stopped\0"
    "race_safety\0load_last_best_results\0"
    "save_last_best_results\0MasterSerialPort_init\0"
    "connect_with_master\0master_serial_dc\0"
    "master_serial_receive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_racewindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   94,    2, 0x06 /* Public */,
       6,    1,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,  102,    2, 0x08 /* Private */,
      10,    4,  105,    2, 0x08 /* Private */,
      14,    0,  114,    2, 0x08 /* Private */,
      15,    1,  115,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,
      20,    0,  122,    2, 0x08 /* Private */,
      21,    0,  123,    2, 0x08 /* Private */,
      22,    0,  124,    2, 0x08 /* Private */,
      23,    0,  125,    2, 0x08 /* Private */,
      24,    0,  126,    2, 0x08 /* Private */,
      25,    0,  127,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::Int, QMetaType::Int,    4,   11,   12,   13,
    QMetaType::Void,
    QMetaType::QString, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        case 0: _t->send_results_of_race((*reinterpret_cast< const team(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 1: _t->connect_with_master_return_Message((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->receive_final_position((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->receiveRaceWindowData((*reinterpret_cast< const team(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4]))); break;
        case 4: _t->raceTimeTick(); break;
        case 5: { QString _r = _t->race_time_format((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: _t->on_sensorButton_clicked(); break;
        case 7: _t->race_has_began(); break;
        case 8: _t->race_has_been_stopped(); break;
        case 9: _t->race_safety(); break;
        case 10: _t->load_last_best_results(); break;
        case 11: _t->save_last_best_results(); break;
        case 12: _t->MasterSerialPort_init(); break;
        case 13: _t->connect_with_master(); break;
        case 14: _t->master_serial_dc(); break;
        case 15: _t->master_serial_receive(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (racewindow::*_t)(const team & , const int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&racewindow::send_results_of_race)) {
                *result = 0;
            }
        }
        {
            typedef void (racewindow::*_t)(const int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&racewindow::connect_with_master_return_Message)) {
                *result = 1;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void racewindow::send_results_of_race(const team & _t1, const int & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void racewindow::connect_with_master_return_Message(const int & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
