/****************************************************************************
** Meta object code from reading C++ file 'simpoi_widget.h'
**
** Created: Tue Feb 9 22:53:24 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "simpoi_widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simpoi_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SimpoiWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      29,   23,   13,   13, 0x0a,
      52,   23,   13,   13, 0x0a,
      75,   23,   13,   13, 0x0a,
      99,   23,   13,   13, 0x0a,
     123,   13,   13,   13, 0x0a,
     140,   13,   13,   13, 0x0a,
     150,   13,   13,   13, 0x0a,
     168,   13,   13,   13, 0x0a,
     183,  179,   13,   13, 0x0a,
     213,  179,   13,   13, 0x0a,
     242,  179,   13,   13, 0x0a,
     273,  179,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SimpoiWidget[] = {
    "SimpoiWidget\0\0update()\0value\0"
    "poi1_speed_change(int)\0poi1_angle_change(int)\0"
    "path1_speed_change(int)\0path1_angle_change(int)\0"
    "poi1_clockwise()\0poi1_cc()\0path1_clockwise()\0"
    "path1_cc()\0str\0path1_height_changed(QString)\0"
    "path1_width_changed(QString)\0"
    "path1_centerx_changed(QString)\0"
    "path1_centery_changed(QString)\0"
};

const QMetaObject SimpoiWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_SimpoiWidget,
      qt_meta_data_SimpoiWidget, 0 }
};

const QMetaObject *SimpoiWidget::metaObject() const
{
    return &staticMetaObject;
}

void *SimpoiWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SimpoiWidget))
        return static_cast<void*>(const_cast< SimpoiWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int SimpoiWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: update(); break;
        case 1: poi1_speed_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: poi1_angle_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: path1_speed_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: path1_angle_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: poi1_clockwise(); break;
        case 6: poi1_cc(); break;
        case 7: path1_clockwise(); break;
        case 8: path1_cc(); break;
        case 9: path1_height_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: path1_width_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: path1_centerx_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: path1_centery_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
