/****************************************************************************
** Meta object code from reading C++ file 'quickcalculate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../quickcalculate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quickcalculate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QuickCalculate_t {
    QByteArrayData data[6];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QuickCalculate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QuickCalculate_t qt_meta_stringdata_QuickCalculate = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QuickCalculate"
QT_MOC_LITERAL(1, 15, 25), // "on_btnPutNumberOK_clicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 23), // "on_btnGetResult_clicked"
QT_MOC_LITERAL(4, 66, 22), // "on_btn_ShowImg_clicked"
QT_MOC_LITERAL(5, 89, 18) // "on_btnExit_clicked"

    },
    "QuickCalculate\0on_btnPutNumberOK_clicked\0"
    "\0on_btnGetResult_clicked\0"
    "on_btn_ShowImg_clicked\0on_btnExit_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QuickCalculate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QuickCalculate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QuickCalculate *_t = static_cast<QuickCalculate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnPutNumberOK_clicked(); break;
        case 1: _t->on_btnGetResult_clicked(); break;
        case 2: _t->on_btn_ShowImg_clicked(); break;
        case 3: _t->on_btnExit_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QuickCalculate::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QuickCalculate.data,
      qt_meta_data_QuickCalculate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QuickCalculate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuickCalculate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QuickCalculate.stringdata0))
        return static_cast<void*>(const_cast< QuickCalculate*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QuickCalculate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
