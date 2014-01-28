/****************************************************************************
** Meta object code from reading C++ file 'SideBySideRenderWindowsQt.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SideBySideRenderWindowsQt.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SideBySideRenderWindowsQt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SideBySideRenderWindowsQt[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      33,   27,   26,   26, 0x05,
      51,   26,   26,   26, 0x05,
      67,   61,   26,   26, 0x05,

 // slots: signature, parameters, type, tag, flags
      96,   26,   26,   26, 0x0a,
     107,   26,   26,   26, 0x0a,
     131,   26,   26,   26, 0x0a,
     157,   26,   26,   26, 0x0a,
     182,   26,   26,   26, 0x0a,
     195,   26,   26,   26, 0x0a,
     210,   26,   26,   26, 0x0a,
     224,   26,   26,   26, 0x0a,
     236,   26,   26,   26, 0x0a,
     250,   26,   26,   26, 0x0a,
     263,   26,   26,   26, 0x0a,
     282,   26,   26,   26, 0x0a,
     300,   26,   26,   26, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SideBySideRenderWindowsQt[] = {
    "SideBySideRenderWindowsQt\0\0value\0"
    "valueChanged(int)\0clicked()\0event\0"
    "mouseMoveEvent(QMouseEvent*)\0slotExit()\0"
    "setSliceNumberLeft(int)\0"
    "setSliceNumberCenter(int)\0"
    "setSliceNumberRight(int)\0renderLeft()\0"
    "renderCenter()\0renderRight()\0clearleft()\0"
    "clearcenter()\0clearright()\0"
    "renderGreenColor()\0renderBlueColor()\0"
    "renderRedColor()\0"
};

void SideBySideRenderWindowsQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SideBySideRenderWindowsQt *_t = static_cast<SideBySideRenderWindowsQt *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->clicked(); break;
        case 2: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->slotExit(); break;
        case 4: _t->setSliceNumberLeft((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setSliceNumberCenter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setSliceNumberRight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->renderLeft(); break;
        case 8: _t->renderCenter(); break;
        case 9: _t->renderRight(); break;
        case 10: _t->clearleft(); break;
        case 11: _t->clearcenter(); break;
        case 12: _t->clearright(); break;
        case 13: _t->renderGreenColor(); break;
        case 14: _t->renderBlueColor(); break;
        case 15: _t->renderRedColor(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SideBySideRenderWindowsQt::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SideBySideRenderWindowsQt::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SideBySideRenderWindowsQt,
      qt_meta_data_SideBySideRenderWindowsQt, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SideBySideRenderWindowsQt::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SideBySideRenderWindowsQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SideBySideRenderWindowsQt::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SideBySideRenderWindowsQt))
        return static_cast<void*>(const_cast< SideBySideRenderWindowsQt*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SideBySideRenderWindowsQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void SideBySideRenderWindowsQt::valueChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SideBySideRenderWindowsQt::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void SideBySideRenderWindowsQt::mouseMoveEvent(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
