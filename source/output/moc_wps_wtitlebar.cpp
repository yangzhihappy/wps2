/****************************************************************************
** Meta object code from reading C++ file 'wps_wtitlebar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/wps_wtitlebar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wps_wtitlebar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WPS_WTitleBar_t {
    QByteArrayData data[5];
    char stringdata[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WPS_WTitleBar_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WPS_WTitleBar_t qt_meta_stringdata_WPS_WTitleBar = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 8),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 6),
QT_MOC_LITERAL(4, 31, 11)
    },
    "WPS_WTitleBar\0sigClose\0\0sigMin\0"
    "slotClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WPS_WTitleBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06,
       3,    0,   30,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   31,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void WPS_WTitleBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WPS_WTitleBar *_t = static_cast<WPS_WTitleBar *>(_o);
        switch (_id) {
        case 0: _t->sigClose(); break;
        case 1: _t->sigMin(); break;
        case 2: _t->slotClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WPS_WTitleBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WPS_WTitleBar::sigClose)) {
                *result = 0;
            }
        }
        {
            typedef void (WPS_WTitleBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WPS_WTitleBar::sigMin)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject WPS_WTitleBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WPS_WTitleBar.data,
      qt_meta_data_WPS_WTitleBar,  qt_static_metacall, 0, 0}
};


const QMetaObject *WPS_WTitleBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WPS_WTitleBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WPS_WTitleBar.stringdata))
        return static_cast<void*>(const_cast< WPS_WTitleBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int WPS_WTitleBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void WPS_WTitleBar::sigClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void WPS_WTitleBar::sigMin()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
